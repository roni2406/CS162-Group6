#include <iostream>
#include <fstream>
#include "Course.h"
using namespace std;

void AddACourse(course newCourse, char* filename, ofstream& fout)
{
	cout << "You have created a new Course. Please enter the name of Course: ";
	cin.get(newCourse.courseName, '\n');
	cin.ignore(100, '\n');
	cout << "Course ID : ";
	cin.get(newCourse.courseID, '\n');
	cin.ignore(100, '\n');
	cout << "Course's teacher : ";
	cin.get(newCourse.teacherName, '\n');
	cin.ignore(100, '\n');
	cout << "Number of Course Credit : ";
	cin >> newCourse.numOfCre;
	cout << "Course will occur on : ";
	cin.get(newCourse.dayofweek, '\n');
	cin.ignore(100, '\n');
	cout << "Course will begin at : ";
	cin.get(newCourse.sessionHour, '\n');
	cin.ignore(100, '\n');
	fout.open(filename, ios::app);
	fout << "Course : " << newCourse.courseName << '\n'
		<< "ID : " << newCourse.courseID << '\n'
		<< "Teacher : " << newCourse.teacherName << '\n'
		<< "Number of Credit : " << newCourse.numOfCre << '\n'
		<< "Course Day : " << newCourse.dayofweek << '\n'
		<< "Session Hours : " << newCourse.sessionHour << '\n';
	fout.close();
}