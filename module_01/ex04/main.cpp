/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:52 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 14:47:09 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

void	checkArguments(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		exit(1);
	}
	std::string toFind = av[2];
	if (toFind.empty())
	{
		std::cout << "Invalid string. The find string can't be empty." << std::endl;
		exit(1);
	}
}

std::string	findAndReplaceInLine(std::string toFind, std::string toReplace, std::string line)
{
	size_t startPosition = 0;
	while (1)
	{
		startPosition = line.find(toFind, startPosition);
		if (startPosition == std::string::npos)
			break ;
		line.erase(startPosition, toFind.length());
		line.insert(startPosition, toReplace);
		startPosition += toReplace.length();
	}
	return (line);
}

int	main(int ac, char **av)
{
	checkArguments(ac, av);
	std::string newFile = av[1];
	std::string	toFind = av[2];
	std::string	toReplace = av[3];
	std::string line;
	
	newFile += ".replace";
	std::ifstream file(av[1]);
	std::ofstream replacefile(newFile.c_str());
	if (file.is_open() && replacefile.is_open())
	{
		if (toFind == toReplace)
			replacefile << file.rdbuf();
		while (std::getline(file, line))
		{
			line = findAndReplaceInLine(toFind, toReplace, line);
			replacefile << line << std::endl;
		}
		file.close();
		replacefile.close();
	}
	else
	{
		std::cout << "Error opening file." << std::endl;
		exit(1);
	}
}
