/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:44 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/04 19:27:45 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
#include <stdexcept>

#define RED		"\033[31m"
#define RESET	"\033[0m"

#define SIGNAL		"+-"
#define VALID_SET	"+-0123456789."
#define DATE_SET	"-0123456789"
#define SPACES_SET	" \t\n\r\f\v"

#define ERR_OPEN		"could not open file."

#define ERR_DB_OPEN		"Couldn't open data.csv file"
#define ERR_DB_FIELDS	"Invalid fields in data.csv file"
#define ERR_DB_INVALID	"Invalid data.csv file"

#define ERR_IN_OPEN		"Couldn't open "
#define ERR_IN_FIELDS	"Invalid fields in "

#define ERR_BAD_INPUT	"Error: bad input => "
#define ERR_NOT_NB		"Error: not a number."
#define ERR_NOT_POS		"Error: not a positive number."
#define ERR_TOO_LARGE	"Error: too large a number."

#define DB_IS_LARGER	1
#define IN_IS_LARGER	-1
#define EQUAL			0

struct btcPrice
{
	std::tm		date;
	float		price;
	float		amount;
};

bool isValidNumber(std::string const &in);
bool isValidDate(std::string const &in, btcPrice &node);
bool isValidValue(std::string const &in);
bool isValidAmount(std::string const &in);

std::vector<btcPrice> getDatabase();
void readInput(std::vector<btcPrice> &database, std::string const &filename);
float exchangeValue(std::vector<btcPrice> const &database, btcPrice const &in);

std::string trim(std::string const &str);
