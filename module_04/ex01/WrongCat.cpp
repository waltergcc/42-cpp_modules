/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:56:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 16:42:32 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// Operators

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

// Member functions

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Meow meow!" << std::endl;
}
