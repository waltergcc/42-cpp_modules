/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:44:57 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 16:42:32 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors

Dog::Dog(void) 
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

// Operators

Dog	&Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

// Member functions

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Woof woof!" << std::endl;
}
