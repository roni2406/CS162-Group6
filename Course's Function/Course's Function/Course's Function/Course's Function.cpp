#include <iostream>
#include <fstream>
#include "Course.h"
using namespace std;

void course::Input_Course() {
	cout << "You have created a new Course. Please enter the name of Course: ";
	cin.get(courseName, '\n');
	cin.ignore(100, '\n');
	cout << "Course ID : ";
	cin.get(courseID, '\n');
	cin.ignore(100, '\n');
	cout << "Course's teacher : ";
	cin.get(teacherName, '\n');
	cin.ignore(100, '\n');
	cout << "Number of Course Credit : ";
	cin >> numOfCre;
	cout << "Course will occur on : ";
	cin.get(dayofweek, '\n');
	cin.ignore(100, '\n');
	cout << "Course will begin at : ";
	cin.get(sessionHour, '\n');
	cin.ignore(100, '\n');
}
void course::Input_1_Stu(student* newStudents) {
	if (numOfStu <= 50) {
		stuOfCourse[++numOfStu] = newStudents;
	}
	else cout << "Cant add more student";
}
void course::Load_Stus(char* studentfile) {
	ifstream f;
	f.open(studentfile, ios::app);
	while (!f.eof() && numOfStu <= 50) {
		numOfStu++;
		f >> stuOfCourse[numOfStu]->No
			>> stuOfCourse[numOfStu]->stuID
			>> stuOfCourse[numOfStu]->person.firstName
			>> stuOfCourse[numOfStu]->person.lastName
			>> stuOfCourse[numOfStu]->person.gender
			>> stuOfCourse[numOfStu]->person.dob.day
			>> stuOfCourse[numOfStu]->person.dob.month
			>> stuOfCourse[numOfStu]->person.dob.year
			>> stuOfCourse[numOfStu]->person.socialID;
	}
	if (numOfStu > 50)cout << "Cant adds more student";
}
void course::Delete_1_Stu() {
	cout << "Enter student's ID to delete";
	char ID[9];
	cin >> ID;
	int i = 0;
	for (; i <= numOfStu; i++) {
		if (stuOfCourse[i]->stuID == ID);
		break;
	}
	for (; i < numOfStu; i++) {
		stuOfCourse[i] = stuOfCourse[i + 1];
	}
	numOfStu--;
}
void course::Update_Course(int press) {
	switch (press) {
	case 1:
		cin >> courseName;
	case 2:
		cin >> courseID;
	case 3:
		cin >> teacherName;
	case 4:
		cin >> numOfCre;
	case 5:
		cin >> dayofweek;
	case 6:
		cin >> sessionHour;
	}
}
void course:: Add_Course( char* coursefile, ofstream& fout) {
	fout.open(coursefile, ios::app);
	fout << "Course : " << courseName << '\n'
		<< "ID : " << courseID << '\n'
		<< "Teacher : " << teacherName << '\n'
		<< "Number of Credit : " << numOfCre << '\n'
		<< "Course Day : " << dayofweek << '\n'
		<< "Session Hours : " << sessionHour << '\n';
	for (int i = 1; i <= numOfStu; i++) {
		fout << stuOfCourse[numOfStu]->No
			<< stuOfCourse[numOfStu]->stuID
			<< stuOfCourse[numOfStu]->person.firstName
			<< stuOfCourse[numOfStu]->person.lastName
			<< stuOfCourse[numOfStu]->person.gender
			<< stuOfCourse[numOfStu]->person.dob.day
			<< stuOfCourse[numOfStu]->person.dob.month
			<< stuOfCourse[numOfStu]->person.dob.year
			<< stuOfCourse[numOfStu]->person.socialID;
	}
	fout.close();
}
int main() {

}