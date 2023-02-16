/*
 * Recatangle.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
	/// @brief 
	double length;
	double width;
public:
	Rectangle();
	virtual ~Rectangle();

	double getLength();
	double getWidth();
	void setLength(double);
	void setWidth(double);
	void setArea(double, double);
	void setParameter(double, double);
	void setErrorMessage();
};

#endif /* RECTANGLE_H_ */