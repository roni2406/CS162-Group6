#pragma once

#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>
#include "account.h"
#include "schoolYear.h"
#include "semester.h"
#include "course.h"
using namespace std;

const int screenWidth = 1512;
const int screenHeight = 982;
const int MAX_INPUT_CHARS = 50;
const int MAX_SCHOOLYEARS = 10;


//// Page
void StudentorStaffPage(const int screenWidth, const int screenHeight, account& CurrentUser);

void LogInPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser);
void LogInPageStaff(const int screenWidth, const int screenHeight, account& CurrentUser);

void SignUpPage(const int screenWidth, const int screenHeight, account& CurrentUser);

void ProfilePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser); // need to add information about student
void ViewCoursesPageStudent();
void CoursePageStudent();
void ScoreboardStudent();

void ProfilePageStaff(const int screenWidth, const int screenHeight, account& CurrentUser); // need to add information about staff

void ChangePasswordPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser);
void ChangePasswordPageStaff(const int screenWidth, const int screenHeight, account& CurrentUser);

void CreateSchoolYearPage(const int screenWidth,const int screenHeight, account& CurrentUser); 
void ViewSchoolYearsPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void SchoolYearPage(const int screenWidth, const int screenHeight, account& CurrentUser, char* &Year);
void viewClassinSchoolYearPage(); // thay bao z 

void createClassPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void ViewClassesPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void ClassPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void addStudentPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void addStudentCSV(const int screenWidth, const int screenHeight,char* classname, account& CurrentUser);


void CreateSemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char* &Year);
void ViewSemestersPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year);
void SemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester); // need to include struct semester to display and save data

void CreateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester); // need to include struct semester to display and save data
void ViewCoursesPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester); // need to include struct semester to display and save data
void CoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char* &Semester, course& Course); // need to include struct semester, course to display and save data

// in course page have following functions: delete, view student in the course, add student, delete student
void DeleteCoursePage(); //?
void StudentCoursePage(); // ?
void addStudentPage();
void deleteStudentPage();
// export list student in the course
void scoreboardPage();

//// Objects

/// button:

// used for "bo-goc" button and have 1 case display ( can be used now)
struct Button1 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Texture2D texture;
	float frameHeight;
	Rectangle sourceRec;
	Rectangle btnBounds;
	int state = 0;					// Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool action = false;			// Button action should be activated
	void workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser));
};

// used for just-text button
struct Button2 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Rectangle button = { 0, 0, 0, 0 };
	bool mouseonbutton = false;
	bool action = false;
	void workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser));

};

// used for "bo-goc" button that need to update information Year
struct Button3 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Texture2D texture;
	float frameHeight;
	Rectangle sourceRec;
	Rectangle btnBounds;
	int state = 0;					// Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool action = false;			// Button action should be activated
	void workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a));
};

//used for button that need to update information Year
struct Button4 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Rectangle button = { 0, 0, 0, 0 };
	bool mouseonbutton = false;
	bool action = false;
	bool state = true;
	void workbutton(Vector2 mousePoint, account& CurrentUser, char* &a, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char* &a));
};

// used for "bo-goc" button that need to update information Year, Semester
struct Button5 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Texture2D texture;
	float frameHeight;
	Rectangle sourceRec;
	Rectangle btnBounds;
	int state = 0;					// Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool action = false;			// Button action should be activated
	void workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b));
};
//used for button that need to update information Year, Semester
struct Button6 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Rectangle button = { 0, 0, 0, 0 };
	bool mouseonbutton = false;
	bool action = false;
	void workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b));
};
// used for just-text button which move to Course
struct Button7 {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Rectangle button = { 0, 0, 0, 0 };
	bool mouseonbutton = false;
	bool action = false;
	void workbutton(Vector2 mousePoint, account& CurrentUser, char*&a, char*& b, course& c, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b, course& c));

};
/// textbox

// used for normal-text textbox
struct Textbox1 {
	char text[MAX_INPUT_CHARS + 1] = "\0";
	int lettercount = 0;
	Rectangle textbox;
	bool mouseontextbox = false;
	void worktextbox(bool& somethingfalsedisplay);
};

// used for hidden-text textbox (such as password)
struct Textbox2 {
	char text[MAX_INPUT_CHARS + 1] = "\0";
	char hiddentext[MAX_INPUT_CHARS + 1] = "\0";
	int lettercount = 0;
	int lettercounthidden = 0;
	Rectangle textbox;
	bool mouseontextbox = false;
	void worktextbox(bool& somethingfalsedisplay);
};

// schoolyear text (use for multiple page (global variable))


