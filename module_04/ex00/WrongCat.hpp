/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:53:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 16:20:01 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat(void);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat(void);

		// Operators
		WrongCat &operator=(WrongCat const &src);
		
		// Member functions
		void makeSound(void) const;	
};

#endif