/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:16:10 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/14 04:02:33 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool isOverTheEdge(const Point p1, const Point p2, const Point p)
{
	Fixed slope((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
	Fixed intercept(p1.getY() - slope * p1.getX());

	return (p.getY() == slope * p.getX() + intercept);
}

float getTriangleArea(const Point p1, const Point p2, const Point p3)
{
	Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(first + second + third);

	return (std::abs(result.toFloat()) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	if (isOverTheEdge(a, b, point) || isOverTheEdge(b, c, point) || isOverTheEdge(c, a, point))
		return (false);

	float areaABC = getTriangleArea(a, b, c);
	float subABP = getTriangleArea(a, b, point);
	float subBCP = getTriangleArea(b, c, point);
	float subCAP = getTriangleArea(c, a, point);

	return (areaABC == subABP + subBCP + subCAP);
}
