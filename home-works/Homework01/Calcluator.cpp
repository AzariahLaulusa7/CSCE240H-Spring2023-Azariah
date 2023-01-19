//============================================================================
// Name        : File Calculator
// Author      : Azariah Laulusa
// Description : A calculator that adds, multiplies, subtracts, and divides
// two integers
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

// Introductions to the program
void introductions() {
    cout << "\nWelcome to File Calculator!" << endl;
    cout << "This program can add, subtract, divide,"
        << " and multiply two integers from a file or manually.\n" << endl;
}

// Add
void Add() {

    // Integer variables
    char num1;
    char num2;

    // Prompt user to give two numbers
    cout << "\nLet's add numbers! Please enter two positive integers in the order "
        << "you want to add them!\n" << endl;
    cin >> num1;
    cin >> num2;

    // Create total variable
    double total;

    // Check user's numbers
    if(isdigit(num1) && isdigit(num2)){
        //calculate
        int temp1 = num1 - '0';
        int temp2 = num2 - '0';
        total = temp1 + temp2;
        // Output answer
        cout << "\nAnswer: " << num1 << " + " << num2 << " = " << total << "\n"<< endl;
    } else
        cout << "\nYour numbers were invalid. Next time, please input positive integers!\n";

}

// Subtract
void Subtract() {

    // Integer variables
    char num1;
    char num2;

    // Prompt user to give two numbers
    cout << "\nLet's subtract numbers!\nPlease enter two positive integers in the order "
        << "you want to subract them!\n" << endl;
    cin >> num1;
    cin >> num2;

    // Create total variable
    double total;

    // Check user's numbers
    if(isdigit(num1) && isdigit(num2)){
        //calculate
        int temp1 = num1 - '0';
        int temp2 = num2 - '0';
        total = temp1 - temp2;
        // Output answer
        cout << "\nAnswer: " << num1 << " - " << num2 << " = " << total << "\n"<< endl;
    } else
        cout << "\nYour numbers were invalid. Next time, please input positive integers!\n";

}

// Multiply
void Multiply() {

    // Integer variables
    char num1;
    char num2;

    // Prompt user to give two numbers
    cout << "\nLet's multiply numbers! Please enter two positive integers in the order "
        << "you want to multiply them!\n" << endl;
    cin >> num1;
    cin >> num2;

    // Create total variable
    double total;

    // Check user's numbers
    if(isdigit(num1) && isdigit(num2)){
        //calculate
        int temp1 = num1 - '0';
        int temp2 = num2 - '0';
        total = temp1 * temp2;
        // Output answer
        cout << "\nAnswer: " << num1 << " * " << num2 << " = " << total << "\n"<< endl;
    } else
        cout << "\nYour numbers were invalid. Next time, please input positive integers!\n";

}

// Divide
void Divide() {

    // Integer variables
    char num1;
    char num2;

    // Prompt user to give two numbers
    cout << "\nLet's divide numbers! Please enter two positive integers in the order "
        << "you want to divide them!\n" << endl;
    cin >> num1;
    cin >> num2;

    // Create total variable
    double total;

    // Check user's numbers
    if(isdigit(num1) && isdigit(num2)){
        //calculate
        int temp1 = num1 - '0';
        int temp2 = num2 - '0';
        total = temp1 / temp2;
        // Output answer
        cout << "\nAnswer: " << num1 << " / " << num2 << " = " << total << "\n"<< endl;
    } else
        cout << "\nYour numbers were invalid. Next time, please input positive integers!\n";

}

// Manual calculator operation
void ManualCalculator() {

    // Operation choice variable
    int operation;

    // Ask user for operation
    cout << "\nEnter 1: Add\n"
        << "Enter 2: Subtract\n"
        << "Enter 3: Multiply\n"
        << "Enter 4: Divide\n" << endl;
        
    // Get choice of operation
    cin >> operation;

    if(operation == 1) {
        Add();
    } else if (operation == 2) {
        Subtract();
    } else if (operation == 3) {
        Multiply();
    }else if (operation == 4) {
        Divide();
    } else {
         cout << " You did not enter a valid choice. Next time please choose between "
            << "1, 2, 3, 4.\n" << endl;
    }

}

