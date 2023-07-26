/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:29:09 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:14:06 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		// Constructors
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		
		// Operators
		Animal &operator=(Animal const &src);

		// Getters and Setters
		std::string getType(void) const;
		void setType(std::string const type);
	
		// Member functions
		virtual void makeSound(void) const = 0;
};

#endif
