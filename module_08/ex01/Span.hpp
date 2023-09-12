/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/11 23:58:37 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>

class Span
{
	private:
		unsigned int N;
		std::vector<int> storage;
		
	public:
		Span();
		Span(Span const &other);
		Span(unsigned int N);
		~Span();
		
		Span &operator=(Span const &other);

		unsigned int getN() const;
		std::vector<int> getStorage() const;

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void autoFill();		

		class FullStorageException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Span const &span);
