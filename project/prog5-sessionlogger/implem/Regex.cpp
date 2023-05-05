/*
 * Regex.cpp
 *
 *  Created on: March 17, 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <string.h>
#include <regex>
#include <iomanip>
#include <math.h>
#include "Regex.h"

Regex::Regex() {

    // default variables
    match = "";

}

Regex::~Regex() {
	// TODO Auto-generated destructor stub

}

string Regex::getMatch() {
    return match;
}

void Regex::setMatch(string userQ) {

    // regex pattern variables
    string patternI1 = "[Ii]1";
    string patternI2 = "[Ii]2";
    string patternI3 = "[Ii]3";
    string patternI4 = "[Ii]4";
    string patternI5 = "[Ii]5";
    string patternI6 = "[Ii]6";
    string patternI7 = "[Ii]7";
    string patternI8 = "[Ii]8";
    string patternI9 = "[Ii]9";
    string patternI10 = "[Ii]10";
    string patternI11 = "[Ii]11";
    string patternI12 = "[Ii]12";
    string patternEverything = "(.*)([Ee][Vv][Ee][Rr][Yy][Tt][Hh][Ii][Nn][Gg])(.*)";
    string patternQuit = "(.*)([Qq][Uu]?[Ii]?[Tt]?)(.*)";

    // regex patterns
    regex pattern1(patternI1);
    regex pattern2(patternI2);
    regex pattern3(patternI3);
    regex pattern4(patternI4);
    regex pattern5(patternI5);
    regex pattern6(patternI6);
    regex pattern7(patternI7);
    regex pattern8(patternI8);
    regex pattern9(patternI9);
    regex pattern10(patternI10);
    regex pattern11(patternI11);
    regex pattern12(patternI12);
    regex pattern13(patternEverything);
    regex pattern14(patternQuit);

    // check patterns
    if(regex_match(userQ,pattern1)) {
        match = "I1";
    } else if(regex_match(userQ,pattern2)) {
        match = "I2";
    } else if(regex_match(userQ,pattern3)) {
        match = "I3";
    } else if(regex_match(userQ,pattern4)) {
        match = "I4";
    } else if(regex_match(userQ,pattern5)) {
        match = "I5";
    } else if(regex_match(userQ,pattern6)) {
        match = "I6";
    } else if(regex_match(userQ,pattern7)) {
        match = "I7";
    } else if(regex_match(userQ,pattern8)) {
        match = "I8";
    } else if(regex_match(userQ,pattern9)) {
        match = "I9";
    } else if(regex_match(userQ,pattern10)) {
        match = "I10";
    } else if(regex_match(userQ,pattern11)) {
        match = "I11";
    } else if(regex_match(userQ,pattern12)) {
        match = "I12";
    } else if(regex_match(userQ,pattern13)) {
        match = "everything";
    } else if(regex_match(userQ,pattern14)) {
        match = "quit";
    }

    if(match != "")
        return;

    // question strings to compare for percentages
    regex I1[3] = {regex("(.*)([wW][hH][aA][tT])(.*)"),regex("(.*)([iI][sS])(.*)"),regex("(.*)([rR][Aa][Bb][Ii][Ee][Ss]?[?]?)(.*)")};
    regex I2[4] = {regex("(.*)([wW][hH][oO])(.*)"),regex("(.*)([iI][sS])(.*)"),regex("(.*)([aA][tT])(.*)"),regex("(.*)([rR][iI][sS][kK][sS]?[?]?)(.*)"),};
    regex I3[7] = {regex("(.*)([wW][hH][aA][tT])(.*)"),regex("(.*)([cC][aA][nN])(.*)"),regex("(.*)([tT][rR][aA][vV][eE][lL][eE][rR][sS]?)(.*)"),regex("(.*)([dD][oO])(.*)"),regex("(.*)([tT][oO])(.*)"),regex("(.*)([pP][rR][eE][vV][eE][nN][tT])(.*)"),regex("(.*)([rR]?[aA][bB][iI][eE][sS]?[?]?)(.*)")};
    regex I4[2] = {regex("(.*)([aA][fF][tT][eE][rR])(.*)"),regex("(.*)([tT][rR][aA][vV][eE][lL][sS]?)(.*)")};
    regex I5[2] = {regex("(.*)([Mm][Oo][Rr][Ee])(.*)"),regex("(.*)([iI][nN][fF][oO][rR][mM][aA][tT][iI][oO][nN][sS]?)(.*)")};
    regex I6[6] = {regex("(.*)([Ww][Hh][Aa][Tt])(.*)"),regex("(.*)([Aa][Rr][Ee])(.*)"),regex("(.*)([Tt][Hh][Ee])(.*)"),regex("(.*)([Tt][Yy][Pp][Ee][Ss]?)(.*)"),regex("(.*)([Oo][Ff])(.*)"),regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?[?]?)(.*)")};
    regex I7[2] = {regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?)(.*)"),regex("(.*)([Ss][Yy][Mm][Pp][Tt][Oo][Mm][Ss]?)(.*)")};
    regex I8[5] = {regex("(.*)([Ww][Hh][Ee][Nn])(.*)"),regex("(.*)([Tt][Oo])(.*)"),regex("(.*)([Cc][Aa][Ll][Ll])(.*)"),regex("(.*)([Aa])(.*)"),regex("(.*)([Dd][Oo][Cc][Tt][Oo][Rr])(.*)")};
    regex I9[2] = {regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?)(.*)"),regex("(.*)([Dd][Ii][Aa][Gg][Nn][Oo][Ss][Ii][Ss])(.*)")};
    regex I10[2] = {regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?)(.*)"),regex("(.*)([Tt][Rr][Ee][Aa][Tt][Mm][Ee][Nn][Tt][Ss]?)(.*)")};
    regex I11[2] = {regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?)(.*)"),regex("(.*)([Cc][Oo][Mm][Pp][Ll][Ii][Cc][Aa][Tt][Ii][Oo][Nn][Ss]?)(.*)")};
    regex I12[2] = {regex("(.*)([Rr][Aa][Bb][Ii][Ee][Ss]?)(.*)"),regex("(.*)([Vv][Aa][Cc][Cc][Ii][Nn][Ee][Ss]?)(.*)")};

    // percentages
    double numberOfMatches[12] {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

    // keywords that the questions should have
    int keyword1 = 0;// rabies
    int keyword2 = 0;// risks
    int keyword2two = 0;//who
    int keyword3 = 0;// prevent
    int keyword5 = 0;// more
    int keyword6 = 0;// types
    int keyword7 = 0;// symptomes
    int keyword8One = 0;// call doctor
    int keyword8Two = 0;
    int keyword9 = 0;// diagnosis
    int keyword10 = 0;// treatments
    int keyword11 = 0;// complications
    int keyword12 = 0;// vaccines


    // compare strings and find percentage
    int matches = 0;
    for(int i=0; i<3; i++) {// I1
        if(regex_match(userQ,I1[i])) {
            matches++;
            if(i==2)
                keyword1++;
        }
    }
    numberOfMatches[0] = matches;

    matches = 0;
    for(int i=0; i<4; i++) {// I2
        if(regex_match(userQ,I2[i])) {
            matches++;
            if(i==0)
                keyword2++;
            if(i==3)
                keyword2two++;
        }
    }
    numberOfMatches[1] = matches;
    
    matches = 0;
    for(int i=0; i<7; i++) {// I3
        if(regex_match(userQ,I3[i])) {
            matches++;
            if(i==5)
                keyword3++;
        }
    }
    numberOfMatches[2] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I4
        if(regex_match(userQ,I4[i]))
            matches++;
    }
    numberOfMatches[3] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I5
        if(regex_match(userQ,I5[i])) {
            matches++;
            if(i==0)
                keyword5++;
        }
    }
    numberOfMatches[4] = matches;

    matches = 0;
    for(int i=0; i<6; i++) {// I6
        if(regex_match(userQ,I6[i])) {
            matches++;
            if(i==3)
                keyword6++;
        }
    }
    numberOfMatches[5] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I7
        if(regex_match(userQ,I7[i])) {
            matches++;
            if(i==1)
                keyword7++;
        }
    }
    numberOfMatches[6] = matches;

    matches = 0;
    for(int i=0; i<5; i++) {// I8
        if(regex_match(userQ,I8[i])) {
            matches++;
            if(i==2)
                keyword8One++;
            if(i==4)
                keyword8Two++;
        }
    }
    numberOfMatches[7] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I9
        if(regex_match(userQ,I9[i])) {
            matches++;
            if(i==1)
                keyword9++;
        }
    }
    numberOfMatches[8] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I10
        if(regex_match(userQ,I10[i])) {
            matches++;
            if(i==1)
                keyword10++;
        }
    }
    numberOfMatches[9] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I11
        if(regex_match(userQ,I11[i])) {
            matches++;
            if(i==1)
                keyword11++;
        }
    }
    numberOfMatches[10] = matches;

    matches = 0;
    for(int i=0; i<2; i++) {// I12
        if(regex_match(userQ,I12[i])) {
            matches++;
            if(i==1)
                keyword12++;
        }
    }
    numberOfMatches[11] = matches;

    // greatest percentage index variable
    double maxMatch = 0.0;
    int greatIndex = 0;

    // find greatest percentage
    for(int i=0; i<12; i++) {
        if(numberOfMatches[i]>maxMatch) {
            maxMatch = numberOfMatches[i];
            greatIndex = i;
        }
    }

    // if the match is still 0
    if(maxMatch == 0.0) {
        return;
    }

    // check greatIndex and decide answer
    if(greatIndex==0) {// I1
        if(keyword1 != 0)
            match = "I1";
    } else if(greatIndex==1) {// I2
        if(keyword2 != 0 && keyword2two != 0)
            match = "I2";
    } else if(greatIndex==2) {// I3
        if(keyword3 != 0)
            match = "I3";
    } else if(greatIndex==3) {// I4
        if(numberOfMatches[3] >= 2)
            match = "I4";
    } else if(greatIndex==4) {// I5
        if(keyword5 != 0)
            match = "I5";
    } else if(greatIndex==5) {// I6
        if(keyword6 != 0)
            match = "I6";
    } else if(greatIndex==6) {// I7
        if(keyword7 != 0)
            match = "I7";
    } else if(greatIndex==7) {// I8
        if(keyword8Two != 0)
            match = "I8";
    } else if(greatIndex==8) {// I9
        if(keyword9 != 0)
            match = "I9";
    } else if(greatIndex==9) {// I10
        if(keyword10 != 0)
            match = "I10";
    } else if(greatIndex==10) {// I11
        if(keyword11 != 0)
            match = "I11";
    } else if(greatIndex==11) {// I12
        if(keyword12 != 0)
            match = "I12";
    }

}

void Regex::reset() {
    match = "";
}