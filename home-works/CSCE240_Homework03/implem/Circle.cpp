/*
 * Rectangle.cpp
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <cmath>
#include <string.h>
#include "headers/Circle.h"

Circle::Circle() {
	// default radius value
	radius = 0.0;

}

Circle::~Circle() {
	// destructor

}

// get radius
double Circle::getRadius() {
	return radius;
}

// set radius
void Circle::setRadius(double rad) {
	radius = rad;
}

// set area based on radius
void Circle::setArea(double rad) {

	cout << "\nCalculating Area...\n" << endl;
	area = M_PI * (rad*rad);
	cout << "\nWriting Area...\n" << endl;
	cout << "CIRCLE AREA <" << area << ">\n" << endl;

}

// set parameter value based on radius
void Circle::setParameter(double rad) {

	cout << "\nCalculating Parameter...\n" << endl;
	parameter = 2 * M_PI * rad;
	cout << "\nWriting Parameter...\n" << endl;
	cout << "CIRCLE PARAMETER <" << parameter << ">\n" << endl;

}

// new error message for circle
void Circle::setErrorMessage() {

	errorMessage = "CIRCLE \"Not Enough Information\"\n";

}