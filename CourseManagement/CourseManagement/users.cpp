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
void student::inputAStudent(char* student_id, char* first_name, char* last_name, bool Gender, char* DoB, char* social_ID) {
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
	fout << "," << "-1";
	fout << "," << "-1";
	fout << "," << "-1";
	fout << "," << "-1";
	fout.close();
}
bool student::checkData() {
	if (!Student.checkData() || strlen(stuID) != 8)
		return false;
	return true;
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
	int n = (int)strlen(fileNameIn);
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
	if (numOfschoolYear > 7) {
		numOfschoolYear = 7;
	}
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
bool checkSemesterAndSchoolYear(char* semester, char* schoolyear) {
	int numSemester = 0;
	ifstream file_schoolyear("../data/schoolYear.txt");
	char* tmp_schoolyear = new char[100];
	while (!file_schoolyear.eof()) {
		file_schoolyear.get(tmp_schoolyear, 100, '\n');
		file_schoolyear.ignore(500, '\n');
		if (strcmp(tmp_schoolyear, schoolyear) == 0) {
			ifstream file_semester("../data/" + (string)(schoolyear)+"/Semester.csv");
			if (!file_semester.is_open()) {
				delete[] tmp_schoolyear;
				return false;
			}

			file_semester.get();
			while (!file_semester.eof()) {
				++numSemester;
				file_semester.ignore(500, '\n');
			}
			if (strcmp(semester, "Fall") == 0 && numSemester >= 1) return true;
			if (strcmp(semester, "Summer") == 0 && numSemester >= 2) return true;
			if (strcmp(semester, "Autumn") == 0 && numSemester >= 3) return true;
			file_semester.close();
		}
	}
	delete[]tmp_schoolyear;
	file_schoolyear.close();
	return false;
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
		fin.ignore(500, '\n');
	}
	s.No = cnt + 1;
	fin.close();
	ofstream fout;
	fout.open(filename, ios::app);
	if (s.No != 1) fout << endl;
	fout << s.No << ",";
	fout << s.stuID << ",";
	fout << s.Student.lastName << "," << s.Student.firstName << ",";
	if (s.Student.gender == 1) fout << "Male,";
	else fout << "Female,";
	s.Student.dob.outputADateToFile(fout);
	fout << "," << s.Student.socialID << ",";
	s.mark.outputScoreBoardToFile(fout);
	fout.close();
}
void InputScoreBoardWithCSV(char* addressOfInputFile, char* addressOfOutputFile)
{
	ifstream fin;
	ofstream fout;
	fin.open(addressOfInputFile);
	fout.open(addressOfOutputFile);
	while (!fin.eof()) 
	{
		student s;
		inputStudentAndScoreWithCSV(fin, s);
		if (s.No != 1) fout << endl;
		fout << s.No << ",";
		fout << s.stuID << ",";
		fout << s.Student.lastName << "," << s.Student.firstName << ",";
		if (s.Student.gender == 1) fout << "Male,";
		else fout << "Female,";
		s.Student.dob.outputADateToFile(fout);
		fout << "," << s.Student.socialID;
		s.mark.outputScoreBoardToFile(fout);
	}
	fin.close();
	fout.close();
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
		if (ListOfStudyingScores[i].totalMark >= 0)
		{
			numOfSemesterCredits += ListOfStudyingCourses[i].numOfCre;
			SemesterGPA += ListOfStudyingCourses[i].numOfCre * ListOfStudyingScores[i].totalMark;
		}
	}
	SemesterGPA /= numOfSemesterCredits;
	return SemesterGPA;
}
double getOverallGPA(char* stuID)
{
	double OverallGPA = 0;
	int numOfStudyingCourses = countOverallNumberOfCourses(stuID);
	course* ListOfStudyingCourses = GetOverallCourseListFromStart(stuID);
	scoreboard* ListOfStudyingScores = GetOverallScoresListFromStart(stuID);
	int numOfOverallCredits = 0;
	for (int i = 0; i < numOfStudyingCourses; ++i)
	{
		if (ListOfStudyingScores[i].totalMark >= 0)
		{
			numOfOverallCredits += ListOfStudyingCourses[i].numOfCre;
			OverallGPA += ListOfStudyingCourses[i].numOfCre * ListOfStudyingScores[i].totalMark;
		}
	}
	OverallGPA /= numOfOverallCredits;
	return OverallGPA;
}
double getTransferScaleTenToFour(double totalMark)
{
	if (totalMark >= 8.5)
		return 4;
	else if (8 <= totalMark && totalMark < 8.5)
		return 3.67;
	else if (7.5 <= totalMark && totalMark < 8)
		return 3.33;
	else if (7 <= totalMark && totalMark < 7.5)
		return 3;
	else if (6.5 <= totalMark && totalMark < 7)
		return 2.67;
	else if (6 <= totalMark && totalMark < 6.5)
		return 2.33;
	else if (5.5 <= totalMark && totalMark < 6)
		return 2;
	else if (5 <= totalMark && totalMark < 5.5)
		return 1.67;
	else if (4.5 <= totalMark && totalMark < 5)
		return 1.33;
	else if (4 <= totalMark && totalMark < 4.5)
		return 1;
	else return 0;
}
double getScaleFour_SemesterGPA(char* stuID, char* schoolYear, char* semester)
{
	double ScaleFour_SemesterGPA = 0;
	course* ListOfStudyingCourses = viewCoursesOfAStudent(stuID, schoolYear, semester);
	scoreboard* ListOfStudyingScores = GetsaveScore(stuID, schoolYear, semester);
	int numOfStudyingCourses = countCoursesOfAStudent(stuID, schoolYear, semester);
	int numOfSemesterCredits = 0;
	for (int i = 0; i < numOfStudyingCourses; ++i)
	{
		if (ListOfStudyingScores[i].totalMark >= 0)
		{
			double FourMark = getTransferScaleTenToFour(ListOfStudyingScores[i].totalMark);
			numOfSemesterCredits += ListOfStudyingCourses[i].numOfCre;
			ScaleFour_SemesterGPA += ListOfStudyingCourses[i].numOfCre * FourMark;
		}
	}
	ScaleFour_SemesterGPA /= numOfSemesterCredits;
	return ScaleFour_SemesterGPA;
}
double getScaleFour_OverallGPA(char* stuID)
{
	double ScaleFour_OverallGPA = 0;
	int numOfStudyingCourses = countOverallNumberOfCourses(stuID);
	course* ListOfStudyingCourses = GetOverallCourseListFromStart(stuID);
	scoreboard* ListOfStudyingScores = GetOverallScoresListFromStart(stuID);
	int numOfOverallCredits = 0;
	for (int i = 0; i < numOfStudyingCourses; ++i)
	{
		if (ListOfStudyingScores[i].totalMark >= 0)
		{
			double FourMark = getTransferScaleTenToFour(ListOfStudyingScores[i].totalMark);
			numOfOverallCredits += ListOfStudyingCourses[i].numOfCre;
			ScaleFour_OverallGPA += ListOfStudyingCourses[i].numOfCre * FourMark;
		}
	}
	ScaleFour_OverallGPA /= numOfOverallCredits;
	return ScaleFour_OverallGPA;
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
bool HaveEmptyLine(string filename) {// return 1 if have empty line
	ifstream fin(filename);
	if (!fin.is_open()) return true;
	string s;
	while (!fin.eof()) {
		getline(fin, s);
		if (s.empty())
			return true;
	}
	fin.close();
	return false;
}
bool CheckValidName(char* name) {
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] >= '0' && name[i] <= '9')
			return false;
	}
	return true;
}
bool CheckFileFormat(string file) {
		//if (HaveEmptyLine(file) == 1)return false;
		ifstream f(file);
		while (!f.eof()) {
			int check_int = 0;
			char check_char = '\0';
			char check_string[100];

			f >> check_int;

			if (check_int == 0) return false;
			check_int = 0;

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

		
			f.get(check_string, 100, ',');
			if (strlen(check_string) != 8) return false;
			for (int i = 0; i < 8; i++) {
				if (check_string[i] < '0' || check_string[i] > '9') return false;
			}

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			f.get(check_string, 100, ',');
			if (CheckValidName(check_string) == 0)return false;

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			f.get(check_string, 100, ',');
			if (CheckValidName(check_string) == 0)return false;

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			f.get(check_string, 100, ',');
			if (string(check_string) != "Male" && string(check_string) != "Female")return false;

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			f.get(check_string, 100, ',');
			if (checkDateInput(check_string) == 0)return false;

			f >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			f.get(check_string, 100, '\n');
			if (strlen(check_string) != 12) return false;
			f.ignore(500, '\n');
		}
		f.close();
		return true;
	}
