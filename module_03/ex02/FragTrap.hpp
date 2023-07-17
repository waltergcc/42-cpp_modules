/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:45:19 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 19:40:22 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
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