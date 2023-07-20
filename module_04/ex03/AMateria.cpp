/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:56:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/20 17:04:00 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

// Getters

std::string const & AMateria::getType() const
{
	return (this->type);
}

// Member Functions

void AMateria::use(ICharacter& target)
{
	(void)target;
}
