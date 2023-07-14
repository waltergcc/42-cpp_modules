/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:03:21 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/13 22:46:45 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		// Constructors
		Point();
		Point(float const x, float const y);
		Point(Point const &copy);
		~Point();

		// Overload operators
		Point 	&operator=(Point const &copy);
		bool	operator==(Point const &copy) const;
		
		// Get / Set
		Fixed	getX() const;
		Fixed	getY() const;
		
};

bool	bsp(Point a, Point b, Point c, Point point);

#endif
