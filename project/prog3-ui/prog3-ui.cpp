//============================================================================
// Name        : prog3-ui.cpp
// Author      : Azariah Laulusa
// Description : This program is a chit chat program that will answer the 12 topics for diseases
// and chat with the user.
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <regex>

#include "DiseaseData.h"
#include "WebmdData.h"
#include "CDCData.h"

#include "DiseaseData.cpp"
#include "CDCData.cpp"
#include "WebmdData.cpp"

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

    // Introductions
    cout << "\nWelcome to The Disease Chit Chat Program!" << endl;
    cout << "This program will chit chat with you about a specific disease.\n"
        << "In this case, this program only has information on Rabies.\n"
        << "Let's get started!\n\n" << endl;
    cout << "Hello! What would you like to know about rabies? If you want to exit, just enter \"0\".\n" << endl;
        string response;

    // Keeping track of questions
    int hi = 0;
    int how = 0;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    int ten = 0;
    int eleven = 0;
    int twelve = 0;
    int everything = 0;

    // Create CDCData and WebmdData variables and parse data
    DiseaseData disease;
    WebmdData web;
    CDCData cdc;
    if(!cdc.cdcParse("data/rabies-cdc-extracted.txt")) {
        cout << "File is not reading. Please try again later.\n\n" << endl;
    }
    if(!web.webmdParse("data/rabies-webmd-extracted.txt")) {
        cout << "File is not reading. Please try again later.\n\n" << endl;
    }
    if(!cdc.mixParse() || !web.mixParse()) {
        cout << "File is not reading. Please try again later.\n\n" << endl;
    }

    // While loop until quit
    while(1) {

        // Keep get input from user
        getline(cin,response);

        // Check response to get an answer
        if(response == "0") {
            break;
        } else if(regex_match(response,regex("(.*)[wW][hH][aA][tT][ -]?[iI][sS][ -]?[rR][Aa][Bb][Ii][Ee][Ss][?]?(.*)"))) {
            if(one > 0 && one < 3) {
                cout << cdc.getI1() << "\n...Once again.\n" << endl;
            } else if(one == 3 || one > 3) {
                cout << cdc.getI1() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI1() << "\n" << endl;
            }
            one ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Cc][Aa][Ll][Ll][ -]?[Aa]?[ -]?]?[Dd][Oo][Cc][Tt][Oo][Rr](.*)"))) {
            if(eight > 0 && eight < 3) {
                cout << web.getI8() << "\n...Once again.\n" << endl;
            } else if(eight == 3 || eight > 3) {
                cout << web.getI8() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << web.getI8() << "\n" << endl;
            }
            eight ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Rr][Aa][Bb][Ii][Ee][Ss]?[ -]?]?[Dd][Ii][Aa][Gg][Nn][Oo][Ss][Ii][Ss](.*)"))) {
            if(nine > 0 && nine < 3) {
                cout << web.getI9() << "\n...Once again.\n" << endl;
            } else if(nine == 3 || nine > 3) {
                cout << web.getI9() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << web.getI9() << "\n" << endl;
            }
            nine ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Rr][Aa][Bb][Ii][Ee][Ss]?[ -]?]?[Tt][Rr][Ee][Aa][Tt][Mm][Ee][Nn][Tt][Ss]?(.*)"))) {
            if(ten > 0 && ten < 3) {
                cout << web.getI10() << "\n...Once again.\n" << endl;
            } else if(ten == 3 || ten > 3) {
                cout << web.getI10() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << web.getI10() << "\n" << endl;
            }
            ten ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Rr][Aa][Bb][Ii][Ee][Ss]?[ -]?]?[Cc][Oo][Mm][Pp][Ll][Ii][Cc][Aa][Tt][Ii][Oo][Nn][Ss]?(.*)"))) {
            if(eleven > 0 && eleven < 3) {
                cout << web.getI11() << "\n...Once again.\n" << endl;
            } else if(eleven == 3 || eleven > 3) {
                cout << web.getI11() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << web.getI11() << "\n" << endl;
            }
            eleven ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Rr][Aa][Bb][Ii][Ee][Ss]?[ -]?]?[Vv][Aa][Cc][Cc][Ii][Nn][Ee][Ss]?(.*)"))) {
            if(twelve > 0 && twelve < 3) {
                cout << cdc.getI12() << "\n...Once again.\n" << endl;
            } else if(twelve == 3 || twelve > 3) {
                cout << cdc.getI12() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI12() << "\n" << endl;
            }
            twelve ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Rr][Aa][Bb][Ii][Ee][Ss]?[ -]?]?[Ss][Yy][Mm][Pp][Tt][Oo][Mm][Ss]?(.*)"))) {
            if(seven > 0 && seven < 3) {
                cout << web.getI7() << "\n...Once again.\n" << endl;
            } else if(seven == 3 || seven > 3) {
                cout << web.getI7() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << web.getI7() << "\n" << endl;
            }
            seven ++;
            continue;
        } else if(regex_match(response,regex("(.*)[wW][hH][oO][ -]?[iI][sS][ -]?[aA][tT][ -]?[rR][iI][sS][kK][?]?(.*)"))) {
            if(two > 0 && two < 3) {
                cout << cdc.getI2() << "\n...Once again.\n" << endl;
            } else if(two == 3 || two > 3) {
                cout << cdc.getI2() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI2() << "\n" << endl;
            }
            two ++;
            continue;
        } else if(regex_match(response,regex("(.*)[wW][hH][aA][tT][ -]?[cC][aA][nN][ -]?[tT][rR][aA][vV][eE][lL][eE][rR][sS][ -]?[dD][oO][ -]?[tT][oO][ -]?[pP][rR][eE][vV][eE][nN][tT][ -]?[rR][aA][bB][iI][eE][sS][?]?(.*)"))) {
            if(three > 0 && three < 3) {
                cout << cdc.getI3() << "\n...Once again.\n" << endl;
            } else if(three == 3 || three > 3) {
                cout << cdc.getI3() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI3() << "\n" << endl;
            }
            three ++;
            continue;
        } else if(regex_match(response,regex("(.*)[aA][fF][tT][eE][rR][ -]?[tT][rR][aA][vV][eE][lL](.*)"))) {
            if(four > 0 && four < 3) {
                cout << cdc.getI4() << "\n...Once again.\n" << endl;
            } else if(four == 3 || four > 3) {
                cout << cdc.getI4() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI4() << "\n" << endl;
            }
            four ++;
            continue;
        } else if(regex_match(response,regex("(.*)[Mm][Oo][Rr][Ee][ -]?[iI][nN][fF][oO][rR][mM][aA][tT][iI][oO][nN](.*)"))) {
            if(five > 0 && five < 3) {
                cout << cdc.getI5() << "\n...Once again.\n" << endl;
            } else if(five == 3 || five > 3) {
                cout << cdc.getI5() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << cdc.getI5() << "\n" << endl;
            }
            five ++;
            continue;
        } else if(regex_match(response,regex("(.*)[[Ww][Hh][Aa][Tt][ -]?[Aa][Rr][Ee][ -]?[Tt][Hh][Ee][ -]?]?[Tt][Yy][Pp][Ee][Ss][ -]?[Oo][Ff][ -]?[Rr][Aa][Bb][Ii][Ee][Ss][?]?(.*)"))) {
            if(six > 0 && six < 3) {
                cout << "There is only one type of rabies, but you can get rabies from different types of animals." << "\n...Once again.\n" << endl;
            } else if(six == 3 || six > 3) {
                cout << "There is only one type of rabies, but you can get rabies from different types of animals."  << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << "There is only one type of rabies, but you can get rabies from different types of animals." << "\n" << endl;
            }
            six ++;
            continue;
        } else if(regex_match(response, regex("(.*)[Ee][Vv][Ee][Rr][Yy][Tt][Hh][Ii][Nn][Gg](.*)"))) {
            if(everything > 0 && everything < 3) {
                cout << web.printEverything() << "\n...Once again.\n" << endl;
            } else if(everything == 3 || everything > 3) {
                cout << web.printEverything() << "\nYou have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << "\n" << endl;
            }
            everything ++;
            continue;
        } else if(regex_match(response, regex("(.*)[Hh][Ee][Ll][Ll][Oo](.*)"))) {
            if(hi > 0 && hi < 3) {
                cout << randomResponse(0) << " again!\n" << endl;
            } else if(hi == 3 || hi > 3) {
                cout << randomResponse(0) << ". You have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << randomResponse(0) << "!\n" << endl;
            }
            hi ++;
            continue;
        } else if(regex_match(response, regex("(.*)[Bb][Yy][Ee](.*)")) || regex_match(response, regex("(.*)[Hh][Ee][Ll][Pp](.*)"))) {
            cout << "If you want to leave, please enter \"0\" to exit, or you can continue to ask qeustions about rabies.\n" << endl;
            continue; 
        } else if(regex_match(response, regex("(.*)[Hh][Oo][Ww][ -]?[Aa][Rr][Ee][ -]?[Yy][Oo][Uu][?]?(.*)"))) { 
            if(how > 0 && how < 3) {
                cout << randomResponse(3) << " again!\n" << endl;
            } else if(how == 3 || how > 3) {
                cout << randomResponse(3) << ". You have asked me this already too many times. Please ask me something else about Rabies.\n" << endl;
            } else {
                cout << randomResponse(3) << "!\n" << endl;
            }
            how ++;
            continue;
        } else {
            cout << randomResponse(1) << ". I don't have any information for \"" << response << "\". Please ask me something else about rabies.\n" << endl;
            continue;
        }
    }

    // Outro
    cout << "\nGoodbye! Come again soon! :)" << endl;

    return 0;
}