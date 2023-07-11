/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:52 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/11 18:29:01 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void	mainHeader(void)
{
	std::cout << "\033c";
	std::cout << "**********************************" << std::endl;
	std::cout << "*            HARL 2.0            *" << std::endl;
	std::cout << "**********************************" << std::endl << std::endl;
	std::cout << "We will pass by the program trought levels" << std::endl;
}

int	main(void)
{
	Harl harl;

	mainHeader();
	pressEnter();
	
	std::cout << "***** level DEBUG *****" << std::endl << std::endl;
	harl.complain("DEBUG");
	pressEnter();

	std::cout << "***** level INFO *****" << std::endl << std::endl;
	harl.complain("INFO");
	pressEnter();

	std::cout << "***** level WARNING *****" << std::endl << std::endl;
	harl.complain("WARNING");
	pressEnter();

	std::cout << "***** level ERROR *****" << std::endl << std::endl;
	harl.complain("ERROR");
	pressEnter();
}