bool checkMark(char* mark) {
	// check -1 and other mark from 0 to 10.
	if (strcmp(mark, "-1") == 0) return true;
	if (strlen(mark) > 4) return false;

	int numofDot = 0;
	for (int i = 0; i < strlen(mark); i++) {
		if (mark[i] == '.') ++numofDot;
		else if (mark[i] < '0' || mark[i] > '9') return false;
	}

	if (numofDot > 1) return false;
	else if (numofDot == 1) {
		int i = 0;
		// before dot
		// Ex: 7.4 -> check 7
		char* getBeforeDot = new char[5];
		while (mark[i] != '.') {
			getBeforeDot[i] = mark[i];
			++i;
		}
		getBeforeDot[i] = '\0';
		int beforeMark = atoi(getBeforeDot);
		delete[] getBeforeDot;
		if (beforeMark < 0 || beforeMark > 10) return false;
		++i;
		if (beforeMark == 10) {
			if (mark[i] != '0') return false;
		}
	}
	else {
		int intMark = atoi(mark);
		if (intMark < 0 || intMark > 10) return false;
	}
	return true;
}
bool CheckFileFormatWithScoreboard(string file) {
	//if (HaveEmptyLine(file) == 1)return false;
	ifstream fin;
	fin.open(file);
	while (!fin.eof()) {
		int check_int = 0;
		char check_char = '\0';
		char check_string[100];

		fin >> check_int;

		if (check_int == 0) return false;
		check_int = 0;

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';


		fin.get(check_string, 100, ',');
		if (strlen(check_string) != 8) return false;
		for (int i = 0; i < 8; i++) {
			if (check_string[i] < '0' || check_string[i] > '9') return false;
		}

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';

		fin.get(check_string, 100, ',');
		if (CheckValidName(check_string) == 0) return false;

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';

		fin.get(check_string, 100, ',');
		if (CheckValidName(check_string) == 0) return false;

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';

		fin.get(check_string, 100, ',');
		if (string(check_string) != "Male" && string(check_string) != "Female") return false;

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';

		fin.get(check_string, 100, ',');
		if (checkDateInput(check_string) == 0) return false;

		fin >> check_char;
		if (check_char != ',') return false;
		check_char = '\0';

		fin.get(check_string, 100, ',');
		if (strlen(check_string) != 12) return false;
		
		// check scoreboard
		for (int i = 1; i <= 4; i++) {
			fin >> check_char;
			if (check_char != ',')return false;
			check_char = '\0';

			if (i == 4) fin.get(check_string, 100, '\n');
			else fin.get(check_string, 100, ',');
			
			if (!checkMark(check_string)) return false;
		}
		fin.ignore(500, '\n');
	}
	fin.close();
	return true;
}