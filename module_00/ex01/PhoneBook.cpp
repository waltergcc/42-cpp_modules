/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:28:08 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/09 01:26:10 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_id = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::add(void)
{
	std::string firstName, lastName, nickname, phone, secret;

	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	
	if (firstName.length() < 1
		|| lastName.length() < 1
		|| nickname.length() < 1
		|| phone.length() < 1
		|| secret.length() < 1)
	{
		std::cout << std::endl;
		std::cout << "Invalid Contact. A new contact can't have any empty field." << std::endl;
		std::cout << "Press ENTER to continue." << std::endl;
		std::cin.ignore();
		return ;
	}
	this->_contacts[this->_id++ % 8] = Contact(firstName, lastName, nickname, phone, secret);
	std::cout << std::endl;
	std::cout << "Contact added successfully." << std::endl;
	std::cout << "Press ENTER to continue." << std::endl;
	std::cin.ignore();
}

void	PhoneBook::_printTable(void)
{
	std::string field;

	std::cout << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].getFirstName().length() > 0)
		{
			std::cout << "|" << std::setw(10) << i + 1 << "|";
			field = this->_contacts[i].getFirstName();
			std::cout << std::setw(10) << Contact::formatWidth(field) << "|";
			field = this->_contacts[i].getLastName();
			std::cout << std::setw(10) << Contact::formatWidth(field) << "|";
			field = this->_contacts[i].getNickname();
			std::cout << std::setw(10) << Contact::formatWidth(field) << "|" << std::endl;
		}
	}
	std::cout << std::endl;
}

void	PhoneBook::search(void)
{
	std::string input;
	int 		index;
	int 		maxIndex = this->_id > 7 ? 8 : this->_id;
	
	if (this->_id == 0)
	{
		std::cout << std::endl;
		std::cout << "No contacts added yet." << std::endl;
		std::cout << "Press ENTER to back." << std::endl;
		std::cin.ignore();
		return ;
	}
	this->_printTable();
	std::cout << "Please insert the contact index to display all info or type BACK to return" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		index = std::atoi(input.c_str());
		if (input == "BACK")
			break ;
		else if (index < 1 || index > maxIndex)
		{
			std::cout << "Invalid option. Please try again or type BACK to return." << std::endl;
			continue ;
		}
		else
		{
			this->_contacts[index - 1].displayContact();
			std::cout << "Press ENTER to continue." << std::endl;
			std::cin.ignore();
			break ;
		}
	}
}