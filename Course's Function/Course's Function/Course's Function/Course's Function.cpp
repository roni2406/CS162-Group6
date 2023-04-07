#include <iostream>
#include <fstream>
#include "Course.h"
#include "raylib.h"
using namespace std;

int main() {
	ListCourse list;
	InitWindow(1512, 982, "d");
	Input_course(list);
	viewcourse(list);

	CloseWindow();
	return 0;
}
	




 
