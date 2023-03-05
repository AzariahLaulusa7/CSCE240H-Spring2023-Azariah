/*
 * CDCData.h
 *
 *  Created on: March 2, 2023
 *      Author: Azariah Laulusa
 */

#ifndef CDCDATA_H_
#define CDCDATA_H_

#include "DiseaseData.h"

class CDCData: public DiseaseData {
private:
    string i2;
	string i3;
	string i4;
    string i5;

public:
	CDCData();
	virtual ~CDCData();

    string getI2();
    string getI3();
	string getI4();
    string getI5();

    void setI2(string);
	void setI3(string);
	void setI4(string);
    void setI5(string);

	bool cdcParse(string);
};

#endif /* CDCDATA_H_ */