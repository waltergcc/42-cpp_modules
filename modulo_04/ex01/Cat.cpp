/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:56:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 22:18:19 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = src;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

// Operators

Cat	&Cat::operator=(Cat const &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

// Member functions

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow meow!" << std::endl;
}

// Getters

Brain	*Cat::getBrain(void) const {return (this->_brain);}
