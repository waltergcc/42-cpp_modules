/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 08:24:11 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 14:40:57 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	main_header(void)
{
	std::cout << CLEAR;
	std::cout << "**********************************" << std::endl;
	std::cout << "*       80's PHONEBOOK APP       *" << std::endl;
	std::cout << "**********************************" << std::endl << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "- ADD" << std::endl;
	std::cout << "- SEARCH" << std::endl;
	std::cout << "- EXIT" << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string user_input;
	int 		invalid_command = NO;
	
	while (1)
	{
		if (!invalid_command)
			main_header();
		std::cout << "Enter a command: ";
		std::getline(std::cin, user_input);
		if (user_input == "ADD")
			phonebook.add();
		else if (user_input == "SEARCH")
			phonebook.search();
		else if (user_input == "EXIT")
			break ;
		else
		{
			std::cout << "Invalid command. Please insert a valid command." << std::endl;
			invalid_command = YES;
			continue ;
		}
		invalid_command = NO;
	}
	std::cout << CLEAR;
}
