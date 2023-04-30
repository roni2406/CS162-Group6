#include <iostream>
#include <string>
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
	if (gender == 1) fout << "Male,";
	else fout << "Female,";
	dob.outputADateToFile(fout);
	fout << "," << socialID;
}

bool person::checkData() {
	if (!dob.checkdata() || strlen(socialID) != 12)
		return false;
	return true;
}

//student
void student::inputAStudent(char* student_id, char* first_name, char* last_name, 
	bool Gender, char* DoB, char* social_ID) {
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

bool student::checkData() {
	if (!Student.checkData() || strlen(stuID) != 8)
		return false;
	return true;
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
void sortToStuID(student*& StudentArray, int numOfStudents)
{
	for (int i = 0; i < numOfStudents - 1; ++i)
	{
		for (int j = 0; j < numOfStudents - i - 1; ++j)
		{
			if (strcmp(StudentArray[j].stuID, StudentArray[j + 1].stuID) == 1)
				swap(StudentArray[j], StudentArray[j + 1]);
		}
	}
	for (int i = 0; i < numOfStudents; ++i)
		StudentArray[i].No = i + 1;
}

bool checkdata_FileName(char* fileNameIn)
{
	int n = strlen(fileNameIn);
	if (fileNameIn[n - 4] == '.' && fileNameIn[n - 3] == 'c'
		&& fileNameIn[n - 2] == 's' && fileNameIn[n - 1] == 'v') return true;
	else return false;
}

void getStudyingSchoolYear(char* stuID, int& numOfschoolYear, char**& schoolYear) {
	char* first2degitOfstuID = new char[3];
	first2degitOfstuID[0] = stuID[0];
	first2degitOfstuID[1] = stuID[1];
	first2degitOfstuID[2] = '\0';

	char now[9];
	_strdate_s(now);
	now[8] = '\0';
	char* nowYear = new char[3];
	nowYear[0] = now[6];
	nowYear[1] = now[7];
	nowYear[2] = '\0';
	
	numOfschoolYear = atoi(nowYear) - atoi(first2degitOfstuID) + 1;
	schoolYear = new char* [numOfschoolYear];
	for (int i = 0; i < numOfschoolYear; i++) {
		schoolYear[i] = new char[10];
	}

	int yearInNum = atoi(first2degitOfstuID);
	for (int i = 0; i < numOfschoolYear; i++) {
		char* prevYear = new char[3];
		int_to_char(yearInNum, prevYear);
		++yearInNum;
		char* nextYear = new char[3];
		int_to_char(yearInNum, nextYear);

		string makeSchoolYear = "20" + string(prevYear) + "-20" + string(nextYear);
		for (int j = 0; j < 9; j++) {
			schoolYear[i][j] = makeSchoolYear[j];
		}
		schoolYear[i][9] = '\0';

		delete[] prevYear;
		delete[] nextYear;
	}
	delete[] first2degitOfstuID;
	delete[] nowYear;
}

// 20
void inputStudentAndScoreWithCSV(ifstream& fin, student& s)
{
	fin >> s.No;
	s.stuID = new char[100];
	fin.ignore(100, ',');
	fin.get(s.stuID, 100, ',');
	fin.ignore(100, ',');
	
	s.Student.lastName = new char[100];
	fin.get(s.Student.lastName, 100, ',');

	s.Student.firstName = new char[100];
	fin.ignore(100, ',');
	fin.get(s.Student.firstName, 100, ',');

	char* tmp = new char[100];
	fin.ignore(100, ',');
	fin.get(tmp, 100, ',');
	if (strcmp(tmp, (char*)"Male") == 0) s.Student.gender = 1;
	else s.Student.gender = 0;
	delete[] tmp;

	char* dateofBirth = new char[20];
	fin.ignore(100, ',');
	fin.get(dateofBirth, 100, ',');
	s.Student.dob.inputADateWithChar(dateofBirth);
	delete[] dateofBirth;

	s.Student.socialID = new char[100];
	fin.ignore(100, ',');
	fin.get(s.Student.socialID, 100, ',');

	s.mark.inputScoreBoardWithCSV(fin);
}

void outputStudentAndScoreToFile(char* filename, student& s)
{
	ifstream fin;
	fin.open(filename);
	int cnt = 0;
	fin.get();
	while (!fin.eof()) {
		cnt++;
		fin.ignore(200, '\n');
	}
	s.No = cnt + 1;
	fin.close();
	ofstream fout;
	fout.open(filename, ios::app);
	if (s.No != 1) fout << endl;
	fout << s.No << ",";
	fout << s.stuID << ",";
	fout << s.Student.lastName << "," << s.Student.firstName << ",";
	if (s.Student.gender == 1) fout << "male,";
	else fout << "female,";
	s.Student.dob.outputADateToFile(fout);
	fout << "," << s.Student.socialID << ",";
	s.mark.outputScoreBoardToFile(fout);
	fout.close();
}

void InputScoreBoardWithCSV(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName)
{
	ifstream fin;
	fin.open(addressOfOutputFile);
	while (!fin.eof()) 
	{
		student s;
		inputStudentAndScoreWithCSV(fin, s);
	}
	fin.close();
}

// 24

void viewPersonalStudentScoreboard(char* stuID, char* schoolYear, char* semester, scoreboard*& saveScore)
{
	int numOfCourses = countCourse(schoolYear, semester);
	saveScore = new scoreboard[numOfCourses];	
	int cnt = 0;
	course* CoursesInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		countStu(CoursesInSemester[i], schoolYear, semester);
		int numOfStuInCourse = CoursesInSemester[i].numOfStu;
		student* StuInCourse = nullptr;
		Load_stu(CoursesInSemester[i], schoolYear, semester, StuInCourse);
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			if (strcmp(stuID, StuInCourse[j].stuID) == 0)
			{
				saveScore[cnt++] = StuInCourse[j].mark;
				break;
			}
		}
	}
}

