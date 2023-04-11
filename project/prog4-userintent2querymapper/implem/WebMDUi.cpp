/*
 * WebMDUi.cpp
 *
 *  Created on: April 6, 2023
 *      Author: Azariah Laulusa
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <regex>
#include "WebMDUi.h"

WebMDUi::WebMDUi() {

    // default variables for the CDC data
    i7 = "I have no available information for this question.";
	i8 = "I have no available information for this question.";
    i9 = "I have no available information for this question.";
    i10 = "I have no available information for this question.";
    i11 = "I have no available information for this question.";
}

WebMDUi::~WebMDUi() {
	// TODO Auto-generated destructor stub

}

// getters
string WebMDUi::getI7() {
    return i7;
}
string WebMDUi::getI8() {
	return i8;
}
string WebMDUi::getI9() {
	return i9;
}
string WebMDUi::getI10() {
    return i10;
}
string WebMDUi::getI11() {
    return i11;
}

// setters
void WebMDUi::setI7() {

    // create variables
    string questionWebMD = "What Are the Symptoms?";

    // Get answers
    string answerWebMD = readWebMDFile(questionWebMD);
    string answer = answerWebMD;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i7 = answer;

}
void WebMDUi::setI8() {

    // create variables
    string questionWebMD = "An Animal Bit Me. What Should I Do?";

    // Get answers
    string answerWebMd = readWebMDFile(questionWebMD);
    string answer = answerWebMd;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i8 = answer;

}
void WebMDUi::setI9() {

    // create variables
    string questionWebMD = "What Are the Symptoms?";

    // Get answers
    string answerWebMD = readWebMDFile(questionWebMD);
    string answer = answerWebMD;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i9 = answer;

}
void WebMDUi::setI10() {

    // create variables
    string questionWebMD = "If your doctor suspects rabies";

    // Get answers
    string answerWebMD = readWebMDFile(questionWebMD);
    string answer = answerWebMD;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i10 = answer;

}
void WebMDUi::setI11() {

    // create variables
    string questionWebMD = "As the virus spreads through your central";

    // Get answers
    string answerWebMD = readWebMDFile(questionWebMD);
    string answer = answerWebMD;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i11 = answer;

}

// Send WebMD tag
string WebMDUi::tagWebMD() {

    // Create variable for tag
    string WebMDTag = "\n\n***\"https://www.webmd.com/a-to-z-guides/what-is-rabies\"***\n\n";
    return WebMDTag;

}