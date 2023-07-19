/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:56:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 16:42:32 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

// Operators

Cat	&Cat::operator=(Cat const &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

// Member functions

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow meow!" << std::endl;
}
