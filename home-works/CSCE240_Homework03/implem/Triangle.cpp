/*
 * Triangle.cpp
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <cmath>
#include <string.h>
#include "headers/Triangle.h"

Triangle::Triangle() {
	// TODO Auto-generated constructor stub
    firstSide = 0.0;
    secSide = 0.0; 
    thirdSide = 0.0;

}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub

}

double Triangle::getFirstSide() {
	return firstSide;
}

double Triangle::getSecSide() {
	return secSide;
}

double Triangle::getThirdSide() {
	return thirdSide;
}


void Triangle::setFirstSide(double s1) {

	firstSide = s1;

}

void Triangle::setSecSide(double s2) {

	secSide = s2;

}

void Triangle::setThirdSide(double s3) {

	thirdSide = s3;

}

void Triangle::setArea(double s1, double s2, double s3) {

	cout << "\nCalculating Area..." << endl;
	double semi = (s1 + s2 + s3)/2;
	area = sqrt(semi*(semi-s1)*(semi-s2)*(semi-s3));
	cout << "Writing Area...\n" << endl;
	cout << "TRIANGLE AREA <" << area << ">\n" << endl;

}

void Triangle::setParameter(double s1, double s2, double s3) {

	cout << "\nCalculating Parameter...\n" << endl;
	parameter = s1 + s2 + s3;
	cout << "\nWriting Parameter...\n" << endl;
	cout << "TRIANGLE PARAMETER <" << parameter << ">\n" << endl;

}

void Triangle::setErrorMessage() {

	errorMessage = "TRIANGLE \"Not Enough Information\"";

}