//============================================================================
// Name        : OOGeometricPropertyCalculator.cpp
// Author      : Azariah Laulusa
// Description : This program takes in an input file and calculates the parameter or the area
// using the shapes and their dimensions in the input file. Then, the program writes the shape
// and the results in an output file called output.txt using classes.
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cmath>

#include "headers/Shape.h"
#include "headers/Circle.h"
#include "headers/Rectangle.h"
#include "headers/Triangle.h"

#include "Shape.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Triangle.cpp"

using namespace std;

//============================================================================

// Read and write method
void readWriteFile(string in_file_name) {

    //check if the file is empty
    if(in_file_name.empty()) {
        cout << "Your file is empty. There is nothing to calculate.\n" 
            << "Please give a file with shapes and their dimensions!\n"
            << "Ex:\n\tCIRCLE <radius-in-cm>" <<endl;
        return;
    }

    // Line and output variables
	string out_file_name = "data/output.txt";
	string line;

    // Start reading and writing file
    ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {
            while (getline(in_myfile, line)) {

                // Check if line is empty
                if(line.empty()) {
                    cout << "** ATTENTION **\n"
                        << "This line is empty. There is not enough "
                        << "information to calculate.\n";
                    out_myfile << "EMPTY \"Not enough information to calculate\"\n";
                    continue;
                }

                cout << "\n\t reading .. - " << line << "\n" << endl;

                // Extracting shape
                int shapeEnd = line.find(" ");
                string shape = line.substr(0,shapeEnd);

                // Check dimensions
                int leftParam = 0;
                int rightParam = 0;

                for(int i=0; i<line.length(); i++) {
                    if(line.at(i) == '<'){
                        leftParam++;
                    } else if(line.at(i) == '>') {
                        rightParam++;
                    }
                }

                if(leftParam != rightParam) { 
                    cout << "** ATTENTION **\n"
                        << "Your dimensions are off in line " << line
                        << ".\nPlease make sure each "
                        << "dimension is between a \"<\" and a \">\"."
                        << "\n\nEx:\n\tCircle <23>\n"
                        << endl;
                    out_myfile << "\"Not enough information to calculate\"\n";
                    continue;
                }

                // Find shape
                if(shape == "CIRCLE") {

                    // Create circle class variable
                    Circle circle;

                    // Check if there are enough dimensions
                    if(leftParam != 1) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tCIRCLE <10>\n"
                            << endl;
                        circle.setErrorMessage();
                        out_myfile << circle.getErrorMessage();
                        continue;
                    }

                    // Find radius
                    string radius = circle.parse(line);

                    // Check if radius is empty
                    if(radius.empty()) {
                        cout << "** ATTENTION **\n"
                            << "You have empty dimensions. Please input valid dimensions.\n"
                            << "\nEx:\n\tCIRCLE <10>\n" << endl;
                        circle.setErrorMessage();
                        out_myfile << circle.getErrorMessage();
                        continue;
                    }

                    // Check if radius is number
                    if(circle.checkIfNumber(radius)) {

                        // Convert string to a number
                        double rad = stod(radius);
                        circle.setRadius(rad);
                        
                    } else {

                        // Radius is not a valid dimension
                        circle.setErrorMessage();
                        out_myfile << circle.getErrorMessage();// output error message
                        continue;// read next line

                    }

                    // Assign radius a variable
                    double finalRad = circle.getRadius();

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        // Get Area
                        circle.setArea(finalRad);
                        out_myfile << "CIRCLE AREA <" << circle.getArea() << ">\n";

                    } else if(choice == '2') {

                        // Get Paramter
                        circle.setParameter(finalRad);
                        out_myfile << "CIRCLE PARAMETER <" << circle.getParameter() << ">\n";

                    } else {

                        // Invalid choice
                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Area will be calculated since you didn't choose.\n"
                            << endl;
                        circle.setArea(finalRad);
                        out_myfile << "CIRCLE AREA <" << circle.getArea() << ">\n";

                    }


                } else if(shape == "RECTANGLE") {

                    // Class variable
                    Rectangle rectangle;

                    // Check if there are enough dimensions
                    if(leftParam != 2) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tRECTANGLE <30><40>\n"
                            << endl;
                        rectangle.setErrorMessage();
                        out_myfile << rectangle.getErrorMessage();
                        continue;
                    }

                    // Find length
                    int lengBegin = line.find("<");
                    string lengTemp = line.substr(lengBegin + 1);
                    int lengEnd = lengTemp.find(">");
                    string length = lengTemp.substr(0, lengEnd);

                    // Check length
                    if(rectangle.checkIfNumber(length)) {

                        // Convert string to a number
                        double leng = stod(length);
                        rectangle.setLength(leng);
                        
                    } else {

                        // Length is not a valid dimension
                        rectangle.setErrorMessage();
                        out_myfile << rectangle.getErrorMessage();
                        continue;

                    }

                    // Find width
                    int widBegin = lengTemp.find("<");
                    string widTemp = lengTemp.substr(widBegin + 1);
                    int widEnd = widTemp.find(">");
                    string width = widTemp.substr(0, widEnd);

                    // Check width
                    if(rectangle.checkIfNumber(width)) {

                        // Convert string to a number to calculate
                        double wid = stod(width);
                        rectangle.setWidth(wid);
                        
                    } else {

                        // Width is not a valid dimension
                        rectangle.setErrorMessage();
                        out_myfile << rectangle.getErrorMessage();
                        continue;

                    }

                    // Check if the length and the width are empty
                    if(length.empty() || width.empty()){
                        cout << "** ATTENTION **\n"
                            << "You have empty dimensions. Please input valid dimensions.\n"
                            << "\nEx:\n\tRECTANGLE <10><60>\n" << endl;
                        out_myfile << "RECTANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Assign length and width variables
                    double finalLeng = rectangle.getLength();
                    double finalWid = rectangle.getWidth();

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        // Get Area
                        rectangle.setArea(finalLeng, finalWid);
                        out_myfile << "RECTANGLE AREA <" << rectangle.getArea() << ">\n";

                    } else if(choice == '2') {

                        // Get Parameter
                        rectangle.setParameter(finalLeng, finalWid);
                        out_myfile << "RECTANGLE PARAMETER <" << rectangle.getParameter() << ">\n";

                    } else {

                        // Invalid choice
                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Area will be calculated since you didn't choose.\n"
                            << endl;
                        rectangle.setArea(finalLeng, finalWid);
                        out_myfile << "RECTANGLE AREA <" << rectangle.getArea() << ">\n";

                    }

                } else if(shape == "TRIANGLE") {

                    // Class variable
                    Triangle triangle;

                    // Check if there are enough dimensions
                    if(leftParam != 3) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tTRIANGLE <30><40><10>\n"
                            << endl;
                        triangle.setErrorMessage();
                        out_myfile << triangle.getErrorMessage();
                        continue;
                    }

                    // Find first side
                    int firstBegin = line.find("<");
                    string firstTemp = line.substr(firstBegin + 1);
                    int firstEnd = firstTemp.find(">");
                    string firstSide = firstTemp.substr(0, firstEnd);

                    // Check first side
                   if(triangle.checkIfNumber(firstSide)) {

                        // Convert string to a number
                        double firstS = stod(firstSide);
                        triangle.setFirstSide(firstS);
                        
                    } else {

                        //  First side is invalid
                        triangle.setErrorMessage();
                        out_myfile << triangle.getErrorMessage();
                        continue;

                    }

                    // Find second side
                    int secondBegin = firstTemp.find("<");
                    string secondTemp = firstTemp.substr(secondBegin + 1);
                    int secondEnd = secondTemp.find(">");
                    string secondSide = secondTemp.substr(0, secondEnd);

                    // Check second side
                   if(triangle.checkIfNumber(secondSide)) {

                        // Convert string to a number
                        double secS = stod(secondSide);
                        triangle.setFirstSide(secS);
                        
                    } else {

                        // Second number is invalid
                        triangle.setErrorMessage();
                        out_myfile << triangle.getErrorMessage();
                        continue;

                    }
                    // Find third side
                    int thirdBegin = secondTemp.find("<");
                    string thirdTemp = secondTemp.substr(thirdBegin + 1);
                    int thirdEnd = thirdTemp.find(">");
                    string thirdSide = thirdTemp.substr(0, thirdEnd);

                    // Check third side
                    if(triangle.checkIfNumber(thirdSide)) {

                        // Convert string to a number
                        double thirdS = stod(thirdSide);
                        triangle.setFirstSide(thirdS);
                        
                    } else {

                        // Third number is invalid
                        triangle.setErrorMessage();
                        out_myfile << triangle.getErrorMessage();
                        continue;

                    }

                    // Check if any side is empty
                    if(firstSide.empty() || secondSide.empty() || thirdSide.empty()){
                        cout << "** ATTENTION **\n"
                            << "You have empty dimensions. Please input valid dimensions.\n"
                            << "\nEx:\n\tTRIANGLE <10><30><40>\n" << endl;
                        out_myfile << "TRIANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Set area and parameter
                    double s1 = triangle.getFirstSide();
                    double s2 = triangle.getSecSide();
                    double s3 = triangle.getThirdSide();

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        // Get Area
                        triangle.setArea(s1, s2, s3);
                        if(isnan(triangle.getArea())) {// if not a number
                            cout << "\n**The area is not a number."
                                << " The area can't be found with these dimensions.**\n" << endl;
                            out_myfile << "TRIANGLE AREA <" << "-" << ">\n";// fill in with a dash
                        } else {
                            out_myfile << "TRIANGLE AREA <" << triangle.getArea() << ">\n";
                        }

                    } else if(choice == '2') {

                        // Get Parameter
                        triangle.setParameter(s1, s2, s3);
                        out_myfile << "TRIANGLE PARAMETER <" << triangle.getParameter() << ">\n";

                    } else {

                        // Invalid choice
                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Parameter will be calculated since you didn't choose.\n"
                            << endl;
                        triangle.setParameter(s1, s2, s3);
                        out_myfile << "TRIANGLE PARAMETER <" << triangle.getParameter() << ">\n";

                    }



                } else {
                    cout << "\n** ATTENTION **\n"
                        << "The shape in \"" << line << "\" can't be read.\n"
                        << "The shape in each line should be CAPITALIZED.\n"
                        << "Choose either \"CIRCLE\", \"RECTANGLE\", or \"TRIANGLE\",\n"
                        << "and there should be a space (\" \") "
                        << "between the shape "
                        << "and their dimensions.\n\nEx:\n\tCIRCLE <radius-in-cm>\n"
                        << endl;
                    out_myfile << "CIRCLE \"Not enough information to calculate\"\n";
                    continue;
                }

            }

            // Close output file
			out_myfile.close();

        } else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

		// Close input file
		in_myfile.close();
    } else
		cout << "Unable to open input file - " << in_file_name << endl;
}

// Main Method
int main()
{
    // Introductions
    cout << "\nWelcome to Geometric Property Calculator!" << endl;
    cout << "This program can find the parameter or area of shapes"
        << " in a given file.\n" << endl;

    // While loop to give an option to quit
    while(1) {

        // Input file
        string in_file_name;

	    // Prompt user to pick whether to choose
        cout << "\nLet's caluclate!\n"
            << "Enter your file name or enter 0 to quit.\n\n" 
            << "Ex:\n\t<<file>>.txt (Just a file)\n\t<<folder>>/<<file>>.txt "
            << "(A file in a folder)\n" << endl;
        
        // Get input
        cin >> in_file_name;

        if(in_file_name == "0")
            break;
        
        // Call read and write method
        readWriteFile(in_file_name);
    }

    // Outro
    cout << "\nGoodbye! Come again soon! :)" << endl;

    return 0;
}
