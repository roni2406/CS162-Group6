#pragma once

#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>
#include "back_end.h"
using namespace std;

const int screenWidth = 1512;
const int screenHeight = 982;
const int MAX_INPUT_CHARS = 18;

//// Page
void LogInPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void SignUpPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void ProfilePage(const int screenWidth, const int screenHeight, account& CurrentUser);
void ChangePasswordPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void CreateSchoolYearPage(const int screenWidth,const int screenHeight, account& CurrentUser); 

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
	int State = 0;					// Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool Action = false;			// Button action should be activated
	void workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser));
};

// used for "bo-goc" button and have 2 cases display (in process)
struct Button2 {
	const int screenHeight = 982;
	Texture2D texture;
	float frameHeight;
	Rectangle sourceRec;
	Rectangle btnBounds;
	int State;
	bool Action;
	bool Display;
	void workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser));
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


