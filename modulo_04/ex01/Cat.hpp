/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:53:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 15:56:01 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		// Operators
		Cat &operator=(Cat const &src);
		
		// Member functions
		void makeSound(void) const;	
};

#endif