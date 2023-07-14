/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:46:57 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 04:45:49 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------------------------------ CONSTRUCTORS --------------------------------

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(int const value)
{
	this->_value = value * (1 << Fixed::_bits);
}

Fixed::Fixed(float const value)
{
	this->_value = roundf(value * (1 << Fixed::_bits));
}

Fixed::~Fixed(){}

// --------------------------- ARITHMETIC OPERATORS ---------------------------

Fixed &Fixed::operator=(Fixed const &copy)
{
	if (this == &copy)
		return (*this);
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	return (Fixed(this->toFloat() / copy.toFloat()));
}

// --------------------------- COMPARISON OPERATORS ---------------------------

bool Fixed::operator>(Fixed const &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator<(Fixed const &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool Fixed::operator>=(Fixed const &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator<=(Fixed const &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator==(Fixed const &copy) const
{
	return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator!=(Fixed const &copy) const
{
	return (this->getRawBits() != copy.getRawBits());
}

// ---------------------------- INCREMENT OPERATORS ---------------------------

Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int tmp)
{
	(void)tmp;
	Fixed duplicate(*this);
	++(*this);
	return (duplicate);
}

Fixed Fixed::operator--(int tmp)
{
	(void)tmp;
	Fixed duplicate(*this);
	--(*this);
	return (duplicate);
}

// ---------------------------- MIN / MAX FUNCTIONS ---------------------------

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

// ------------------------------ SET / GET -----------------------------------

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// ---------------------------- CONVERT FUNCTIONS -----------------------------

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << Fixed::_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << Fixed::_bits));
}

// ---------------------------- AUX FUNCTIONS ---------------------------------

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}
