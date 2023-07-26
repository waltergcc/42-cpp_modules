/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:41 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:15:00 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure(void);
		Cure(Cure const & src);
		~Cure(void);
		
		// Operators
		Cure & operator = (Cure const & src);
		
		// Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
