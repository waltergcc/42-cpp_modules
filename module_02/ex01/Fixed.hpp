/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:42:37 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 15:09:43 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		// Variables
		int					_value;
		static const int	_bits = 8;
			
	public:
		// Constructors
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		
		// Overload
		Fixed &operator=(Fixed const &copy);
		
		// Getters and Setters
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		// Member functions
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif
