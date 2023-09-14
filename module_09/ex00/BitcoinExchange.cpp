/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:41 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/04 19:27:42 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidNumber(std::string const &in)
{
	if ((in.find_first_not_of(VALID_SET) != std::string::npos)		// check if there is any invalid char
		|| (in.find_first_of(".") != in.find_last_of("."))			// check if there is more than one dot
		|| (in.find_first_of(".") == in.length() - 1)				// check if the dot is the last char
		|| (in.find_first_of(".") == 0)								// check if the dot is the first char
		|| (in.find_first_of(SIGNAL) != in.find_last_of(SIGNAL)))	// check if there is more than one signal
		return (false);
	return (true);	
}
bool isValidDate(std::string const &in, btcPrice &node)
{
	if ((in.length() != 10)												// check if the date has 10 chars
		|| (in.find_first_not_of(DATE_SET) != std::string::npos)		// check if there is any invalid char
		|| (in.find_first_of("-") != 4 || in.find_last_of("-") != 7))	// check if the date has the format YYYY-MM-DD
		return (false);

	std::tm date;
	if (strptime(in.c_str(), "%Y-%m-%d", &date))
	{
		date.tm_year += 1900;
		date.tm_mon += 1;
		node.date = date;
		return (true);
	}
	return (false);
}

bool isValidValue(std::string const &in)
{
	if (!isValidNumber(in))
		return (false);
	
	float nb = std::atof(in.c_str());

	if (nb < 0 || nb >= (float)INT_MAX)
		return (false);
	
	return (true);
}

bool isValidAmount(std::string const &in)
{
	if (!isValidNumber(in))
	{
		std::cerr << ERR_NOT_NB << std::endl;	
		return (false);
	}	
	float nb = std::atof(in.c_str());
	if (nb < 0)
	{
		std::cerr << ERR_NOT_POS << std::endl;
		return (false);
	}
	else if (nb > 1000)
	{
		std::cerr << ERR_TOO_LARGE << std::endl;
		return (false);
	}
	return (true);
}

std::string trim(std::string const &str)
{
    size_t start = str.find_first_not_of(SPACES_SET);
    size_t end = str.find_last_not_of(SPACES_SET);

    if (start == std::string::npos)
        return "";

    return (str.substr(start, end - start + 1));
}

std::vector<btcPrice> getDatabase()
{
	std::ifstream	file("data.csv");
	std::vector<btcPrice> database;
	std::string line;

	if (!file.is_open())
		throw std::runtime_error(ERR_DB_OPEN);

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error(ERR_DB_FIELDS);

	while (std::getline(file, line))
	{
		btcPrice tmp;
		std::string date;
		std::string value;
		std::stringstream ss(line);

		std::getline(ss, date, ',');
		ss >> value;

		tmp.price = std::atof(value.c_str());
		if (!isValidDate(date, tmp) || !isValidValue(value))
			throw std::runtime_error(ERR_DB_INVALID);
		database.push_back(tmp);
	}
	file.close();
	return (database);
}

int compareDates(std::tm const &a, std::tm const &b)
{
	if (a.tm_year > b.tm_year)
		return (DB_IS_LARGER);
	else if (a.tm_year < b.tm_year)
		return (IN_IS_LARGER);
	else if (a.tm_mon > b.tm_mon)
		return (DB_IS_LARGER);
	else if (a.tm_mon < b.tm_mon)
		return (IN_IS_LARGER);
	else if (a.tm_mday > b.tm_mday)
		return (DB_IS_LARGER);
	else if (a.tm_mday < b.tm_mday)
		return (IN_IS_LARGER);
	return (EQUAL);
}

float exchangeValue(std::vector<btcPrice> const &database, btcPrice const &in)
{
	// if the input date is before the first date in the database
	if (compareDates(database[0].date, in.date) == DB_IS_LARGER)
		return (0);

	std::vector<btcPrice>::const_iterator it;

	for (it = database.begin(); it != database.end(); it++)
	{
		btcPrice db = *it;

		int cmp = compareDates(db.date, in.date);
		if (cmp == EQUAL)
			return (db.price * in.amount);
		else if (cmp == DB_IS_LARGER) // if the database date is after the input date
		{
			it--;
			db = *it;
			return (db.price * in.amount);
		}
	}
	btcPrice lastValue = database.back();
	return (lastValue.price * in.amount);
}


void readInput(std::vector<btcPrice> &database, std::string const &filename)
{
	std::ifstream	file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error(ERR_IN_OPEN + filename);

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error(ERR_IN_FIELDS + filename);
	
	while (std::getline(file, line))
	{
		btcPrice tmp;
		std::string date;
		std::string amount;
		std::string remaing;
		std::stringstream ss(line);

		std::getline(ss, date, '|');
		date = trim(date);
		ss >> amount;
		tmp.amount = std::atof(amount.c_str());

		if (!isValidDate(date, tmp) || ss.fail())
		{
			std::cerr << ERR_BAD_INPUT << line << std::endl;
			continue;
		}
		ss >> remaing;
		if (!ss.fail())
			std::cerr << ERR_BAD_INPUT << line << std::endl;
		else if (!isValidAmount(amount)){}
		else
		{
			std::cout << date << " => ";
			std::cout << tmp.amount << " = ";
			std::cout << exchangeValue(database, tmp) << std::endl;
		}
	}
	file.close();
}
