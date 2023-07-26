/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:53:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:14:15 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
		
	public:
		// Constructors
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		// Operators
		Cat &operator=(Cat const &src);
		
		// Member functions
		void makeSound(void) const;

		// Getters
		Brain *getBrain(void) const;
};

#endif
