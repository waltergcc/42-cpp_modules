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
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <string>
#include <list>
#include <deque>
#include <ctime>
#include <algorithm>
#include <stdexcept>

#define VALID_SET	"0123456789"
#define LIMITER		5

#define ERROR	"Error"

// common functions
bool isValidNumber(std::string const &in);
bool isValidInput(char **av);
void printBefore(char **av);

// list functions
void fillList(std::list<int> &list, char **av);
void listInsert(std::list<int> &sorted, int const &nb);
void listInsertionSort(std::list<int> &list);
void listMergeInsertionSort(std::list<int> &list);
void sortList(std::list<int> &list, char **av, double &time);
void printListAfter(std::list<int> &list);

// deque functions
void fillDeque(std::deque<int> &deque, char **av);
void dequeInsert(std::deque<int> &sorted, int const &nb);
void dequeInsertionSort(std::deque<int> &deque);
void dequeMergeInsertionSort(std::deque<int> &deque);
void sortDeque(std::deque<int> &deque, char **av, double &time);
void printDequeAfter(std::deque<int> &deque);
