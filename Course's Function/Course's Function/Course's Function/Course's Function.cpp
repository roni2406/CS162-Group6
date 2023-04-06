#include <iostream>
#include <fstream>
#include "Course.h"
#include "raylib.h"
using namespace std;
void course::Load_stu(char* filename) {
	ifstream f;
	f.open(filename);
	int i = 0;
	if (!f)return;
	while (!f.eof()&&i<50) {
		f >> stuOfCourse[++i].No;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].stuID, 1000);
		f.getline(stuOfCourse[i].person.lastName,100);
		f.getline(stuOfCourse[i].person.firstName, 100);
		f >> stuOfCourse[i].person.gender;
		f >> stuOfCourse[i].person.dob.day;
		f >> stuOfCourse[i].person.dob.month;
		f >> stuOfCourse[i].person.dob.year;
		f.ignore(1, '\n');
		f.getline(stuOfCourse[i].person.socialID, 100);

		numOfStu = i;
	}

}
/*void course::check_stu(char* filename) {
	for (int i = 1; i < numOfStu; i++) {
		for (int k = i + 1; k <=numOfStu; k++)
			if (stuOfCourse[i].stuID == stuOfCourse[k].stuID)
			{
				while (k < numOfStu) {
					stuOfCourse[k] = stuOfCourse[k + 1];
					k;
				}
				--numOfStu;
			}
	}
	//vut may th bi xóa vao file moi 

}
*/
void Load_Course(ListCourse& list) {
	ifstream courses;
	courses.open("Courses.txt");
	int no = 1;
	while(!courses.eof()){
		courses.getline(list.course[no].courseName,1000);
		courses.getline(list.course[no].courseID, 1000);
		courses.getline(list.course[no].teacherName, 1000);
		courses.getline(list.course[no].numOfCre, 1000);	
		courses.getline(list.course[no].dayofweek, 1000);
		courses.getline(list.course[no].sessionHour,1000);
		courses.getline(list.course[no].studentfile, 1000);
		list.course[no].Load_stu(list.course[no].studentfile);
		list.len = no;
		no++; 
	}
	list.len--;
	courses.close();
}

