/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 18:22:10 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl << std::endl;
}

int	main(void)
{
	titleHeader("SCAVTRAP DEFAULT");
	ScavTrap	firstRobot;

	firstRobot.attack("invasors");
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(9);
	std::cout << firstRobot << std::endl;
	firstRobot.beRepaired(5);
	std::cout << firstRobot << std::endl;
	firstRobot.guardGate();
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(100);
	std::cout << firstRobot << std::endl;
	firstRobot.beRepaired(50);
	firstRobot.attack("traitors");
	pressEnter();

	titleHeader("SCAVTRAP SPECIFIC");
	ScavTrap	secondRobot("Scav3000");
	
	secondRobot.attack("invasors");
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(78);
	std::cout << secondRobot << std::endl;
	secondRobot.beRepaired(89);
	std::cout << secondRobot << std::endl;
	secondRobot.guardGate();
	std::cout << secondRobot << std::endl;
	secondRobot.attack("monsters");
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(200);
	std::cout << secondRobot << std::endl;
	secondRobot.attack("monsters");
	pressEnter();

	titleHeader("SCAVTRAP COPY");
	ScavTrap	thirdRobot(secondRobot);
	thirdRobot.attack("traitors");
	std::cout << thirdRobot << std::endl;
	pressEnter();

	titleHeader("CLAPTRAPS DESTUCTORS");
}
