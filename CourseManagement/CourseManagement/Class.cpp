#include <iostream>
#include <string.h>
#include <fstream>
#include "Class.h"
#include "Date.h"
using namespace std;

// 2
void InputAClass(char* classID, Class &className)
{
	className.classID = _strdup(classID);
}

void CreateAClass(char* classID)
{
	Class Object;
	InputAClass(classID, Object);
	ofstream fout;
	CreateASingleClassList(Object, fout);
	AddAClassToList(Object, fout);
}

void CreateASingleClassList(Class className, ofstream& fout)
{
	fout.open("../data/Classes/" + string(className.classID) + ".csv");
	fout.close();
}

void AddAClassToList(Class className, ofstream& fout)
{
	ifstream fin;
	fin.open("../data/Classes/Listofclasses.txt");
	fin.get();

	fout.open("../data/Classes/Listofclasses.txt", ios::app);
	if(!fin.eof()) fout << '\n';
	fout << className.classID;
	
	fin.close();
	fout.close();
}

bool CheckClassExisted(char* ClassID)
{
	ifstream fin;
	Class* ClassList = nullptr;
	int numOfClasses = 0;

	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);

	for (int i = 0; i < numOfClasses; ++i)
		if (strcmp(ClassID, ClassList[i].classID) == 0)
			return true;
	return false;
}

// 15
void viewClasses_PrepareData_SavedToClassArray(Class*& ClassList, ifstream& fin, int& numOfClasses) // 15
{
	fin.open("../data/Classes/Listofclasses.txt");
	ClassList = new Class[1000];
	numOfClasses = 0;
	char* str = nullptr;
	int tmp = 0;
	while (!fin.eof())
	{
		str = new char[11];
		fin >> str;
		ClassList[numOfClasses].classID = _strdup(str);
		++numOfClasses;
		delete[]str;
		str = nullptr;
	}
	fin.close();
}

void sortClasses(Class* classList) {
	int numOfClasses = countClasses();
	for (int i = 0; i < numOfClasses; i++) {
		for (int j = 0; j < numOfClasses - i - 1; j++)
			if (strcmp(classList[j].classID, classList[j + 1].classID) == 1) {
				swap(classList[j], classList[j + 1]);
			}
	}
}

Class* viewClasses()
{
	ifstream fin;
	Class* ClassList = nullptr;
	int numOfClasses = 0;
	viewClasses_PrepareData_SavedToClassArray(ClassList, fin, numOfClasses);
	sortClasses(ClassList);
	return ClassList;
}

int countClasses()
{
	ifstream fin;
	int numOfClasses = 0;
	fin.open("../data/Classes/Listofclasses.txt");
	fin.get();
	while (!fin.eof()) {
		++numOfClasses;
		fin.ignore(100, '\n');
	}
	fin.close();
	return numOfClasses;
}

