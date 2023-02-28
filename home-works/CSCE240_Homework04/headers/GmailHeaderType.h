/*
 * GmailHeaderType.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Azariah Laulusa
 */

#ifndef GMAILHEADERTYPE_H_
#define GMAILHEADERTYPE_H_

#include "BaseEmailHeaderType.h"

class GmailHeaderType: public BaseEmailHeaderType {
private:
	string deliveredTo;
	string xGoogleSmtpSource;

public:
	GmailHeaderType();
	virtual ~GmailHeaderType();

	string getDeliveredTo();
	string getXGoogleSmtpSource();

	void setDeliveredTo(string);
	void setXGoogleSmtpSource(string);

	bool parseFile(string);
};

#endif /* GMAILHEADERTYPE_H_ */