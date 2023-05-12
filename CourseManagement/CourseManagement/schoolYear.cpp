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

    if (sYear.length() != 9 || sYear[4] != '-' || sYear <= Years[n - 1]) {
        delete[] Years;
        return false;
    }
    delete[] Years;

    char* s1 = new char[5];
    char* s2 = new char[5];
    for (int i = 0; i < 4; i++) {
        s1[i] = sYear[i];
        s2[i] = sYear[i + 5];
    }
    int year1 = atoi(s1);
    int year2 = atoi(s2);
    if (year2 - year1 != 1) {
        return false;
    }
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
        get[i] = new char[sYear[i].length() + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sYear[i].length(); j++)
            get[i][j] = (char)sYear[i][j];
        get[i][sYear[i].length()] = '\0';
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