#include <iostream>
#include <fstream>
#include "Class.h"
#include <raylib.h>
#include "Function.h"
using namespace std;
ifstream fin;
ofstream fout;

int main()
{
    account CurrentUser;
    InitWindow(screenWidth, screenHeight, "Course Management System");
    addStudentPage(screenWidth, screenHeight, CurrentUser);
    StudentorStaffPage(screenWidth, screenHeight, CurrentUser);
    return 0;
}



