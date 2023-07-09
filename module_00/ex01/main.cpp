/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 08:24:11 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/08 22:41:43 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	instructions_header(void)
{
	std::cout << CLEAR;
	std::cout << "/* ********************************************/" << std::endl;
	std::cout << "/*                                            */" << std::endl;
	std::cout << "/*          Welcome to phonebook app          */" << std::endl;
	std::cout << "/*                                            */" << std::endl;
	std::cout << "/*  plese insert one of the follow commands:  */" << std::endl;
	std::cout << "/*                                            */" << std::endl;
	std::cout << "/*  ADD    - create a new contact             */" << std::endl;
	std::cout << "/*  SEARCH - display a existent contact       */" << std::endl;
	std::cout << "/*  EXIT   - exits the app                    */" << std::endl;
	std::cout << "/*                                            */" << std::endl;
	std::cout << "/* ********************************************/" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string user_input;
	int 		invalid_command = NO;
	
	while (1)
	{
		if (!invalid_command)
			instructions_header();
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