// Add
int Add(string input) {
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        total = total + num;
    }
    return total;
}

// Subtract
int Subtract(string input) {
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        if(i == 0) {
            total = total + num;
        } else 
            total = total - num;
    }
    return total;
}

// Multiply
int Multiply(string input) {
    int total = 1;
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
            total = total * num;
    }
    return total;
}

// Divide
int Divide(string input) {
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        if (i == 0) {
            total = total + num;
        }else
            total = total / num;
    }
    return total;
}

// Read file
void ReadFile() {

    // Intro
    cout << "\nLet's read a file!\n\n";

    // File Reading Variables
	string file_name;
	string line;

    // Prompt user for a file
    cout << "Insert your file name...\n"
        << "Ex:\n"
        << "    <<file>>.text (Just a file)\n"
        << "    <<folder>>/<<file>>.text (A file in a folder)\n" << endl;

    // Get file
    cin >> file_name;

    // Read file and calculate each row
    // Output total for each row
    // Each row should be two numbers
	ifstream myfile(file_name);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {

            // Total and input variables
            int total;
            string input;

            //Getting nums
            for(int i = 0; i < line.length(); i++) {
                char num = line[i];
                if(isdigit(num)) {
                    input += num;
                }
            }

            // Operation Choice
            cout << "\nChoose an operation:\n"
                << "Enter 1: Add\n"
                << "Enter 2: Subtract\n"
                << "Enter 3: Multiply\n" 
                << "Enter 4: Divide\n" << endl;

            // Choice variable
            char choice;
            cin >> choice;

            // Pick operation
            if(choice == '1') {
                total = Add(input);// Finding total
                string output;// Creating string to show operation
                // Put relevant symbols into created string
                for(int i = 0; i < input.length(); i++) {
                    output += input[i];
                    if(i+1 != input.length())
                        output += " + ";
                }
                cout << "\n" << output << " = " << total << "\n";
            } else if (choice == '2') {
                total = Subtract(input);
                string output;
                for(int i = 0; i < input.length(); i++) {
                    output += input[i];
                    if(i+1 != input.length())
                        output += " - ";
                }
                cout << "\n" << output << " = " << total << "\n";
            } else if (choice == '3') {
                total = Multiply(input);
                string output;
                for(int i = 0; i < input.length(); i++) {
                    output += input[i];
                    if(i+1 != input.length())
                        output += " * ";
                }
                cout << "\n" << output << " = " << total << "\n";
            }else if (choice == '4') {
                total = Divide(input);
                string output;
                for(int i = 0; i < input.length(); i++) {
                    output += input[i];
                    if(i+1 != input.length())
                        output += " / ";
                }
                cout << "\n" << output << " = " << total << "\n";
            } else {
                cout << " You did not enter a valid choice. Next time please choose between "
                    << "1, 2, 3, 4.\n" << endl;
            }
		}

		myfile.close();
	} else
		cout << "Unable to open file - " << file_name << endl;
}

// Write file
void WriteFile(){
    cout << "\nLet's write a file!\n\n";

    // Writing variables
	string in_file_name;
	string out_file_name = "results.txt";
	string line;

    // Get file from user
    // Prompt user for a file
    cout << "Insert your file name...\n"
        << "Ex:\n"
        << "    <<file>>.text (Just a file)\n"
        << "    <<folder>>/<<file>>.text (A file in a folder)\n" << endl;

    cin >> in_file_name;

	ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {
			while (getline(in_myfile, line)) {

                cout << "\n\t reading .. - " << line << "\n" << endl;

                // Total and input variables
                int total;
                string input;

                //Getting nums
                for(int i = 0; i < line.length(); i++) {
                    char num = line[i];
                    if(isdigit(num)) {
                        input += num;
                    }
                }

                // Operation Choice
                cout << "\nChoose an operation:\n"
                    << "Enter 1: Add\n"
                    << "Enter 2: Subtract\n"
                    << "Enter 3: Multiply\n" 
                    << "Enter 4: Divide\n" << endl;

                // Choice variable
                char choice;
                cin >> choice;

                // Pick operation
                if(choice == '1') {
                    total = Add(input);// Finding total
                    string output;// Creating string to show operation
                    // Put relevant symbols into created string
                    for(int i = 0; i < input.length(); i++) {
                        output += input[i];
                        if(i+1 != input.length())
                            output += " + ";
                    }
                    cout << "\t\t writing .. - " << output << " = " << total << "\n";
                    out_myfile << output << " = " << total;
                } else if (choice == '2') {
                    total = Subtract(input);
                    string output;
                    for(int i = 0; i < input.length(); i++) {
                        output += input[i];
                        if(i+1 != input.length())
                            output += " - ";
                    }
                    cout << "\n" << output << " = " << total << "\n";
                } else if (choice == '3') {
                    total = Multiply(input);
                    string output;
                    for(int i = 0; i < input.length(); i++) {
                        output += input[i];
                        if(i+1 != input.length())
                            output += " * ";
                    }
                    cout << "\n" << output << " = " << total << "\n";
                }else if (choice == '4') {
                    total = Divide(input);
                    string output;
                    for(int i = 0; i < input.length(); i++) {
                        output += input[i];
                        if(i+1 != input.length())
                            output += " / ";
                    }
                    cout << "\n" << output << " = " << total << "\n";
                } else {
                    cout << "\nnYou did not enter a valid choice. Next time, please choose between "
                        << "1, 2, 3, or 4!\n" << endl;
            }
				//cout << "\t reading .. - " << line << endl;
				//string out_line = "A prefix - " + line + '\n';
				//cout << "\t\t writing .. - " << out_line;
				//out_myfile << out_line;
			} // end-while

			// Close output file
			out_myfile.close();
		} else {
			cout << "\nUnable to open output file - " << out_file_name << "\n"<< endl;
		} // end-if

		// Close input file
		in_myfile.close();
	} else
		cout << "Unable to open input file - " << in_file_name << "\n" << endl;
}

// File calculator operation
// This method will read a file and calculate
// Each file should have only two numbers
// The method will either add, subtract, multiply,
// or divide each row of numbers
// Each row should consist of numbers
void FileCalculator() {
    
    // Introductions
    char fileChoice;
    cout << "\nWelcome to the File Calculator!\n"
        << "Would you like to read or write a file?\n" 
        << "\nEnter 1: Read a file\n"
        << "Enter 2: Write a file\n" << endl;

    // User's choice
    cin >> fileChoice;

    // Based on the choice go to that method
    if(fileChoice == '1') {
        ReadFile();
    }else if(fileChoice == '2') {
        WriteFile();
    } else
        cout << "\nYou did not enter a valid choice. Next time, Please choose between 1 or 2!\n"
            << endl;
}

int main()
{
    introductions();

    while(1) {

        // Input variable
        char input;
        
        // Prompt user to pick whether to choose
        cout << "\nLet's caluclate!\n"
            << "Which calculator do you want to use?\n\n"
            << "Enter 1: Manual Calculator (manually plug in numbers)\n"
            << "Enter 2: File Calculator (calculating operations from a file)\n"
            << "Enter 3: Exit\n" << endl;
        
        // Get input
        cin >> input;

        // Choices
        if(input == '1') {
            ManualCalculator();
        } else if(input == '2') {
            FileCalculator();
        } else if(input == '3') {
            break;
        } else {
            cout << "\nYou did not enter a valid choice. Please choose between 0, 1, or 2!\n"
            << endl;
        }
    }

    cout << "\nGoodbye! Come again soon! :)" << endl;

    return 0;
}