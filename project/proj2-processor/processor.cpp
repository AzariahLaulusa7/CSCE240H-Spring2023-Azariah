//============================================================================
// Name        : Project Assignment #2 Processor
// Author      : Azariah Laulusa
// Description : Processes data from files obtained from Project #1 and return contents to user.
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <cctype>

using namespace std;

// Read Webmd file from the extractor output
void readWebMDFile(string question) {

    // Variables to read from webmd extracted file, and print question and answer
    string in_file_name = "data/rabies-webmd-extracted.txt";
    string out_file_name = "test/test_output.txt";
	string line;

    // Start reading and writing
    ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {

            // Output answer to file and terminal
            out_myfile << "Question: " << question << "\n\n" << endl;
            out_myfile << "Answer:\n" << endl;

            // Create a variable to activate when to print info
            int print = 0;

            // Look through each line for the question in WebMD file
            while (getline(in_myfile, line)) {

                if(line.find(question) != string::npos){// if find question then print
                    print = 1;
                }

                if(print == 1) {// print line
                    if(line.find("*") != string::npos && line.find(question) == string::npos) {// stop print
                    print = 0;
                    break;
                    }
                    cout << line << endl;
                    out_myfile << line << endl;
                }
            }

            // Website the data was extracted from
            out_myfile << "\n\"https://www.webmd.com/a-to-z-guides/what-is-rabies\"" << endl;

        } else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

        // Close input file
		in_myfile.close();
    } else
		cout << "Unable to open input file - " << in_file_name << endl;

}

// Read CDC file from the extractor output
void readCDCFile(string question) {

    // Variables to read from cdc extracted file, and print question and answer
    string in_file_name = "data/rabies-cdc-extracted.txt";
    string out_file_name = "test/test_output.txt";
	string line;

    // Start reading and writing
    ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {

            // Output
            out_myfile << "Question: " << question << "\n\n" << endl;
            out_myfile << "Answer:\n" << endl;

            // Print variable
            int print = 0;

            // Looking for question in CDC file
            while (getline(in_myfile, line)) {

                if(line.find(question) != string::npos){// start print
                    print = 1;
                }

                if(print == 1) {// print line
                    if(line.find("*") != string::npos && line.find(question) == string::npos) {// stop print
                    print = 0;
                    break;
                    }
                    cout << line << endl;
                    out_myfile << line << endl;
                }
            }

            // Print website the info was extracted from
            out_myfile << "\n\"https://wwwnc.cdc.gov/travel/diseases/rabies\"" << endl;

        } else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

        // Close input file
		in_myfile.close();
    } else
		cout << "Unable to open input file - " << in_file_name << endl;

}

