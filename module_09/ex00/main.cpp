/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/10 22:50:40 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(ERR_OPEN);
		std::vector<btcPrice> database = getDatabase();
		readInput(database, av[1]);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return (EXIT_FAILURE);
	}
}
