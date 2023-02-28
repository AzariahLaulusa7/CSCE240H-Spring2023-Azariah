/*
 * OutlookHeaderType.cpp
 *
 *  Created on: Feb 24, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <regex>
#include "OutlookHeaderType.h"

OutlookHeaderType::OutlookHeaderType() {

    // default variables for outlook header type
	xMsHasAttach = "N/A";
	xMsExchangeOrganizationScl = "N/A";
    contentLanguage = "N/A";
    acceptLanguage = "N/A";
    references = "N/A";
    threadIndex = "N/A";
    threadTopic = "N/A";
    authenticationResults = "N/A";

}

OutlookHeaderType::~OutlookHeaderType() {
	// TODO Auto-generated destructor stub

}

// getters
string OutlookHeaderType::getXMsHasAttach() {
	return xMsHasAttach;
}
string OutlookHeaderType::getXMsExchangeOrganizationScl() {
    return xMsExchangeOrganizationScl;
}
string OutlookHeaderType::getContentLanguage() {
    return contentLanguage;
}
string OutlookHeaderType::getAcceptLanguage() {
    return acceptLanguage;
}
string OutlookHeaderType::getReferences() {
    return references;
}
string OutlookHeaderType::getThreadIndex() {
    return threadIndex;
}
string OutlookHeaderType::getThreadTopic() {
    return threadTopic;
}
string OutlookHeaderType::getAuthenticationResults() {
    return authenticationResults;
}

// setters
void OutlookHeaderType::setXMsHasAttach(string type) {

    if(type.empty())
        return;
    xMsHasAttach = type;

}
void OutlookHeaderType::setXMsExchangeOrganizationScl(string type) {

    if(type.empty())
        return;
    xMsExchangeOrganizationScl = type;

}
void OutlookHeaderType::setContentLanguage(string type) {

    if(type.empty())
        return;
    contentLanguage = type;

}
void OutlookHeaderType::setAcceptLanguage(string type) {

    if(type.empty())
        return;
    acceptLanguage = type;

}
void OutlookHeaderType::setReferences(string type) {

    if(type.empty())
        return;
    references = type;

}
void OutlookHeaderType::setThreadIndex(string type) {

    if(type.empty())
        return;
    threadIndex = type;

}
void OutlookHeaderType::setThreadTopic(string type) {

    if(type.empty())
        return;
    threadTopic = type;

}
void OutlookHeaderType::setAuthenticationResults(string type) {
    if(type.empty())
        return;
    authenticationResults = type;
}

// parse user's header file
bool OutlookHeaderType::parseFile(string file) {

    //Reading given file and parsing all standard and unique parts
	string line;
	ifstream in_myfile(file);

    // Exception handling
    try {
        if (in_myfile.is_open()) {
                while (getline(in_myfile, line)) {// check every line
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
                    } else if(regex_match(line,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[lL][aA][nN][gG][uU][aA][gG][eE]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        contentLanguage = value;
                    } else if(regex_match(line,regex("(.*)[xX][- ]?[mM][sS][- ]?[eE][xX][cC][hH][aA][nN][gG][eE][- ]?[oO][rR][gG][aA][nN][iI][zZ][aA][tT][iI][oO][nN][- ]?[sS][cC][lL]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        xMsExchangeOrganizationScl = value;
                    } else if(regex_match(line,regex("(.*)[xX][- ]?[mM][sS][- ]?[hH][aA][sS][- ]?[aA][tT][tT][aA][cC][hH]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        xMsHasAttach = value;
                    } else if(regex_match(line,regex("(.*)[aA][cC][cC][eE][pP][tT][- ]?[lL][aA][nN][gG][uU][aA][gG][eE]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        acceptLanguage = value;
                    } else if(regex_match(line,regex("(.*)[rR][eE][fF][eE][rR][eE][nN][cC][eE][sS]?:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        references = value;
                    } else if(regex_match(line,regex("(.*)[tT][hH][rR][eE][aA][dD][- ]?[iI][nN][dD][eE][xX]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        threadIndex = value;
                    } else if(regex_match(line,regex("(.*)[tT][hH][rR][eE][aA][dD][- ]?[tT][oO][pP][iI][cC]:(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        threadTopic = value;
                    } else if(regex_match(line,regex("(.*)[aA][uU][tT][hH][eE][nN][tT][iI][cC][aA][tT][iI][oO][nN][- ]?[rR][eE][sS][uU][lL][tT][sS]?(.*)"))) {
                        int index = line.find(":");
                        string value = line.substr(index+1);
                        authenticationResults = value;
                    }
                } // end-while

            // Close input file
            in_myfile.close();

            // Successfully parsed
            return true;
        } else {
            cout << "Seems like \"" << file << "\" does not exist\n" 
                << "Please enter an existing email header file.\n\n" << endl;
            return false;
        }
    } catch(exception& e) {
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;
    }

}