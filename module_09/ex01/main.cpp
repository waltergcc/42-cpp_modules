/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/10 22:44:11 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(USAGE);
		rpn(av[1]);
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}
