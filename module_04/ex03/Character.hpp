/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:06:33 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:14:50 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		int			inventoryCount;
		AMateria	*inventory[4];
		AMateria	*unequiped[4];

	public:
		// Constructors
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character(void);
		
		// Operators
		Character & operator = (Character const & src);
		
		// Getters
		std::string const & getName() const;
		
		// Member Functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
