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

//student
void student::inputAStudent(int positionInList, char* student_id, person stu) {
	No = positionInList;
	stuID = student_id;
	Student = stu; // can use?
}
void student::outputAStudentToFile(ofstream& fout) {
	fout << endl << No << ",";
	Student.outputAPersonToFile(fout);
	fout << "," << stuID;
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

//front-end
void addAStudent(char* first_name, char* last_name, bool Gender, char* DoB,
	char* social_ID, int positionInList, char* student_id) {

	student s;
	person a;
	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
	s.inputAStudent(positionInList, student_id, a);

	ofstream fout;
	fout.open("../data/listOfStudent", ios::app);
	s.outputAStudentToFile(fout);
	fout.close();
}

void addAStaff(char* first_name, char* last_name, bool Gender, char* DoB,
	char* social_ID, char* staff_id) {

	staff s;
	person a;
	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
	s.inputAStaff(staff_id, a);

	ofstream fout;
	fout.open("../data/listOfStudent", ios::app);
	s.outputAStaffToFile(fout);
	fout.close();
}