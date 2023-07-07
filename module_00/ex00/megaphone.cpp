/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:11:37 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/07 17:56:47 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>

void megaphone(char *s)
{
	while (*s)
		std::cout << (char)toupper(*(s++));
}

int main(int ac, char **av)
{
	if (ac > 1)
		while (*(++av))
			megaphone(*av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}