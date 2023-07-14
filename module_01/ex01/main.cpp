/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:52 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 14:45:05 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	mainHeader(void)
{
	std::cout << "\033c";
	std::cout << "**********************************" << std::endl;
	std::cout << "*         OUR C++ ZOMBIES        *" << std::endl;
	std::cout << "**********************************" << std::endl << std::endl;
}

int	main(void)
{
	std::string zombiesClass;
	int			hordeSize;
	Zombie 		*zombie;

	mainHeader();
	while (1)
	{
		std::cout << "Enter the size of the zombie's horde: " << std::endl;
		std::cin >> hordeSize;
		if (std::cin.fail() || hordeSize <= 0)
		{
			std::cout << "Invalid input. Try again with a positive integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			break ;
	}
	std::cout << "Now enter a name for your zombies class: " << std::endl;
	std::cin >> zombiesClass;
	
	mainHeader();
	zombie = zombieHorde(hordeSize, zombiesClass);
	for (int i = 0; i < hordeSize; i++)
		zombie[i].announce();
	delete [] zombie;
}
