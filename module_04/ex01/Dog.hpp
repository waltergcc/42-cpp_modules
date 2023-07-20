/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:43:01 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 20:52:01 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
		
	public:
		// Constructors
		Dog(void);
		Dog(Dog const &src);	
		virtual ~Dog(void);
		
		// Operators
		Dog &operator=(Dog const &src);

		// Member functions
		void makeSound(void) const;

		// Getters
		Brain *getBrain(void) const;
};

#endif