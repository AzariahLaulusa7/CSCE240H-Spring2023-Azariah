/*
 * WebmdData.h
 *
 *  Created on: March 2, 2023
 *      Author: Azariah Laulusa
 */

#ifndef WEBMDDATA_H_
#define WEBMDDATA_H_

#include "DiseaseData.h"

class WebmdData: public DiseaseData {
private:
	string i7;
	string i8;
	string i9;
    string i10;
	string i11;

public:
	WebmdData();
	virtual ~WebmdData();

	string getI7();
	string getI8();
	string getI9();
    string getI10();
	string getI11();

	void setI7(string);
	void setI8(string);
	void setI9(string);
    void setI10(string);
	void setI11(string);

	bool webmdParse(string);
};

#endif /* WEBMDDATA_H_ */