scoreboard* GetsaveScore(char* stuID, char* schoolYear, char* semester)
{
	scoreboard* saveScore = nullptr;
	viewPersonalStudentScoreboard(stuID, schoolYear, semester, saveScore);
	return saveScore;
}

double getSemesterGPA(char* stuID, char* schoolYear, char* semester)
{
	double SemesterGPA = 0;
	course* ListOfStudyingCourses = viewCoursesOfAStudent(stuID, schoolYear, semester);
	scoreboard* ListOfStudyingScores = GetsaveScore(stuID, schoolYear, semester);
	int numOfStudyingCourses = countCoursesOfAStudent(stuID, schoolYear, semester);
	int numOfSemesterCredits = 0;
	for (int i = 0; i < numOfStudyingCourses; ++i)
	{
		numOfSemesterCredits += ListOfStudyingCourses[i].numOfCre;
		SemesterGPA += ListOfStudyingCourses[i].numOfCre * ListOfStudyingScores[i].totalMark;
	}
	SemesterGPA /= numOfSemesterCredits;
	SemesterGPA = round(SemesterGPA * 100.0) / 100.0;
	return SemesterGPA;
}

void OutputToFileCoursesAndScores(char* stuID, char* schoolYear, char* semester, char* filename)
{
	ofstream fout;
	course* ListOfStudyingCourses = viewCoursesOfAStudent(stuID, schoolYear, semester);
	scoreboard* ListOfStudyingScores = GetsaveScore(stuID, schoolYear, semester);
	int numOfStudyingCourses = countCoursesOfAStudent(stuID, schoolYear, semester);
	fout.open(filename);
	for (int i = 0; i < numOfStudyingCourses; ++i)
	{
		fout << ListOfStudyingCourses[i].courseID << ","
			 << ListOfStudyingCourses[i].courseName << ","
			 << ListOfStudyingCourses[i].numOfCre << ","
			 << ListOfStudyingCourses[i].className << ","
			 << ListOfStudyingScores[i].totalMark << ","
			 << ListOfStudyingScores[i].finalMark << ","
			 << ListOfStudyingScores[i].midtermMark << ","
			 << ListOfStudyingScores[i].otherMark;
		if (i != numOfStudyingCourses - 1)
			fout << '\n';
	}
	fout.close();
}