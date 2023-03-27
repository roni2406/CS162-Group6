#include <iostream>
#include <fstream>
#include "Course.h"
#include"raylib.h"
using namespace std;

/*void course::Input_Course() {
	cout << "You have created a new Course. Please enter:\nName of Course: ";
	cin.get(courseName,'\n');
	cin.ignore(100, '\n');
	cout << "Course ID : ";
	cin.get(courseID, '\n');
	cin.ignore(100, '\n');
	cout << "Course's teacher : ";
	cin.get(teacherName, '\n');
	cin.ignore(100, '\n');
	cout << "Number of Course Credit : ";
	cin >> numOfCre;
	cin.ignore(100, '\n');
	cout << "Course will occur on : ";
	cin.get(dayofweek, '\n');
	cin.ignore(100, '\n');
	cout << "Course will begin at : ";
	cin.get(sessionHour, '\n');
	cin.ignore(100, '\n');
}*/
void course::Input_1_Stu(student* newStudents) {
	if (numOfStu < 50) {
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
void course:: Add_Course( char* semeterfile, ofstream& fout) {
	fout.open(semeterfile, ios::app);
	fout << "Course : " << courseName << '\n'
		<< "ID : " << courseID << '\n'
		<< "Teacher : " << teacherName << '\n'
		<< "Number of Credit : " << numOfCre << '\n'
		<< "Course Day : " << dayofweek << '\n'
		<< "Session Hours : " << sessionHour << '\n';
	/*for (int i = 1; i <= numOfStu; i++) {
		fout << stuOfCourse[numOfStu]->No
			<< stuOfCourse[numOfStu]->stuID
			<< stuOfCourse[numOfStu]->person.firstName
			<< stuOfCourse[numOfStu]->person.lastName
			<< stuOfCourse[numOfStu]->person.gender
			<< stuOfCourse[numOfStu]->person.dob.day
			<< stuOfCourse[numOfStu]->person.dob.month
			<< stuOfCourse[numOfStu]->person.dob.year
			<< stuOfCourse[numOfStu]->person.socialID;
	}*/
	fout.close();
}
/*void View_Course(course* course, int k) {
	int i = 0;
	while (i<k) {
		cout <<"Coures Name : "<< course[i].courseName << '\n'
			 <<"ID : "<<course[i].courseID << '\n'	
			 <<"Teacher : "<< course[i].teacherName << '\n'
			 <<"Number of Credit : "<< course[i].numOfCre << '\n'
			 <<"Course Day : "<<course[i].dayofweek << '\n'
			 <<"Session Hours : " << course[i].sessionHour << '\n' << '\n';
		i++;
	}
}*/
void overall_page() {

}
int main() {

	course  course[10];
	int Pos = 00;
	int scrollSpeed = 25;
	InitWindow(1620, 920, "cs2");
	char str[6] = "";
	while (!WindowShouldClose()) {
		Pos += (GetMouseWheelMove() * scrollSpeed);
		if (Pos > 0)Pos = 0;
		if (Pos < -1500)Pos = -1500;//num of course/6*wight
		BeginDrawing();
		ClearBackground(WHITE);
		float mouseWheelMovement = GetMouseWheelMove();
		int i = 0;//k=num of courses
		for (int k = 0; k < 10; k++) {
			DrawText(TextFormat("Course: " ), 17, Pos + (i += 20), 20, RED);
			DrawText(str,100, Pos+(i), 20, RED);
			DrawText(TextFormat("ID: "), 17, Pos + (i += 20), 20, RED);
			DrawText(str, 50, Pos + (i), 20, RED);
			DrawText(TextFormat("Teacher: ", course[k].teacherName), 17, Pos + (i += 20), 20, RED);
			DrawText(str, 115, Pos + (i), 20, RED);
			DrawText(TextFormat("Number of Credit: ", course[k].numOfCre), 17, Pos + (i += 20), 20, RED);
			DrawText(str, 205, Pos + (i), 20, RED);
			DrawText(TextFormat("Course Day: ", course[k].dayofweek), 17, Pos + (i += 20), 20, RED);
			DrawText(TextFormat("Session Hours: ", course[k].dayofweek), 17, Pos + (i += 20), 20, RED);
			i += 50;
		}
		EndDrawing();
	}
	CloseWindow();
}