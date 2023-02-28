/*
 * BaseEmailHeaderType.cpp
 *
 *  Created on: Feb , 2023
 *      Author: Azariah Laulusa
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "BaseEmailHeaderType.h"

BaseEmailHeaderType::BaseEmailHeaderType() {

    // default variables for base email header type
	partValue = "N/A";
    messageHeader = "N/A";
    partName = "N/A";
	from = "N/A";
	to = "N/A";
	date = "N/A";
    contentType = "N/A";
    contentTransferEncoding = "N/A";
    messageId = "N/A";
    cc = "N/A";
    received = "N/A";
    subject = "N/A";
    replyTo = "N/A";
    mimeVersion = "N/A";

}

BaseEmailHeaderType::~BaseEmailHeaderType() {
	// TODO Auto-generated destructor stub

}

// getters
string BaseEmailHeaderType::getCC() {
	return cc;
}
string BaseEmailHeaderType::getContentTransferEncoding() {
    return contentTransferEncoding;
}
string BaseEmailHeaderType::getContentType() {
    return contentType;
}
string BaseEmailHeaderType::getDate() {
    return date;
}
string BaseEmailHeaderType::getFrom() {
    return from;
}
string BaseEmailHeaderType::getMessageHeader() {
    return messageHeader;
}
string BaseEmailHeaderType::getMessageId() {
    return messageId;
}
string BaseEmailHeaderType::getMimeVersion() {
    return mimeVersion;
}
string BaseEmailHeaderType::getPartName() {
    return partName;
}
string BaseEmailHeaderType::getPartValue() {
    return partValue;
}
string BaseEmailHeaderType::getReceived() {
    return received;
}
string BaseEmailHeaderType::getReplyTo() {
    return replyTo;
}
string BaseEmailHeaderType::getSubject() {
    return subject;
}
string BaseEmailHeaderType::getTo() {
    return to;
}

// setters
void BaseEmailHeaderType::setCC(string type) {

    if(type.empty())
        return;
    cc = type;

}
void BaseEmailHeaderType::setContentTransferEncoding(string type) {

    if(type.empty())
        return;
    contentTransferEncoding = type;

}
void BaseEmailHeaderType::setContentType(string type) {

    if(type.empty())
        return;
    contentType = type;

}
void BaseEmailHeaderType::setDate(string type) {

    if(type.empty())
        return;
    date = type;

}
void BaseEmailHeaderType::setFrom(string type) {

    if(type.empty())
        return;
    from = type;

}
void BaseEmailHeaderType::setMessageHeader(string type) {

    if(type.empty())
        return;
    messageHeader = type;

}
void BaseEmailHeaderType::setMessageId(string type) {

    if(type.empty())
        return;
    messageId = type;

}
void BaseEmailHeaderType::setMimeVersion(string type) {

    if(type.empty())
        return;
    mimeVersion = type;

}
void BaseEmailHeaderType::setPartName(string type) {

    if(type.empty())
        return;
    partName = type;

}
void BaseEmailHeaderType::setPartValue(string type) {

    if(type.empty())
        return;
    partName = type;

}
void BaseEmailHeaderType::setReceived(string type) {

    if(type.empty())
        return;
    received = type;

}
void BaseEmailHeaderType::setReplyTo(string type) {

    if(type.empty())
        return;
    replyTo = type;

}
void BaseEmailHeaderType::setSubject(string type) {

    if(type.empty())
        return;
    subject = type;

}
void BaseEmailHeaderType::setTo(string type) {

    if(type.empty())
        return;
    to = type;

}

// Check file
bool BaseEmailHeaderType::checkFile(string file) {

    // Exception handling with file
    ifstream myfile(file);

    try {
        cout << "\n\nAccessing header file...\n\n" << endl; 

        if (myfile.is_open()) {

            while (!myfile.eof())
                myfile.get();

		    myfile.close();
        }

    } catch(exception& e) {
        cerr << "\n\n**Exception: file access**\n" << endl;
        cout << "\t" << e.what() << "\n\n" << endl;
        return false;
    }

    return true;
}