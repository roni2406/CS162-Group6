#include <iostream>
#include <fstream>
#include <raylib.h>
#include "account.h"
#include "Function.h"
#include "schoolYear.h"

using namespace std;


//FRONT_END--------------------------------------------------------
void StudentorStaffPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,screenWidth,screenHeight};
	Vector2 mousePoint = { 0.0f, 0.0f };

	Texture2D student = LoadTexture("student.png");
	Texture2D staff = LoadTexture("staff.png");


	Button3 Student;
	Student.button = { 53, 295, 645, 518 };

	Button3 Staff;
	Staff.button = { 839, 295, 645, 518 };

	SetTargetFPS(40);
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("COURSE MANAGEMENT SYSTEM", 430, 10, 40, DARKBLUE);
		DrawRectangleRec(Student.button, WHITE);
		DrawRectangleRec(Staff.button, WHITE);

		mousePoint = GetMousePosition();
		Staff.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		Student.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		EndDrawing();
	}
	CloseWindow();

}
void LogInPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,screenWidth,screenHeight };
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		EndDrawing();
	}
	CloseWindow();
}
void LogInPageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {

	Rectangle background = { 0,0,screenWidth,screenHeight};

	//Initialize textbox-------------------------------------------------------
	Textbox1 username;
	username.textbox = { 477, 239,558,106 };

	Textbox2 password;
	password.textbox = { 477, 403,558,106 };
	
	Button3 backtopreviouspage;
	backtopreviouspage.button = { 1200, 20, 300, 30 };
	////initialize login button---------------------------------------------------------------------------------------------------
	Texture2D loginButton = LoadTexture("loginButton.png");

	float frameHeightloginButton = (float)loginButton.height;
	Rectangle sourceRecloginButton = { 0, 0, (float)loginButton.width, frameHeightloginButton };
	// Define button bounds on screen
	Rectangle btnBoundsloginButton = { (screenWidth / 2.0f - loginButton.width / 2.0f) - 10, 550, (float)loginButton.width, frameHeightloginButton };

	int loginbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool loginbtnAction = false;         // Button action should be activated
	bool isLoginFalseDisplay = false;
   
	////initialize signup button---------------------------------------------------------------------------------------------------
	Button1 SignUp;
	SignUp.texture = LoadTexture("signupButton.png");
	SignUp.frameHeight = (float)SignUp.texture.height;
	SignUp.sourceRec = { 0, 0, (float)SignUp.texture.width, SignUp.frameHeight };
	SignUp.btnBounds = { (screenWidth / 2.0f - SignUp.texture.width / 2.0f) - 10, 650, (float)SignUp.texture.width, SignUp.frameHeight };

	////initialize for login--------------------------------------------------------------------------------------------------------------

	account inputLoginData;
	Vector2 mousePoint = { 0.0f, 0.0f };
	
	SetTargetFPS(40);
	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//Draw--------------------------------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE,DARKBLUE,DARKBLUE,SKYBLUE);
		DrawRectangle(347, 173, 818, 560, WHITE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawText("Back to the previous page", 1200, 20, 20, DARKBLUE);
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(backtopreviouspage.button, WHITE);
		DrawRectangleRec(password.textbox, LIGHTGRAY);
		DrawText("* Username", 477, 200, 30, DARKBLUE);
		DrawText("* Password", 477, 364, 30, DARKBLUE);
		DrawText("or", 735, 615, 30,DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		username.worktextbox(isLoginFalseDisplay);
		password.worktextbox(isLoginFalseDisplay);


		DrawText(username.text, 500, 270, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(password.hiddentext, 500, 440, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);

		////Function of login button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		loginbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
		}
		else loginbtnState = 0;

		inputLoginData.userName = _strdup(username.text);
		inputLoginData.password = _strdup(password.text);

		if (loginbtnAction)
		{
			
			if (LoginFunction(inputLoginData)) {
				CurrentUser.password = password.text;
				CurrentUser.userName = username.text;
				ProfilePageStaff(screenWidth, screenHeight, CurrentUser);
			}
			else isLoginFalseDisplay = true;
		}
		if (isLoginFalseDisplay) DrawText("Invalid username or password!", 477, 520, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecloginButton.y = loginbtnState * frameHeightloginButton;
		DrawTextureRec(loginButton, sourceRecloginButton, { btnBoundsloginButton.x, btnBoundsloginButton.y }, WHITE); // Draw button frame
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		////Function of signup button-------------------------------------------------------------------------------------------------------------------------
		backtopreviouspage.workbutton(mousePoint, CurrentUser, StudentorStaffPage);
		SignUp.workbutton(mousePoint, CurrentUser, SignUpPage);
		EndDrawing();
	}
	CloseWindow();
}

void SignUpPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,screenWidth,screenHeight};

	//Initialize---------------------------------------------------------------------
	Textbox1 username;
	username.textbox = { 471, 200, 558, 112 };

	Textbox2 password;
	password.textbox = { 471, 373, 558, 112 };
	Textbox2 confirmpass;
	confirmpass.textbox = { 471, 546, 558, 112 };

	Button3 backtologinsite;
	backtologinsite.button = { 1300, 20, 200, 30 };



	////initialize signup button---------------------------------------------------------------------------------------------------
	Texture2D signupButton = LoadTexture("signupButton.png");
	float frameHeightsignupButton = (float)signupButton.height;
	Rectangle sourceRecsignupButton = { 0, 0, (float)signupButton.width, frameHeightsignupButton };
	Rectangle btnBoundssignupButton = { (screenWidth / 2.0f - signupButton.width / 2.0f) - 10, 700, (float)signupButton.width, frameHeightsignupButton };

	int signupbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool signupbtnAction = false;         // Button action should be activated
	bool issignupFalseDisplay = false;

	//// initialize for sign up-------------------------------------------------------------------------------------------------------
	account newinfo;

	Vector2 mousePoint = { 0.0f, 0.0f };

	//SetTargetFPS(40);

	//Draw----------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(348, 110, 800, 680, WHITE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawRectangleRec(backtologinsite.button, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawText("Back to Log in Site", 1300, 20, 20, DARKBLUE);
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(password.textbox, LIGHTGRAY);
		DrawRectangleRec(confirmpass.textbox, LIGHTGRAY);
		DrawText("* Username", 471, 165, 30, DARKBLUE);
		DrawText("* Password", 471, 338, 30, DARKBLUE);
		DrawText("* Confirm Password", 471, 511, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		username.worktextbox(issignupFalseDisplay);
		password.worktextbox(issignupFalseDisplay);
		confirmpass.worktextbox(issignupFalseDisplay);
		

		DrawText(username.text, 500, 231, 40, DARKBLUE);
		DrawText(password.hiddentext, 500, 400, 40, DARKBLUE);
		DrawText(confirmpass.hiddentext, 500, 573, 40, DARKBLUE);

		DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmpass.lettercount, MAX_INPUT_CHARS), 1050, 620, 20, DARKBLUE);
		////-------------------------------------------------------------------------------------------------------------------------------------------------

		////Function of signup button------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		signupbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundssignupButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) signupbtnAction = true;
		}
		else signupbtnState = false;

		newinfo.userName = _strdup(username.text);
		newinfo.password = _strdup(password.text);

		if (signupbtnAction)
		{
			if (username.text[0] == '\0' || password.text[0] == '\0' || confirmpass.text[0] == '\0') {
				issignupFalseDisplay = true;
			}
			else if (SignupFunction(newinfo, confirmpass.text)) {
				issignupFalseDisplay = false;
				LogInPageStaff(screenWidth, screenHeight, CurrentUser);
			}
			else
				issignupFalseDisplay = true;
		}
		if (issignupFalseDisplay) DrawText("Username have been used or wrong password! Please try again!", 430, 673, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecsignupButton.y = signupbtnState * frameHeightsignupButton;
		DrawTextureRec(signupButton, sourceRecsignupButton, { btnBoundssignupButton.x, btnBoundssignupButton.y }, WHITE); // Draw button frame

		///Function of back to log in site
		backtologinsite.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		EndDrawing();
	}
	CloseWindow();

}
void ProfilePageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {
	////Initialize variable---------------------------------------------------------------------------------------------
	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,screenWidth,screenHeight};
	
	Button1 ChangePass;
	ChangePass.texture = LoadTexture("changePassBtn.png");
	ChangePass.frameHeight = (float)ChangePass.texture.height;
	ChangePass.sourceRec = { 0, 0, (float)ChangePass.texture.width, ChangePass.frameHeight };
	ChangePass.btnBounds = { 170, 800, (float)ChangePass.texture.width, ChangePass.frameHeight };

	Button1 LogOut;
	LogOut.texture = LoadTexture("logOutBtn.png");
	LogOut.frameHeight = (float)LogOut.texture.height;
	LogOut.sourceRec = { 0, 0, (float)LogOut.texture.width,LogOut.frameHeight };
	LogOut.btnBounds = { 170, 730, (float)LogOut.texture.width,LogOut.frameHeight };

	Button1 CreateSchoolYear;
	CreateSchoolYear.texture = LoadTexture("createSchoolYearBtn.png");
	CreateSchoolYear.frameHeight = (float)CreateSchoolYear.texture.height;
	CreateSchoolYear.sourceRec = { 0, 0, (float)CreateSchoolYear.texture.width, CreateSchoolYear.frameHeight };
	CreateSchoolYear.btnBounds = { 552, 277, (float)CreateSchoolYear.texture.width, CreateSchoolYear.frameHeight };
	
	Button1 ViewSchoolYear;
	ViewSchoolYear.texture = LoadTexture("viewschoolyearbtn.png");
	ViewSchoolYear.frameHeight = (float)ViewSchoolYear.texture.height;
	ViewSchoolYear.sourceRec = { 0, 0, (float)ViewSchoolYear.texture.width, ViewSchoolYear.frameHeight };
	ViewSchoolYear.btnBounds = { 1081, 277, (float)ViewSchoolYear.texture.width, ViewSchoolYear.frameHeight };

	Button1 CreateClass;
	CreateClass.texture = LoadTexture("createClassBtn.png");
	CreateClass.frameHeight = (float)CreateClass.texture.height;
	CreateClass.sourceRec = { 0, 0, (float)CreateClass.texture.width, CreateClass.frameHeight };
	CreateClass.btnBounds = { 552, 605, (float)CreateClass.texture.width, CreateClass.frameHeight };

	Button1 ViewClass;
	ViewClass.texture = LoadTexture("createClassBtn.png");
	ViewClass.frameHeight = (float)ViewClass.texture.height;
	ViewClass.sourceRec = { 0, 0, (float)ViewClass.texture.width, ViewClass.frameHeight };
	ViewClass.btnBounds = { 1081, 605, (float)ViewClass.texture.width, ViewClass.frameHeight };
	
	//Position of schoolyear---------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		BeginDrawing();
		DrawText("WELCOME!", 670, 15, 40, DARKBLUE);

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);

		DrawRectangle(70, 170, 360, 750, WHITE);
		DrawRectangleLines(69, 169, 362, 752, BLACK);
		DrawRectangleLines(68, 168, 364, 754, BLACK);

		DrawRectangle(480, 170, 980, 750, WHITE);
		DrawRectangleLines(479, 169, 982, 752, BLACK);
		DrawRectangleLines(478, 168, 984, 754, BLACK);

		DrawRectangle(480, 108, 250, 60, WHITE);
		DrawRectangleLines(479, 107, 252, 62, BLACK);
		DrawRectangleLines(478, 106, 254, 64, BLACK);
		DrawText("School Years", 500, 123, 30, DARKBLUE);

		DrawTexture(avatar, 150, 100, WHITE);
		DrawText("Username: ", 90, 330, 20, DARKBLUE);
		DrawText(CurrentUser.userName, 200, 330, 20, DARKGRAY);

		mousePoint = GetMousePosition();
		////change password button function-----------------------------------------------------------------------------------------------------------
		ChangePass.workbutton(mousePoint, CurrentUser, ChangePasswordPage);
		LogOut.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		CreateSchoolYear.workbutton(mousePoint, CurrentUser, CreateSchoolYearPage);
		ViewSchoolYear.workbutton(mousePoint, CurrentUser, ViewSchoolYearPage);
		CreateClass.workbutton(mousePoint, CurrentUser, createClassPage);
		ViewClass.workbutton(mousePoint, CurrentUser, ViewClassesPage);

		//// display schoolyear from createschoolyear page--------------------------------------------------------------------------------------------
		EndDrawing();
	}
	CloseWindow();
}

void ChangePasswordPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,screenWidth,screenHeight};
	Vector2 mousePoint = { 0.0f, 0.0f };

	Textbox2 oldpass;
	oldpass.textbox = { 477, 239, 558, 106 };

	Textbox2 newpass;
	newpass.textbox = { 477, 403, 558, 106 };

	Textbox2 confirmnewpass;
	confirmnewpass.textbox = { 477, 567, 558, 106 };

	Button3 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	bool isChangePassFalseDisplay = false;
	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 710, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);

		DrawRectangle(347, 173, 818, 630, WHITE);
		DrawRectangleRec(oldpass.textbox, LIGHTGRAY);
		DrawRectangleRec(newpass.textbox, LIGHTGRAY);
		DrawRectangleRec(confirmnewpass.textbox, LIGHTGRAY);
		DrawText("* Old Password", 477, 200, 30, DARKBLUE);
		DrawText("* New Password", 477, 364, 30, DARKBLUE);
		DrawText("* Confirm New Password", 477, 528, 30, DARKBLUE);

		////Textbox function-----------------------------------------------------------------------------------------------------------------------------------------
		oldpass.worktextbox(isChangePassFalseDisplay);
		newpass.worktextbox(isChangePassFalseDisplay);
		confirmnewpass.worktextbox(isChangePassFalseDisplay);

		
		DrawText(oldpass.hiddentext, 500, 270, 40, DARKBLUE);
		DrawText(newpass.hiddentext, 500, 435, 40, DARKBLUE);
		DrawText(confirmnewpass.hiddentext, 500, 600, 40, DARKBLUE);

		DrawText(TextFormat("%i/%i", oldpass.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", newpass.lettercount, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmnewpass.lettercount, MAX_INPUT_CHARS), 1050, 620, 20, DARKBLUE);
		////-------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		////Button function----------------------------------------------------------------------------------------------------------
		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (usechangePassFunction(CurrentUser, oldpass.text, newpass.text, confirmnewpass.text) && oldpass.text[0] != '\0' && newpass.text[0] != '\0' && confirmnewpass.text[0] != '\0') {
				ProfilePageStaff(screenWidth, screenHeight, CurrentUser);
			}
			else {
				isChangePassFalseDisplay = true;
			}
		}
		if (isChangePassFalseDisplay) DrawText("Please try again!", 477, 685, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);
		EndDrawing();
	}
	CloseWindow();
}
void CreateSchoolYearPage(const int screenWidth,const int screenHeight, account& CurrentUser) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,screenWidth,screenHeight};

	Textbox1 schoolyear;
	schoolyear.textbox = { 477, 239, 558, 106 };
	
	Button3 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 400, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);

		DrawRectangle(347, 173, 818, 373, WHITE);
		DrawRectangleRec(schoolyear.textbox, LIGHTGRAY);
		DrawText("* School Year (YYYY-YYYY)", 477, 200, 30, DARKBLUE);
		
		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		schoolyear.worktextbox(confirmBtnFalseDisplay);

		DrawText(schoolyear.text, 500, 270, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", schoolyear.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (createASchoolYear(schoolyear.text)) {
				confirmBtnFalseDisplay = false;
				ProfilePageStaff(screenWidth, screenHeight, CurrentUser);
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawText("Schoolyear must be in right form. Try again!", 500, 360, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);

		EndDrawing();
	}
	CloseWindow();
}
void ViewSchoolYearPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	int n = countSchoolYear();
	char** Years = getSchoolYearArr();
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle background = { 0,0,screenWidth,screenHeight};

	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	


	Button3 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	int scrollspeed = 25;
	float y_schoolyear = 257;
	float x_schoolyear = 668;
	bool schoolyearadded = false;
	while (!WindowShouldClose()) {
		y_schoolyear += ((GetMouseWheelMove() * scrollspeed) - (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)));
		if (y_schoolyear > 202) y_schoolyear = 202;
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("SCHOOLYEARS", 620, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		DrawRectangleLines(321, 135, 872, 807, BLACK);
		mousePoint = GetMousePosition();
		Button3* schoolyear = new Button3[n];

		int j = 0;
		for (int i = 0; i < n; ++i) {
			schoolyear[i].button = { x_schoolyear - 122, y_schoolyear - 12, 421, 59 };
			DrawRectangleRec(schoolyear[i].button, LIGHTGRAY);
			DrawText(Years[i], x_schoolyear, y_schoolyear, 32, DARKBLUE);
			schoolyear[i].workbutton(mousePoint, CurrentUser, ProfilePageStaff);
			y_schoolyear += 100;
		}
		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);
		delete[] schoolyear;
		EndDrawing();
	}
	
	CloseWindow();

}

void createClassPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,screenWidth,screenHeight};

	Textbox1 classname;
	classname.textbox = { 477, 239, 558, 106 };

	Button3 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 400, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);

		DrawRectangle(347, 173, 818, 373, WHITE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawText("* Class Name", 477, 200, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		classname.worktextbox(confirmBtnFalseDisplay);

		DrawText(classname.text, 500, 270, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", classname.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			/*if () {
				confirmBtnFalseDisplay = false;*/
				ProfilePageStaff(screenWidth, screenHeight, CurrentUser);
			//}
			//else confirmBtnFalseDisplay = true;
		}
		//if (confirmBtnFalseDisplay) DrawText("Class name must be in right form. Try again!", 500, 360, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);

		EndDrawing();
	}
	CloseWindow();
}


void ViewClassesPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	//Initialize variable---------------------------------------------------------------------------------------------
	Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();

	Rectangle background = { 0,0,screenWidth,screenHeight};

	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	Texture2D changePassBtn = LoadTexture("changePassBtn.png");
	float frameHeightchangePassBtn = (float)changePassBtn.height;
	Rectangle sourceRecchangePassBtn = { 0, 0, (float)changePassBtn.width,frameHeightchangePassBtn };
	// Define button bounds on screen
	Rectangle btnBoundschangePassBtn = { 170, 800, (float)changePassBtn.width, frameHeightchangePassBtn };
	int changePassBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool changePassBtnAction = false;         // Button action should be activated

	Texture2D logOutBtn = LoadTexture("logOutBtn.png");
	float frameHeightlogOutBtn = (float)logOutBtn.height;
	Rectangle sourceReclogOutBtn = { 0, 0, (float)logOutBtn.width,frameHeightlogOutBtn };
	// Define button bounds on screen
	Rectangle btnBoundslogOutBtn = { 170, 730, (float)logOutBtn.width, frameHeightlogOutBtn };
	int logOutBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool logOutBtnAction = false;         // Button action should be activated

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		BeginDrawing();
		DrawText("WELCOME!", 670, 15, 40, DARKBLUE);

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(70, 170, 360, 750, WHITE);
		DrawRectangleLines(69, 169, 362, 752, BLACK);
		DrawRectangleLines(68, 168, 364, 754, BLACK);

		DrawRectangle(480, 170, 980, 750, WHITE);
		DrawRectangleLines(479, 169, 982, 752, BLACK);
		DrawRectangleLines(478, 168, 984, 754, BLACK);

		DrawRectangle(780, 108, 250, 60, WHITE);
		DrawRectangleLines(479, 107, 252, 62, BLACK);
		DrawRectangleLines(478, 106, 254, 64, BLACK);
		DrawText("School Years", 800, 123, 30, DARKBLUE);

		DrawTexture(avatar, 150, 100, WHITE);
		DrawText("Username: ", 90, 330, 20, DARKBLUE);
		DrawText(CurrentUser.userName, 200, 330, 20, DARKGRAY);
		////change password button function-----------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		changePassBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundschangePassBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) changePassBtnAction = true;
		}
		else changePassBtnState = 0;
		if (changePassBtnAction) {
			ChangePasswordPage(screenWidth, screenHeight, CurrentUser);
		}
		// Calculate button frame rectangle to draw depending on button state
		sourceRecchangePassBtn.y = changePassBtnState * frameHeightchangePassBtn;
		DrawTextureRec(changePassBtn, sourceRecchangePassBtn, { btnBoundschangePassBtn.x, btnBoundschangePassBtn.y }, WHITE); // Draw button frame
		////log out button function-------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		logOutBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundslogOutBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) logOutBtnAction = true;
		}
		else logOutBtnState = 0;
		if (logOutBtnAction) {
			LogInPageStaff(screenWidth, screenHeight, CurrentUser);
		}
		// Calculate button frame rectangle to draw depending on button state
		sourceReclogOutBtn.y = logOutBtnState * frameHeightlogOutBtn;
		DrawTextureRec(logOutBtn, sourceReclogOutBtn, { btnBoundslogOutBtn.x, btnBoundslogOutBtn.y }, WHITE); // Draw button frame
		
		EndDrawing();
	}
	CloseWindow();
}

