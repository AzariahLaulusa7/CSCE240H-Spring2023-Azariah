/*
 * WebmdData.cpp
 *
 *  Created on: March 2, 2023
 *      Author: Azariah Laulusa
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <regex>
#include "CDCData.h"

CDCData::CDCData() {

    // default variables for the CDC data
    i2 = "I'm sorry. I have no available information at this moment.";
	i3 = "I'm sorry. I have no available information at this moment.";
    i4 = "I'm sorry. I have no available information at this moment.";
    i5 = "I'm sorry. I have no available information at this moment.";
}

CDCData::~CDCData() {
	// TODO Auto-generated destructor stub

}

// getters

string CDCData::getI2() {
    return i2;
}
string CDCData::getI3() {
	return i3;
}
string CDCData::getI4() {
    return i4;
}
string CDCData::getI5() {
    return i5;
}

// setters
void CDCData::setI2(string data) {

    if(data.empty())
        return;
    i2 = data;

}
void CDCData::setI3(string data) {

    if(data.empty())
        return;
    i3 = data;

}
void CDCData::setI4(string data) {

    if(data.empty())
        return;
    i4 = data;

}
void CDCData::setI5(string data) {

    if(data.empty())
        return;
    i5 = data;

}

// Parsing CDC file to get values
bool CDCData::cdcParse(string file) {

    // Reading given file and parsing all standard and unique parts
	string line;
    ifstream in_myfile(file);

    // Variables that will be combined
    string one = "";
    string two = "";
    string three = "";
    string travel = "";
    string clinical = "";

    // Print variables to indicate when to print the lines following
    int print = 0;


    // Try and catch exception handling
    try {
        if (in_myfile.is_open()) {

            while (getline(in_myfile, line)) {
                if(regex_match(line,regex("(.*)[wW][hH][oO] [iI][sS] [aA][tT] [rR][iI][sS][kK]?(.*)"))) {// find value for all parts
                    print == 1;
                } else if(regex_match(line,regex("(.*)[wW][hH][aA][tT] [cC][aA][nN] [tT][rR][aA][vV][eE][lL][eE][rR][sS] [dD][oO] [tT][oO] [pP][rR][eE][vV][eE][nN][tT] [rR][aA][bB][iI][eE][sS]?(.*)"))) {
                    print == 2;
                } else if(regex_match(line,regex("(.*)[aA][fF][tT][eE][rR] [tT][rR][aA][vV][eE][lL](.*)"))) {
                    print == 3;
                } else if(regex_match(line,regex("(.*)[tT][rR][aA][vV][eE][lL][eE][rR] [iI][nN][fF][oO][rR][mM][aA][tT][iI][oO][nN](.*)"))) {
                    print == 4;
                } else if(regex_match(line,regex("(.*)[cC][lL][iI][nN][iI][cC][iI][aA][nN] [Ii][nN][fF][oO][rR][mM][aA][tT][iI][oO][nN](.*)"))) {
                    print == 5;
                }

                // if statements for print
                if(print == 1) {// who is at risk
                    if(line.find("*") != string::npos && line.find("Who is at risk?") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    one = one + line;
                } else if(print == 2) {// what can travelers do
                    if(line.find("*") != string::npos && line.find("What can travelers") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    two = two + line;
                } else if(print == 3) {// after travel
                    if(line.find("*") != string::npos && line.find("After Travel") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    three = three + line;
                } else if(print == 4) {// more information
                    if(line.find("*") != string::npos && line.find("Traveler Information") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    travel = travel + line;
                } else if(print == 5) {// more information
                    if(line.find("-") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    clinical = clinical + line;
                }


            } // end-while

            // Assign values to questions
            i2 = one;
            i3 = two;
            i4 = three;

            // Combine strings to get more information
            i5 = travel + clinical;

            // Close input file
            in_myfile.close();

            // Success
            return true;

        } else {
            cout << "Seems like \"" << file << "\" does not exist.\n" 
                << "Please enter an existing email header file.\n\n" << endl;
            return false;// fail
        }
    } catch(exception& e) {// catch exception
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;// fail
    }

}