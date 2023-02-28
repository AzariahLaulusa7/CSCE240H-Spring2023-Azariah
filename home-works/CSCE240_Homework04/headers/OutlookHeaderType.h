/*
 * OutlookHeaderType.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Azariah Laulusa
 */

#ifndef OUTLOOKHEADERTYPE_H_
#define OUTLOOKHEADERTYPE_H_

#include "BaseEmailHeaderType.h"

class OutlookHeaderType: public BaseEmailHeaderType {
private:
	string xMsHasAttach;
	string xMsExchangeOrganizationScl;
    string contentLanguage;
    string acceptLanguage;
    string references;
    string threadIndex;
    string threadTopic;
    string authenticationResults;

public:
	OutlookHeaderType();
	virtual ~OutlookHeaderType();

	string getXMsHasAttach();
	string getXMsExchangeOrganizationScl();
    string getContentLanguage();
    string getAcceptLanguage();
    string getReferences();
    string getThreadIndex();
    string getThreadTopic();
    string getAuthenticationResults();

	void setXMsHasAttach(string);
	void setXMsExchangeOrganizationScl(string);
    void setContentLanguage(string);
    void setAcceptLanguage(string);
    void setReferences(string);
    void setThreadIndex(string);
    void setThreadTopic(string);
    void setAuthenticationResults(string);

    bool parseFile(string);
};

#endif /* OUTLOOKHEADERTYPE_H_ */