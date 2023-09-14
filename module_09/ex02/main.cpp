/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:27:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/11 01:51:47 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::list<int>	list;
	std::deque<int>	deque;
	double			listTime;
	double			dequeTime;
	
	try
	{
		if (!isValidInput(av) || ac == 1)
			throw std::runtime_error(ERROR);
		++av;
		printBefore(av);
		sortList(list, av, listTime);
		sortDeque(deque, av, dequeTime);
		printListAfter(list);
		// printDequeAfter(deque);
		std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << listTime << " miliseconds" << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeTime << " miliseconds" << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}
