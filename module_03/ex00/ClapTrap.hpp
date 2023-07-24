/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:03:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 16:49:54 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		// Constructors and destructor
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);

		// Operators
		ClapTrap	&operator=(ClapTrap const &copy);

		// Get functions
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		
		// Member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	isGameOver(void);
};

std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap);

#endif
