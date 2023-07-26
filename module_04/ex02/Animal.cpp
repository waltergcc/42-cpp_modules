/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:33:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 22:39:10 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors

Animal::Animal(void) 
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) 
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void) 
{
	std::cout << "Animal destructor called" << std::endl;
}

// Operators

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->type = src.getType();
	return (*this);
}

// Getters and Setters

std::string Animal::getType(void) const {return (this->type);}
void Animal::setType(std::string const type) {this->type = type;}
