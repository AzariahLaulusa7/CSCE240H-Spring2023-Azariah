/*
 * Triangle.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {
protected:
	double firstSide;
	double secSide;
	double thirdSide;
public:
	Triangle();
	virtual ~Triangle();

	double getFirstSide();
	double getSecSide();
	double getThirdSide();
	void setFirstSide(double);
	void setSecSide(double);
	void setThirdSide(double);
	void setArea(double, double, double);
	void setParameter(double, double, double);
	void setErrorMessage();
};

#endif /* TRIANGLE_H_ */