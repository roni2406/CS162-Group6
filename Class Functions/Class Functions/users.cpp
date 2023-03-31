#include <iostream>
#include <fstream>
#include "Date.h"
#include "scoreboard.h"
#include "users.h"
using namespace std;

//person
void person::inputAPerson(char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID) {
	firstName = _strdup(first_name);
	lastName = _strdup(last_name);
	gender = Gender;
	dob.inputADateWithChar(DoB);
	socialID = _strdup(social_ID);
}

void person::outputAPersonToFile(ofstream& fout) {
	fout << firstName << "," << lastName << ",";
	if (gender == 1) fout << "male,";
	else fout << "female,";
	dob.outputADateToFile(fout);
	fout << "," << socialID;
}

void person::inputAPersonWithCSVFile(ifstream& fin) {
	fin.get(firstName, 100, ',');
	fin.ignore(100, ',');
	fin.get(lastName, 100, ',');

	char* tmp = new char[10];
	fin.ignore(100, ',');
	fin.get(tmp, 100, ',');
	if (strcmp(tmp, (char*)"male") == 0) gender = 1;
	else gender = 0;
	delete[] tmp;

	char* dateofBirth = new char[20];
	fin.ignore(100, ',');
	fin.get(dateofBirth, 100, ',');
	dob.inputADateWithChar(dateofBirth);
	delete[] dateofBirth;

	fin.ignore(100, ',');
	fin.get(socialID, 100, ',');
}

//student
void student::inputAStudent(ifstream& fin, char* student_id, person stu) {
	stuID = _strdup(student_id);
	Student = stu;
	stuAcc.userName = _strdup(stuID);
	stuAcc.password = (char*)"123";
}
void student::outputAStudentToFile(char* filename) {
	ifstream fin;
	fin.open(filename);
	int cnt = 0;
	while (!fin.eof()) {
		char* tmp = new char[200];
		cnt++;
		cin.get(tmp, 200, '\n');
		delete[] tmp;
	}
	No = cnt;
	fin.close();
	ofstream fout;
	fout.open(filename, ios::app);
	fout << endl << No << ",";
	Student.outputAPersonToFile(fout);
	fout << "," << stuID;
	fout.close();

	addinfo(stuAcc, (char*)"student_account", fout);
}
void student::inputAStudentWithCSVFile(ifstream& fin) {
	Student.inputAPersonWithCSVFile(fin);
	fin.ignore(100, ',');
	fin.get(stuID, 100, '\0');
}

//staff
void staff::inputAStaff(char* staff_id, person sta) {
	Staff = sta;
	staffID = _strdup(staff_id);
}
void staff::outputAStaffToFile(ofstream& fout) {
	fout << endl;
	Staff.outputAPersonToFile(fout);
	fout << "," << staffID;
}

//other
//filename is a file which data will be add to
void addAStudent(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
	char* social_ID, char* student_id) {

	ifstream fin;
	fin.open(filename);
	student s;
	person a;
	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
	s.inputAStudent(fin, student_id, a);
	fin.close();

	ofstream fout;
	fout.open(filename, ios::app);
	s.outputAStudentToFile(filename);
	fout.close();
}

void addAStaff(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
	char* social_ID, char* staff_id) {

	staff s;
	person a;
	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
	s.inputAStaff(staff_id, a);

	ofstream fout;
	fout.open(filename, ios::app);
	s.outputAStaffToFile(fout);
	fout.close();
}

void addStudentsWithCSV(char* fileNameIn, char* filenameOut) {
	ifstream fin;
	fin.open(fileNameIn);
	while (!fin.eof()) {
		student s;
		s.inputAStudentWithCSVFile(fin);
		s.outputAStudentToFile(filenameOut);
	}
	fin.close();
}