//============================================================================
// Name        : Project Assignment #1 Extractor
// Author      : Azariah Laulusa
// Description : Extracts disease information from websites.
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

//Counts words
int WordCounting(string line) {

    // Check if empty
    if(line.empty())
        return 0;
    
    // Word counting variable
    int wordCount = 0;
    int count = 0;

    // Counting words
    for(int i=0; i<line.length(); i++) {
        // if space don't count
        if(line.at(i) == ' ' || line.at(i) == '\n') 
            wordCount++;
    }

    return wordCount;

}

// Counts characters not inlcuding spaces
int CharCounting(string line) {

    // Check if empty
    if(line.empty())
        return 0;

    // Char counting variable
    int outCharCount = 0;

    // Counting characters
    for(int i=0; i<line.length(); i++) {
        // if space continue
        if(line.at(i) == ' ' || line.at(i) == '\n' 
            || line.at(i) == '\t') {
            continue;
        } else
            outCharCount++;
    }

    return outCharCount;

}

// Counts all characters including spaces
int AllCharCounting (string line) {

    // Check if empty
    if(line.empty())
        return 0;

    // Char counting variable
    int allCharCount = 0;

    // Counting characters
    for(int i=0; i<line.length(); i++) {
        allCharCount++;// counts all chars
    }

    return allCharCount;

}

// Checks special characters CDC file ONLY
string replacingSpecialChar(string line) {

    // Replace special characters
    if(line.find("&rsquo;") != string::npos) {// this character symbolizes "'"
        int specBegin = line.find("&");
        string replace = "'";
        line.replace(specBegin,7,replace);
    }
    if (line.find("&nbsp;") != string::npos) {// this character is a no break space
        int specBegin = line.find("&");
        string replace = " ";// replace with a space
        line.replace(specBegin,6,replace);
    }

    return line;

}

// Checks for websites for cdc lines ONLY
string checkingCDCWebsites(string line) {

    int websiteCount = 0;// Amount of websites
    for(int i=0; i<line.length(); i++) { // Find website amount
        if(line.at(i) == '<' && line.at(i+1) == 'a') 
            websiteCount++;
    }
    int search = 0;// Amount of times to search for websites
    while(search < websiteCount) {
        if(line.find("<a") != string::npos) {
            int begin = line.find("<");
            int end = line.find("</a>");
            int length = 0;
            for(int i=begin; i<end+1; i++) {
                length++;
            }
            length = length + 3;
            string temp = line.substr(begin+1);
            int tempEnd = temp.find("<");
            string newLine = temp.substr(0,tempEnd);
            int webBegin = newLine.find("\"");
            string webTemp = newLine.substr(webBegin+1);
            int webEnd = webTemp.find("\"");
            string website = webTemp.substr(0,webEnd);
            if(website.find("http") == string::npos) {
                string url = "(\"https://wwwnc.cdc.gov";
                string endQuote = "\") ";
                website.insert(0,url);
                website.insert(website.length(),endQuote);
            } else {
                string beginQuote = "(\"";
                string endQuote = "\") ";
                website.insert(0,beginQuote);
                website.insert(website.length(),endQuote);
            }
            line.replace(begin,length,website);
            search++;
        }
    }

    return line;

}

