#include <iostream>
#include <direct.h>
#include <fstream>
#include "schoolYear.h"
using namespace std;

void schoolYear::inputASchoolYear(char* year) {
	sYear = _strdup(year);
}

void schoolYear::createASchoolYear() {
    ofstream fout;
    fout.open("../data/schoolYear.txt", ios::app);
    fout << endl;
    fout << sYear;
    fout.close();

    string stringSchoolYear = string(sYear);
    if (_mkdir(("../data/" + stringSchoolYear).c_str()));
}

void createASchoolYear(char* schoolyear) {
    schoolYear s;
    s.inputASchoolYear(schoolyear);
    s.createASchoolYear();
}