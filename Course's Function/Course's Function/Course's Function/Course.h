#include <iostream>
#include"raylib.h"
using namespace std;
#ifndef COURSE_H
#define COURSE_H

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
    char firstName[10];
    char lastName[20];
    bool gender; // 0(false) : male; 1(true) : female
    Date dob;
    char socialID[20];
};

struct student {
    int No;
    char stuID[9];
    person person;
    scoreboard mark;
};

struct course {
    char courseID[30];
    char courseName[30];
    char className[30];
    char teacherName[30];
    char numOfCre[30];
    int numOfStu = 0;
    int maxStu = 50;
    char dayofweek[30];
    char sessionHour[30]; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)).
    // A course will be taught in only one session in a week
    char studentfile[30];
    student stuOfCourse[50];
    void Load_stu(char* filename);

};

struct ListCourse {
    course course[50];
    int len = 0;
};
struct Textbox {
    char text[20 + 1] = "\0";
    int lettercount = 0;
    Rectangle textbox;
    bool mouseontextbox = false;
    bool check = 0;
    void worktextbox(bool& somethingfalsedisplay);
};
void Textbox::worktextbox(bool& somethingfalsedisplay) {
    if (CheckCollisionPointRec(GetMousePosition(), textbox)) mouseontextbox = true;
    else mouseontextbox = false;
    if (mouseontextbox)
    {
        // Set the window's cursor to the I-Beam
        //SetMouseCursor(MOUSE_CURSOR_IBEAM);
    }
        // Get char pressed (unicode character) on the queue
        if (mouseontextbox&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) check = 1;
        if (check == 1) {
            int key = GetCharPressed();
            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (lettercount < 20))
                {
                    text[lettercount] = (char)key;
                    text[lettercount + 1] = '\0'; // Add null terminator at the end of the string.
                    lettercount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                lettercount--;
                if (lettercount < 0) lettercount = 0;
                text[lettercount] = '\0';
            }
        }
    
    if (!mouseontextbox && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))check = 0;
    if (check) {
        DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, BLUE);
        DrawRectangleLines((int)textbox.x - 1, (int)textbox.y - 1, (int)textbox.width + 2, (int)textbox.height + 2, BLUE);
        DrawRectangleLines((int)textbox.x - 2, (int)textbox.y - 2, (int)textbox.width + 4, (int)textbox.height + 4, BLUE);
        somethingfalsedisplay = false;
    }
    else DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, LIGHTGRAY);

}
void Stus_to_Course(ListCourse& list);
void viewcourse(ListCourse &list);
void view_Stu(ListCourse& list, int k);
#endif