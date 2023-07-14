/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:37:29 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 04:49:20 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

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
	titleHeader("SUBJECT TEST");
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a,b) << std::endl;
	pressEnter();

    Fixed c(3.14f);
    Fixed d(c);
	
	titleHeader("ARITHMETIC OPERATORS");
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed div = b / c;
	std::cout << "Valor de b: " << b << std::endl;
	std::cout << "Valor de c: " << c << std::endl;
	std::cout << "b + c: " << sum << std::endl;
	std::cout << "b - c: " << diff << std::endl;
	std::cout << "b * c: " << prod << std::endl;
	std::cout << "b / c: " << div << std::endl;
	pressEnter();
	
	titleHeader("COMPARISON OPERATORS");
	std::cout << "Valor de b: " << b << std::endl;
	std::cout << "Valor de c: " << c << std::endl;
    bool greater = b > c;
    bool less = b < c;
    bool greaterOrEqual = b >= c;
    bool lessOrEqual = b <= c;
    bool equal = b == c;
    bool notEqual = b != c;
	std::cout << "b > c: " << greater << std::endl;
	std::cout << "b < c: " << less << std::endl;
	std::cout << "b >= c: " << greaterOrEqual << std::endl;
	std::cout << "b <= c: " << lessOrEqual << std::endl;
	std::cout << "b == c: " << equal << std::endl;
	std::cout << "b != c: " << notEqual << std::endl;
	pressEnter();

	titleHeader("INCREMENT OPERATORS");
    Fixed e = a++;
    Fixed f = c--;
	std::cout << "Valor de a: " << a << std::endl;
	std::cout << "Valor de e: " << e << std::endl;
	std::cout << "Valor de c: " << c << std::endl;
	std::cout << "Valor de f: " << f << std::endl;
	pressEnter();

	titleHeader("MIN AND MAX");
    Fixed minResult = Fixed::min(a, b);
    Fixed maxResult = Fixed::max(a, b);
	std::cout << "Valor de a: " << a << std::endl;
	std::cout << "Valor de b: " << b << std::endl;
	std::cout << "Min: " << minResult << std::endl;
	std::cout << "Max: " << maxResult << std::endl;
	pressEnter();

	titleHeader("OVERLOADING OPERATORS");
    std::cout << "Valor de a: " << a << std::endl;
    std::cout << "Valor de b: " << b << std::endl;
    std::cout << "Valor de c: " << c << std::endl;
	pressEnter();

    return 0;
}