//---------------------------------------
bool addAStudentToClass(char* className, char* first_name, char* last_name, char* Gender, char* DoB,
	char* social_ID, char* student_id) {
	if (className[0] != student_id[0] || className[1] != student_id[1]) return false;
	if (!checkDateInput(DoB) || (strcmp(Gender, "Male") != 0 && strcmp(Gender, "Female") != 0))
		return false;

	bool gender;
	if (strcmp(Gender, "Male") == 0) {
		gender = 1;
	}
	else gender = 0;

	string fileName = "../data/Classes/" + string(className) + ".csv";

	student s;
	s.inputAStudent(student_id, first_name, last_name, gender, DoB, social_ID);

	if (!s.checkData()) return false;
	if (!checkStudentExistInClass(s, className)) return false;
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

bool addStudentsWithCSV(char* fileNameIn, char* fileNameOut, student*& stuArr, int& numOfDupsStu) {
	bool returnValue = 1;
	// return true if no duplicate => stuArr = nullptr and numOfDupsStu = 0
	// return false if there are dups => update stuArr and numofDupsStu
	stuArr = new student[100];
	numOfDupsStu = 0;

	ifstream fin;
	fin.open(fileNameIn);
	string fileNameOutAddress = "../data/Classes/" + string(fileNameOut) + ".csv";
	char* fileNameOutAddressChar = new char[100];
	for (int i = 0; i < fileNameOutAddress.size(); i++) {
		fileNameOutAddressChar[i] = fileNameOutAddress[i];
	}
	fileNameOutAddressChar[fileNameOutAddress.size()] = '\0';

	while (!fin.eof()) {
		student s;
		s.inputStudentsWithCSVFile(fin);
		if (s.stuID[0] != fileNameOut[0] || s.stuID[1] != fileNameOut[1]) {
			returnValue = 0;
			stuArr[numOfDupsStu] = s;
			++numOfDupsStu;
			continue;
		}
		if (checkStudentExistInClass(s, fileNameOut)) {
			account stuAcc;
			stuAcc.userName = _strdup(s.stuID);
			stuAcc.password = _strdup(dateToChar(s.Student.dob));
			addinfo(stuAcc, (char*)"../data/student_account.txt");
			s.outputAStudentToFile(fileNameOutAddressChar);
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

bool checkStudentExistInClass(student x, char* className) {
	//return true if the student haven't existed
	//return false if the student have existed
	ifstream fin;
	fin.open("../data/Classes/" + string(className) + ".csv");
	int n = countStudentInClass(className);
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

//---------------------------------------
// 16
student* viewStudentsInClass(char* className)
{
	int n = countStudentInClass(className);
	student* Class = nullptr;
	if (n != 0) {
		Class = new student[n];
	}
	ifstream fin;
	fin.open("../data/Classes/" + string(className) + ".csv");
	for (int i = 0; i < n; i++) {
		Class[i].inputStudentsWithCSVFile(fin);
		fin.ignore(100, '\n');
	}
	fin.close();
	sortToStuID(Class, n);
	return Class;
}

int countStudentInClass(char* className) {
	int numOfStu = 0;
	ifstream fin;
	fin.open("../data/Classes/" + string(className) + ".csv");
	fin.get();
	while (!fin.eof()){
		++numOfStu;
		fin.ignore(100, '\n');
	}
	fin.close();
	return numOfStu;
}

bool CheckData_InputStudents(char* No, char* student_id, char* Gender, char* DoB, char* social_ID)
{
	int NoStu = atoi(No);
	if (NoStu <= 0) return false;

	int n = (int)strlen(student_id);
	if (n != 8) return false;

	int GenderStu = atoi(Gender);
	if (GenderStu != 0 && GenderStu != 1) return false;

	Date tmp;
	tmp.inputADateWithChar(DoB);
	if (checkDateInput(DoB) == false || tmp.checkdata() == false) return false;

	int m = (int)strlen(social_ID);
	if (m != 12) return false;

	return true;
}

// 23 
// Old Code
/*
void viewStuWithScore(char* className, char* schoolYear, char* semester, int*& numOfCoursesPerStudent,
	scoreboard**& ScoresInSemester_Class, course**& CoursesInSemester_Class)
{
	int numOfStuInClass = countStudentInClass(className);
	int numOfCourses = countCourse(schoolYear, semester);
	ScoresInSemester_Class = new scoreboard * [numOfStuInClass];
	CoursesInSemester_Class = new course* [numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)			
	{													
		ScoresInSemester_Class[i] = new scoreboard[numOfCourses];
		CoursesInSemester_Class[i] = new course [numOfCourses];
	}
	numOfCoursesPerStudent = new int[numOfStuInClass] {0};


	student* StuInAClass = viewStudentsInClass(className);
	course* CoursesListInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		countStu(CoursesListInSemester[i], schoolYear, semester);
		int numOfStuInCourse = CoursesListInSemester[i].numOfStu;
		student* StuInCourse = nullptr;
		Load_stu(CoursesListInSemester[i], schoolYear, semester, StuInCourse);
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			for (int k = 0; k < numOfStuInClass; ++k)
			{
				if (strcmp(StuInAClass[k].stuID, StuInCourse[j].stuID) == 0)
				{
					ScoresInSemester_Class[k][numOfCoursesPerStudent[k]] = StuInCourse[j].mark;
					CoursesInSemester_Class[k][numOfCoursesPerStudent[k]] = CoursesListInSemester[i];
					++numOfCoursesPerStudent[k];
					break;
				}
			}
		}
	}
}

int* GetNumOfCoursesPerStudent(char* className, char* schoolYear, char* semester)
{
	int* numOfCoursesPerStudent = nullptr;
	scoreboard** SemesterScores_Class = nullptr;
	course** SemesterCourses_Class = nullptr;
	viewStuWithScore(className, schoolYear, semester, numOfCoursesPerStudent, SemesterScores_Class, SemesterCourses_Class);
	return numOfCoursesPerStudent;
}

scoreboard** GetSemesterScore_Class(char* className, char* schoolYear, char* semester)
{
	int* numOfCoursesPerStudent = nullptr;
	scoreboard** SemesterScores_Class = nullptr;
	course** SemesterCourses_Class = nullptr;
	viewStuWithScore(className, schoolYear, semester, numOfCoursesPerStudent, SemesterScores_Class, SemesterCourses_Class);
	return SemesterScores_Class;
}

course** GetSemesterCourses_Class(char* className, char* schoolYear, char* semester)
{
	int* numOfCoursesPerStudent = nullptr;
	scoreboard** SemesterScores_Class = nullptr;
	course** SemesterCourses_Class = nullptr;
	viewStuWithScore(className, schoolYear, semester, numOfCoursesPerStudent, SemesterScores_Class, SemesterCourses_Class);
	return SemesterCourses_Class;
}
*/

// New Version
int* GetNumOfCoursesPerStudent(char* className, char* schoolYear, char* semester)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	int* numOfCoursesPerStudent = new int[numOfStuInClass] {0};
	for (int i = 0; i < numOfStuInClass; ++i)
		numOfCoursesPerStudent[i] = countCoursesOfAStudent(StuInAClass[i].stuID, schoolYear, semester);
	return numOfCoursesPerStudent;
}

course** GetSemesterCourses_Class(char* className, char* schoolYear, char* semester)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	int numOfCourse = countCourse(schoolYear, semester);
	course** SemesterCourses_Class = new course * [numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i) {
		SemesterCourses_Class[i] = new course[numOfCourse];
		SemesterCourses_Class[i] = viewCoursesOfAStudent(StuInAClass[i].stuID, schoolYear, semester);
	}
	return SemesterCourses_Class;
}

scoreboard** GetSemesterScore_Class(char* className, char* schoolYear, char* semester)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	int numOfScore = countCourse(schoolYear, semester);
	scoreboard** SemesterScores_Class = new scoreboard * [numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i) {
		SemesterScores_Class[i] = new scoreboard[numOfScore];
		SemesterScores_Class[i] = GetsaveScore(StuInAClass[i].stuID, schoolYear, semester);
	}
	return SemesterScores_Class;
}

double* GetSemesterGPA_Class(char* className, char* schoolYear, char* semester)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	double* SemesterGPA_Class = new double[numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)
		SemesterGPA_Class[i] = getSemesterGPA(StuInAClass[i].stuID, schoolYear, semester);
	return SemesterGPA_Class;
}

double* GetOverallGPA_Class(char* className)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	double* OverallGPA_Class = new double[numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)
		OverallGPA_Class[i] = getOverallGPA(StuInAClass[i].stuID);
	return OverallGPA_Class;
}

double* GetScaleFour_SemesterGPA_Class(char* className, char* schoolYear, char* semester)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	double* ScaleFour_SemesterGPA_Class = new double[numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)
		ScaleFour_SemesterGPA_Class[i] = getScaleFour_SemesterGPA(StuInAClass[i].stuID, schoolYear, semester);
	return ScaleFour_SemesterGPA_Class;
}

double* GetScaleFour_OverallGPA_Class(char* className)
{
	student* StuInAClass = viewStudentsInClass(className);
	int numOfStuInClass = countStudentInClass(className);
	double* ScaleFour_OverallGPA_Class = new double[numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)
		ScaleFour_OverallGPA_Class[i] = getScaleFour_OverallGPA(StuInAClass[i].stuID);
	return ScaleFour_OverallGPA_Class;
}

bool CheckClassName(char* className) {
	if (strlen(className) > 10 || strlen(className) < 3)
		return false;
	if ((className[0] >= 48 && className[0] <= 57) && (className[1] >= 48 && className[1] <= 57)) {
		for (int i = 2; i < strlen(className); i++) {
			if ((className[i] < 48) || (className[i] > 57 && className[i] < 65) || (className[i] > 90))
				return false;
		}
		return true;
	}
	return false;
}
bool HaveEmptyLine(string filename) {// return 1 if have empty line
	ifstream f(filename);
	char s[100];
	while (!f.eof()) {
		f.getline(s, 100);
		if (string(s).empty())
			return true;
	}
	f.close();
}
bool CheckValidName(char* name) {
	for (int i = 0; i < strlen(name); i++) {
		if ((name[i] != 32 && name[i] < 65) || (name[i] > 90 && name[i] < 97) || name[i] > 122)
			return false;
	}
	return true;
}
bool CheckFileFormat(string file) {
	if (HaveEmptyLine(file) == 1)return false;
	ifstream f(file);
	int check_int;
	char check_char;
	char check_string[100];
	while (!f.eof()) {
		f >> check_int;
		if (check_int == 0) return false;

		f >> check_char;
		if (check_char != ',')return false;

		f >> check_int;
		if (check_int == 0) return false;

		f >> check_char;
		if (check_char != ',')return false;

		f.get(check_string, 100, ',');
		if (CheckValidName(check_string) == 0)return false;

		f >> check_char;
		if (check_char != ',')return false;

		f.get(check_string, 100, ',');
		if (CheckValidName(check_string) == 0)return false;

		f >> check_char;
		if (check_char != ',')return false;

		f.get(check_string, 100, ',');
		if (string(check_string) != "Male" && string(check_string) != "Female")return false;

		f >> check_char;
		if (check_char != ',')return false;

		f.get(check_string, 100, ',');
		if (checkDateInput(check_string) == 0)return false;

		f >> check_char;
		if (check_char != ',')return false;

		f >> check_int;
		if (check_int == 0)return false;
	}
	return true;
}