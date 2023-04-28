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

	int n = strlen(student_id);
	if (n != 8) return false;

	int GenderStu = atoi(Gender);
	if (GenderStu != 0 && GenderStu != 1) return false;

	Date tmp;
	tmp.inputADateWithChar(DoB);
	if (checkDateInput(DoB) == false || tmp.checkdata() == false) return false;

	int m = strlen(social_ID);
	if (m != 12) return false;

	return true;
}

// 23 
void viewStuWithScore(char* className, char* schoolYear, char* semester, int*& numOfCoursesPerStudent,
	scoreboard**& saveFinal, char***& courseNameWithScoreBoard)
{
	int numOfStuInClass = countStudentInClass(className);
	int numOfCourses = countCourse(schoolYear, semester);
	saveFinal = new scoreboard * [numOfStuInClass];
	courseNameWithScoreBoard = new char** [numOfStuInClass];
	for (int i = 0; i < numOfStuInClass; ++i)			// Number of Courses occurs in 1 Semester
	{													// 1 students can NOT register more courses than this!
		saveFinal[i] = new scoreboard[numOfCourses];
		courseNameWithScoreBoard[i] = new char* [numOfCourses];
		for (int j = 0; j < numOfCourses; ++j)			// Number of characters in 1 course
			courseNameWithScoreBoard[i][j] = new char[100];
	}
	numOfCoursesPerStudent = new int[numOfStuInClass] {0};

	student* StuInAClass = viewStudentsInClass(className);
	course* CoursesInSemester = viewCoursesInSemester(schoolYear, semester);
	for (int i = 0; i < numOfCourses; ++i)
	{
		countStu(CoursesInSemester[i], schoolYear, semester);
		int numOfStuInCourse = CoursesInSemester[i].numOfStu;
		student* StuInCourse = nullptr;
		Load_stu(CoursesInSemester[i], schoolYear, semester, StuInCourse);
		for (int j = 0; j < numOfStuInCourse; ++j)
		{
			for (int k = 0; k < numOfStuInClass; ++k)
			{
				if (StuInAClass[k].stuID == StuInCourse[j].stuID)
				{
					saveFinal[k][numOfCoursesPerStudent[k]] = StuInCourse[j].mark;
					courseNameWithScoreBoard[k][numOfCoursesPerStudent[k]] = _strdup(CoursesInSemester[i].courseName);
					++numOfCoursesPerStudent[k];
					break;
				}
			}
		}
	}
}