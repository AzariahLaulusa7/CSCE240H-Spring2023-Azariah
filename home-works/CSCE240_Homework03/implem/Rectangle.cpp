/*
 * Rectangle.cpp
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <string.h>
#include <cmath>
#include "headers/Rectangle.h"

// default
Rectangle::Rectangle() {
	// default values
    length = 0.0;
    width = 0.0; 

}

// deconstructor
Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub

}

// return length
double Rectangle::getLength() {
	return length;
}

// return width
double Rectangle::getWidth() {
	return width;
}

// set width
void Rectangle::setWidth(double wid) {

	// Set width
	width = wid;

}

// set length
void Rectangle::setLength(double leng) {

	// Set length
	length = leng;
}

// set area using width and length
void Rectangle::setArea(double length, double width) {

	// Set area
	 cout << "\nCalculating Area..." << endl;
		area = length * width;
		cout << "Writing Area...\n" << endl;
		cout << "RECTANGLE AREA <" << area << ">\n" << endl;

}

// find parameter using length and width
void Rectangle::setParameter(double length, double width) {

	// Set parameter
	cout << "\nCalculating Parameter...\n" << endl;
		double parameter = (2 * length) + (2 * width);
		cout << "\nWriting Parameter...\n" << endl;
		cout << "RECTANGLE PARAMETER <" << parameter << ">\n" << endl;
}

// create new error message for rectangle
void Rectangle::setErrorMessage() {

	errorMessage = "Rectangle \"Not Enough Information\"";

}