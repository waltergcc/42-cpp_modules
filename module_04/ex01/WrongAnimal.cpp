/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:33:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:13:52 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors

WrongAnimal::WrongAnimal(void) 
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) 
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Operators

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.getType();
	return (*this);
}

// Getters and Setters

std::string WrongAnimal::getType(void) const {return (this->type);}
void WrongAnimal::setType(std::string const type) {this->type = type;}

// Member functions

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: ..." << std::endl;
}
