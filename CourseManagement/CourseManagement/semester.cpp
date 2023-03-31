#include <iostream>
#include <direct.h>
#include <fstream>
#include "Date.h"
#include "schoolYear.h"
#include "semester.h"
using namespace std;

void semester::inputASemester(char* Year, char* start_date, char* end_date, char* number_of_course) {
	sYear.inputASchoolYear(Year);
	startDate.inputADateWithChar(start_date);
	endDate.inputADateWithChar(end_date);
	numOfCourse = atoi(number_of_course);
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
	fin >> numOfCourse;
	delete[] tmp;
}

void semester::outputASemesterToCSVFile(char* school_year) {
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
		if (_mkdir(("../data/" + (string)(school_year) + "/fall").c_str()));
		break;
	case 1:
		if (_mkdir(("../data/" + (string)(school_year) + "/summer").c_str()));
		break;
	case 2:
		if (_mkdir(("../data/" + (string)(school_year) + "/autumn").c_str()));
	}
	fin.close();
	ofstream fout;
	fout.open("../data/" + (string)(school_year)+"/Semester.csv", ios::app);
	if(numSemester != 0) fout << endl;
	fout << No << ",";
	startDate.outputADateToFile(fout);
	fout << ",";
	endDate.outputADateToFile(fout);
	fout << "," << numOfCourse;
	fout.close();
}

//check data
bool createASemester(char* school_year, char* start_date, char* end_date, char* number_of_course) {
	semester s;
	s.inputASemester(school_year, start_date, end_date, number_of_course);
	s.outputASemesterToCSVFile(school_year);
	return true;
}

int countSemester(char* school_year) {
	ifstream fin;
	fin.open("../data/" + (string)(school_year)+"semester.csv");
	int numSemester = 0;
	fin.get();
	while (!fin.eof()) {
		++numSemester;
		fin.ignore(500, '\n');
	}
	return numSemester;
}

semester* getSemester(char* school_year) {
	int numOfSemester = countSemester(school_year);
	semester* semesterArr = new semester[5];
	ifstream fin;
	fin.open("../data/" + (string)(school_year)+"semester.csv");
	for (int i = 0; i < numOfSemester; i++) {
		semesterArr[i].inputASemesterWithCSVFile(fin);
	}
	fin.close();
	return semesterArr;
}