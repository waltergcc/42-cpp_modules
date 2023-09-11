/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:23 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/11 14:56:40 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl << std::endl;
}

int main(void)
{
	{
		titleHeader("INT ARRAY TEST");

		int array[] = {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999, 1010101010};

		::iter(array, 10, printContent<int>);
	}
	pressEnter();
	{
		titleHeader("STRING ARRAY TEST");

		std::string array[] = {
			"first", "second", "third", "fourth",
			"fifth", "sixth", "seventh", "eighth",
			"ninth", "tenth"};
		
		::iter(array, 10, printContent<std::string>);
	}
	pressEnter();
}
