/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 17:53:28 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	titleHeader("CLAPTRAP DEFAULT");
	ClapTrap	firstRobot;

	firstRobot.attack("invasors");
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(5);
	std::cout << firstRobot << std::endl;
	firstRobot.beRepaired(5);
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(15);
	std::cout << firstRobot << std::endl;
	firstRobot.attack("traitors");
	pressEnter();

	titleHeader("CLAPTRAP SPECIFIC");
	ClapTrap	secondRobot("Version 2.0");
	secondRobot.attack("invasors");
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(9);
	std::cout << secondRobot << std::endl;
	secondRobot.beRepaired(1);
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(2);
	std::cout << secondRobot << std::endl;
	secondRobot.beRepaired(2);
	pressEnter();

	titleHeader("CLAPTRAP COPY");
	ClapTrap	thirdRobot(secondRobot);
	thirdRobot.attack("traitors");
	std::cout << thirdRobot << std::endl;
	pressEnter();

	titleHeader("CLAPTRAPS DESTUCTORS");
}
