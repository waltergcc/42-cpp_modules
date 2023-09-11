/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/11 15:07:05 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void printContent(T const &content)
{
	std::cout << content << std::endl;
}

template <typename T, typename F>
void iter(T *array, int size, F f)
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}
