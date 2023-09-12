/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:23 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/12 00:45:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void debugMessageConstructors(int newline)
{
	std::cout << std::endl;
	std::cout << BLUE << "constructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageStatus(int newline)
{
	std::cout << std::endl;
	std::cout << PURPLE << "status> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageDestructors(int newline)
{
	std::cout << std::endl;
	std::cout << YELLOW << "destructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageAction(std::string action)
{
	std::cout << std::endl;
	std::cout << GREEN << "action> " << RESET;
	if (action.length())
		std::cout << action << std::endl;
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
	std::cout << "*" << std::endl << "************************************" << std::endl;
}

int main(int, char**)
{
	{
		titleHeader("MUTANT STACK TEST");
		
		debugMessageConstructors(WITHOUT_NEWLINE);
		MutantStack<int> mstack;
		
		debugMessageAction("insert 5, 17, 589 on stack");
		mstack.push(5);
		mstack.push(17);
		mstack.push(589);
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Top value: " << mstack.top() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Stack size: " << mstack.size() << std::endl;
		
		debugMessageAction("remove top value");
		mstack.pop();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Top value: " << mstack.top() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "Stack size: " << mstack.size() << std::endl;
		
		debugMessageAction("insert value 3, 5, 737 and 0 on stack");
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		debugMessageAction("print all values on stack using iterator");
		std::cout << "\t";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout << std::endl;

		debugMessageAction("copy the Mutant Stack to another common stack");
		std::stack<int> s(mstack);

		debugMessageAction("delete all values on stack");
		MutantStack<int>::iterator itEnd;
		while (!mstack.empty())
		{
			itEnd = mstack.end();
			--itEnd;
			std::cout << "\t" << "... deleting " << *itEnd << " from stack" << std::endl;
			mstack.pop();			
		}
		
		debugMessageDestructors(WITHOUT_NEWLINE);
	}
	pressEnter();
	{
		titleHeader("SAME TEST BUT WITH LIST");

		std::list<int> list;
		
		debugMessageAction("insert 5, 17, 589 on list");
		list.push_back(5);
		list.push_back(17);
		list.push_back(589);
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List top value: " << list.back() << std::endl;

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List size: " << list.size() << std::endl;

		debugMessageAction("remove top value");
		list.pop_back();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List top value: " << list.back() << std::endl;
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "List size: " << list.size() << std::endl;

		debugMessageAction("insert value 3, 5, 737 and 0 on list");
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		
		++it;
		--it;
		debugMessageAction("print all values on list using iterator");
		std::cout << "\t";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout << std::endl;

		debugMessageAction("copy the list to another list");
		std::list<int> s(list);

		debugMessageAction("delete all values on list");
		std::list<int>::iterator itEnd;
		while (!list.empty())
		{
			itEnd = list.end();
			--itEnd;
			std::cout << "\t" << "... deleting " << *itEnd << " from list" << std::endl;
			list.pop_back();			
		}
	}
	pressEnter();
}
