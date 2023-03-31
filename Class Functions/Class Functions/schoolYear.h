#include <iostream>
#include <fstream>
using namespace std;

#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

struct schoolYear {
	string sYear;

	bool checkdata();
	void inputASchoolYear(char* year);
	void createASchoolYear();
};

void getSchoolYear(string* sYear, int& n);

// front end use
bool createASchoolYear(char* schoolyear);
int countSchoolYear();
char** getSchoolYearArr();
// schoolyear must have 8 chars and must larger than prev year. Otherwise, return false.

#endif