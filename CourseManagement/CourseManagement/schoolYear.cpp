#include <iostream>
#include <direct.h>
#include <fstream>
#include <string>
#include "schoolYear.h"
using namespace std;

void schoolYear::inputASchoolYear(char* year) {
	sYear = string(year);
}

bool schoolYear::checkdata() {
    ifstream fin;
    fin.open("../data/schoolYear.txt");
    string* Years = new string[100];
    int n;
    getSchoolYear(Years, n, fin);
    fin.close();

    if (sYear.length() != 9 || sYear <= Years[n - 1]) {
        delete[] Years;
        return false;
    }
    delete[] Years;
    return true;
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

void getSchoolYear(string* sYear, int& n, ifstream& fin) {
    n = 0;
    while (!fin.eof()) {
        getline(fin, sYear[n++]);
    }
}

bool createASchoolYear(char* schoolyear) {
    schoolYear s;
    s.inputASchoolYear(schoolyear);
    if (s.checkdata()) {
        s.createASchoolYear();
        return true;
    }
    return false;
}