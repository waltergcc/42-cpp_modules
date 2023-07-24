/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:30:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 23:54:52 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap : virtual public ClapTrap
{
	protected:
		static int const initHit = 100;
		static int const initEnergy = 50;
		static int const initDamage = 20;
		
	public:
		// Constructors 
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap(void);

		// Operators
		ScavTrap	&operator=(ScavTrap const &copy);

		// Special member functions
		void	guardGate(void);
		void	attack(std::string const &target);
};

#endif
