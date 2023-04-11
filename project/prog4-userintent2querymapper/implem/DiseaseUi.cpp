/*
 * DiseaseUi.cpp
 *
 *  Created on: April 6, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string.h>
#include "DiseaseUi.h"

DiseaseUi::DiseaseUi() {

    // default variables for the base disease data
	i1 = "I have no information to answer this question.";
    i6 = "I have no information to answer this question.";
    i12 = "I have no infromation to answer this question.";

}

DiseaseUi::~DiseaseUi() {
	// Destructs constructor

}

// getters
string DiseaseUi::getI1() {
	return i1;
}
string DiseaseUi::getI6() {
	return i6;
}
string DiseaseUi::getI12() {
	return i12;
}

// setters
void DiseaseUi::setI1() {

    // create variables
    string questionWeb = "What Is Rabies?";
    string questionCDC = "What is rabies?";

    // Get answers
    string answerWeb = readWebMDFile(questionWeb);
    string answerCDC = readCDCFile(questionCDC);

    cout << answerWeb << endl;
    cout << answerCDC << endl;

    // Combine answers
    string answer = answerWeb + answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i1 = answer;

}
void DiseaseUi::setI12() {

    // create variables
    string questionWeb = "An Animal Bit Me. What Should I Do?";
    string questionCDC = "What can travelers do to prevent rabies?";

    // Get answers
    string answerWeb = readWebMDFile(questionWeb);
    string answerCDC = readCDCFile(questionCDC);

    // Combine answers
    string answer = answerWeb + answerCDC;

    // Check results and assign answer
    if(answer == "") {
        return;
    }
    i12 = answer;

}

// Get data from WebMD extracted data
string DiseaseUi::readWebMDFile(string question) {

    // Variables to read from webmd extracted file and store answer
    string in_file_name = "data/rabies-webmd-extracted.txt";
	string line;
    string answer = "";

    // Start reading and writing
    ifstream in_myfile(in_file_name);
	if (in_myfile.is_open()) {

        // Create a variable to activate when to print info
        int found = 0;
        int print = 0;

        // Look through each line for the question in WebMD file
        while (getline(in_myfile, line)) {

            // If find match then change found variable to start print
            if(line.find(question) != string::npos){// start print
                found = 1;
            }

            if(found == 1) {// print line
                if(line.find("*") != string::npos && line.find(question) == string::npos) {// stop print
                    found = 0;
                    break;
                }
                if(print > 0)// don't print header or the first line
                    answer = answer + line + "\n";
                print++;
            }

        }

        // Close input file
        in_myfile.close();

    } else {
		cout << "Unable to open input file - " << in_file_name << endl;
        exit;
    }

    return answer;

}

// Get data from WebMD extracted data
string DiseaseUi::readCDCFile(string question) {

    // Variables to read from cdc extracted file, and print question and answer
    string in_file_name = "data/rabies-cdc-extracted.txt";
	string line;
    string answer = "";

    // Start reading and writing
    ifstream in_myfile(in_file_name);
	if (in_myfile.is_open()) {

        // Print variable
        int found = 0;
        int print = 0;

        // Looking for question in CDC file
        while (getline(in_myfile, line)) {

            if(line.find(question) != string::npos){// start print
                found = 1;
            }

            if(found == 1) {// print line
                if(line.find("*") != string::npos && line.find(question) == string::npos) {// stop print
                    found = 0;
                    break;
                }
                if(print > 0)
                    answer = answer + line + "\n";
                print++;
            }

        }

        // Close input file
		in_myfile.close();
    } else {
		cout << "Unable to open input file - " << in_file_name << endl;
        exit;
    }

    return answer;

}

// Tag for both CDC and WebMD websites
string DiseaseUi::tag() {

    // Create variable for tag
    string WebMDTag = "\n\n***\"https://www.webmd.com/a-to-z-guides/what-is-rabies\" and \"https://wwwnc.cdc.gov/travel/diseases/rabies\"***\n\n";
    return WebMDTag;

}
