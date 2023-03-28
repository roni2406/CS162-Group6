#include <iostream>
#include <fstream>
#include <raylib.h>
#include "Function.h"

using namespace std;
#define MAX_INPUT_CHARS 20


int main()
{   
    account CurrentUser;
    InitWindow(screenWidth, screenHeight, "MainPage");
    StudentorStaffPage(screenWidth, screenHeight, CurrentUser);
    
    
    return 0;
}



