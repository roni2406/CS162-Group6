#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct scoreboard {
    double totalMark;
    double finalMark;
    double midtermMark;
    double otherMark;
};

struct person {
    char* firstName;
    char* lastName;
    bool gender; // 0(false) : male; 1(true) : female
    Date dob;
    char* socialID;
};

struct student {
    int No;
    char stuID[9];
    person student;
    scoreboard mark;
};

struct staff {
    char* headTeacher; // if staff is head teacher -> save the class he/she teaches, otherwise none
    char* department; // Ex: khoa CNTT, khoa giao vu, khoa luat...
    char* staffID;
    person staff;
};

struct course {
    char* courseID;
    char* courseName;
    char* className;
    char* teacherName;
    int numOfCre;
    int maxStu = 50;
    char dayofweek[4];
    char sessionHour[3]; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    student* stuOfCourse;
};

struct semester {
    char schoolYear[10];
    int No;
    Date startDate;
    Date endDate;
    int numOfCourse;
    course* courseName;
};

struct Class {
    char* classID;
    int numOfStu;
    student* stuInClass;
};


// At the beginning of a school year (often in September), an academic staff member will:

void addSchoolYear(int schoolYear, char* filename, ofstream& fout); // 1
// user input new school year, let save this year into file

// 2
// void createAClass(Class className, char* filename, ofstream& fout); // 2    
// user input info of a new class, let save this into a new class file
void read_input_user_createAClass(Class& className);
void AddAClassToList(Class& className, ofstream& fout);
void CreateASingleClassList(Class className, ofstream& fout);



void addAStudentToClass(student newStu, char* filename, ofstream& fout); // 3
// user input info of a new student, let save this into a file

// 4
// seperate into 2 function
void inputStudentsToClass(student* newStudents, char* filename, ifstream& fin);
// user input a file
void addStudentToClass(student* newStudents, char* filename, ofstream& fout);
// save the file into text file

// At the beginning of a semester, an academic staff member will:

void CreateASemester(semester newSemester, char* filename, ofstream* fout); // 6
// user input info of a new semester, let save this into a semester file

void AddACourse(course newCourse, char* filename, ofstream* fout); // 7  -Taken
// user input info of a new course in a semester, let save this into a semester file

// void addStudentsToCourse(); // 8
// seperate into 2 function
void inputStudentsToCourse();
void addStudentsToCourse();

void viewCourses(); // 9
void updateCourseInformation(); // 10
void removeStudentToCourse(); // 11
void addAStudentToCourse(); // 12
void DeleteACourse(); // 13



// In a semester, a student still can:
void viewStudingCourses(); // 14



// At any time, an academic staff member can:
void viewClasses(); // 15
void viewStudentsInAClass(); // 16
void viewCourses(); // 17
void viewStudentInACourse(); // 18



// At the end of a semester, an academic staff member can:
void exportStudentsInACourse(); // 19
void importScoreboardOfACourse(); // 20
void viewScoreboardOfACourse(); // 21
void updateStudentResult(); // 22
void importScoreboardOfAClass(); // 23



// When the scoreboard has been published (by the academic staff member), a student can:
void viewScoreboard(); // 24

int main()
{
    return 0;
}