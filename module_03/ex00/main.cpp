/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/17 16:14:16 by wcorrea-         ###   ########.fr       */
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
	ClapTrap	boringTalk;

	boringTalk.attack("people's time");
	std::cout << boringTalk << std::endl;
	boringTalk.takeDamage(5);
	std::cout << boringTalk << std::endl;
	boringTalk.beRepaired(5);
	std::cout << boringTalk << std::endl;
	boringTalk.takeDamage(15);
	std::cout << boringTalk << std::endl;
	boringTalk.attack("people's time again");
	pressEnter();

	titleHeader("CLAPTRAP SPECIFIC");
	ClapTrap	pyramidScheme("Pyramid Scheme");
	pyramidScheme.attack("people's wallet");
	std::cout << pyramidScheme << std::endl;
	pyramidScheme.takeDamage(9);
	std::cout << pyramidScheme << std::endl;
	pyramidScheme.beRepaired(1);
	std::cout << pyramidScheme << std::endl;
	pyramidScheme.takeDamage(2);
	std::cout << pyramidScheme << std::endl;
	pyramidScheme.beRepaired(2);
	pressEnter();

	titleHeader("CLAPTRAP COPY");
	ClapTrap	newScheme(pyramidScheme);
	newScheme.attack("people's wallet again");
	std::cout << newScheme << std::endl;
	pressEnter();

	titleHeader("CLAPTRAPS DESTUCTORS");
}
