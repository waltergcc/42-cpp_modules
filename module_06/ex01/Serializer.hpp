/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/05 11:54:04 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
	std::string name;
	size_t 		age;
	Data 		*next;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer();
	
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
