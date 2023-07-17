/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:45:06 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 19:41:21 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// --------------------------- CONSTURCTORS ----------------------------------

FragTrap::FragTrap(void)
{
	std::cout << "FlagTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FlagTrap constructor with parameter called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FlagTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FlagTrap destructor called" << std::endl;
}

// --------------------------- OPERATORS ----------------------------------

FragTrap	&FragTrap::operator = (FragTrap const &copy)
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

void	FragTrap::attack(std::string const &target)
{
	if (!this->_energyPoints || !this->_hitPoints)
	{
		std::cout << "FlagTrap " << this->_name << " is out of action!" << std::endl;
		return ;
	}
	std::cout << "FlagTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FlagTrap " << this->_name << " high fives everyone!" << std::endl;
}
