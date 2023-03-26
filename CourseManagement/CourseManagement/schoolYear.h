#include <iostream>
using namespace std;

#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

struct schoolYear {
	char* sYear;

	void inputASchoolYear(char* year);
	void createASchoolYear();
};

// front end use
void createASchoolYear(char* schoolyear);

#endif