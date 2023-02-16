/*
 * Shape.cpp
 *
 *  Created on: Feb 7, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <string.h>
#include "headers/Shape.h"

Shape::Shape() {

    // default variables for shape
	area = 0.0;
    parameter = 0.0;
    errorMessage = "\"Not enough information\"\n";

}

Shape::~Shape() {
	// TODO Auto-generated destructor stub

}

// get area
double Shape::getArea() {
	return area;
}

// get parameter
double Shape::getParameter() {
    return parameter;
}

// get error message
string Shape::getErrorMessage() {
    return errorMessage;
}

bool Shape::checkIfNumber(string number) {

    // Check if number
    bool numberCheck = true;
    int check = 0;

    for(int i=0; i<number.length(); i++){
        if(number.at(i) == '.') {
            continue;
        } else if(!isdigit(number.at(i))) {
            check++;
        }
    }

    // Warning message
    if(check != 0) {
        cout << "** ATTENTION **\n"
            << "This dimension \"" << number << "\" is not valid.\n"
            << "Please put valid dimensions. The dimensions should be "
            << "positive numbers with no spaces.\n"
            << "\nEx:\n\tCIRCLE <10>\n" << endl;
        numberCheck = false;
    }

    // Return results
    return numberCheck;

}

string Shape::parse(string line) {

    int begin = line.find("<");
    string temp = line.substr(begin + 1);
    int end = temp.find(">");
    string radius = temp.substr(0, end);
    return radius;
    
}