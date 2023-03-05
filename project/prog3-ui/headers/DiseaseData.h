/*
 * DiseaseData.h
 *
 *  Created on: Marhc 2, 2023
 *      Author: Azariah Laulusa
 */

#ifndef DISEASEDATA_H_
#define DISEASEDATA_H_

#include <string>

using namespace std;

class DiseaseData {
protected:
    string i1;
    string i12;

public:
	DiseaseData();
	virtual ~DiseaseData();

    string getI1();
	string getI12();
	

    void setI1(string);
	void setI12(string);
	
    string printEverything();
    bool mixParse();
    bool checkFile(string);

};

#endif /* DISEASEDATA_H_ */