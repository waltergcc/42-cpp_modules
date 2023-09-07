/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:25:59 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/05 11:38:58 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}
