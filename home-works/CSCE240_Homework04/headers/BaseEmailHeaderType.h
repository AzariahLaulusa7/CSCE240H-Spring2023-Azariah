/*
 * BaseEmailHeaderType.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Azariah Laulusa
 */

#ifndef BASEEMAILHEADERTYPE_H_
#define BASEEMAILHEADERTYPE_H_

#include <string>

using namespace std;

class BaseEmailHeaderType {
protected:
    string partValue;
    string messageHeader;
    string partName;
	string from;
	string to;
	string date;
    string contentType;
    string contentTransferEncoding;
    string messageId;
    string cc;
    string received;
    string subject;
    string replyTo;
    string mimeVersion;

public:
	BaseEmailHeaderType();
	virtual ~BaseEmailHeaderType();

    string getPartValue();
	string getMessageHeader();
	string getPartName();
	string getFrom();
	string getTo();
	string getDate();
    string getContentType();
    string getContentTransferEncoding();
    string getMessageId();
    string getCC();
    string getReceived();
    string getSubject();
    string getReplyTo();
    string getMimeVersion();

    void setMessageHeader(string);
	void setPartName(string);
	void setFrom(string);
	void setTo(string);
	void setDate(string);
    void setContentType(string);
    void setContentTransferEncoding(string);
    void setMessageId(string);
    void setCC(string);
    void setReceived(string);
    void setSubject(string);
    void setReplyTo(string);
    void setMimeVersion(string);
    void setPartValue(string);

    bool checkFile(string);
};

#endif /* BASEEMAILHEADERTYPE_H_ */