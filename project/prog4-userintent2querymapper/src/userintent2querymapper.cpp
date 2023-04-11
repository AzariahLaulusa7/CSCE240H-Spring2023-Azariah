//============================================================================
// Name        : prog4-userintent2querymapper.cpp
// Author      : Azariah Laulusa
// Description : This program is a chit chat program that will answer the 12 topics for diseases
// and try to figure out the user's intent.
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <regex>

#include "Regex.h"
#include "CDCUi.h"
#include "WebMDUi.h"
#include "DiseaseUi.h"

#include "Regex.cpp"
#include "CDCUi.cpp"
#include "WebMDUi.cpp"
#include "DiseaseUi.cpp"

using namespace std;

//============================================================================

// Random response generator
string randomResponse(int number) {

    // Random responses
    string response = "";

    // Responses
    if(number == 0) {// responding to hello
        string randoms[4] = {"Hello","Hi","Nice to meet you","Greetings"};
        response = response + randoms[rand() % 4];
    } else if(number == 1) {// negative
        string randoms[5] = {"Uh oh","Oops","Oh no","Sorry","Whoopsie"};
        response = response + randoms[rand() % 5];
    } else if(number == 3) {// responding to how are you
        string randoms[3] = {"I'm doing well. Thank you","I'm doing great","I'm chilling"};
        response = response + randoms[rand() % 3];
    }

    return response;
}

// Main
int main() {

    // Create variables for files
    string webmdFile = "data/rabies-webmd-extracted.txt";
    string cdcFile = "data/rabies-cdc-extracted.txt";

    // Create class variables
    Regex check;
    DiseaseUi main;
    WebMDUi web;
    CDCUi cdc;

    // Set answers for questions
    main.setI1();
    main.setI12();
    cdc.setI2();
    cdc.setI3();
    cdc.setI4();
    cdc.setI5();
    web.setI7();
    web.setI8();
    web.setI9();
    web.setI10();
    web.setI11();

    // Tracking variables
    int hi = 0;
    int how = 0;

    // Introductions
    cout << "\nWelcome to The Disease Chit Chat Program!" << endl;
    cout << "This program will chit chat with you about a specific disease.\n"
        << "In this case, this program only has information on Rabies.\n"
        << "Let's get started!\n\n" << endl;
    cout << "Hello! If you want to exit, just enter \"quit\".\n" << endl;

        while(1) {

            cout << check.getMatch() << endl;

            // get user input
            string response;
            getline(cin,response);

            // figure out user intent
            check.setMatch(response);

            // Check for general and common phrases
            if(regex_match(response, regex("(.*)[Hh][Ee][Ll][Ll][Oo](.*)")) || regex_match(response, regex("(.*)[Hh][Ii](.*)"))
                || regex_match(response, regex("(.*)[Hh][Oo][Ll][Aa](.*)")) || regex_match(response, regex("(.*)[Bb][Oo][Nn][Jj][Oo][Uu][Rr](.*)"))) {
                if(hi > 0 && hi < 3) {
                    cout << randomResponse(0) << " again!\n" << endl;
                } else {
                    cout << randomResponse(0) << "!\n" << endl;
                }
                hi++;
            } else if(regex_match(response, regex("(.*)[Bb][Yy][Ee](.*)")) || regex_match(response, regex("(.*)[Ee][Xx][Ii][Tt](.*)"))
                || regex_match(response, regex("(.*)[Ll][Ee][Aa][Vv][Ee](.*)"))) {
                cout << "If you want to leave, please enter \"quit\" to exit, or you can continue to ask qeustions about rabies.\n" << endl;
            } else if(regex_match(response, regex("(.*)[Hh][Oo][Ww][ -]?[Aa][Rr][Ee][ -]?[Yy][Oo][Uu][?]?(.*)"))) { 
                if(how > 0) {
                    cout << randomResponse(3) << " again!\n" << endl;
                } else {
                    cout << randomResponse(3) << "!\n" << endl;
                }
                how ++;
            } else if(check.getMatch() == "")// check if there is no match
                cout << randomResponse(1) << ". I have no information to answer this question " << response << ".\n" << endl;


            // Reponses for disease related questions, options, everything, and quit
            if(check.getMatch() == "I1") {

                cout << main.getI1() + main.tag() << endl;

            } if(check.getMatch() == "I2") {

                cout << cdc.getI2() + cdc.tagCDC() << endl;
                
            } if(check.getMatch() == "I3") {

                cout << cdc.getI3() + cdc.tagCDC() << endl;
                
            } if(check.getMatch() == "I4") {

                cout << cdc.getI4() + cdc.tagCDC() << endl;
                
            } if(check.getMatch() == "I5") {

                cout << cdc.getI5() + cdc.tagCDC() << endl;
                
            } if(check.getMatch() == "I6") {

                cout << main.getI6() + main.tag() << endl;
                
            } if(check.getMatch() == "I7") {

                cout << web.getI7() + web.tagWebMD() << endl;
                
            } if(check.getMatch() == "I8") {

                cout << web.getI8() + web.tagWebMD() << endl;
                
            } if(check.getMatch() == "I9") {

                cout << web.getI9() + web.tagWebMD() << endl;
                
            } if(check.getMatch() == "I10") {

                cout << web.getI10() + web.tagWebMD() << endl;
                
            } if(check.getMatch() == "I11") {

                cout << web.getI11() + web.tagWebMD() << endl;
                
            } if(check.getMatch() == "I12") {

                cout << main.getI12() + main.tag() << endl;
                
            } if(check.getMatch() == "everything") {

                string everything = main.getI1() + "\n"
                    + main.getI12() + "\n"
                    + cdc.getI2() + "\n"
                    + cdc.getI3() + "\n"
                    + cdc.getI4() + "\n"
                    + cdc.getI5() + "\n"
                    + web.getI7() + "\n"
                    + web.getI9() + "\n"
                    + web.getI10() + "\n"
                    + web.getI11() + "\n"
                    + main.tag();

                cout << everything << endl;
                
            } if(check.getMatch() == "quit") {
                break;
            }

            check.reset();
        }

        cout << "Goodbye. Come again soon!" << endl;

        return 0;
}