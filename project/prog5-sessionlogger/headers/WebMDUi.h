/*
 * WebMDUi.h
 *
 *  Created on: April 6, 2023
 *      Author: Azariah Laulusa
 */

#ifndef WEBMDUI_H_
#define WEBMDUI_H_

#include "DiseaseUi.h"

class WebMDUi: public DiseaseUi {
private:
    string i7;
	string i8;
	string i9;
    string i10;
    string i11;

public:
	WebMDUi();
	virtual ~WebMDUi();

    string getI7();
	string getI8();
	string getI9();
    string getI10();
	string getI11();

	void setI7();
	void setI8();
	void setI9();
    void setI10();
	void setI11();

	string tagWebMD();
};

#endif /* WEBMDUI_H_ */