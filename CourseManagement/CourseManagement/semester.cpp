#include <iostream>
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

void semester::outputASemesterToCSVFile(char* filename) {
	ifstream fin;
	fin.open(filename);
	int numCourse = 0;
	while (!fin.eof()) {
		++numCourse;
		fin.ignore(500, '\n');
	}
	No = numCourse + 1;
	fin.close();
	ofstream fout;
	fout.open(filename, ios::app);
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
	char* filename = new char[100];
	filename = _strdup(school_year);
	strcat_s(filename, strlen(filename) + 13, (char*)"semester.csv");
	s.outputASemesterToCSVFile(filename);
	delete[] filename;
	return true;
}