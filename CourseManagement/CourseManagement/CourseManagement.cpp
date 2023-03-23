#include <iostream>
#include <fstream>
#include <raylib.h>
#include "Function.h"

using namespace std;
#define MAX_INPUT_CHARS 20


int main()
{
    const int screenWidth = 1512;
    const int screenHeight = 982;
    InitWindow(screenWidth, screenHeight, "MainPage");
    drawloginPage();
    return 0;
}



