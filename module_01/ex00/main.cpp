/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:52 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/13 11:57:50 by wcorrea-         ###   ########.fr       */
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
	std::string chumpName;
	std::string zombieName;
	Zombie *zombie;

	mainHeader();
	std::cout << "Enter a name to the chump: " << std::endl;
	std::cin >> chumpName;
	std::cout << "Now enter a name to the zombie: " << std::endl;
	std::cin >> zombieName;
	
	mainHeader();
	zombie = newZombie(zombieName); 
	zombie->announce();
	
	randomChump(chumpName);

	delete zombie;
}