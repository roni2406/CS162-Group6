#include <iostream>
#include <direct.h>
#include <fstream>
#include "Date.h"
#include "schoolYear.h"
#include "semester.h"
#include <string>
using namespace std;

void semester::inputASemester(char* Year, char* start_date, char* end_date) {
	sYear.inputASchoolYear(Year);
	startDate.inputADateWithChar(start_date);
	endDate.inputADateWithChar(end_date);
}
void semester::inputASemesterWithCSVFile(ifstream& fin) {
	fin >> No;
	char* tmp = new char[20];
	fin.ignore(100, ',');
	fin.get(tmp, 20, ',');
	startDate.inputADateWithChar(tmp);
	fin.ignore(100, ',');
	fin.get(tmp, 20, ',');
	endDate.inputADateWithChar(tmp);
	delete[] tmp;
}
void semester::outputASemesterToCSVFile(char* school_year) {
	ofstream fout;
	fout.open("../data/" + (string)(school_year)+"/Semester.csv", ios::app);
	fout.close();

	ifstream fin;
	fin.open("../data/" + (string)(school_year) + "/Semester.csv");
	int numSemester = 0;
	fin.get();
	while (!fin.eof()) {
		++numSemester;
		fin.ignore(500, '\n');
	}
	No = numSemester + 1;
	switch (numSemester) {
	case 0:
		if (_mkdir(("../data/" + (string)(school_year) + "/Fall").c_str()))
		break;
	case 1:
		if (_mkdir(("../data/" + (string)(school_year) + "/Summer").c_str()))
		break;
	case 2:
		if (_mkdir(("../data/" + (string)(school_year)+"/Autumn").c_str()));
	}
	fin.close();

	fout.open("../data/" + (string)(school_year)+"/Semester.csv", ios::app);
	if(numSemester != 0) fout << endl;
	fout << No << ",";
	startDate.outputADateToFile(fout);
	fout << ",";
	endDate.outputADateToFile(fout);
	fout.close();
}
bool semester::checkdata() {
	if (!startDate.checkdata() || !endDate.checkdata()) return false;
	return true;
}
bool createASemester(char* school_year, char* start_date, char* end_date) {
	if (!checkDateInput(start_date) || !checkDateInput(end_date)) return false;
	semester s;
	s.inputASemester(school_year, start_date, end_date);
	if (!s.checkdata()) return false;
	s.outputASemesterToCSVFile(school_year);
	return true;
}
int countSemester(char* school_year) {
	ofstream fout;
	fout.open("../data/" + (string)(school_year)+"/Semester.csv", ios::app);
	fout.close();

	ifstream fin;
	fin.open("../data/" + (string)(school_year)+ "/Semester.csv");
	int numSemester = 0;
	fin.get();
	while (!fin.eof()) {
		++numSemester;
		fin.ignore(500, '\n');
	}
	fin.close();
	return numSemester;
}
void getsemestername(char** semestername, int n) {
	const char* tmp1 = "Fall";
	const char* tmp2 = "Summer";
	const char* tmp3 = "Autumn";
	for (int i = 0; i < 3; ++i) {
		semestername[i] = new char[10];
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			for (int j = 0; j < strlen(tmp1); ++j) {
				semestername[i][j] = tmp1[j];
			}
			semestername[i][strlen(tmp1)] = '\0';
		}
		if (i == 1) {
			for (int j = 0; j < strlen(tmp2); ++j) {
				semestername[i][j] = tmp2[j];
			}
			semestername[i][strlen(tmp2)] = '\0';
		}
		if (i == 2) {
			for (int j = 0; j < strlen(tmp3); ++j) {
				semestername[i][j] = tmp3[j];
			}
			semestername[i][strlen(tmp3)] = '\0';
		}
	}
}
semester* getSemester(char* school_year) {
	int numOfSemester = countSemester(school_year);
	semester* semesterArr = new semester[5];
	ifstream fin;
	fin.open("../data/" + (string)(school_year)+"/Semester.csv");
	for (int i = 0; i < numOfSemester; i++) {
		semesterArr[i].inputASemesterWithCSVFile(fin);
	}
	fin.close();
	return semesterArr;
}