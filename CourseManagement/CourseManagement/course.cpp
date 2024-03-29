#include "course.h"
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "semester.h"
#include "users.h"
#include<string>
using namespace std;

void AddCourseToFile(char* coursename, char* id, char* classname, char* teacher, char* nofc, char* maxstu, char* courseday, char* sshour, char*& Year, char*& semester) {
	ifstream fin;
	fin.open("../data/" + (string)(Year)+"/" + (string)(semester)+"/ListOfCourse.txt");
	ofstream f;
	f.open("../data/" + (string)(Year) +  "/" + (string)(semester) + "/ListOfCourse.txt", ios::app);
	fin.get();
	if (!fin.eof()) f << '\n';
	f << coursename << ","
		<< id << ","
		<< classname << ","
		<< teacher << ","
		<< nofc << ","
		<< maxstu << ","
		<< courseday << ","
		<< sshour;
	fin.close();
	f.close();
}
int countCourse(char*year, char*semester) {
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/ListOfCourse.txt", ios::app);
	fout.close();
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/"+(string)(semester)+"/ListOfCourse.txt");
	int num = 0;
	fin.get();
	while (!fin.eof()) {
		++num;
		fin.ignore(500, '\n');
	}
	return num;
	fin.close();
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
		fin >> courses[i].numOfCre;
		fin.ignore(1000, ',');
		fin >> courses[i].maxStu;
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
		if (i >= 1) fout << "\n";
		fout << courses[i].courseName	<< ','
			<< courses[i].courseID		<< ','
			<< courses[i].className		<< ','
			<< courses[i].teacherName	<< ','
			<< courses[i].numOfCre		<< ','
			<< courses[i].maxStu		<< ','
			<< courses[i].dayofweek	    << ','
			<< courses[i].sessionHour	;
	}
	fout.close();
}
int countStu(course& Course, char* year, char* semester) {
	Course.numOfStu = 0;
	ofstream fout;
	fout.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(Course.courseName)+"-" + string(Course.className) + ".csv", ios::app);
	fout.close();
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(Course.courseName)+"-" + string(Course.className) + ".csv");
	int num = 0;
	fin.get();
	while (!fin.eof()) {
		++num;
		++Course.numOfStu;
		fin.ignore(500, '\n');
	}
	return num;
	fin.close();
}
void Load_stu(course& Course, char* year, char* semester, student*& liststudents) {
	ifstream fin;
	fin.open("../data/" + (string)(year)+"/" + (string)(semester)+"/"+(string)(Course.courseName) + "-" + string(Course.className) + ".csv");

	int n = Course.numOfStu;
	Course.stuOfCourse = new student[n];

	int i = 0;
	while (i<n) {
		inputStudentAndScoreWithCSV(fin, Course.stuOfCourse[i]);
		++i;
	}
	fin.close();
	sortToStuID(Course.stuOfCourse, Course.numOfStu);
	liststudents = Course.stuOfCourse;
} 
void Return_stu(course& Course, char* year, char* semester) {
	sortToStuID(Course.stuOfCourse, Course.numOfStu);
	ofstream f;
	f.open("../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(Course.courseName) + "-" + string(Course.className) + ".csv");
	for (int i = 0; i < Course.numOfStu; i++) {
		if (i >= 1) f << "\n";
		f << Course.stuOfCourse[i].No << ","
			<< Course.stuOfCourse[i].stuID << ","
			<< Course.stuOfCourse[i].Student.lastName << ","
			<< Course.stuOfCourse[i].Student.firstName << ","
			<< Course.stuOfCourse[i].Student.gender << ","
			<< Course.stuOfCourse[i].Student.dob.d << "/"
			<< Course.stuOfCourse[i].Student.dob.m << "/"
			<< Course.stuOfCourse[i].Student.dob.y << ","
			<< Course.stuOfCourse[i].Student.socialID << ","
			<< Course.stuOfCourse[i].mark.totalMark << ","
			<< Course.stuOfCourse[i].mark.finalMark << ","
			<< Course.stuOfCourse[i].mark.midtermMark << ","
			<< Course.stuOfCourse[i].mark.otherMark;

	}
	f.close();
}
void deleteCourse(course*& courses, int no, int& num, char* year, char* semester) {
	if (no >= num) {
		return;
	}
	string tmp = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courses[no].courseName) + "-" + string(courses[no].className) + ".csv";
	remove(tmp.c_str());
	for (int i = no + 1; i < num; i++) {
		courses[i - 1] = courses[i];
	}
	num--;
	ReturnCoursesToFile(year, semester, num, courses);
}
bool updateCourse(char* year, char* semester, course& courses, char* courseName_tmp, char* ID, char* className_tmp, char* teacherName_tmp, char* nofc, char* maxstu, char* courseday, char* sshours) {
	string tmp = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courses.courseName) + "-" + string(courses.className) + ".csv";
	if (courseName_tmp[0] != '\0')  courses.courseName = _strdup(courseName_tmp);
	else courseName_tmp = _strdup(courses.courseName);
	if (className_tmp[0] != '\0')	courses.className = _strdup(className_tmp);
	else className_tmp = _strdup(courses.className);
	if (ID[0] != '\0')				courses.courseID = _strdup(ID);
	if (teacherName_tmp[0] != '\0') courses.teacherName = _strdup(teacherName_tmp);
	if (nofc[0] != '\0')			courses.numOfCre = atoi(nofc);
	if (maxstu[0] != '\0')			courses.maxStu = atoi(maxstu);
	if (courseday[0] != '\0')		courses.dayofweek = _strdup(courseday);
	if (sshours[0] != '\0')			courses.sessionHour = _strdup(sshours);
	string tmp_new = "../data/" + (string)(year)+"/" + (string)(semester)+"/" + (string)(courseName_tmp)+"-" + string(className_tmp) + ".csv";
	if (rename(tmp.c_str(), tmp_new.c_str()) == 0) return true;
	else return false;
}
void deleteStudent(course& course, int no, int& n, char* Year, char* Semester) {
	for (int i = no + 1; i < course.numOfStu; ++i) {
		course.stuOfCourse[i - 1] = course.stuOfCourse[i];
	}
	course.numOfStu--;
	n--;
	Return_stu(course, Year, Semester);
}
bool CheckValidCourse(char* coursename, char* ID, char* classname, char* nofc, char* maxstudents, char* Year, char* semester) {
	for (int i = 0; i < strlen(nofc); ++i) {
		if (nofc[i] < 48 || nofc[i] > 57) return 0;
	}
	for (int i = 0; i < strlen(maxstudents); ++i) {
		if (maxstudents[i] < 48 || maxstudents[i] > 57) return 0;
	}
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
bool exportStudentsInCourseToFile(char* addressOfOutputFile, char* schoolYear, char* semester, course& Course) {
	ifstream fin;
	fin.open("../data/" + string(schoolYear) + "/" + string(semester)
		+ "/" + string(Course.courseName) + "-" + string(Course.className) + ".csv");
	if (!fin) return false;
	fin.get();
	if (fin.eof()) return false;
	fin.close();
	fin.open("../data/" + string(schoolYear) + "/" + string(semester)
		+ "/" + string(Course.courseName) + "-" + string(Course.className) + ".csv");
	ofstream fout;
	string tmp = string(addressOfOutputFile) + "/" + string(Course.courseName) + "-" + string(Course.className) + ".csv";
	fout.open(tmp);
	if (!fout) return false;
	fout.close();
	student* stuArr = new student[Course.numOfStu];
	int cnt = 0;

	while (!fin.eof()) {
		if (cnt < Course.numOfStu) stuArr[cnt++].inputStudentsWithCSVFile(fin);
	}
	char* filename = (char*)tmp.c_str();
	sortToStuID(stuArr, cnt);
	for (int i = 0; i < cnt; ++i) {
		stuArr[i].outputAStudentToFile(filename);
	}
	delete[] stuArr;
	fin.close();
	return true;
}

//---------------------------------------------------------------
int countStudentInCourse(char* schoolYear, char* semester, char* course) {
	int numOfStu = 0;
	ifstream fin;
	fin.open("../data/" + string(schoolYear) + "/" + string(semester) + "/" + string(course) + ".csv");
	fin.get();
	while (!fin.eof()) {
		++numOfStu;
		fin.ignore(100, '\n');
	}
	fin.close();
	return numOfStu;
}
bool checkStudentExistInCourse(student x, char* schoolYear, char* semester, char* course) {
	//return true if the student haven't existed
	//return false if the student have existed
	ifstream fin;
	fin.open("../data/" + string(schoolYear) + "/" + string(semester) + "/" + string(course) + ".csv");
	int n = countStudentInCourse(schoolYear, semester, course);
	for (int i = 0; i < n; i++) {
		student s;
		s.inputStudentsWithCSVFile(fin);
		if (strcmp(s.stuID, x.stuID) == 0) {
			fin.close();
			return false;
		}
	}
	fin.close();
	return true;
}
bool checkStuHaveClass(char* stuID) {
	// return false if the student is not in any class
	ifstream fin;
	fin.open("../data/student_account.txt");
	while (!fin.eof()) {
		char* tmp = new char[100];
		fin.get(tmp, 100, '\n');
		if (strcmp(tmp, stuID) == 0) {
			delete[] tmp;
			return true;
		}
		delete[] tmp;
		fin.ignore(100, '\n');
		fin.ignore(100, '\n');
	}
	fin.close();
	return false;
}
bool addAStudentToCourse(course& Course, char* schoolYear, char* semester, char* course_name, char* first_name, char* last_name, char* Gender, char* DoB, char* social_ID, char* student_id) {

	if (Course.numOfStu >= Course.maxStu) return false;
	if (!checkDateInput(DoB) || (strcmp(Gender, "Male") != 0 && strcmp(Gender, "Female") != 0)) 
		return false;
	bool gender;
	if (strcmp(Gender, "Male") == 0) {
		gender = 1;
	}
	else gender = 0;

	string fileName = "../data/" + string(schoolYear) + "/" + string(semester) + "/" + string(course_name) + ".csv";

	student s;
	s.inputAStudent(student_id, first_name, last_name, gender, DoB, social_ID);

	if (!s.checkData() || !checkStuHaveClass(s.stuID)) return false;
	if (!checkStudentExistInCourse(s, schoolYear, semester, course_name)) return false;

	ofstream fout;
	fout.open(fileName, ios::app);
	s.outputAStudentToFile((char*)fileName.c_str());
	s.mark.outputScoreBoardToFile((char*)fileName.c_str());
	fout.close();
	++Course.numOfStu;
	return true;
}
bool addStudentsToCourseWithCSV(char* fileNameIn, char* schoolYear, char* semester, char* course_name, course& Course, student*& stuArr, int& numOfDupsStu) {
	bool returnValue = 1;
	// return true if no duplicate => stuArr = nullptr and numOfDupsStu = 0
	// return false if there are dups => update stuArr and numofDupsStu
	stuArr = new student[100];
	numOfDupsStu = 0;

	ifstream fin;
	fin.open(fileNameIn);
	string fileNameOutAddress = "../data/" + string(schoolYear) + "/" + string(semester) + "/" + string(course_name) + ".csv";
	char* fileNameOutAddressChar = new char[100];
	for (int i = 0; i < fileNameOutAddress.size(); i++) {
		fileNameOutAddressChar[i] = fileNameOutAddress[i];
	}
	fileNameOutAddressChar[fileNameOutAddress.size()] = '\0';

	while (!fin.eof()) {
		student s;
		s.inputStudentsWithCSVFile(fin);
		if (checkStudentExistInCourse(s, schoolYear, semester, course_name) && checkStuHaveClass(s.stuID) 
			&& Course.numOfStu < Course.maxStu) {
			s.outputAStudentToFile(fileNameOutAddressChar);
			s.mark.outputScoreBoardToFile(fileNameOutAddressChar);
			++Course.numOfStu;

		}
		else {
			returnValue = 0;
			stuArr[numOfDupsStu] = s;
			++numOfDupsStu;
		}
	}
	delete[] fileNameOutAddressChar;
	fin.close();
	if (returnValue) {
		delete[] stuArr;
		stuArr = nullptr;
	}
	return returnValue;
}

// 21
student* viewScoreBoardOfCourse(char* addressOfOutputFile, char* schoolYear, char* semester, char* courseName)
{
	course c;
	countStu(c, schoolYear, semester);
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

// 14
int countCoursesOfAStudent(char* stuID, char* schoolYear, char* semester)
{
	if (schoolYear == nullptr || semester == nullptr) return 0;
	int numOfCoursesOfAStudent = 0;

	int numOfCourses = countCourse(schoolYear, semester);
	course* CoursesInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		countStu(CoursesInSemester[i], schoolYear, semester);
		int numOfStuInCourse = CoursesInSemester[i].numOfStu;
		student* Course = nullptr;
		Load_stu(CoursesInSemester[i], schoolYear, semester, Course);
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			if (strcmp(stuID,Course[j].stuID)==0)
			{
				++numOfCoursesOfAStudent;
				break;
			}
		}
	}
	return numOfCoursesOfAStudent;
}
course* viewCoursesOfAStudent(char* stuID, char* schoolYear, char* semester)
{
	if (schoolYear == nullptr || semester == nullptr) return nullptr;
	int numOfCourses = countCourse(schoolYear, semester);

	course* saveCourse = new course[numOfCourses];
	int cnt = 0;
	course* CoursesInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		countStu(CoursesInSemester[i], schoolYear, semester);
		int numOfStuInCourse = CoursesInSemester[i].numOfStu;
		student* Course = nullptr;
		Load_stu(CoursesInSemester[i], schoolYear, semester, Course);
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			if (strcmp(stuID,Course[j].stuID)==0)
			{
				saveCourse[cnt++] = CoursesInSemester[i];
				break;
			}
		}
	}
	return saveCourse;
}
bool checkDataUpdateStudent(char* mark) {
	for (int i = 0; i < strlen(mark); ++i) {
		if (i == 1) {
			if (mark[i] != '.' && mark[i] != 48) return false;
		}
		else if (i == 2) {
			if (mark[i] != '.' && (mark[i] < 48 || mark[i] > 57)) return false;
		}
		else if (mark[i] < 48 || mark[i] > 57) return false;
	}
	return true;
}
bool UpdateStudentMark(student& s, char* totalMark, char* finalMark, char* midtermMark, char* otherMark) {
	// check data
	if (!checkMark(totalMark)) return false;
	if (!checkMark(finalMark)) return false;
	if (!checkMark(midtermMark)) return false;
	if (!checkMark(otherMark)) return false;
	if (totalMark[0] != '\0')		s.mark.totalMark = atof(totalMark);
	if (finalMark[0] != '\0')		s.mark.finalMark = atof(finalMark);
	if (midtermMark[0] != '\0')		s.mark.midtermMark = atof(midtermMark);
	if (otherMark[0] != '\0')		s.mark.otherMark = atof(otherMark);
	return true;
}

