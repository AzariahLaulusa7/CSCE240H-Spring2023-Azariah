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

#include "Regex.h"

#include "Regex.cpp"

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
    cout << "Hello! If you want to exit, just enter \"quit\".\n" << endl;
    Regex check;

        while(1) {

            cout << check.getMatch() << endl;

            // get user input
            string response;
            getline(cin,response);

            // figure out user intent
            check.setMatch(response);
            cout << check.getMatch() << endl;

            check.reset();
        }

        return 0;
}