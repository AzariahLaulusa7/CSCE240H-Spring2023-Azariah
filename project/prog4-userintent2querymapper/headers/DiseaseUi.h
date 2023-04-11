/*
 * DiseaseUi.h
 *
 *  Created on: April 6, 2023
 *      Author: Azariah Laulusa
 */

#ifndef DISEASEUI_H_
#define DISEASEUI_H_

#include <string>

using namespace std;

class DiseaseUi {
protected:
    string i1;
    string i6;
    string i12;

public:
	DiseaseUi();
	virtual ~DiseaseUi();

    string getI1();
    string getI6();
	string getI12();
	

    void setI1();
	void setI12();
	
    string readWebMDFile(string);
    string readCDCFile(string);

    string tag();

};

#endif /* DISEASEDATA_H_ */