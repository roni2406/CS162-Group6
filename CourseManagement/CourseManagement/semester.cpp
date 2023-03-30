#include <iostream>
#include <direct.h>
#include <fstream>
#include "Date.h"
#include "schoolYear.h"
#include "semester.h"
using namespace std;

void semester::inputASemester(char* Year, char* start_date, char* end_date, int number_of_course) {
	sYear.inputASchoolYear(Year);
	startDate.inputADateWithChar(start_date);
	endDate.inputADateWithChar(end_date);
	numOfCourse = number_of_course;
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
	fin.open("../data/" + (string)(school_year) + "semester.csv");
	int numCourse = 0;
	fin.get();
	while (!fin.eof()) {
		++numCourse;
		fin.ignore(500, '\n');
	}
	No = numCourse + 1;
	switch (numCourse) {
	case 0:
		if (_mkdir(("../data/" + (string)(school_year) + "fall").c_str()));
		break;
	case 1:
		if (_mkdir(("../data/" + (string)(school_year) + "summer").c_str()));
		break;
	case 2:
		if (_mkdir(("../data/" + (string)(school_year) + "autumn").c_str()));
	}
	fin.close();
	ofstream fout;
	fout.open(school_year, ios::app);
	if(numCourse != 0) fout << endl;
	fout << No << ",";
	startDate.outputADateToFile(fout);
	fout << ",";
	endDate.outputADateToFile(fout);
	fout << "," << numOfCourse;
}

//check data
bool createASemester(char* school_year, char* start_date, char* end_date, int number_of_course) {
	semester s;
	s.inputASemester(school_year, start_date, end_date, number_of_course);
	s.outputASemesterToCSVFile(school_year);
	return true;
}

int countSemester(char* school_year) {
	ifstream fin;
	fin.open("../data/" + (string)(school_year)+"semester.csv");
	int numCourse = 0;
	fin.get();
	while (!fin.eof()) {
		++numCourse;
		fin.ignore(500, '\n');
	}
	return numCourse;
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