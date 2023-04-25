#include "course.h"
#include <iostream>
#include <fstream>
#include <string>
#include "semester.h"
//#include "Function.h"
#include "users.h"
#include<string>
using namespace std;

void AddCourseToFile(char* coursename, char* id, char* classname, char* teacher, char* nofc, char* maxstu, char* courseday,
	char* sshour, char*& Year, char*& semester) {
	ofstream f;
	f.open("../data/" + (string)(Year) +  "/" + (string)(semester) + "/ListOfCourse.txt", ios::app);
	f << coursename << ","
		<< id << ","
		<< classname << ","
		<< teacher << ","
		<< nofc << ","
		<< maxstu << ","
		<< courseday << ","
		<< sshour << '\n';
}
int countCourse(char*year, char*semester) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt", ios::app);
	fout.close();
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/"+(string)(semester)+"/ListOfCourse.txt");
	int num = 0;
	while (!fin.eof()) {
		++num;
		fin.ignore(500, '\n');
	}
	return num-1;
}

course* viewCoursesInSemester(char* year, char* semester)
{
	int numOfCourses = countCourse(year, semester);
	course* TotalCoursesInSemester;
	LoadCourseFromFile(year, semester, numOfCourses, TotalCoursesInSemester);
	return TotalCoursesInSemester;
}

void LoadCourseFromFile(char* year, char* semester, int& num, course* &courses) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt", ios::app);
	fout.close();
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt");
	courses = new course[num];
	for (int i = 0; i < num; i++) {
		courses[i].courseName = new char[100];
		fin.get(courses[i].courseName, 100, ',');
		fin.ignore(1000, ',');
		courses[i].courseID = new char[100];
		fin.get(courses[i].courseID, 100, ',');
		fin.ignore(1000, ',');
		courses[i].className = new char[100];
		fin.get(courses[i].className, 100, ',');
		fin.ignore(1000, ',');
		courses[i].teacherName = new char[100];
		fin.get(courses[i].teacherName, 100, ',');
		fin.ignore(1000, ',');
		courses[i].numOfCre = new char[100];
		fin.get(courses[i].numOfCre, 100, ',');
		fin.ignore(1000, ',');
		courses[i].maxStu = new char[100];
		fin.get(courses[i].maxStu, 100, ',');
		fin.ignore(1000, ',');
		courses[i].dayofweek = new char[100];
		fin.get(courses[i].dayofweek, 100, ',');
		fin.ignore(1000, ',');
		courses[i].sessionHour = new char[100];
		fin.get(courses[i].sessionHour, 100);
		fin.ignore(1000, '\n');
	}
	fin.close();
}
void ReturnCoursesToFile(char* year, char* semester, int& num, course*& courses) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt");
	for (int i = 0; i < num; i++) {
		fout << courses[i].courseName	<< ','
			<< courses[i].courseID		<< ','
			<< courses[i].className		<< ','
			<< courses[i].teacherName	<< ','
			<< courses[i].numOfCre		<< ','
			<< courses[i].maxStu		<< ','
			<< courses[i].dayofweek	    << ','
			<< courses[i].sessionHour	<< '\n';
	}
	fout.close();
}
void course:: countStu(char* year, char* semester) {
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName)+"-" + string(className) + ".txt");
	int num = 0;
	while (!fin.eof()) {
		++num;
		fin.ignore(500, '\n');
	}
	numOfStu= num -1;
}
void course::Load_stu(char* year, char* semester) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName)+ "-" + string(className) + ".txt", ios::app);
	fout.close();
	ifstream f;
	f.open("../data/" + (string)(year)+"/" + (string)(semester)+"/"+(string)(courseName) + "-" + string(className) + ".txt");

	if (!f)return;
	int i = 0;
	while (i<numOfStu) {
		f >> stuOfCourse[i].No;
		f.ignore(100, ',');
		stuOfCourse[i].stuID = new char[100];
		f.get(stuOfCourse[i].stuID, 100,',');
		f.ignore(100,',');
		stuOfCourse[i].Student.lastName = new char[100];
		f.get(stuOfCourse[i].Student.lastName, 100,',');
		f.ignore(100,',');
		stuOfCourse[i].Student.firstName = new char[100];
		f.get(stuOfCourse[i].Student.firstName, 100,',');
		f.ignore(100,',');
		f >> stuOfCourse[i].Student.gender;
		f.ignore(100,',');
		f >> stuOfCourse[i].Student.dob.d;
		f.ignore(100,'/');
		f >> stuOfCourse[i].Student.dob.m;
		f.ignore(100,'/');
		f >> stuOfCourse[i].Student.dob.y;
		f.ignore(100,',');
		stuOfCourse[i].Student.socialID = new char[100];
		f.get(stuOfCourse[i].Student.socialID, 100);
		f.ignore();
		++i;
	}
} 