void Course_to_File(ListCourse& list) {
	ofstream courses;
	courses.open("Courses.txt");
	for (int no =1; no <= list.len; no++) {
		courses << list.course[no].courseName << '\n'
			<< list.course[no].courseID << '\n'
			<< list.course[no].teacherName << '\n'
			<< list.course[no].numOfCre << '\n'
			<< list.course[no].dayofweek << '\n'
			<< list.course[no].sessionHour << '\n'
			<< list.course[no].studentfile << '\n';
		
	}

	courses.close();
}
void Stu_to_file(ListCourse &list,int k) {
	ofstream stufile;
	stufile.open(list.course[k].studentfile);
	for (int no = 1; no <= list.course[k].numOfStu; no++) {
		stufile << list.course[k].stuOfCourse[no].No << '\n'
			<< list.course[k].stuOfCourse[no].stuID << '\n'
			<< list.course[k].stuOfCourse[no].person.lastName << '\n'
			<< list.course[k].stuOfCourse[no].person.firstName << '\n'
			<< list.course[k].stuOfCourse[no].person.gender << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.day << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.month << '\n'
			<< list.course[k].stuOfCourse[no].person.dob.year << '\n';
			if (no != list.len)stufile << list.course[k].stuOfCourse[no].person.socialID << '\n';
			else stufile<< list.course[k].stuOfCourse[no].person.socialID;
	}
}
void delete_course(ListCourse& list,int i ) {
	while (i < list.len) {
		list.course[i] = list.course[i+1];
		++i;
	}
	list.len--;
}
void delete_stu(ListCourse& list, int k,int no) {
	while (no < list.course[k].numOfStu) {
		list.course[k].stuOfCourse[no] = list.course[k].stuOfCourse[no+1];
		++no;
	}
	--list.course[k].numOfStu;
}
void update_course(ListCourse &list,int k) {
	bool i = 0;

	Textbox coursename;
	Textbox teachername;
	Textbox ID;
	Textbox nofc;
	Textbox courseday;
	Textbox sshours;
	coursename.textbox = { 270,177,922,77 };
	ID.textbox = { 270,304,922,77 };
	teachername.textbox = { 270, 431,922,77 };
	nofc.textbox = { 270, 558,922,77 };
	courseday.textbox = { 270, 685,330,77 };
	sshours.textbox = { 887,685,330,77 };

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		DrawText("Course Name :", 265, 158, 20, BLUE);
		coursename.worktextbox(i);
		if (coursename.lettercount == 0)DrawText(list.course[k].courseName, 290, 190, 48, LIGHTGRAY);
		else DrawText(coursename.text, 290, 190, 48, BLUE);

		DrawText("ID :", 265, 285, 20, BLUE);
		ID.worktextbox(i);
		if (ID.lettercount == 0)DrawText(list.course[k].courseID, 290,318, 48, LIGHTGRAY);
		else DrawText(ID.text, 290, 318, 48, BLUE);

		DrawText("Teacher Name :", 265, 412, 20, BLUE);
		teachername.worktextbox(i);
		if (teachername.lettercount == 0)DrawText(list.course[k].teacherName, 290,442, 48, LIGHTGRAY);
		else DrawText(teachername.text, 290, 442, 48, BLUE);

		DrawText("Num of cre :", 265, 539, 20, BLUE);
		nofc.worktextbox(i);
		if (nofc.lettercount == 0)DrawText(list.course[k].numOfCre, 290, 570, 48, LIGHTGRAY);
		else DrawText(nofc.text, 290, 570, 48, BLUE);

		DrawText("Course days :", 265, 666, 20, BLUE);
		courseday.worktextbox(i);
		if (courseday.lettercount == 0)DrawText(list.course[k].dayofweek, 290, 693, 48, LIGHTGRAY);
		else DrawText(courseday.text, 290, 693, 48, BLUE);

		DrawText("Session Hours :", 882, 666, 20, BLUE);
		sshours.worktextbox(i);
		if (sshours.lettercount == 0)DrawText(list.course[k].sessionHour, 882+25, 693, 48, LIGHTGRAY);
		else DrawText(sshours.text, 882 + 25, 693, 48, BLUE);

		if (!CheckCollisionPointRec(GetMousePosition(), { 626, 820, 260, 102 })) {
			DrawRectangle(626, 820, 260, 102, BLUE);
			DrawText("  NEXT", 648, 850, 48, WHITE);
		}
		else {
			DrawRectangle(626, 820, 260, 102, DARKBLUE);
			DrawText("  NEXT", 648, 850, 48, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT())) {
			
				if (coursename.lettercount != 0)	strncpy_s(list.course[k].courseName, coursename.text, '\n');
				if(ID.lettercount != 0)			strncpy_s(list.course[k].courseID, ID.text, '\n');
				if(teachername.lettercount != 0 )	strncpy_s(list.course[k].teacherName, teachername.text, '\n');
			    if(nofc.lettercount != 0)			strncpy_s(list.course[k].numOfCre, nofc.text, '\n');
				if(courseday.lettercount != 0)		strncpy_s(list.course[k].dayofweek, courseday.text, '\n');
			    if(sshours.lettercount != 0)		strncpy_s(list.course[k].sessionHour, sshours.text, '\n');
				
			
				Course_to_File(list);

				break;
			}
		}

		EndDrawing();
	}
	viewcourse(list);

}
void Input_course(ListCourse& list){
	Load_Course(list);

	bool i = 0;

	Textbox coursename;
	Textbox teachername;
	Textbox ID;
	Textbox nofc;
	Textbox courseday;
	Textbox sshours;
	coursename.textbox = { 270,177,922,77 };
	ID.textbox = { 270,304,922,77 };
	teachername.textbox = { 270, 431,922,77 };
	nofc.textbox = { 270, 558,922,77 };
	courseday.textbox = { 270, 685,330,77 };
	sshours.textbox = { 887,685,330,77 };

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		DrawText("Course Name :", 265, 158, 20, BLUE);
		coursename.worktextbox(i);
		DrawText(coursename.text, 290, 190, 48, BLUE);

		DrawText("ID :", 265, 285, 20, BLUE);
		ID.worktextbox(i);
		DrawText(ID.text, 290, 318, 48, BLUE);

		DrawText("Teacher Name :", 265, 412, 20, BLUE);
		teachername.worktextbox(i);
		DrawText(teachername.text, 290, 442, 48, BLUE);

		DrawText("Num of cre :", 265, 539, 20, BLUE);
		nofc.worktextbox(i);
		DrawText(nofc.text, 290, 570, 48, BLUE);

		DrawText("Course days :", 265, 666, 20, BLUE);
		courseday.worktextbox(i);
		DrawText(courseday.text, 290, 693, 48, BLUE);

		DrawText("Session Hours :", 882, 666, 20, BLUE);
		sshours.worktextbox(i);
		DrawText(sshours.text, 882 + 25, 693, 48, BLUE);

		if (!CheckCollisionPointRec(GetMousePosition(), { 626, 820, 260, 102 })) {
			DrawRectangle(626, 820, 260, 102, BLUE);
			DrawText("  NEXT", 648, 850, 48, WHITE);
		}
		else {
			DrawRectangle(626, 820, 260, 102, DARKBLUE);
			DrawText("  NEXT", 648, 850, 48, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT())) {
				TextCopy(list.course[++list.len].courseName, coursename.text);
				strncpy_s(list.course[list.len].courseID, ID.text, '\n');
				strncpy_s(list.course[list.len].teacherName, teachername.text, '\n');
				strncpy_s(list.course[list.len].numOfCre, nofc.text, '\n');
				strncpy_s(list.course[list.len].dayofweek, courseday.text, '\n');
				strncpy_s(list.course[list.len].sessionHour, sshours.text, '\n');
				break;
			}
		}
		
		EndDrawing();
	}
	Stus_to_Course(list);
	Course_to_File(list);
}
void Stus_to_Course(ListCourse& list) {

	char* file = new char[1000]; bool filedropped=0;
		while (!WindowShouldClose()) {
			if (IsFileDropped())
			{
				FilePathList droppedFiles = LoadDroppedFiles();
				TextCopy(file, droppedFiles.paths[0]);
				filedropped = 1;
				UnloadDroppedFiles(droppedFiles);
			}
			
			BeginDrawing();
			ClearBackground(WHITE);

			DrawText("INSERT STUDENTS TO COURSE", 350, 60, 50, BLUE);
			DrawText("Enter Csv file contain list of students", 250, 150, 50, BLUE);
			if(filedropped)
			DrawText(file, 200, 255, 48, BLUE);
			else DrawText("Drop Here ", 626, 255, 48,GRAY);

			if (!CheckCollisionPointRec(GetMousePosition(), { 626, 620, 260, 102 })) {
				DrawRectangle(626, 620, 260, 102, BLUE);
				DrawText("  NEXT", 648, 650, 48, WHITE);
			}
			else {
				DrawRectangle(626, 620, 260, 102, DARKBLUE);
				DrawText("  NEXT", 648, 650, 48, GRAY);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT())) {
					if (filedropped) {
						TextCopy(list.course[list.len].studentfile, file);
						Course_to_File(list);
						list.course[list.len].Load_stu(file);
					}
					break;
				}
			}
			EndDrawing();
		}
		delete[]file;
}
void viewcourse(ListCourse& list) {
	Load_Course(list);
	float Pos = 0;
	float scrollSpeed = 35;
	/*Texture2D button_up, button_down;
	button_up = LoadTexture("but.png");
	button_down = LoadTexture("tub.png");
	float Yrec = button_up.height + Pos / 1500 * 920;
	float recheight = (920 - 2 * button_up.height) * 920 / (1500 + 920);
	float tmp = 0;*/

	bool rc = 0, Is_update = 0, viewStu = 0; float x = 0,y = 0,y_gap=0;int del;
	while (!WindowShouldClose()) {
	
		Pos += (GetMouseWheelMove() * scrollSpeed - 20*float(IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)));
	//	Yrec = button_up.height - float(Pos * (920 - 2 * button_up.height) / (1500 + 920));
		if (Pos > 0)Pos = 0;
		if (Pos < -(float(list.len)* 982 / 6))Pos = -(float(list.len) * 982 /6);//num of course/6*wight
		BeginDrawing();
		ClearBackground(SKYBLUE);
/*2 cai nut//////////////////
		DrawTexture(button_up, 1500, 0, WHITE);
		DrawTexture(button_down, 1500, 890, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), { 1590, 0, float(button_up.width),float(button_up.height) })) {
			DrawTexture(button_up, 1500, 0, LIGHTGRAY);
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
				DrawTexture(button_up, 1500, 0, GRAY);
				Pos += 1.0;
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), { 1500,890,float(button_down.width),float(button_down.height) })) {
			DrawTexture(button_down, 1500, 890, LIGHTGRAY);
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
				DrawTexture(button_down, 1500, 890, GRAY);
				Pos -= 1.0;
			}
		}*/
/* Cai thanh//////////////////////////////////////
		if (CheckCollisionPointRec(GetMousePosition(), { 1500,Yrec,float(button_down.width),recheight }) && IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
			DrawRectangle(1590, Yrec, button_up.width, recheight, LIGHTGRAY);
			tmp = Yrec - GetMouseY();
		}
		if (!CheckCollisionPointRec(GetMousePosition(), { 1500,Yrec,float(button_down.width),recheight }) && check == 0)DrawRectangle(1590, Yrec, button_up.width, recheight, RAYWHITE);
		if (CheckCollisionPointRec(GetMousePosition(), { 1500,Yrec,float(button_down.width),recheight }) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))check = 1;
		if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))check = 0;
		if (check == 1) {
			
			Yrec = tmp + float(GetMouseY());
			Pos = (float(button_up.height) - Yrec) * (1500 + 920) / (920 - 2 * float(button_up.height));
			
			if (Pos > 0) { Pos = 0; 
			Yrec = float(button_up.height) - float(Pos * (920 - 2 * float(button_up.height)) / (1500 + 920));
			}
			
			if (Pos < -1500) { Pos = -1500; 
			Yrec = float(button_up.height) - float(Pos * (920 - 2 * float(button_up.height)) / (1500 + 920)); 
			}
			DrawRectangle(1590, Yrec, button_up.width, recheight, GRAY);
		}*/
///////////////////////////////////////////////////////////////
		int i = 0;
		for (int k = 1; k <=list.len; k++) {
			if (CheckCollisionPointRec(GetMousePosition(), { 10,Pos + i + 10,300, 140 })) {
				DrawRectangleLines(10, Pos + i + 10, 300, 140,BLACK);
				if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
					del = k;
					rc = 1;
					x = float(GetMouseX());
					y_gap = float(GetMouseY()-Pos);
				}
			}
			else DrawRectangleLines(10,Pos+i+10,300, 140,WHITE);
			y = Pos + y_gap;
			DrawText(TextFormat("%s%s", "Course: ", list.course[k].courseName), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "ID: ", list.course[k].courseID), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Teacher: ", list.course[k].teacherName), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Number of Credit: ", list.course[k].numOfCre), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Course Day: ", list.course[k].dayofweek), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Session Hours: ", list.course[k].sessionHour), 17, Pos + (i += 20), 20, MAROON);
			if (rc) {
				DrawRectangle(x,y,160, 75, LIGHTGRAY);
				DrawText("Delete", x + 7, y + 3, 20, MAROON);
				DrawLine(x, y + 25, x +160, y + 25, BLACK);
				DrawText("Update", x + 7, y + 3 + 25, 20, MAROON);
				DrawLine(x, y + 50, x +160, y +50, BLACK);
				DrawText("View Students ", x + 7, y + 3 + 50, 20, MAROON);

				if (CheckCollisionPointRec(GetMousePosition(), { x,y,160,25 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))delete_course(list, del);
				if (CheckCollisionPointRec(GetMousePosition(), { x,y + 25,160,25 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))Is_update = 1;
				if (CheckCollisionPointRec(GetMousePosition(), { x,y + 50,160,25 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))viewStu = 1;
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))rc = 0;
			}
			i += 50;
		}
		if (Is_update||viewStu)break;
		EndDrawing();
	}
	if (viewStu)view_Stu(list, del);
	if (Is_update)update_course(list, del);

	Course_to_File(list);
}
void view_Stu(ListCourse& list,int k) {

	float Pos = 0;
	float scrollSpeed = 35;
	float x, y; bool rc=0; int del;
	while (!WindowShouldClose()) {
		Pos += (GetMouseWheelMove() * scrollSpeed - 20 * float(IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)));
		if (Pos > 0)Pos = 0;
	//	if (Pos < -(float(list.len) * 982 / 12))Pos = -(float(list.len) * 982 / 12);//num of course/6*wight
		BeginDrawing();
		ClearBackground(SKYBLUE);
	
		int i = 0;
		for (int no = 1; no <= list.course[k].numOfStu; no++) {
			if (CheckCollisionPointRec(GetMousePosition(), { 10,Pos + i + 10,300, 140 })) {
				DrawRectangleLines(10, Pos + i + 10, 300, 140, BLACK);
				if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
					del = no;
					rc = 1;
					x = float(GetMouseX());
					y = float(GetMouseY());
				}
			}
			else DrawRectangleLines(10, Pos + i + 10, 300, 140, WHITE);

			DrawText(TextFormat("%s%i", "No: ", list.course[k].stuOfCourse[no].No), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "ID: ", list.course[k].stuOfCourse[no].stuID), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "First Name: ", list.course[k].stuOfCourse[no].person.firstName), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Last name: ", list.course[k].stuOfCourse[no].person.lastName), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%i/%i/%i", "Day of birth: ", list.course[k].stuOfCourse[no].person.dob.day, list.course[k].stuOfCourse[no].person.dob.month, list.course[k].stuOfCourse[no].person.dob.year), 17, Pos + (i += 20), 20, MAROON);
			DrawText(TextFormat("%s%s", "Social ID: ", list.course[k].stuOfCourse[no].person.socialID), 17, Pos + (i += 20), 20, MAROON);
			if (rc) {
				DrawRectangle(x, y, 80, 25, LIGHTGRAY);
				DrawText("Delete", x + 7, y + 3, 20, MAROON);
				
			
				if (CheckCollisionPointRec(GetMousePosition(), { x,y,80,25 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) delete_stu(list, k, del);
				
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))rc = 0;
			}
			i += 50;
		}
		EndDrawing();
	}
	Stu_to_file(list, k);

}


int main(void){
	ListCourse list;
	InitWindow(1512, 982, "d");
	Input_course(list);
	viewcourse(list);

	CloseWindow();
}
	




 
