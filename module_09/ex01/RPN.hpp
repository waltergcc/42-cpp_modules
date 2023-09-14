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
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

#define VALID_SET	"0123456789"

#define ERROR	"Error"
#define INVALID	"Invalid operations"
#define USAGE	"Usage: ./rpn \"[expression]\""

bool isValidNumber(std::string const &in);
bool isOperator(std::string const &in);

void doOperation(std::string const &in, std::stack<int> &stack);
void addNumber(std::string const &in, std::stack<int> &stack);

void rpn(std::string const &in);
