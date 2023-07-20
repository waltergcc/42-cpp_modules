/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:45:31 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/20 17:46:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Constructors
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);

		// Operators
		Ice & operator = (Ice const & src);
		
		// Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif