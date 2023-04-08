#include "course.h"
#include "Function.h"
#include "users.h"

void AddCourseToFile(char* coursename, char* id, char* classname, char* teacher, char* nofc, char* courseday, char* sshour, char*& Year, char*& semester) {
	ofstream f;
	f.open("../data/" + (string)(Year) +  "/" + (string)(semester) + "/ListOfCourse.txt", ios::app);
	f << coursename << ","
		<< id << ","
		<< classname << ","
		<< teacher << ","
		<< nofc << ","
		<< courseday << ","
		<< sshour << '\n';
}
int countCourse(char*year, char*semester) {
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/"+(string)(semester)+"/ListOfCourse.txt");
	int num = 0;
	fin.get();
	while (!fin.eof()) {
		++num;
		fin.ignore(500, '\n');
	}
	return num;
}
void LoadCourseFromFile(char* year, char* semester,int num) {
	course* courses;
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt");
	courses = new course[num];
	for (int i = 0; i <= num; i++) {
		//fin.getline(courses[i].courseName, 1000, ',');
		fin.getline(courses[i].courseID, 1000, ',');
		fin.getline(courses[i].className, 1000, ',');
		fin.getline(courses[i].teacherName, 1000, ',');
		fin.getline(courses[i].numOfCre, 1000, ',');
		fin.getline(courses[i].dayofweek, 1000, ',');
		fin.getline(courses[i].sessionHour, 1000);
	}
}
void course::Load_stu(char* year, char* semester) {
	ifstream f;
	f.open("../data/" + (string)(year)+"/" + (string)(semester)+"/"+(string)(courseName)+".txt");
	int i = 0;
	if (!f)return;
	while (!f.eof() && i < 50) {
		f >> stuOfCourse[++i].No;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].stuID, 1000);
		f.getline(stuOfCourse[i].Student.lastName, 100);
		f.getline(stuOfCourse[i].Student.firstName, 100);
		f >> stuOfCourse[i].Student.gender;
		f >> stuOfCourse[i].Student.dob.d;
		f >> stuOfCourse[i].Student.dob.m;
		f >> stuOfCourse[i].Student.dob.y;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].Student.socialID, 100);
		numOfStu = i;
	}
}
void deleteCourse(course* courses, int no ,int& num) {
	while (no<num) {
		courses[no] = courses[no + 1];
		++no;
	}
	num--;
}
void deleteStudent(course* course, int k, int no) {
	while (no < course[k].numOfStu) {
		course[k].stuOfCourse[no] = course[k].stuOfCourse[no + 1];
		++no;
	}
	--course[k].numOfStu;
}
char* GetFileDrop() {
	char* filepath = new char;
	if (IsFileDropped())
	{
		FilePathList droppedFiles = LoadDroppedFiles();
		TextCopy(filepath, droppedFiles.paths[0]);
		UnloadDroppedFiles(droppedFiles);
	}
	return filepath;
}