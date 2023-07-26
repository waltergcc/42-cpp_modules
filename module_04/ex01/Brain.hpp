/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:47:38 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:13:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>

class Brain
{
	private:
		std::string ideas[100];

	public:
		// Constructors
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);
		
		// Operators
		Brain &operator=(Brain const &src);
		
		// Member functions
		void	showIdeas(void) const;
};

#endif
