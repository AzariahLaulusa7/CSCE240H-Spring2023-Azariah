/*
 * DiseaseData.cpp
 *
 *  Created on: March 2, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string.h>
#include "DiseaseData.h"

DiseaseData::DiseaseData() {

    // default variables for the base disease data
	i1 = "I'm sorry. I have no available information at this moment.";
    i12 = "I'm sorry. I have no available information at this moment.";

}

DiseaseData::~DiseaseData() {
	// Destructs constructor

}

// getters
string DiseaseData::getI1() {
	return i1;
}
string DiseaseData::getI12() {
	return i12;
}

// setters
void DiseaseData::setI1(string data) {

    if(data.empty())
        return;
    i1 = data;

}
void DiseaseData::setI12(string data) {

    if(data.empty())
        return;
    i1 = data;

}

// Check file
bool DiseaseData::checkFile(string file) {

    // Exception handling with file
    ifstream myfile(file);

    try {
        cout << "\n\nAccessing header file...\n\n" << endl; 

        if (myfile.is_open()) {

            while (!myfile.eof())
                myfile.get();

		    myfile.close();
        }

    } catch(exception& e) {
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;
    }

    return true;
}

// Mix strings for values that have a mixed values
bool DiseaseData::mixParse() {

    // Exception handling with file
    string webmd = "data/rabies-webmd-extracted.txt";
    string cdc = "data/rabies-cdc-extracted.txt";
    ifstream webmdfile(webmd);
    ifstream cdcfile(cdc);
    string line;
    string webmdValue = "";
    string cdcValue = "";
    string vaccineWeb = "";
    string vaccineCdc = "";

    // Print variable
    int print = 0;

    try {

        if (webmdfile.is_open()) {

            while (getline(webmdfile, line)) {
                if(regex_match(line,regex("(.*)[wW]hat [iI]s [rR]abies?(.*)"))) {// find value for all parts
                    print = 1;
                } else if(regex_match(line,regex("(.*)[iI]f your doctor suspects(.*)"))) {
                    print = 2;
                }

                if(print == 1) {// print line
                    if(line.find("*") != string::npos && line.find("(.*)[wW]hat [iI]s [rR]abies?(.*)") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    webmdValue = webmdValue + line;
                } else if(print == 2) {// print line
                    if(line.find("*") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    vaccineWeb = vaccineWeb + line;
                }
            } // end-while

            // Close input file
            webmdfile.close();

        } else {
            cout << "\n\nThis file \"" << webmd << "\" can't be accessed. Please try again.\n\n"
                << endl;
            return false;
        }

        print = 0;// reset

        if (cdcfile.is_open()) {

            while (getline(cdcfile, line)) {
                if(regex_match(line,regex("(.*)[wW]hat [iI]s [rR]abies?(.*)"))) {// find value for all parts
                    print = 1;
                } else if(regex_match(line,regex("(.*)pre-travel rabies(.*)"))) {// find value for all parts
                    print = 2;
                }

                if(print == 1) {// print line
                    if(line.find("*") != string::npos && line.find("(.*)[wW]hat [iI]s [rR]abies?(.*)") == string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    cdcValue = cdcValue + line;
                } else if(print == 1) {// print line
                    if(line.find("*") != string::npos) {// stop print
                        print = 0;
                        continue;
                    }
                    vaccineCdc = vaccineCdc + line;
                }
            } // end-while

            // Close input file
            cdcfile.close();

        } else {
            cout << "\n\nThis file \"" << cdc << "\" can't be accessed. Please try again.\n\n"
                << endl;
            return false;
        }

        // combine strings
        i1 = cdcValue + webmdValue;
        i12 = vaccineCdc + vaccineWeb;

        // Success
        return true;

    } catch(exception& e) {// catch exception
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;
    }
}

// Print everything method
string DiseaseData::printEverything() {

    // String for CDC and WebMD
    string tempcdc = "";
    string tempweb = "";
    string everything = "";

    // Exception handling with file
    string webmd = "data/rabies-webmd-extracted.txt";
    string cdc = "data/rabies-cdc-extracted.txt";
    ifstream webmdfile(webmd);
    ifstream cdcfile(cdc);
    string line;

    // Print variable
    int print = 0;

    try {

        if (webmdfile.is_open()) {

            while (getline(webmdfile, line)) {
                if(regex_match(line,regex("(.*)[wW]hat [iI]s [rR]abies?(.*)"))) {// find value for all parts
                  continue;
                } else if(line.find("---") != string::npos) {
                    break;
                }
                tempweb = tempweb + line;
            } // end-while

            // Close input file
            webmdfile.close();

        } else {
            cout << "\n\nThis file \"" << webmd << "\" can't be accessed. Please try again.\n\n"
                << endl;
        }

        if (cdcfile.is_open()) {

            while (getline(cdcfile, line)) {
                if(regex_match(line,regex("(.*)[wW]hat [iI]s [rR]abies?(.*)"))) {// find value for all parts
                    continue;
                } else if(line.find("---") != string::npos) {
                    print = 0;
                    break;
                }
                tempcdc = tempcdc + line;
            } // end-while

            // Close input file
            cdcfile.close();

        } else {
            cout << "\n\nThis file \"" << cdc << "\" can't be accessed. Please try again.\n\n"
                << endl;
        }

        // combine strings
        everything = tempweb + tempcdc;

    } catch(exception& e) {
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
    }

    return everything;
}