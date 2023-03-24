#include <iostream>
#include <fstream>
#include "Course.h"
using namespace std;

void course:: Add_Courses(course newCourse, char* filename, ofstream& fout)
{
	fout.open(filename, ios::app);
	fout << "Course : " << newCourse.courseName << '\n'
		<< "ID : " << newCourse.courseID << '\n'
		<< "Teacher : " << newCourse.teacherName << '\n'
		<< "Number of Credit : " << newCourse.numOfCre << '\n'
		<< "Course Day : " << newCourse.dayofweek << '\n'
		<< "Session Hours : " << newCourse.sessionHour << '\n';
	fout.close();
}
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
	if (numOfStu < 50) {
		stuOfCourse[numOfStu] = newStudents;
		numOfStu++;
	}
	else cout << "Cant add more student";
}
void course::Add_Stus(char*filename) {
	ifstream f;
	f.open(filename);
	while (!f.eof() && numOfStu < 50) {
		f>> stuOfCourse[numOfStu]->No
		 >>	stuOfCourse[numOfStu]->stuID
		 >>	stuOfCourse[numOfStu]->person.firstName
		 >>	stuOfCourse[numOfStu]->person.lastName
		 >>	stuOfCourse[numOfStu]->person.gender
		 >>	stuOfCourse[numOfStu]->person.dob.day
		 >>	stuOfCourse[numOfStu]->person.dob.month
		 >>	stuOfCourse[numOfStu]->person.dob.year
		 >>	stuOfCourse[numOfStu]->person.socialID;
		numOfStu++;
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

int main() {

}