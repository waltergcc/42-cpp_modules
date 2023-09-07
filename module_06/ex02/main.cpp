/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:13 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/05 09:28:24 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base * generate(void)
{
	switch(std::rand() % 3)
	{
		case 0:
			std::cout << "create new A instance" << std::endl;
			return (new A());
		case 1:
			std::cout << "create new B instance" << std::endl;
			return (new B());
		case 2:
			std::cout << "create new C instance" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << "unknown" << std::endl;
	}
}

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

int	main()
{
	{
		titleHeader("INDENTIFY FROM POINTER");
		Base *base;

		for (int i = 0; i < 5; i++)
		{
			base = generate();
			
			std::cout << "Base address: " << base << std::endl;
			std::cout << "Base type   : ";
			
			identify(base);
			
			std::cout << std::endl;
			delete base;
		}
	}
	pressEnter();
	{
		titleHeader("INDENTIFY FROM REFERENCE");
		Base *base;
		
		for (int i = 0; i < 5; i++)
		{
			base = generate();
			
			std::cout << "Base address: " << base << std::endl;
			std::cout << "Base type   : ";
			
			identify(*base);
			
			std::cout << std::endl;
			delete base;
		}
	}
	pressEnter();
	{
		titleHeader("UNKNOWN TYPE");

		Base *emptyPointer = NULL;
		Base emptyClass;

		std::cout << "emptyPointer address: " << emptyPointer << std::endl;
		std::cout << "Base type           : ";
		identify(emptyPointer);

		std::cout << std::endl;
		std::cout << "emptyClass address  : " << &emptyClass << std::endl;
		std::cout << "Base type           : ";
		identify(emptyClass);		
	}
	pressEnter();
}
