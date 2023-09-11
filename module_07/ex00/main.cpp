/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:23 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/09 00:44:02 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

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

int main(void)
{
	{
		titleHeader("SUBJECT TEST");
		
		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	pressEnter();
	{
		titleHeader("SAME TYPE TEST");

		std::string first = "first";
		std::string second = "second";

		std::cout << "===== before swap =====" << std::endl;
		std::cout << "first = " << first << std::endl;
		std::cout << "second = " << second << std::endl;
		std::cout << std::endl;

		::swap(first, second);

		std::cout << "===== after swap =====" << std::endl;
		std::cout << "first = " << first << std::endl;
		std::cout << "second = " << second << std::endl;
		std::cout << std::endl;

		float a = -987.6895659f;
		float b = -987.6545654f;

		std::cout << "float a = " << a << std::endl;
		std::cout << "float b = " << b << std::endl;
		std::cout << std::endl;
		
		std::cout << "who is min between a and b? ";
		std::cout << ::min(a, b) << std::endl;

		std::cout << "who is max between a and b? ";
		std::cout << ::max(a, b) << std::endl;
	}
	pressEnter();
	// {
	// 	titleHeader("DIFFERENT TYPE TEST");

	// 	std::string first = "first";
	// 	char second = 's';

	// 	std::cout << "===== before swap =====" << std::endl;
	// 	std::cout << "first = " << first << std::endl;
	// 	std::cout << "second = " << second << std::endl;
	// 	std::cout << std::endl;

	// 	::swap(first, second);
	// 	std::cout << "===== after swap =====" << std::endl;
	// 	std::cout << "first = " << first << std::endl;
	// 	std::cout << "second = " << second << std::endl;
	// 	std::cout << std::endl;

	// 	int a = 123;
	// 	float b = 123.456f;

	// 	std::cout << "int a = " << a << std::endl;
	// 	std::cout << "float b = " << b << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << "who is min between a and b? ";
	// 	std::cout << ::min(a, b) << std::endl;

	// 	std::cout << "who is max between a and b? ";
	// 	std::cout << ::max(a, b) << std::endl;
	// }
}
