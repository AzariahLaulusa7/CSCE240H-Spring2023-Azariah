//============================================================================
// Name        : Geometric Property Calculator
// Author      : Azariah Laulusa
// Description : This program takes in an input file and calculates the parameter or the area
// using the shapes and their dimensions in the input file. Then, the program writes the shape
// and the results in an output file called output.txt
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

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

                    // Check if there are enough dimensions
                    if(leftParam != 1) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tCIRCLE <10>\n"
                            << endl;
                        out_myfile << "CIRCLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Find radius
                    int radBegin = line.find("<");
                    string radTemp = line.substr(radBegin + 1);
                    int radEnd = radTemp.find(">");
                    string radius = radTemp.substr(0, radEnd);

                    // Check if radius is empty
                    if(radius.empty()){
                        cout << "** ATTENTION **\n"
                            << "You have empty dimensions. Please input valid dimensions.\n"
                            << "\nEx:\n\tCIRCLE <10>\n" << endl;
                        out_myfile << "CIRCLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Check if radius is number
                    int check = 0;

                    for(int i=0; i<radius.length(); i++){
                        if(radius.at(i) == '.') {
                            continue;
                        } else if(!isdigit(radius.at(i))) {
                            check++;
                        }
                    }

                    // Warning message
                    if(check != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << radius << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces.\n"
                            << "\nEx:\n\tCIRCLE <10>\n" << endl;
                        out_myfile << "CIRCLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Convert string to a number
                    double rad = stod(radius);

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        cout << "\nCalculating Area...\n" << endl;
                        double area = M_PI * (rad*rad);
                        cout << "\nWriting Area...\n" << endl;
                        cout << "CIRCLE AREA <" << area << ">\n" << endl;;
                        out_myfile << "CIRCLE AREA <" << area << ">\n";

                    } else if(choice == '2') {

                        cout << "\nCalculating Parameter...\n" << endl;
                        double parameter = 2 * M_PI * rad;
                        cout << "\nWriting Parameter...\n" << endl;
                        cout << "CIRCLE PARAMETER <" << parameter << ">\n" << endl;;
                        out_myfile << "CIRCLE PARAMETER <" << parameter << ">\n";

                    } else {

                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Area will be calculated since you didn't choose.\n"
                            << endl;
                        cout << "\nCalculating Area..." << endl;
                        double area = M_PI * (rad*rad);
                        cout << "Writing Area...\n" << endl;
                        cout << "CIRCLE AREA <" << area << ">\n" << endl;;
                        out_myfile << "CIRCLE AREA <" << area << ">\n";

                    }


                } else if(shape == "RECTANGLE") {

                    // Check if there are enough dimensions
                    if(leftParam != 2) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tRECTANGLE <30><40>\n"
                            << endl;
                        out_myfile << "RECTANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    //Find length
                    int lengBegin = line.find("<");
                    string lengTemp = line.substr(lengBegin + 1);
                    int lengEnd = lengTemp.find(">");
                    string length = lengTemp.substr(0, lengEnd);

                    // Check length
                    int check = 0;
                    for(int i=0; i<length.length(); i++){
                        if(length.at(i) == '.') {
                            continue;
                        } else if(!isdigit(length.at(i))) {
                            check++;
                        }
                    }

                    // Warning message
                    if(check != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << length << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces."
                            << "\nEx:\n\tRECTANGLE <10><60>\n" << endl;
                        out_myfile << "RECTANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Find width
                    int widBegin = lengTemp.find("<");
                    string widTemp = lengTemp.substr(widBegin + 1);
                    int widEnd = widTemp.find(">");
                    string width = widTemp.substr(0, widEnd);

                    // Check width
                    int checkWidth = 0;

                    for(int i=0; i<width.length(); i++){
                        if(width.at(i) == '.') {
                            continue;
                        } else if(!isdigit(width.at(i))) {
                            checkWidth++;
                        }
                    }

                    // Warning message
                    if(checkWidth != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << width << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces."
                            << "\nEx:\n\tRECTANGLE <10><60>\n" << endl;
                        out_myfile << "RECTANGLE <" << length << "> \"Not enough information to calculate\"\n";
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

                    // Convert string to a number
                    double leng = stod(length);
                    double wid = stod(width);

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        cout << "\nCalculating Area..." << endl;
                        double area = leng * wid;
                        cout << "Writing Area...\n" << endl;
                        cout << "RECTANGLE AREA <" << area << ">\n" << endl;;
                        out_myfile << "RECTANGLE AREA <" << area << ">\n";

                    } else if(choice == '2') {

                        cout << "\nCalculating Parameter...\n" << endl;
                        double parameter = (2 * leng) + (2 * wid);
                        cout << "\nWriting Parameter...\n" << endl;
                        cout << "RECTANGLE PARAMETER <" << parameter << ">\n" << endl;;
                        out_myfile << "RECTANGLE PARAMETER <" << parameter << ">\n";

                    } else {

                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Area will be calculated since you didn't choose.\n"
                            << endl;
                        cout << "\nCalculating Area..." << endl;
                        double area = leng * wid;
                        cout << "Writing Area...\n" << endl;
                        cout << "RECTANGLE AREA <" << area << ">\n" << endl;;
                        out_myfile << "RECTANGLE AREA <" << area << ">\n";

                    }

                } else if(shape == "TRIANGLE") {

                    // Check if there are enough dimensions
                    if(leftParam != 3) {
                        cout << "\n** ATTENTION **\n"
                            << "Please make sure your dimensions are valid.\n"
                            << "\nEx:\n\tTRIANGLE <30><40><10>\n"
                            << endl;
                        out_myfile << "TRIANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Find first side
                    int firstBegin = line.find("<");
                    string firstTemp = line.substr(firstBegin + 1);
                    int firstEnd = firstTemp.find(">");
                    string firstSide = firstTemp.substr(0, firstEnd);

                    // Check first side
                    int checkFirst = 0;

                    for(int i=0; i<firstSide.length(); i++){
                        if(firstSide.at(i) == '.') {
                            continue;
                        } else if(!isdigit(firstSide.at(i))) {
                            checkFirst++;
                        }
                    }

                    // Warning message
                    if(checkFirst != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << firstSide << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces.\n"
                            << "\nEx:\n\tTRIANGLE <10><30><40>\n" << endl;
                        out_myfile << "TRIANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }

                    // Find second side
                    int secondBegin = firstTemp.find("<");
                    string secondTemp = firstTemp.substr(secondBegin + 1);
                    int secondEnd = secondTemp.find(">");
                    string secondSide = secondTemp.substr(0, secondEnd);

                    // Check second side
                    int checkSec = 0;

                    for(int i=0; i<secondSide.length(); i++){
                        if(secondSide.at(i) == '.') {
                            continue;
                        } else if(!isdigit(secondSide.at(i))) {
                            checkSec++;
                        }
                    }

                    // Warning message
                    if(checkSec != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << secondSide << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces.\n"
                            << "\nEx:\n\tTRIANGLE <10><30><40>\n" << endl;
                        out_myfile << "TRIANGLE \"Not enough information to calculate\"\n";
                        continue;
                    }
                    // Find third side
                    int thirdBegin = secondTemp.find("<");
                    string thirdTemp = secondTemp.substr(thirdBegin + 1);
                    int thirdEnd = thirdTemp.find(">");
                    string thirdSide = thirdTemp.substr(0, thirdEnd);

                    // Check third side
                    int checkThird = 0;

                    for(int i=0; i<thirdSide.length(); i++){
                        if(thirdSide.at(i) == '.') {
                            continue;
                        } else if(!isdigit(thirdSide.at(i))) {
                            checkThird++;
                        }
                    }

                    // Warning message
                    if(checkThird != 0) {
                        cout << "** ATTENTION **\n"
                            << "This dimension \"" << thirdSide << "\" is not valid.\n"
                            << "Please put valid dimensions. The dimensions should be "
                            << "positive numbers with no spaces.\n"
                            << "\nEx:\n\tTRIANGLE <10><30><40>\n" << endl;
                        out_myfile << "TRIANGLE \"Not enough information to calculate\"\n";
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

                    // Convert string to a number
                    double first = stod(firstSide);
                    double second = stod(secondSide);
                    double third = stod(thirdSide);

                    // Prompt user to pick area or parameter
                    cout << "Do you want to find the Area or Parameter?\n"
                        << "Enter 1: Area\n"
                        << "Enter 2: Parameter\n" << endl;
                    char choice;
                    cin >> choice;

                    // Based on choice calculate results
                    if(choice == '1') {

                        cout << "\nCalculating Area..." << endl;
                        string area = "-";
                        cout << "Writing Area...\n" << endl;
                        cout << "TRIANGLE AREA <" << area << ">\n" << endl;;
                        out_myfile << "TRIANGLE AREA <" << area << ">\n";

                    } else if(choice == '2') {

                        cout << "\nCalculating Parameter...\n" << endl;
                        double parameter = first + second + third;
                        cout << "\nWriting Parameter...\n" << endl;
                        cout << "TRIANGLE PARAMETER <" << parameter << ">\n" << endl;;
                        out_myfile << "TRIANGLE PARAMETER <" << parameter << ">\n";

                    } else {

                        cout << "You did not enter \"1\" or \"2\".\n"
                            << "The Parameter will be calculated since you didn't choose.\n"
                            << endl;
                         cout << "\nCalculating Parameter...\n" << endl;
                        double parameter = first + second + third;
                        cout << "\nWriting Parameter...\n" << endl;
                        cout << "TRIANGLE PARAMETER <" << parameter << ">\n" << endl;;
                        out_myfile << "TRIANGLE PARAMETER <" << parameter << ">\n";

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
                    out_myfile << "\"Not enough information to calculate\"\n";
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

    cout << "\nGoodbye! Come again soon! :)" << endl;

    return 0;
}
