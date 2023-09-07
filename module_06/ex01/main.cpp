/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:23 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/05 11:58:34 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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

int	main()
{
	titleHeader("CREATE DATA STRUCTS");
	Data player1;
	Data player2;
	Data player3;

	player1.name = "Mohamed Salah";
	player1.age = 31;
	player1.next = &player2;

	player2.name = "Alisson Becker";
	player2.age = 30;
	player2.next = &player3;

	player3.name = "Virgil van Dijk";
	player3.age = 30;
	player3.next = NULL;

	std::cout << "===== player 1 =====" << std::endl << std::endl;
	std::cout << "address: " << &player1 << std::endl;
	std::cout << "name   : " << player1.name << std::endl;
	std::cout << "age    : " << player1.age << std::endl;
	std::cout << "next   : " << player1.next << std::endl << std::endl;

	std::cout << "===== player 2 =====" << std::endl << std::endl;
	std::cout << "address: " << &player2 << std::endl;
	std::cout << "name   : " << player2.name << std::endl;
	std::cout << "age    : " << player2.age << std::endl;
	std::cout << "next   : " << player2.next << std::endl << std::endl;

	std::cout << "===== player 3 =====" << std::endl << std::endl;
	std::cout << "address: " << &player3 << std::endl;
	std::cout << "name   : " << player3.name << std::endl;
	std::cout << "age    : " << player3.age << std::endl;
	std::cout << "next   : " << player3.next << std::endl;

	pressEnter();

	titleHeader("SERIALIZE PLAYER 1");
	uintptr_t serializedPlayer1 = Serializer::serialize(&player1);

	std::cout << "===== player 1 =====" << std::endl << std::endl;

	std::cout << "Original address  : " << &player1 << std::endl;
	std::cout << "serialized address: " << serializedPlayer1 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player1.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer1)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.name == Serializer::deserialize(serializedPlayer1)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player1.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer1)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.age == Serializer::deserialize(serializedPlayer1)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player1.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer1)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player1.next == Serializer::deserialize(serializedPlayer1)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;

	pressEnter();

	titleHeader("SERIALIZE PLAYER 2");

	uintptr_t serializedPlayer2 = Serializer::serialize(&player2);

	std::cout << "===== player 2 =====" << std::endl << std::endl;

	std::cout << "Original address  : " << &player2 << std::endl;
	std::cout << "serialized address: " << serializedPlayer2 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player2.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer2)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.name == Serializer::deserialize(serializedPlayer2)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player2.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer2)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.age == Serializer::deserialize(serializedPlayer2)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player2.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer2)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player2.next == Serializer::deserialize(serializedPlayer2)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	
	pressEnter();

	titleHeader("SERIALIZE PLAYER 3");

	uintptr_t serializedPlayer3 = Serializer::serialize(&player3);

	std::cout << "===== player 3 =====" << std::endl << std::endl;

	std::cout << "Original address  : " << &player3 << std::endl;
	std::cout << "serialized address: " << serializedPlayer3 << std::endl;
	std::cout << std::endl;

	std::cout << "Original name   : " << player3.name << std::endl;
	std::cout << "Deserialize name: " << Serializer::deserialize(serializedPlayer3)->name << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.name == Serializer::deserialize(serializedPlayer3)->name)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original age   : " << player3.age << std::endl;
	std::cout << "Deserialize age: " << Serializer::deserialize(serializedPlayer3)->age << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.age == Serializer::deserialize(serializedPlayer3)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << std::endl;

	std::cout << "Original next   : " << player3.next << std::endl;
	std::cout << "Deserialize next: " << Serializer::deserialize(serializedPlayer3)->next << std::endl;
	std::cout << "The original and deserialized are equal?";
	if (player3.next == Serializer::deserialize(serializedPlayer3)->next)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;

	pressEnter();
}
