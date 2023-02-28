/*
 * GmailHeaderType.cpp
 *
 *  Created on: Feb 24, 2023
 *      Author: Azariah Laulusa
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <regex>
#include "GmailHeaderType.h"

GmailHeaderType::GmailHeaderType() {

    // default variables for base email header type
	deliveredTo = "N/A";
    xGoogleSmtpSource = "N/A";

}

GmailHeaderType::~GmailHeaderType() {
	// TODO Auto-generated destructor stub

}

// getters
string GmailHeaderType::getDeliveredTo() {
	return deliveredTo;
}
string GmailHeaderType::getXGoogleSmtpSource() {
    return xGoogleSmtpSource;
}

// setters
void GmailHeaderType::setDeliveredTo(string type) {

    if(type.empty())
        return;
    deliveredTo = type;

}
void GmailHeaderType::setXGoogleSmtpSource(string type) {

    if(type.empty())
        return;
    xGoogleSmtpSource = type;

}

bool GmailHeaderType::parseFile(string file) {

    // Reading given file and parsing all standard and unique parts
	string line;

	ifstream in_myfile(file);
    try {
        if (in_myfile.is_open()) {

            while (getline(in_myfile, line)) {
                if(regex_match(line,regex("(.*)[fF][rR][oO][mM]:(.*)"))) {// find value for all parts
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    from = value;
                } else if(regex_match(line,regex("(.*)[tT][oO]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    to = value;
                } else if(regex_match(line,regex("(.*)[Dd][aA][tT][eE]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    date = value;
                } else if(regex_match(line,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][yY][pP][eE]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    contentType = value;
                } else if(regex_match(line,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][rR][aA][nN][sS][fF][eE][rR][- ]?[eE][nN][cC][oO][dD][iI][nN][gG](.*):"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    contentTransferEncoding = value;
                } else if(regex_match(line,regex("(.*)[mM][eE][sS][sS][aA][gG][eE][- ]?[iI][dD]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    messageId = value;
                } else if(regex_match(line,regex("(.*)[cC][cC]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    cc = value;
                } else if(regex_match(line,regex("(.*)[rR][eE][cC][eE][iI][vV][eE][dD]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    received = value;
                } else if(regex_match(line,regex("(.*)[sS][uU][bB][jJ][eE][cC][tT]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    subject = value;
                } else if(regex_match(line,regex("(.*)[rR][eE][pP][lL][yY][- ]?[tT][oO]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    replyTo = value;
                } else if(regex_match(line,regex("(.*)[mM][iI][mM][eE][- ]?[vV][eE][rR][sS][iI][oO][nN]:(.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    mimeVersion = value;
                } else if(regex_match(line,regex("(.*)[dD][eE][lL][iI][vV][eE][rR][eE][dD][- ]?[tT][oO](.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    deliveredTo = value;
                } else if(regex_match(line,regex("(.*)[xX][- ]?[gG][oO][oO][gG][lL][eE][- ]?[sS][mM][tT][pP][- ]?[sS][oO][uU][rR][cC][eE](.*)"))) {
                    int index = line.find(":");
                    string value = line.substr(index+1);
                    xGoogleSmtpSource = value;
                }
            } // end-while

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