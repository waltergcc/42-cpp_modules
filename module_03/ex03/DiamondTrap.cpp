/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:09:21 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 22:12:34 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------------------- CONSTURCTORS ----------------------------------

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->ClapTrap::_name = this->name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor with parameter called" << std::endl;
	this->name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->ClapTrap::_name = this->name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = copy.name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// --------------------------- OPERATORS ----------------------------------

DiamondTrap	&DiamondTrap::operator = (DiamondTrap const &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	this->ClapTrap::_name = copy.ClapTrap::_name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->name;
	std::cout << " is also known as " << this->ClapTrap::_name << std::endl;
}
