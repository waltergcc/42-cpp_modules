/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:42:37 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/13 16:46:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
			
	public:
		Fixed();
		Fixed(Fixed &copy);
		~Fixed();

		Fixed &operator=(Fixed &copy);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif