/*
 * Circle.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle: public Shape {
protected:
	double radius;
public:
	Circle();
	virtual ~Circle();

	double getRadius();

	void setRadius(double);
	void setArea(double);
	void setParameter(double);
	void setErrorMessage();
};

#endif /* CIRCLE_H_ */