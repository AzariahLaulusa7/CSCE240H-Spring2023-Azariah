/*
 * CDCUi.cpp
 *
 *  Created on: March 2, 2023
 *      Author: Azariah Laulusa
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <regex>
#include "CDCUi.h"

CDCUi::CDCUi() {

    // default variables for the CDC data
    i2 = "I have no available information for this question.";
	i3 = "I have no available information for this question.";
    i4 = "I have no available information for this question.";
    i5 = "I have no available information for this question.";
}

CDCUi::~CDCUi() {
	// TODO Auto-generated destructor stub

}

// getters
string CDCUi::getI2() {
    return i2;
}
string CDCUi::getI3() {
	return i3;
}
string CDCUi::getI4() {
    return i4;
}
string CDCUi::getI5() {
    return i5;
}

// setters
void CDCUi::setI2() {

    // create variables
    string questionCDC = "Who is at risk?";

    // Get answers
    string answerCDC = readCDCFile(questionCDC);
    string answer = answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i2 = answer;

}
void CDCUi::setI3() {

    // create variables
    string questionCDC = "What can travelers do to prevent rabies?";

    // Get answers
    string answerCDC = readCDCFile(questionCDC);
    string answer = answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i3 = answer;

}
void CDCUi::setI4() {

    // create variables
    string questionCDC = "After Travel";

    // Get answers
    string answerCDC = readCDCFile(questionCDC);
    string answer = answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i4 = answer;

}
void CDCUi::setI5() {

    // create variables
    string questionCDC = "Clinician Information";

    // Get answers
    string answerCDC = readCDCFile(questionCDC);
    string answer = answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i5 = answer;

}

// Send CDC tag
string CDCUi::tagCDC() {

    // Create variable for tag
    string CDCTag = "\n\n***\"https://wwwnc.cdc.gov/travel/diseases/rabies\"***\n\n";
    return CDCTag;

}