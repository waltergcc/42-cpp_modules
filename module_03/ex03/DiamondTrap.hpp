/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:09:36 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/24 16:53:51 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		// Constructors
		DiamondTrap(void);
		DiamondTrap(std::string const diamondName);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap(void);

		// Operators
		DiamondTrap	&operator=(DiamondTrap const &copy);
		
		// Member functions
		void	whoAmI(void);
		using	ScavTrap::attack;
};

#endif
