 /*
 * CDCUi.h
 *
 *  Created on: April 6, 2023
 *      Author: Azariah Laulusa
 */

#ifndef CDCUI_H_
#define CDCUI_H_

#include "DiseaseUi.h"

class CDCUi: public DiseaseUi {
private:
    string i2;
	string i3;
	string i4;
    string i5;
    string i9;

public:
	CDCUi();
	virtual ~CDCUi();

    string getI2();
    string getI3();
	string getI4();
    string getI5();

    void setI2();
	void setI3();
	void setI4();
    void setI5();

    string tagCDC();
};

#endif /* CDCUI_H_ */