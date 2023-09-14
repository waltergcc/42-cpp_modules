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

#include "RPN.hpp"

bool isValidNumber(std::string const &in)
{
	if (in.empty() || (in.find_first_not_of(VALID_SET) != std::string::npos))
		return (false);
	return (true);	
}

bool isOperator(std::string const &in)
{
	return (in == "+" || in == "-" || in == "*" || in == "/");
}

void doOperation(std::string const &in, std::stack<int> &stack)
{
	if (stack.size() < 2)
		throw std::runtime_error(INVALID);
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();

	if (in == "+")
		stack.push(b + a);
	else if (in == "-")
		stack.push(b - a);
	else if (in == "*")
		stack.push(b * a);
	else if (in == "/")
		stack.push(b / a);
}

void addNumber(std::string const &in, std::stack<int> &stack)
{
	int nb = std::atoi(in.c_str());

	if (nb > 9)
		throw std::runtime_error(ERROR);
	stack.push(nb);
}

void rpn(std::string const &in)
{
	std::stack<int> stack;
	std::stringstream ss(in);
	std::string token;

	while (!ss.eof())
	{
		std::getline(ss, token, ' ');
		if (token.empty())
			continue;
		if (isOperator(token))
			doOperation(token, stack);
		else if (isValidNumber(token))
			addNumber(token, stack);
		else
			throw std::runtime_error(ERROR);
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		throw std::runtime_error(ERROR);
}
