/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:42:53 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:14:44 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string	type;
	
	public:
		// Constructors
		AMateria(void);
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		// Getters
		std::string const & getType() const;

		// Member Functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
