/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:43:19 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 22:02:29 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// --------------------------- CONSTURCTORS ----------------------------------

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor with parameter called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// --------------------------- OPERATORS ----------------------------------

ScavTrap	&ScavTrap::operator = (ScavTrap const &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	return (*this);
}

// --------------------------- MEMBER FUNCTIONS ----------------------------------

void	ScavTrap::attack(std::string const &target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "ScavTrap " << this->_name << " is out of action!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " bombs " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << std::endl;
}