// Read and write CDC file
void readWriteFileCDC() {

    // Variables to read and write from cdc text file
    string in_file_name = "data/rabies-cdc.txt";
    string out_file_name = "test/rabies-cdc-output.txt";
	string line;

    ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {

            // Content statistics
            // How many lines, words, and characters in input file
            int lineCount = 0;
            int wordCount = 0;
            int charCount = 0;
            int allCharCount = 0;

            // How many lines, words, and characters in output file
            int outLineCount = 0;
            int outWordCount = 0;
            int outCharCount = 0;
            int outAllCharCount = 0;

            while (getline(in_myfile, line)) {

                // Counting lines in input file
                lineCount++;

                // Counting characters in input file
                charCount = charCount + CharCounting(line);
                allCharCount = allCharCount + AllCharCounting(line);

                // Counting words in input file
                wordCount = wordCount + WordCounting(line);

                // Each line is a specific content
                // Find and printing the title
                if(line.find("<title>") != string::npos && line.find("|") != string::npos) {

                    // Find title
                    int begin = line.find(">");
                    string titleTemp = line.substr(begin + 1);
                    int end = titleTemp.find("<");
                    string fullTitle = titleTemp.substr(0,end);
                    int finalEnd = fullTitle.find("|");
                    string title = fullTitle.substr(0,finalEnd);

                    // Print title
                    out_myfile << title << "\n";

                    // Output content statics
                    outLineCount++;
                    outWordCount = outWordCount + WordCounting(title);
                    outCharCount = outCharCount + CharCounting(title);
                    outAllCharCount = outAllCharCount + AllCharCounting(title);
                }

                // Finding and printing headers
                if(line.find("<div>") != string::npos && line.find("h3") != string::npos) {

                        // Find header
                        int lineBegin = line.find("3");// Each header has h3
                        string newLine = line.substr(lineBegin + 1);
                        int headerBegin = newLine.find(">");
                        string tempHeader = newLine.substr(headerBegin + 1);
                        int headerEnd = tempHeader.find("<");
                        string header = tempHeader.substr(0,headerEnd);

                        // Replace special characters
                        header = replacingSpecialChar(header);

                        // Print header
                        out_myfile << "\n\t*" << header << "*\n";// indent once with asteriks

                        // Output content statics
                        outLineCount = outLineCount + 2;// for blank lines
                        outWordCount = outWordCount + WordCounting(header);
                        outCharCount = outCharCount + CharCounting(header);
                        outAllCharCount = outAllCharCount + AllCharCounting(header);

                }

                // Finding and printing paragraphs
                if(line.find("<p>") != string::npos && line.find("div") == string::npos
                    && line.find("id=") == string::npos) {

                    // Create count variables for paragraphs
                    int testWordCount;
                    int testCharCount;
                    int paragraphCharCount;
                    int paragraphWordCount;

                    // Find sub-headers and paragraphs
                    // This paragraph is a sub-header with "<strong>"
                    if(line.find("<strong>") != string::npos) {

                        // Find paragraph
                        int lineBegin = line.find("g");
                        string newLine = line.substr(lineBegin + 1);
                        int pgraphBegin = newLine.find(">");
                        string tempPgraph = newLine.substr(pgraphBegin + 1);
                        int pgraphEnd = tempPgraph.find("<");
                        string paragraph = tempPgraph.substr(0,pgraphEnd);

                        // If there are more texts with the sub-header
                        int moreBegin = tempPgraph.find(">");
                        string tempExtra = tempPgraph.substr(moreBegin + 1);
                        int moreEnd = tempExtra.find("<");
                        string extra = tempExtra.substr(0,moreEnd);

                        // Replace special characters
                        paragraph = replacingSpecialChar(paragraph);
                        extra = replacingSpecialChar(extra);

                        // Print sub-headers and extra texts if they exist
                        if(extra != " " && extra != "\n" && extra != "\t" && extra != "") {
                            out_myfile << "\t\t" << paragraph << extra << "\n";// indent two times
                            outLineCount++;// for extra
                            outWordCount = outWordCount + WordCounting(extra);
                            outCharCount = outCharCount + CharCounting(extra);
                            outAllCharCount = outAllCharCount + AllCharCounting(extra);
                        } else {
                            out_myfile << "\n\t\t\t" << paragraph << "\n\n";// indent three times
                            outLineCount = outLineCount + 3;// for blank lines
                        }

                        // Output content statics
                        outWordCount = outWordCount + WordCounting(paragraph);
                        outCharCount = outCharCount + CharCounting(paragraph);
                        outAllCharCount = outAllCharCount + AllCharCounting(paragraph);

                    } else {

                        // Find paragraphs
                        int pgraphBegin = line.find(">");
                        string tempPgraph = line.substr(pgraphBegin + 1);
                        int pgraphEnd = tempPgraph.find("</p>");
                        string paragraph = tempPgraph.substr(0,pgraphEnd);

                        int spaceCount = 0;// Count spaces to cut long paragraphs into multiple lines
                        string testParagraph;// New string to hold paragraphs

                        // Process of making new lines and adding to the new paragraph
                        for(int i=0; i<paragraph.length(); i++) {
                            if(paragraph.at(i) == ' ')
                                spaceCount++;
                            if(spaceCount == 15) {
                                testParagraph += "\n\t";
                                spaceCount = 0;
                            }
                            testParagraph += paragraph.at(i);
                        }

                        // Replace special characters
                        testParagraph = replacingSpecialChar(testParagraph);

                        // look for websites
                        testParagraph = checkingCDCWebsites(testParagraph);

                        // Count lines
                        int counting = 1; // first line
                        for(int i=0; i<testParagraph.length(); i++) {
                            if(testParagraph.at(i) == '\n') 
                                counting ++;
                        }

                        outLineCount =  outLineCount + counting;

                        // Print paragraph
                        out_myfile << "\t\t" << testParagraph << "\n";

                        // Output content statics
                        outWordCount = outWordCount + WordCounting(testParagraph);
                        outCharCount = outCharCount + CharCounting(testParagraph);
                        outAllCharCount = outAllCharCount + AllCharCounting(testParagraph);

                    }



                }

                // Finding Lists
                if(line.find("<li>") != string::npos && line.find("</li>") != string::npos) {

                    // Get list
                    int listBegin = line.find(">");
                    string tempList = line.substr(listBegin + 1);
                    int listEnd = tempList.find("</li>");
                    string list = tempList.substr(0,listEnd);

                    // Replace special characters
                    list = replacingSpecialChar(list);

                    // look for websites
                    list = checkingCDCWebsites(list);

                    // Print list
                    out_myfile << "\t\t\t-" << list << "\n";// Lists have a dash

                    // Output content statics
                    outLineCount++;
                    outWordCount = outWordCount + WordCounting(list);
                    outCharCount = outCharCount + CharCounting(list);
                    outAllCharCount = outAllCharCount + AllCharCounting(list);

                }

            }

            // Print input results at the end of file
            out_myfile << "\n---Input File Statistics---" << "\n\tTotal Input Lines = "
                    << lineCount << "\n\tTotal Input Words = " << wordCount
                    << "\n\tTotal Input Characters (not including spaces) = " << charCount
                    << "\n\tTotal Input Characters (including spaces) = " << allCharCount;

            // Print output results at the end of file
            out_myfile << "\n\n---Output File Statistics---" << "\n\tTotal Output Lines = "
                    << outLineCount << "\n\tTotal Input Words = " << outWordCount
                    << "\n\tTotal Output Characters (not including spaces) = " << outCharCount
                    << "\n\tTotal Input Characters (including spaces) = " << outAllCharCount;

        } else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

        // Close input file
		in_myfile.close();
    } else
		cout << "Unable to open input file - " << in_file_name << endl;

}

