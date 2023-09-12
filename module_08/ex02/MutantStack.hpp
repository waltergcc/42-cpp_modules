/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:26:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/10 00:10:33 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack()
		{
			std::cout << "create MutantStack" << std::endl;
		}
		
		MutantStack(MutantStack const &other)
		{
			std::cout << "create copy MutantStack from other" << std::endl;
			*this = other;
		}
		
		~MutantStack()
		{
			std::cout << "destroy MutantStack" << std::endl;
		}

		MutantStack &operator=(MutantStack const &other)
		{
			std::cout << "assign MutantStack to other" << std::endl;
			std::stack<T, Container>::operator=(this, other);
			return (*this);
		}

		typedef typename Container::iterator iterator;
		
		iterator begin(void){return (this->c.begin());}
		iterator end(void){return (this->c.end());}
};
