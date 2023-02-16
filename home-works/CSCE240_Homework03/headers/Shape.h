/*
 * Shape.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std;

class Shape {
protected:
	double area;
	double parameter;
	string errorMessage;

public:
	Shape();
	virtual ~Shape();

	double getArea();
	double getParameter();
	string getErrorMessage();
	bool checkIfNumber(string);
	string parse(string);
};

#endif /* SHAPE_H_ */