// Reaading and writing webmd file
void readWriteFileWebmd() {
    
    // Variables to read and write from webmd text file
    string in_file_name = "data/rabies-webmd.txt";
    string out_file_name = "test/rabies-webmd-output.txt";
	string line;

    ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);
	if (in_myfile.is_open()) {
		if (out_myfile.is_open()) {

            // Content statistics
            // How many lines, words, and characters in input file
            int lineCount = 0;
            int wordCount = 0;
            int charCount = 0;
            int allCharCount = 0;

            // How many lines, words, and characters in output file
            int outLineCount = 0;
            int outWordCount = 0;
            int outCharCount = 0;
            int outAllCharCount = 0;

            while (getline(in_myfile, line)) {

                // Counting lines in input file
                lineCount++;

                // Counting characters in input file
                charCount = charCount + CharCounting(line);
                allCharCount = allCharCount + AllCharCounting(line);

                // Counting words in input file
                wordCount = wordCount + WordCounting(line);

                // Find and printing the title
                if(line.find("<title>") != string::npos) {

                    // Find title
                    int begin = line.find(">");
                    string titleTemp = line.substr(begin + 1);
                    int end = titleTemp.find("<");
                    string title = titleTemp.substr(0,end);

                    // Print title to output file
                    out_myfile << title << "\n";

                    // Output content statistics for title 
                    outLineCount++;
                    outWordCount = outWordCount + WordCounting(title);
                    outCharCount = outCharCount + CharCounting(title);
                    outAllCharCount = outAllCharCount + AllCharCounting(title);
                }

                // Find main header
                if(line.find("<h1>") != string::npos) {

                    // Find main header
                    int begin = line.find("<h1>");
                    string temp = line.substr(begin + 4);
                    int end = temp.find("<");
                    string mainHeader = temp.substr(0,end);

                    // Print main header to output file
                    out_myfile << "\n\t*" << mainHeader << "*\n";

                    // Output content statistics for header 
                    outLineCount = outLineCount + 2;// plus empty line
                    outWordCount = outWordCount + WordCounting(mainHeader);
                    outCharCount = outCharCount + CharCounting(mainHeader);
                    outAllCharCount = outAllCharCount + AllCharCounting(mainHeader);
                }

                // The line containing the sections is one long line
                // Using the while loop find each section and then find
                // the paragraphs, headers, and lists
                // Count sections
                int sectionCount = 0;// Amount of sections
                for(int i=0; i<line.length(); i++) { // Find section amount
                    if(line.at(i) == '<' && line.at(i+1) == 's' && line.at(i+2) == 'e') 
                        sectionCount++;
                }
                int search = 0;// Amount of times to search for sections
                
                // Find and look through each section for content
                while(search < sectionCount) {// Goes until there are no more sections
                    if(line.find("<section>") != string::npos) {
                        int begin = line.find("<section>");
                        string sectionTemp = line.substr(begin + 9);
                        int end = sectionTemp.find("</section>");
                        string section = sectionTemp.substr(0,end);// Each section

                        // Finding the content in each section using while loops
                        // Find and replace websites with just the urls and associated word(s)
                        while(section.find("<a") != string::npos) {
                            int begin = section.find("<a");
                            int end = section.find("</a>");
                            int length = 0;
                            for(int i=begin; i<end+1; i++) {
                                length++;
                            }
                            length = length + 3;
                            string temp = section.substr(begin+1);
                            int tempEnd = temp.find("<");
                            string newLine = temp.substr(0,tempEnd);
                            int webBegin = newLine.find("\"h");
                            string webTemp = newLine.substr(webBegin+1);
                            int webEnd = webTemp.find("\"");
                            string website = webTemp.substr(0,webEnd);
                            string beginQuote = "(\"";
                            string endQuote = "\") ";
                            int wBegin = newLine.find(">");
                            string tempWord = newLine.substr(wBegin+1);
                            int wEnd = tempWord.find("<");
                            string word = tempWord.substr(0,wEnd);
                            website.insert(0,beginQuote);
                            website.insert(website.length(),endQuote);
                            website.insert(website.length(),word);
                            section.replace(begin,length,website);
                        }

                        // Find and print headers
                        while(section.find("<h2") != string::npos) {
                            int begin = section.find("<h2");
                            int end = section.find("</h2>");
                            int hBegin = section.find(">");
                            string temp = section.substr(hBegin+1);
                            int hEnd = temp.find("<");
                            string header = temp.substr(0,hEnd);

                            //Print headers and erase
                            out_myfile << "\n\t*" << header << "*\n";

                            // Output content statistics for header 
                            outLineCount = outLineCount + 2;
                            
                            outWordCount = outWordCount + WordCounting(header);
                            outCharCount = outCharCount + CharCounting(header);
                            outAllCharCount = outAllCharCount + AllCharCounting(header);

                            section.erase(begin,end+5);// erase header from line
                        }

                        // Find and print Pragraphs
                        while(section.find("<p>") != string::npos) {
                            int pBegin = section.find("<p>");
                            string newSec = section.substr(pBegin+3);
                            int pEnd = newSec.find("</p>");
                            string paragraph = newSec.substr(0,pEnd);

                            // Cutting paragraph to fill mutliple lines
                            string newParagraph;
                            int spaceCount = 0;
                            for(int i=0; i<paragraph.length(); i++) {
                                if(paragraph.at(i) == ' ')
                                    spaceCount++;
                                if(spaceCount == 15) {
                                    newParagraph += "\n\t";
                                    spaceCount = 0;
                                }
                                newParagraph += paragraph.at(i);
                            }

                            // Finding special characters
                            if(newParagraph.find("<br />") != string::npos) {// Break character
                                int begin = newParagraph.find("<");
                                string replace = "\n\t";
                                newParagraph.replace(begin,6,replace);
                            }

                            //Print paragraphs and erase
                            out_myfile << "\t\t" << newParagraph << "\n";

                            // Count lines
                            int counting = 1; // first line
                            for(int i=0; i<newParagraph.length(); i++) {
                                if(newParagraph.at(i) == '\n') 
                                    counting ++;
                            }

                            outLineCount =  outLineCount + counting;

                            // Output content statistics for paragraph
                            outWordCount = outWordCount + WordCounting(paragraph);
                            outCharCount = outCharCount + CharCounting(paragraph);
                            outAllCharCount = outAllCharCount + AllCharCounting(paragraph);

                            section.erase(pBegin,pEnd+4);// erase paragraph from line
                        }

                        // Find and print lists
                        while(section.find("<li>") != string::npos) {

                            int begin = section.find("<li>");
                            int end = section.find("</li>");
                            end = end + 5;// add the characters from </li>
                            int lBegin = section.find("<li>");
                            string temp = section.substr(lBegin+4);
                            int lEnd = temp.find("</li");
                            string list = temp.substr(0,lEnd);

                            //Print headers and erase
                            out_myfile << "\t\t\t-" << list << "\n";

                            // Output content statistics for list 
                            outLineCount++;
                            outWordCount = outWordCount + WordCounting(list);
                            outCharCount = outCharCount + CharCounting(list);
                            outAllCharCount = outAllCharCount + AllCharCounting(list);

                            section.erase(begin,end-begin);// erase list from line
                        }

                        // Erase current section from the long line
                        line.erase(begin,end+10);
                    }

                    // Increase search after each section is found
                    search++;
                }
            }

            // Print input results at the end of file
            out_myfile << "\n---Input File Statistics---" << "\n\tTotal Input Lines = "
                    << lineCount << "\n\tTotal Input Words = " << wordCount
                    << "\n\tTotal Input Characters (not including spaces) = " << charCount
                    << "\n\tTotal Input Characters (including spaces) = " << allCharCount;

            // Print output results at the end of file
            out_myfile << "\n\n---Output File Statistics---" << "\n\tTotal Output Lines = "
                    << outLineCount << "\n\tTotal Input Words = " << outWordCount
                    << "\n\tTotal Output Characters (not including spaces) = " << outCharCount
                    << "\n\tTotal Input Characters (including spaces) = " << outAllCharCount;

        } else {
			cout << "Unable to open output file - " << out_file_name << endl;
		} // end-if

        // Close input file
		in_myfile.close();
    } else
		cout << "Unable to open input file - " << in_file_name << endl;
    
}

int main()
{
    // Call the read and write functions
    readWriteFileWebmd();
    readWriteFileCDC();

    return 0;

}