// Need Functions to Get Overall GPA:
int countOverallNumberOfCourses(char* stuID)
{
	int numCoursesFromStart = 0;
	int numOfSchoolYear = 0;
	char** schoolYear = nullptr;
	getStudyingSchoolYear(stuID, numOfSchoolYear, schoolYear);
	string* Semester = new string[3];
	Semester[0] = "Fall";
	Semester[1] = "Summer";
	Semester[2] = "Autumn";
	char** semester = new char* [3];
	for (int i = 0; i < 3; ++i)
		semester[i] = new char[10];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < Semester[i].size(); ++j)
			semester[i][j] = Semester[i][j];
	}
	for (int i = 0; i < 3; ++i)
		semester[i][Semester[i].size()] = '\0';
	
	for (int i = 0; i < numOfSchoolYear; ++i)
	{
		for (int j = 0; j < 3; ++j)
			if(checkSemesterAndSchoolYear(semester[j], schoolYear[i]))
				numCoursesFromStart += countCoursesOfAStudent(stuID, schoolYear[i], semester[j]);
	}
	return numCoursesFromStart;
}
course* GetOverallCourseListFromStart(char* stuID)
{
	int numCoursesFromStart = countOverallNumberOfCourses(stuID);
	course* AllCoursesFromStart = new course[numCoursesFromStart];
	

	int numOfSchoolYear = 0;
	char** schoolYear = nullptr;
	getStudyingSchoolYear(stuID, numOfSchoolYear, schoolYear);
	string* Semester = new string[3];
	Semester[0] = "Autumn";
	Semester[1] = "Fall";
	Semester[2] = "Summer";
	char** semester = new char* [3];
	for (int i = 0; i < 3; ++i)
		semester[i] = new char[10];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < Semester[i].size(); ++j)
			semester[i][j] = Semester[i][j];
	}
	for (int i = 0; i < 3; ++i)
		semester[i][Semester[i].size()] = '\0';

	
	int cnt = 0;
	for (int i = 0; i < numOfSchoolYear; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (checkSemesterAndSchoolYear(semester[j], schoolYear[i])) {
				int numOfCoursesOfCurrentSemester = countCoursesOfAStudent(stuID, schoolYear[i], semester[j]);
				course* CoursesOfCurrentSemester = viewCoursesOfAStudent(stuID, schoolYear[i], semester[j]);
				for (int k = 0; k < numOfCoursesOfCurrentSemester; ++k)
					AllCoursesFromStart[cnt + k] = CoursesOfCurrentSemester[k];
				cnt += numOfCoursesOfCurrentSemester;
				delete[]CoursesOfCurrentSemester;
				CoursesOfCurrentSemester = nullptr;
			}
		}
	}
	return AllCoursesFromStart;
}
scoreboard* GetOverallScoresListFromStart(char* stuID)
{
	int numCoursesFromStart = countOverallNumberOfCourses(stuID);
	scoreboard* AllScoresFromStart = new scoreboard[numCoursesFromStart];


	int numOfSchoolYear = 0;
	char** schoolYear = nullptr;
	getStudyingSchoolYear(stuID, numOfSchoolYear, schoolYear);
	string* Semester = new string[3];
	Semester[0] = "Autumn";
	Semester[1] = "Fall";
	Semester[2] = "Summer";
	char** semester = new char* [3];
	for (int i = 0; i < 3; ++i)
		semester[i] = new char[10];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < Semester[i].size(); ++j)
			semester[i][j] = Semester[i][j];
	}
	for (int i = 0; i < 3; ++i)
		semester[i][Semester[i].size()] = '\0';


	int cnt = 0;
	for (int i = 0; i < numOfSchoolYear; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (checkSemesterAndSchoolYear(semester[j], schoolYear[i])) {
				int numOfCoursesOfCurrentSemester = countCoursesOfAStudent(stuID, schoolYear[i], semester[j]);
				scoreboard* ScoresOfCurrentSemester = GetsaveScore(stuID, schoolYear[i], semester[j]);
				for (int k = 0; k < numOfCoursesOfCurrentSemester; ++k)
					AllScoresFromStart[cnt + k] = ScoresOfCurrentSemester[k];
				cnt += numOfCoursesOfCurrentSemester;
				delete[]ScoresOfCurrentSemester;
				ScoresOfCurrentSemester = nullptr;
			}
		}
	}
	return AllScoresFromStart;
}