/// function used for objects

// Button
void Button1::workbutton(Vector2 mousePoint, account& CurrentUser, void(* func)(const int screenWidth, const int screenHeight, account& CurrentUser)) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else state = 0;
	if (action) {
		func(screenWidth, screenHeight, CurrentUser);
	}
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}

void Button3::workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser)) {
	if (CheckCollisionPointRec(mousePoint, button)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else action = false;
	if (action)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser);
	}
}

// Textbox
void Textbox1::worktextbox(bool& somethingfalsedisplay) {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) mouseontextbox = true;
	else mouseontextbox = false;
	if (mouseontextbox)
	{
		// Set the window's cursor to the I-Beam
		SetMouseCursor(MOUSE_CURSOR_IBEAM);

		// Get char pressed (unicode character) on the queue
		int key = GetCharPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0)
		{
			// NOTE: Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125) && (lettercount < MAX_INPUT_CHARS))
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
	else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	if (mouseontextbox) {
		DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, BLUE);
		DrawRectangleLines((int)textbox.x - 1, (int)textbox.y - 1, (int)textbox.width + 2, (int)textbox.height + 2, BLUE);
		DrawRectangleLines((int)textbox.x - 2, (int)textbox.y - 2, (int)textbox.width + 4, (int)textbox.height + 4, BLUE);
		somethingfalsedisplay = false;
	}
	else DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, DARKGRAY);

}