// Reads files and answers users questions
void readFilesAndAnswerQuestions(string disease) {

    // Making sure disease is all lowercased
    transform(disease.begin(), disease.end(), disease.begin(),
        [](unsigned char c){ return tolower(c); });

    // Continue to ask questions until the user wants to exit
    while(1) {

        // Prompt user
        cout << "\nWhat would you like to know about " << disease << "?\n"
            << "If you want to see my question options, then enter \"options\".\n"
            << "If you're done asking questions about " << disease << ", then enter \"exit\".\n" 
            << endl;
        string question;
        getline(cin, question);
        
        // Check question and give a response
        cout << "\n\nsearching for answers...\n\n" << endl;
        if(question == "options") {
            cout << "\n\ngetting options...\n\n" << endl;
            cout << "Here are the question options available for you:\n\n"
                << "\t\t \"What is " << disease << "?\"\n"
                << "\t\t \"Who is at risk?\"\n"
                << "\t\t \"What are the symptoms?\"\n"
                << "\t\t \"How is it spread?\"\n"
                << "\t\t \"More information\"\n"
                << endl;
            continue;
        } else if(question == "exit") {
            cout << "I'll send you back to home. Thank you for your interest in "
                << disease << "!\n"
                << "\n\ngoing back home...\n\n" << endl;
            break;
        } else if(question == "What is rabies?" || question == "what is rabies?"
                    || question == "What is rabies" || question == "what is rabies") {

            // Information in both extracted website files with user an option to choose
            cout << "I found information from a WebMD website and a CDC website.\n"
                << "Which website would you like me to extract the information from?\n"
                << "Type \"webmd\" or \"cdc\".\n" << endl;
            string website;
            getline(cin, website);

            // Get information
            if(website == "webmd") {
                cout << "\n\ngetting information from WebMD...\n\n" << endl;
                cout << "\n\nAnswer:\n" << endl;
                readWebMDFile("What Is Rabies?");
            } else if(website == "cdc") {
                cout << "\n\ngetting information from CDC...\n\n" << endl;
                cout << "\n\nAnswer:\n" << endl;
                readCDCFile("What is rabies?");
            } else {// default
                cout << "You didn't enter any of the choices I gave you.\n"
                    << "I will extract from the CDC website."
                    << "\n\ngetting information from CDC...\n\n" << endl;
                cout << "\n\nAnswer:\n" << endl;
                readCDCFile("What is rabies?");
            }

        } else if(question == "Who is at risk?" || question == "who is at risk?"
                    || question == "Who is at risk" || question == "who is at risk") {
            
            // Read from cdc extracted file
            cout << "\n\nAnswer:\n" << endl;
            readCDCFile("Who is at risk?");

        } else if(question == "What are the sysmptoms?" || question == "what are the sysmptoms?"
                    || question == "What are the sysmptoms" || question == "what are the sysmptoms") {

            // Read from WebMD extracted file
            cout << "\n\nAnswer:\n" << endl;
            readWebMDFile("What Are The Sysmptoms?");

        } else if(question == "How is it spread?" || question == "how is it spread?"
                    || question == "How is it spread" || question == "how is it spread") {

            // Read from WebMD extracted file
            cout << "\n\nAnswer:\n" << endl;
            readWebMDFile("How Is It Spread?");

        } else if(question == "More information"|| question == "more information") {

            // Read from Webmd and cdc files
            cout << "\n\nAnswer:\n" << endl;
            readCDCFile("What can travelers do to prevent rabies?");
            cout << "\n\n" << endl;
            readWebMDFile("An Animal Bit Me. What Should I Do?");
            cout << "\n\n" << endl;
            readWebMDFile("Can You Tell If An Animal Has Rabies?");

            // Output the websites for users
            cout << "If you're not satisfied with the info I gave you,\n"
                << "please visit the websites I extracted this information from.\n\n" << endl;
            cout << "Websites:\n\t-\"https://wwwnc.cdc.gov/travel/diseases/rabies\"\n"
                << "\t-\"https://www.webmd.com/a-to-z-guides/what-is-rabies\"" << endl;

        } else {// no infomration for a question
            cout << "I'm sorry. I have no information for your question \"" << question << "\".\n"
                << "Please ask another question, or check the quesiton options I have available.\n\n"
                << endl;
            continue;
        }
    }

}

int main()
{
    // Introduction
    cout << "\n\nHello! ";

    // Infinte loop
    while(1) {
        // Prompt user for disease
        cout << "\nWhat disease are you interested in? If you want to exit, please enter 0."
            << "\n**Note: Right now, we only have information on Rabies.**\n" << endl;
        string answer;
        getline(cin, answer);

        // If 0 then exit
        if(answer == "0") {
            cout << "Goodbye! Come back soon! :)" << endl;
            break;
        } else { // check answer
            string exists = "(.*)([rR][aA][bB][iI][eE][sS])(.*)";
            string vowel = "(.*)(r[aeiou]b[aeiou][aeiou]s)(.*)";
            regex pattern(exists);
            regex pattern2(vowel);
            if(answer == "rabies" || answer == "RABIES" || answer  == "Rabies") {
                cout << "\n\npulling up information for rabies...\n\n" << endl;
                readFilesAndAnswerQuestions(answer);
            } else if(regex_match(answer,pattern) || regex_match(answer,pattern2) || answer == "rabie") {
                cout << "\nDid you mean rabies? Enter \"yes\" or \"no\".\n" << endl;
                string choice;
                cin >> choice;
                if(choice == "yes") {
                    cout << "\nAwesome! Let's get started!\n\npulling up information for rabies...\n\n" << endl;
                    readFilesAndAnswerQuestions(answer);
                } else if(choice == "no") {
                    cout << "\nMy mistake. Let's try again.\n" << endl;
                    continue;
                } else {
                    cout << "You did not enter yes or no. Please try again.\n" << endl;
                    continue;
                }
            } else {
                cout << "I'm sorry. I don't have any information on " << answer << ".\n" << endl;
                continue;
            }
        }

    }

    return 0;

}