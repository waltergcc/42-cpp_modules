/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:09:21 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 08:43:27 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------------------- CONSTURCTORS ----------------------------------

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitPoints = FragTrap::initHit;
	this->_energyPoints = ScavTrap::initEnergy;
	this->_attackDamage = FragTrap::initDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string const diamondName) : ClapTrap(diamondName), ScavTrap(diamondName), FragTrap(diamondName)
{
	std::cout << "DiamondTrap constructor with parameter called" << std::endl;
	this->_name = diamondName;
	this->_hitPoints = FragTrap::initHit;
	this->_energyPoints = ScavTrap::initEnergy;
	this->_attackDamage = FragTrap::initDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = copy._name;
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
	this->_name = copy._name;
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	this->ClapTrap::_name = copy.ClapTrap::_name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name;
	std::cout << " is also known as " << this->ClapTrap::_name << std::endl;
}
