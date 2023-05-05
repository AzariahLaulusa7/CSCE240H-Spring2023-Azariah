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
#include <ctime>
#include <vector>
#include <chrono>

#include "Regex.h"
#include "CDCUi.h"
#include "WebMDUi.h"
#include "DiseaseUi.h"

#include "Regex.cpp"
#include "CDCUi.cpp"
#include "WebMDUi.cpp"
#include "DiseaseUi.cpp"

using namespace std;
using namespace std::chrono;

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

string getDate() {

    // Get current date
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    auto timeString = oss.str();

    return timeString;

}

string getSessionNumber() {

    // Create session number tracker
    int sessionNum;

    try {

        string fileName = "chat_statistics.csv";
        string line;
    
        fstream file (fileName, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                sessionNum++;
            }
            file.close();
        }
        else
            cout<<"Could not open the file\n";

    } catch(exception& e) {// catch exception
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
    }

    // Turn session number into a string
    int tempNum = sessionNum;
    string final = to_string(tempNum);
    return final;

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

    // Tracking responses
    int userResponse = 0;
    int compResponse = 0;
    string rep;

    // Introductions
    cout << "\nWelcome to The Disease Chit Chat Program!" << endl;
    cout << "This program will chit chat with you about a specific disease.\n"
        << "In this case, this program only has information on Rabies.\n"
        << "Let's get started!\n\n" << endl;
    cout << "Hello! If you want to exit, just enter \"quit\".\n" << endl;

    // Start time
    auto start = high_resolution_clock::now();

    // Open file
    try {

        string out_file_name = "data/chat_sessions/" + getSessionNumber() + "_" + getDate() + ".txt";
        ofstream out_myfile(out_file_name);
        if(out_myfile.is_open()) {

            while(1) {

                // get user input
                string response;
                getline(cin,response);
                userResponse++;// add every time user responds

                // Write user response to chat session text
                out_myfile << "--------------------------------------------\n\nUser: \"" << response << "\"" << endl;

                // figure out user intent
                check.setMatch(response);
                rep = "";

                // Check for general and common phrases
                if(regex_match(response, regex("(.*)[Hh][Ee][Ll][Ll][Oo](.*)")) || regex_match(response, regex("(.*)[Hh][Ii](.*)"))
                    || regex_match(response, regex("(.*)[Hh][Oo][Ll][Aa](.*)")) || regex_match(response, regex("(.*)[Bb][Oo][Nn][Jj][Oo][Uu][Rr](.*)"))) {
                    
                    // Get random response for greetings
                    string randRep = randomResponse(0);

                    if(hi > 0 && hi < 3) {// changing up response when asked multiple times

                        cout << randRep << " again!\n" << endl;
                        rep = rep + " " + randRep + " again!";

                    } else {// original response

                        cout << randRep << "!\n" << endl;
                        rep = rep + " " + randRep + " !";

                    }

                    // Track response
                    hi++;
                    compResponse++;

                } else if(regex_match(response, regex("(.*)[Bb][Yy][Ee](.*)")) || regex_match(response, regex("(.*)[Ee][Xx][Ii][Tt](.*)"))
                    || regex_match(response, regex("(.*)[Ll][Ee][Aa][Vv][Ee](.*)"))) {// if user wants to leave
                    
                    cout << "If you want to leave, please enter \"quit\" to exit, or you can continue to ask qeustions about rabies.\n" << endl;
                    compResponse++;

                    rep = rep + " " + "If you want to leave, please enter \"quit\" to exit, or you can continue to ask qeustions about rabies.\n";

                } else if(regex_match(response, regex("(.*)[Hh][Oo][Ww][ -]?[Aa][Rr][Ee][ -]?[Yy][Oo][Uu][?]?(.*)"))) { 

                    // Get random response for general question
                    string randRep = randomResponse(3);

                    // Check amount of times asked
                    if(how > 0) {

                        cout << randRep << " again!\n" << endl;
                        rep = rep + " " + randRep + " again!";

                    } else {

                        cout << randRep << "!\n" << endl;
                        rep = rep + " " + randRep + " again";

                    }

                    // Keep track of response
                    how ++;
                    compResponse++;

                } else if(check.getMatch() == "") {// check if there is no match

                    // Get random bad/error response
                    string randRep = randomResponse(1);

                    // respond to user and track response
                    cout << randRep << ". I have no information to answer this question " << response << ".\n" << endl;
                    compResponse++;
                    rep = rep + " " + randRep + ". I have no information to answer this question \"" + response +"\".";

                }
                


                // Reponses for disease related questions, options, everything, and quit
                if(check.getMatch() == "I1") {

                    cout << main.getI1() + main.tag() << endl;
                    compResponse++;
                    rep = rep + " " + main.getI1() + main.tag();

                } if(check.getMatch() == "I2") {

                    cout << cdc.getI2() + cdc.tagCDC() << endl;
                    compResponse++;
                    rep = rep + " " + cdc.getI2() + cdc.tagCDC();
                    
                } if(check.getMatch() == "I3") {

                    cout << cdc.getI3() + cdc.tagCDC() << endl;
                    compResponse++;
                    rep = rep + " " + cdc.getI3() + cdc.tagCDC();
                    
                } if(check.getMatch() == "I4") {

                    cout << cdc.getI4() + cdc.tagCDC() << endl;
                    compResponse++;
                    rep = rep + " " + cdc.getI4() + cdc.tagCDC();
                    
                } if(check.getMatch() == "I5") {

                    cout << cdc.getI5() + cdc.tagCDC() << endl;
                    compResponse++;
                    rep = rep + " " + cdc.getI5() + cdc.tagCDC();
                    
                } if(check.getMatch() == "I6") {

                    cout << main.getI6() + main.tag() << endl;
                    compResponse++;
                    rep = rep + " " + main.getI6() + main.tag();
                    
                } if(check.getMatch() == "I7") {

                    cout << web.getI7() + web.tagWebMD() << endl;
                    compResponse++;
                    rep = rep + " " + web.getI7() + web.tagWebMD();
                    
                } if(check.getMatch() == "I8") {

                    cout << web.getI8() + web.tagWebMD() << endl;
                    compResponse++;
                    rep = rep + " " + web.getI8() + web.tagWebMD();
                    
                } if(check.getMatch() == "I9") {

                    cout << web.getI9() + web.tagWebMD() << endl;
                    compResponse++;
                    rep = rep + " " + web.getI9() + web.tagWebMD();
                    
                } if(check.getMatch() == "I10") {

                    cout << web.getI10() + web.tagWebMD() << endl;
                    compResponse++;
                    rep = rep + " " + web.getI10() + web.tagWebMD();
                    
                } if(check.getMatch() == "I11") {

                    cout << web.getI11() + web.tagWebMD() << endl;
                    compResponse++;
                    rep = rep + " " + web.getI11() + web.tagWebMD();
                    
                } if(check.getMatch() == "I12") {

                    cout << main.getI12() + main.tag() << endl;
                    compResponse++;
                    rep = rep + " " + main.getI12() + main.tag();
                    
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
                    compResponse++;
                    rep =  rep + " " + everything;
                    
                } if(check.getMatch() == "quit") {// quit program
                    break;
                }

                // Print data in chat session folder
                out_myfile << "Computer: \"" << rep << "\"\n\n--------------------------------------------" << endl;

                // Reset regex class for new question/user response
                check.reset();
            }

            // End of program
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            rep = "Goodbye. Come again soon!";
            out_myfile << "Computer: \"" << rep << "\"\n\n--------------------------------------------" << endl;
            compResponse++;
            cout << "Goodbye. Come again soon!" << endl;

            // Store info in csv
            string compResp = to_string(compResponse);
            string userResp = to_string(userResponse);
            string time = to_string(duration.count());
            string csvFile = "chat_statistics.csv";
            string row;
            int rowNum = 0;
            fstream csv(csvFile);
            csv.is_open();
            csv << getSessionNumber() << "," << out_file_name << "," << userResp << "," << compResp << "," << time << "\n";
            csv.close();
            out_myfile.close();

        } else 
            cout << "Error: cannot open file to record session. Please make sure destination exists." << endl;

    } catch(exception& e) {// catch exception
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
    }

    return 0;
}