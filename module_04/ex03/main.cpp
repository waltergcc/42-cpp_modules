/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:38:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 23:46:07 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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

int main()
{
	titleHeader("SUBJECT TEST");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	pressEnter();

	titleHeader("LEARN MATERIAS");
	IMateriaSource	*newSrc = new MateriaSource();
	newSrc->learnMateria(new Ice());
	newSrc->learnMateria(new Cure());
	pressEnter();
	
	titleHeader("CREATE CHARACTERS");
	ICharacter	*mark = new Character("Mark S.");
	std::cout << mark->getName() << std::endl;
	ICharacter	*helly = new Character("Helly G.");
	std::cout << helly->getName() << std::endl;
	pressEnter();

	titleHeader("CREATE AND EQUIP MATERIAS");
	AMateria	*buffer;
	for (int i = 0; i < 5; i++)
	{
		if (i > 0)
			std::cout << std::endl;
		std::cout << "Materia #" << i + 1 << ": ";
		if (i % 2 == 0)
			buffer = newSrc->createMateria("cure");
		else
			buffer = newSrc->createMateria("ice");
		mark->equip(buffer);
	}
	pressEnter();
	
	titleHeader("USE MATERIAS");
	for (int i = 0; i < 5; i++)
		mark->use(i, *helly);
	pressEnter();

	titleHeader("UNEQUIP MATERIAS");
	for (int i = 0; i < 6; i++)
		mark->unequip(i);
	pressEnter();
	
	titleHeader("DELETE MARK OBJECTS");
	delete mark;
	pressEnter();

	titleHeader("DELETE HELLY OBJECT");
	delete helly;
	pressEnter();

	titleHeader("DELETE NEW SRC OBJECT");
	delete newSrc;
	pressEnter();

	titleHeader("DEEP COPY TEST");
	IMateriaSource	*copySrc = new MateriaSource();
	copySrc->learnMateria(new Ice());
	copySrc->learnMateria(new Cure());

	Ice	*basic = new Ice();
	Ice *temp = new Ice(*basic);
	
	std::cout << std::endl << "temp : " << temp << " | type: " << temp->getType() << std::endl;
	delete	temp;
	
	std::cout << std::endl << "basic: " << basic << " | type: " << basic->getType() << std::endl;
	delete	basic;
	
	std::cout << std::endl;
	delete	copySrc;
	pressEnter();
}
