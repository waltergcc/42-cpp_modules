/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 19:51:44 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	titleHeader("FRAGTRAP DEFAULT");
	FragTrap	firstRobot;

	firstRobot.attack("invasors");
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(9);
	std::cout << firstRobot << std::endl;
	firstRobot.beRepaired(5);
	std::cout << firstRobot << std::endl;
	firstRobot.highFivesGuys();
	std::cout << firstRobot << std::endl;
	firstRobot.takeDamage(100);
	std::cout << firstRobot << std::endl;
	firstRobot.beRepaired(50);
	firstRobot.attack("traitors");
	pressEnter();

	titleHeader("FRAGTRAP SPECIFIC");
	FragTrap	secondRobot("FragHyperX");
	
	secondRobot.attack("invasors");
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(78);
	std::cout << secondRobot << std::endl;
	secondRobot.beRepaired(89);
	std::cout << secondRobot << std::endl;
	secondRobot.highFivesGuys();
	std::cout << secondRobot << std::endl;
	secondRobot.attack("monsters");
	std::cout << secondRobot << std::endl;
	secondRobot.takeDamage(200);
	std::cout << secondRobot << std::endl;
	secondRobot.attack("monsters");
	pressEnter();

	titleHeader("FRAGTRAP COPY");
	FragTrap	thirdRobot(secondRobot);
	thirdRobot.attack("traitors");
	std::cout << thirdRobot << std::endl;
	pressEnter();

	titleHeader("FRAGTRAP DESTUCTORS");
}