void course::Return_stu(char* year, char* semester) {
	ofstream f;
	f.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName)+"-" + string(className) + ".txt");
	int i = 0;
	if (!f)return;
		for(int i =0;i<numOfStu;i++){
		f << stuOfCourse[i].No<<","
		  <<stuOfCourse[i].stuID << ","
		  <<stuOfCourse[i].Student.lastName << ","
		  <<stuOfCourse[i].Student.firstName << ","
		  << stuOfCourse[i].Student.gender << ","
		  << stuOfCourse[i].Student.dob.d << ","
		  << stuOfCourse[i].Student.dob.m << ","
		  << stuOfCourse[i].Student.dob.y << ","
		  <<stuOfCourse[i].Student.socialID << "\n";
		}
}
void deleteCourse(course*& courses, int no, int& num, char* year, char* semester) {
	if (no >= num) {
		return;
	}
	string tmp = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courses[no].courseName) + "-" + string(courses[no].className) + ".txt";
	remove(tmp.c_str());
	for (int i = no + 1; i < num; i++) {
		courses[i - 1] = courses[i];
	}
	num--;
	ReturnCoursesToFile(year, semester, num, courses);
}
bool updateCourse(char* year, char* semester, course& courses, char* courseName_tmp, char* ID, char* className_tmp, char* teacherName_tmp, char* nofc, char* maxstu, char* courseday, char* sshours) {
	if (courseName_tmp[0] != '\0')  courses.courseName = _strdup(courseName_tmp);
	if (className_tmp[0] != '\0')	courses.className =  _strdup(className_tmp);
	if (ID[0] != '\0')				courses.courseID = _strdup(ID);
	if (teacherName_tmp[0] != '\0') courses.teacherName = _strdup(teacherName_tmp);
	if (nofc[0] != '\0')			courses.numOfCre = _strdup(nofc);
	if (maxstu[0] != '\0')			courses.maxStu = _strdup(maxstu);
	if (courseday[0] != '\0')		courses.dayofweek = _strdup(courseday);
	if (sshours[0] != '\0')			courses.sessionHour = _strdup(sshours);
	string tmp = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courses.courseName) + "-" + string(courses.className) + ".txt";
	string tmp_new = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName_tmp)+"-" + string(className_tmp) + ".txt";
	rename(tmp.c_str(), tmp_new.c_str());
	return true;
}
void deleteStudent(course* course, int k, int no) {
	while (no < course[k].numOfStu - 1) {
		course[k].stuOfCourse[no] = course[k].stuOfCourse[no + 1];
		++no;
	}
	--course[k].numOfStu;
}
void course::add_stu(char* year, char* semester, int No, char* stuID, char lastName, char* firstName, bool gen, int d, int m, int y, char* socialID) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName)+"-" + string(className) + ".txt", ios::app);
	int maxstu = stoi(maxStu);
	if (numOfStu < maxstu) {
		fout << No << ","
			<< stuID << ","
			<< lastName << ","
			<< firstName << ","
			<< gen << ","
			<< d << ","
			<< m << ","
			<< y << ","
			<< socialID << "\n";
	}
	fout.close();
	Load_stu(year, semester);
}
//char* GetFileDrop() {
//	char* filepath = new char;
//	if (IsFileDropped())
//	{
//		FilePathList droppedFiles = LoadDroppedFiles();
//		TextCopy(filepath, droppedFiles.paths[0]);
//		UnloadDroppedFiles(droppedFiles);
//	}
//	return filepath;
//}
bool CheckValidCourse(char* coursename, char* ID, char* classname, char* Year, char* semester) {
	int num = countCourse( Year, semester);
	course* courses;
	LoadCourseFromFile(Year, semester, num, courses);
	for (int i = 0; i < num; i++) {
		if ( 
			   (strcmp(courses[i].className, classname) == 0 && strcmp(courses[i].courseName, coursename) == 0)
			|| (strcmp(courses[i].courseName, coursename) == 0 && strcmp(courses[i].courseID, ID) != 0 )
			|| (strcmp(courses[i].courseName, coursename) != 0 && strcmp(courses[i].courseID, ID) == 0 ))
			return 0;
	}
	return 1;
}

void exportStudentsInCourseToFile(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName) {
	ifstream fin;
	fin.open("../data/" + string(schoolYear) + "/" + string(semester)
		+ "/" + string(courseName) + ".csv");
	while (!fin.eof()) {
		student s;
		s.inputStudentsWithCSVFile(fin);
		s.outputAStudentToFile(addressOfOutputFile);
	}
}

// 21
student* viewScoreBoardOfCourse(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName)
{
	course c;
	c.countStu(schoolYear, semester);
	int numOfS = c.numOfStu;
	student* StuInCourse = nullptr;
	StuInCourse = new student[numOfS];
	ifstream fin;
	fin.open(addressOfOutputFile);
	for (int i = 0; i < numOfS; ++i)
		inputStudentAndScoreWithCSV(fin, StuInCourse[i]);
	fin.close();
	sortToStuID(StuInCourse, numOfS);
	return StuInCourse;
}