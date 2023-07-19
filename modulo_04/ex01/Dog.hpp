/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:43:01 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 15:51:13 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog(void);
		Dog(Dog const &src);	
		virtual ~Dog(void);
		
		// Operators
		Dog &operator=(Dog const &src);

		// Member functions
		void makeSound(void) const;	
};

#endif