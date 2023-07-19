/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:50:25 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 22:11:47 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;

	std::string const	needs[] =
	{
		"I need to eat",
		"I need to sleep",
		"I need to play",
		"I need to poop",
		"I need to pee",
		"I need to run",
		"I need to walk",
		"I need to drink",
		"I need attention",
		"I need to be petted",
		"I need to be brushed",
		"I need to be washed",
	};
	for (int i = 0; i < 100; i++)
		this->ideas[i] = needs[rand() % 12];
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

// Operators

Brain	&Brain::operator=(Brain const &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

// Member functions

void	Brain::showIdeas(void) const
{
	for (int i = 0; i < 5; i++)
		std::cout << "idea #" << i + 1 << ": " << this->ideas[i] << std::endl;
}
