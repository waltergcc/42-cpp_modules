/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:03:30 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/13 22:57:20 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point &Point::operator=(Point const &copy)
{
	if (this == &copy)
		return (*this);
	(Fixed)this->_x = copy._x;
	(Fixed)this->_y = copy._y;
	return (*this);
}

bool Point::operator==(Point const &copy) const
{
	return (this->_x == copy._x && this->_y == copy._y);
}

Fixed Point::getX() const
{
	return (Fixed(this->_x));
}

Fixed Point::getY() const
{
	return (Fixed(this->_y));
}