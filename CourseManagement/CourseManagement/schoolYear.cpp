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
    string* Years = new string[100];
    int n;
    getSchoolYear(Years, n);

    if (sYear[4] != '-' || sYear.length() != 9 || sYear <= Years[n - 1]) {
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

void getSchoolYear(string* sYear, int& n) {
    ifstream fin;
    fin.open("../data/schoolYear.txt");
    n = 0;
    while (!fin.eof()) {
        getline(fin, sYear[n++]);
    }
}

char** changestrtochar(string* sYear) {
    int n = countSchoolYear();
    char** get = new char* [n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sYear[i].length(); j++)
            get[i][j] = (char)sYear[i][j];
    }
    return get;
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

int countSchoolYear() {
    string* Years = new string[100];
    int cnt;
    getSchoolYear(Years, cnt);
    delete[] Years;
    return cnt;
}

char** getSchoolYearArr() {
    string* schoolYearArr = new string[countSchoolYear()];
    int n;
    getSchoolYear(schoolYearArr, n);
    return changestrtochar(schoolYearArr);
}