/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:52 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/11 22:36:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level = -1;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [LEVEL]" << std::endl;
		return (1);
	}

	for (int i = 0; i < 4; i++)
		if (levels[i] == av[1])
			level = i;
	while (level < 4)
	{
		switch (level)
		{
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain("DEBUG");
				break;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				harl.complain("INFO");
				break;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain("WARNING");
				break;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain("ERROR");
				break;
		}
		if (level == 3 || level == -1)
			break;
		else
		{
			level++;
			std::cout << std::endl;	
		}
	}
}