void Textbox2::worktextbox(bool& somethingfalsedisplay) {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) mouseontextbox = true;
	else mouseontextbox = false;
	if (mouseontextbox)
	{
		// Set the window's cursor to the I-Beam
		SetMouseCursor(MOUSE_CURSOR_IBEAM);

		// Get char pressed (unicode character) on the queue
		int key = GetCharPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0)
		{
			// NOTE: Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125) && (lettercount < MAX_INPUT_CHARS))
			{
				text[lettercount] = (char)key;
				text[lettercount + 1] = '\0'; // Add null terminator at the end of the string.
				lettercount++;

				hiddentext[lettercounthidden] = '*';
				hiddentext[lettercounthidden + 1] = '\0';
				lettercounthidden++;
			}

			key = GetCharPressed();  // Check next character in the queue
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			lettercount--;
			if (lettercount < 0) lettercount = 0;
			text[lettercount] = '\0';

			lettercounthidden--;
			if (lettercounthidden < 0) lettercounthidden = 0;
			hiddentext[lettercounthidden] = '\0';
		}
	}
	else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

	if (mouseontextbox) {
		DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, BLUE);
		DrawRectangleLines((int)textbox.x - 1, (int)textbox.y - 1, (int)textbox.width + 2, (int)textbox.height + 2, BLUE);
		DrawRectangleLines((int)textbox.x - 2, (int)textbox.y - 2, (int)textbox.width + 4, (int)textbox.height + 4, BLUE);
		somethingfalsedisplay = false;
	}
	else DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, DARKGRAY);
}