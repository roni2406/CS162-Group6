#include <iostream>
#include <fstream>
#include "Class.h"
#include <raylib.h>
#include "Function.h"

using namespace std;
#define MAX_INPUT_CHARS 20
ifstream fin;
ofstream fout;

int main()
{   
    account CurrentUser;
    InitWindow(screenWidth, screenHeight, "Course Management System");
    //StudentorStaffPage(screenWidth, screenHeight, CurrentUser);
    
    addStudentPage(screenWidth, screenHeight, CurrentUser);
    return 0;
}



