/*
 * Regex.h
 *
 *  Created on: March 17, 2023
 *      Author: Azariah Laulusa
 */

#ifndef REGEX_H_
#define REGEX_H_

#include <string>

using namespace std;

class Regex {
protected:
	string match;

public:
	Regex();
	virtual ~Regex();

    string getMatch();

	void setMatch(string);
	
	void reset();
};

#endif /* REGEX_H_ */