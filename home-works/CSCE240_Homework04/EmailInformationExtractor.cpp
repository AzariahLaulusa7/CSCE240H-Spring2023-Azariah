//============================================================================
// Name        : EmailInformationExtractor.cpp
// Author      : Azariah Laulusa
// Description : This program takes in a email header file and a part name. Then,
// the program will return the part value of the header file.
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <regex>

#include "BaseEmailHeaderType.h"
#include "OutlookHeaderType.h"
#include "GmailHeaderType.h"

#include "BaseEmailHeaderType.cpp"
#include "OutlookHeaderType.cpp"
#include "GmailHeaderType.cpp"

using namespace std;

//============================================================================

// Random response generator
string randomResponse(int number) {

    // Random responses
    string response = "";

    // Positive or negative responses
    if(number == 0) {// positive
        string randoms[7] = {"Super","Awesome","Great","Wonderful","Wow","Ok","Nice"};
        response = response + randoms[rand() % 7];
    } else if(number == 1) {// negative
        string randoms[5] = {"Uh oh","Oops","Oh no","Sorry","Whoopsie"};
        response = response + randoms[rand() % 5];
    }

    return response;
}

// Main
int main()
{
    // Introductions
    cout << "\nWelcome to Email Information Extractor!" << endl;
    cout << "This program takes in a header file and a part name in the file.\n"
        << " Then, the program will return the value of the part name.\n" << endl;

    // While loop until quit
    while(1) {

	    // Prompt user to input or quit
        cout << "\nLet's extract!\n"
            << "What type of header file do you want to extract?\n" 
            << "\tEnter \"outlook\" to extract an outlook header file\n"
            << "\tEnter \"gmail\" to extract a gmail header file\n" 
            << "If you want to exit, enter \"0\"." << endl;

        // Pattern
        string outlookCaps = "(.*)([Ou][Uu][Tt][Ll][Oo][Oo][Kk])(.*)";
        string outlookVowel = "(.*)([aeiou][aeiou][tT][Ll][aeiou][aeiou][kK])(.*)";
        string gmailCaps = "(.*)([gG][mM][aA][iI][lL])(.*)";
        string gmailVowel = "(.*)([gG][mM][aeiou][aeiou][lL])(.*)";
        regex outlookPattern1(outlookCaps);
        regex outlookPattern2(outlookVowel);
        regex gmailPattern1(gmailCaps);
        regex gmailPattern2(gmailVowel);
        
        // Get input
        string headerType;
        getline(cin,headerType);
        if(regex_match(headerType,outlookPattern1) | regex_match(headerType,outlookPattern2)) {
            
            // Outlook header
            OutlookHeaderType outlook;

            // Prompt user for the header file
            cout << "\n" << randomResponse(0) << "! You have an outlook header file. Please enter your outlook header file." 
                << endl;
            string file;
            getline(cin,file);

            // Check file
            if(!outlook.checkFile(file)) {
                cout << randomResponse(1) << ". Seems like \"" << file << "\" is an invalid file. "
                    << "Please input a valid file.\n\n" << endl;
                continue;
            }
            outlook.setMessageHeader(file);
            if(!outlook.parseFile(file)) 
                continue;

            // Prompt user for part name
            cout << "\nWhat is the name of the part you want from your header file?" << endl;
            string part;
            getline(cin,part); 
            outlook.setPartName(part);

            // Search through outlook parts and get value
            if(regex_match(part,regex("(.*)[fF][rR][oO][mM](.*)"))) {// find value for all parts
                cout << outlook.getFrom() << endl;
            } else if(regex_match(part,regex("(.*)[tT][oO](.*)"))) {
                cout << outlook.getTo() << endl;
            } else if(regex_match(part,regex("(.*)[Dd][aA][tT][eE](.*)"))) {
                cout << outlook.getDate() << endl;
            } else if(regex_match(part,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][yY][pP][eE](.*)"))) {
                cout << outlook.getContentType() << endl;
            } else if(regex_match(part,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][rR][aA][nN][sS][fF][eE][rR][- ]?[eE][nN][cC][oO][dD][iI][nN][gG](.*)"))) {
                cout << outlook.getContentTransferEncoding()  << endl;
            } else if(regex_match(part,regex("(.*)[mM][eE][sS][sS][aA][gG][eE][- ]?[iI][dD](.*)"))) {
                cout << outlook.getMessageId() << endl;
            } else if(regex_match(part,regex("(.*)[cC][cC](.*)"))) {
                cout << outlook.getCC() << endl;
            } else if(regex_match(part,regex("(.*)[rR][eE][cC][eE][iI][vV][eE][dD](.*)"))) {
                cout << outlook.getReceived() << endl;
            } else if(regex_match(part,regex("(.*)[sS][uU][bB][jJ][eE][cC][tT](.*)"))) {
                cout << outlook.getSubject() << endl;
            } else if(regex_match(part,regex("(.*)[rR][eE][pP][lL][yY][- ]?[tT][oO](.*)"))) {
                cout << outlook.getReplyTo() << endl;
            } else if(regex_match(part,regex("(.*)[mM][iI][mM][eE][- ]?[vV][eE][rR][sS][iI][oO][nN](.*)"))) {
                cout << outlook.getMimeVersion() << endl;
            } else if(regex_match(part,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[lL][aA][nN][gG][uU][aA][gG][eE](.*)"))) {
                cout << outlook.getContentLanguage() << endl;
            } else if(regex_match(part,regex("(.*)[xX][- ]?[mM][sS][- ]?[eE][xX][cC][hH][aA][nN][gG][eE][- ]?[oO][rR][gG][aA][nN][iI][zZ][aA][tT][iI][oO][nN][- ]?[sS][cC][lL](.*)"))) {
                cout << outlook.getXMsExchangeOrganizationScl() << endl;
            } else if(regex_match(part,regex("(.*)[xX][- ]?[mM][sS][- ]?[hH][aA][sS][- ]?[aA][tT][tT][aA][cC][hH](.*)"))) {
                cout << outlook.getXMsHasAttach() << endl;
            } else if(regex_match(part,regex("(.*)[aA][cC][cC][eE][pP][tT][- ]?[lL][aA][nN][gG][uU][aA][gG][eE](.*)"))) {
                cout << outlook.getAcceptLanguage() << endl;
            } else if(regex_match(part,regex("(.*)[rR][eE][fF][eE][rR][eE][nN][cC][eE][sS]?(.*)"))) {
                cout << outlook.getReferences() << endl;
            } else if(regex_match(part,regex("(.*)[tT][hH][rR][eE][aA][dD][- ]?[iI][nN][dD][eE][xX](.*)"))) {
                cout << outlook.getThreadIndex() << endl;
            } else if(regex_match(part,regex("(.*)[tT][hH][rR][eE][aA][dD][- ]?[tT][oO][pP][iI][cC](.*)"))) {
                cout << outlook.getThreadTopic() << endl;
            } else if(regex_match(part,regex("(.*)[aA][uU][tT][hH][eE][nN][tT][iI][cC][aA][tT][iI][oO][nN][- ]?[rR][eE][sS][uU][lL][tT][sS]?(.*)"))) {
                cout << outlook.getAuthenticationResults() << endl;
            } else {
                cout << "\n" << randomResponse(1) << ". I have no information on the part name \"" << part << "\".\n"
                    << "Please try again.\n\n" << endl;
                continue;
            }
        
        } else if(regex_match(headerType,gmailPattern1) | regex_match(headerType,gmailPattern2)) {

            // Gmail header
            GmailHeaderType gmail;

            // Prompt user for the header file
            cout << "\n" << randomResponse(0) << "! You have a gmail header file. Please enter your gmail header file." 
                << endl;
            string file;
            getline(cin,file);

            // Check file
            if(!gmail.checkFile(file)) {
                cout << randomResponse(1) << ". Seems like \"" << file << "\" is an invalid file. "
                    << "Please input a valid file.\n\n" << endl;
                continue;
            }
            gmail.setMessageHeader(file);
            if(!gmail.parseFile(file))
                continue;

            // Prompt user for part name
            cout << "\nWhat is the name of the part you want from your header file?" << endl;
            string part;
            getline(cin,part);

            // Search through gmail parts and get value
            if(regex_match(part,regex("(.*)[fF][rR][oO][mM](.*)"))) {// find value for all parts
                cout << gmail.getFrom() << endl;
            } else if(regex_match(part,regex("(.*)[tT][oO](.*)"))) {
                cout << gmail.getTo() << endl;
            } else if(regex_match(part,regex("(.*)[Dd][aA][tT][eE](.*)"))) {
                cout << gmail.getDate() << endl;
            } else if(regex_match(part,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][yY][pP][eE](.*)"))) {
                cout << gmail.getContentType() << endl;
            } else if(regex_match(part,regex("(.*)[cC][oO][nN][tT][eE][nN][tT][- ]?[tT][rR][aA][nN][sS][fF][eE][rR][- ]?[eE][nN][cC][oO][dD][iI][nN][gG](.*)"))) {
                cout << gmail.getContentTransferEncoding() << endl;
            } else if(regex_match(part,regex("(.*)[mM][eE][sS][sS][aA][gG][eE][- ]?[iI][dD](.*)"))) {
                cout << gmail.getMessageId() << endl;
            } else if(regex_match(part,regex("(.*)[cC][cC](.*)"))) {
                cout << gmail.getCC() << endl;
            } else if(regex_match(part,regex("(.*)[rR][eE][cC][eE][iI][vV][eE][dD](.*)"))) {
                cout << gmail.getReceived() << endl;
            } else if(regex_match(part,regex("(.*)[sS][uU][bB][jJ][eE][cC][tT](.*)"))) {
                cout << gmail.getSubject() << endl;
            } else if(regex_match(part,regex("(.*)[rR][eE][pP][lL][yY][- ]?[tT][oO](.*)"))) {
                cout << gmail.getReplyTo() << endl;
            } else if(regex_match(part,regex("(.*)[mM][iI][mM][eE][- ]?[vV][eE][rR][sS][iI][oO][nN](.*)"))) {
                cout << gmail.getMimeVersion() << endl;
            } else if(regex_match(part,regex("(.*)[dD][eE][lL][iI][vV][eE][rR][eE][dD][- ]?[tT][oO](.*)"))) {
                cout << gmail.getDeliveredTo() << endl;
            } else if(regex_match(part,regex("(.*)[xX][- ]?[gG][oO][oO][gG][lL][eE][- ]?[sS][mM][tT][pP][- ]?[sS][oO][uU][rR][cC][eE](.*)"))) {
                cout << gmail.getXGoogleSmtpSource() << endl;
            } else {
                cout << "\n" << randomResponse(1) << ". I have no information on the part name \"" << part << "\".\n"
                    << "Please try again.\n\n" << endl;
                continue;
            }

        } else if(headerType == "0") {
            break;
        } else {// invalid input

            // Inform and start from beginning
            cout << "\n\n" << randomResponse(1) << ". You did not enter \"outlook\", \"gmail\", or \"0\".\n"
                << "Your input \"" << headerType << "\" is invalid. Please try again.\n\n"
                << endl;

        }
        
    }

    // Outro
    cout << "\nGoodbye! Come again soon! :)" << endl;

    return 0;
}