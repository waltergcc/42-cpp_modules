/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:45:19 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 23:54:58 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static int const initHit = 100;
		static int const initEnergy = 100;
		static int const initDamage = 30;
		
	public:
		// Constructors
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);
		
		// Operators
		FragTrap	&operator=(FragTrap const &trap);

		// Specific Member functions
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
