#include <iostream>
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
//filename is a file which data will be add to
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

//void addAStaff(char* filename, char* first_name, char* last_name, bool Gender, char* DoB,
//	char* social_ID, char* staff_id) {
//
//	staff s;
//	person a;
//	a.inputAPerson(first_name, last_name, Gender, DoB, social_ID);
//	s.inputAStaff(staff_id, a);
//
//	ofstream fout;
//	fout.open(filename, ios::app);
//	s.outputAStaffToFile(fout);
//	fout.close();
//}

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

bool checkdata_FileName(char* fileNameIn)
{
	int n = strlen(fileNameIn);
	if (fileNameIn[n - 4] == '.' && fileNameIn[n - 3] == 'c'
		&& fileNameIn[n - 2] == 's' && fileNameIn[n - 1] == 'v') return true;
	else return false;
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
	//fin.open("../data/" + string(schoolYear) + "/" + string(semester)
		//+ "/" + string(courseName) + ".csv");
	fin.open(addressOfOutputFile);
	while (!fin.eof()) 
	{
		student s;
		inputStudentAndScoreWithCSV(fin, s);
	}
	fin.close();
}
