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
#include "WebmdData.h"

WebmdData::WebmdData() {

    // default variables for the WebMD data
	i7 = "I'm sorry. I have no available information at this moment.";
    i8 = "I'm sorry. I have no available information at this moment.";
    i9 = "I'm sorry. I have no available information at this moment.";
    i10 = "I'm sorry. I have no available information at this moment.";
    i11 = "I'm sorry. I have no available information at this moment.";

}

WebmdData::~WebmdData() {
	// Destructs constructor

}

// getters
string WebmdData::getI7() {
	return i7;
}
string WebmdData::getI8() {
    return i8;
}
string WebmdData::getI9() {
    return i9;
}
string WebmdData::getI10() {
    return i10;
}
string WebmdData::getI11() {
    return i11;
}

// setters
void WebmdData::setI7(string data) {

    if(data.empty())
        return;
    i7 = data;

}
void WebmdData::setI8(string data) {

    if(data.empty())
        return;
    i8 = data;

}
void WebmdData::setI9(string data) {

    if(data.empty())
        return;
    i9 = data;

}
void WebmdData::setI10(string data) {

    if(data.empty())
        return;
    i10 = data;

}
void WebmdData::setI11(string data) {

    if(data.empty())
        return;
    i11 = data;

}

// Parsing WebMD file for values
bool WebmdData::webmdParse(string file) {

    // Reading given file and parsing all standard and unique parts
	string line;
    ifstream in_myfile(file);

    // String variables used to collect all lines for values
    string symp = "";
    string diagnosis = "";
    string doctor = "Only consider contacting a doctor rabies, if an animal bit you. ";
    string treatment = "";
    string complications = "";

    // print markers
    int print = 0;

	// Try and catch exception handling
    try {
        if (in_myfile.is_open()) {

            while (getline(in_myfile, line)) {
                if(regex_match(line,regex("(.*)[Ww]hat [Aa]re [Tt]he [Ss]ymptoms?(.*)"))) {// find value for all parts
                    print = 1;
                } else if(regex_match(line,regex("(.*)[wW]ash the wound(.*)"))) {
                    print = 2;
                } else if(regex_match(line,regex("(.*)[Hh]ow [Ii]s [Ii]t [Ss]pread?(.*)"))) {
                    print = 3;
                } else if(regex_match(line,regex("(.*)[Ii]f your doctor suspects rabies(.*)"))) {
                    print = 4;
                } else if(regex_match(line,regex("(.*)[Aa]s the virus spreads(.*)"))) {
                    print = 5;
                }

                // if statements for print
                if(print == 1) {// symptoms
                    if(line.find("severe") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    symp = symp + line;
                } else if(print == 2) {// when to call doctor
                    if(line.find("begin treatment") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    treatment = treatment + line;
                } else if(print == 3) {// diagnosis
                    if(line.find("*") != string::npos && line.find("How Is It Spread?") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    diagnosis = diagnosis + line;
                } else if(print == 4) {// treatment
                    if(line.find("*") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    treatment = treatment + line;
                } else if(print == 5) {// complications
                    if(line.find("*") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    complications = complications + line;
                }

            } // end-while

            // Assign values
            i7 = symp;
            i8 = doctor;
            i9 = diagnosis;
            i10 = treatment;
            i11 = complications;

            // Close input file
            in_myfile.close();

            // Success
            return true;

        } else {
            cout << "Seems like \"" << file << "\" does not exist.\n" 
                << "Please enter an existing email header file.\n\n" << endl;
            return false;// fail
        }
    } catch(exception& e) {
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;// fail
    }

}