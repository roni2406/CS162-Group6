#include <iostream>
#include <fstream>
#include "Date.h"
#include "scoreboard.h"
#include "users.h"
#include "Class.h"
using namespace std;

//person
void person::inputAPerson(char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID) {
	firstName = _strdup(first_name);
	lastName = _strdup(last_name);
	gender = Gender;
	dob.inputADateWithChar(DoB);
	socialID = _strdup(social_ID);
}
void person::inputPersonsWithCSVFile(ifstream& fin) {
	lastName = new char[100];
	fin.get(lastName, 100, ',');

	firstName = new char[100];
	fin.ignore(100, ',');
	fin.get(firstName, 100, ',');

	char* tmp = new char[100];
	fin.ignore(100, ',');
	fin.get(tmp, 100, ',');
	if (strcmp(tmp, (char*)"Male") == 0) gender = 1;
	else gender = 0;
	delete[] tmp;

	char* dateofBirth = new char[20];
	fin.ignore(100, ',');
	fin.get(dateofBirth, 100, ',');
	dob.inputADateWithChar(dateofBirth);
	delete[] dateofBirth;

	socialID = new char[100];
	fin.ignore(100, ',');
	fin.get(socialID, 100, '\n');
}
void person::outputAPersonToFile(ofstream& fout) {
	fout << lastName << "," << firstName << ",";
	if (gender == 1) fout << "male,";
	else fout << "female,";
	dob.outputADateToFile(fout);
	fout << "," << socialID;
}

//student
void student::inputAStudent(ifstream& fin, char* student_id,
	char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID) {
	stuID = _strdup(student_id);
	Student.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
}

void student::inputStudentsWithCSVFile(ifstream& fin) {
	fin >> No;
	stuID = new char[100];
	fin.ignore(100, ',');
	fin.get(stuID, 100, ',');

	fin.ignore(100, ',');
	Student.inputPersonsWithCSVFile(fin);
}

void student::outputAStudentToFile(char* filename) {
	ifstream fin;
	fin.open(filename);
	int cnt = 0;
	fin.get();
	while (!fin.eof()) {
		cnt++;
		fin.ignore(200, '\n');
	}
	No = cnt + 1;
	fin.close();
	ofstream fout;
	fout.open(filename, ios::app);
	if (No != 1) fout << endl;
	fout << No << ",";
	fout << stuID << ",";
	Student.outputAPersonToFile(fout);
	fout.close();
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
bool addAStudentToClass(char* className, char* first_name, char* last_name, char* Gender, char* DoB,
	char* social_ID, char* student_id) {
	bool gender;
	if (strcmp(Gender, "Male") == 0) {
		gender = 1;
	}
	else gender = 0;
	string fileName = "../data/Classes/" + string(className) + ".txt";
	ifstream fin;
	fin.open(fileName);
	student s;
	s.inputAStudent(fin, student_id, first_name, last_name, gender, DoB, social_ID);
	fin.close();

	account studentAcc;
	studentAcc.userName = _strdup(student_id);
	studentAcc.password = _strdup(DoB);
	addinfo(studentAcc, (char*)"../data/student_account.txt");

	ofstream fout;
	fout.open(fileName, ios::app);
	s.outputAStudentToFile((char*)fileName.c_str());
	fout.close();
	return true;
}

//void addAStaff(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
//	char* social_ID, char* staff_id) {
//
//	staff s;
//	person a;
//	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
//	s.inputAStaff(staff_id, a);
//
//	ofstream fout;
//	fout.open(filename, ios::app);
//	s.outputAStaffToFile(fout);
//	fout.close();
//}

void addStudentsWithCSV(char* fileNameIn, char* fileNameOut) {
	ifstream fin;
	fin.open(fileNameIn);
	string fileNameOutAddress = "../data/Classes/" + string(fileNameOut) + ".txt";
	char* fileNameOutAddressChar = new char[100];
	for (int i = 0; i < fileNameOutAddress.size(); i++) {
		fileNameOutAddressChar[i] = fileNameOutAddress[i];
	}
	fileNameOutAddressChar[fileNameOutAddress.size()] = '\0';
	while (!fin.eof()) {
		student s;
		s.inputStudentsWithCSVFile(fin);
		account stuAcc;
		stuAcc.userName = _strdup(s.stuID);
		stuAcc.password = _strdup(dateToChar(s.Student.dob));
		addinfo(stuAcc, (char*)"../data/student_account.txt");
		s.outputAStudentToFile(fileNameOutAddressChar);
	}
	delete[] fileNameOutAddressChar;
	fin.close();
}

bool checkdata_FileName(char* fileNameIn)
{
	int n = strlen(fileNameIn);
	if (fileNameIn[n - 4] == '.' && fileNameIn[n - 3] == 'c'
		&& fileNameIn[n - 2] == 's' && fileNameIn[n - 1] == 'v') return true;
	else return false;
}
