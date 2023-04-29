#include "Function.h"
using namespace std;


//FRONT_END--------------------------------------------------------
void StudentorStaffPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};
	Vector2 mousePoint = { 0.0f, 0.0f };

	Texture2D Student = LoadTexture("Student.png");
	Texture2D Staff = LoadTexture("Staff.png");


	Button2 student;
	student.button = { 23, 295, 645, 518 };

	Button2 staff;
	staff.button = { 839, 295, 645, 518 };

	SetTargetFPS(40);
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("COURSE MANAGEMENT SYSTEM", 430, 10, 40, DARKBLUE);
		DrawRectangle(552, 148, 408, 59, WHITE);
		DrawText("You are a", 660, 157, 40, DARKBLUE);
		DrawRectangleRec(student.button, WHITE);
		DrawText("STUDENT", 260, 333, 36, DARKBLUE);
		DrawTexture(Student, 200, 390, RAYWHITE);
		DrawRectangleRec(staff.button, WHITE);
		DrawText("STAFF", 1107, 333, 36, DARKBLUE);
		DrawTexture(Staff, 996, 407, RAYWHITE);

		mousePoint = GetMousePosition();
		staff.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		student.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		EndDrawing();
	}
	CloseWindow();

}
void LogInPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	//Initialize textbox-------------------------------------------------------
	Textbox1 username;
	username.textbox = { 477, 289,558,106 };

	Textbox2 password;
	password.textbox = { 477, 453,558,106 };

	Button2 backtopreviouspage;
	backtopreviouspage.button = { 1200, 20, 300, 30 };
	////initialize login button---------------------------------------------------------------------------------------------------
	Texture2D loginButton = LoadTexture("loginButton.png");

	float frameHeightloginButton = (float)loginButton.height;
	Rectangle sourceRecloginButton = { 0, 0, (float)loginButton.width, frameHeightloginButton };
	// Define button bounds on screen
	Rectangle btnBoundsloginButton = { (screenWidth / 2.0f - loginButton.width / 2.0f) - 10, 600, (float)loginButton.width, frameHeightloginButton };

	int loginbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool loginbtnAction = false;         // Button action should be activated
	bool isLoginFalseDisplay = false;

	bool stafforstudent = false;
	////initialize for login--------------------------------------------------------------------------------------------------------------

	Vector2 mousePoint = { 0.0f, 0.0f };

	SetTargetFPS(40);
	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//Draw--------------------------------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(347, 173, 818, 560, WHITE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(backtopreviouspage.button, WHITE);
		DrawText("Back to the previous page", 1200, 20, 20, DARKBLUE);
		DrawRectangleRec(password.textbox, LIGHTGRAY);
		DrawText("* Username", 477, 250, 30, DARKBLUE);
		DrawText("* Password", 477, 414, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		username.worktextbox(isLoginFalseDisplay);
		password.worktextbox(isLoginFalseDisplay);


		DrawText(username.text, 500, 320, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		DrawText(password.hiddentext, 500, 490, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 500, 20, DARKBLUE);

		////Function of login button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		loginbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
		}
		else loginbtnState = 0;


		if (loginbtnAction)
		{

			if (LoginFunction(username.text, password.text, stafforstudent)) {
				CurrentUser.password = password.text;
				CurrentUser.userName = username.text;
				EndDrawing();
				ProfilePageStudent(screenWidth, screenHeight, CurrentUser);
			}
			else isLoginFalseDisplay = true;
		}
		if (isLoginFalseDisplay) DrawText("Invalid username or password!", 477, 570, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecloginButton.y = loginbtnState * frameHeightloginButton;
		DrawTextureRec(loginButton, sourceRecloginButton, { btnBoundsloginButton.x, btnBoundsloginButton.y }, WHITE); // Draw button frame
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		////Function of signup button-------------------------------------------------------------------------------------------------------------------------
		backtopreviouspage.workbutton(mousePoint, CurrentUser, StudentorStaffPage);
		EndDrawing();
	}
	CloseWindow();
}
void LogInPageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};

	//Initialize textbox-------------------------------------------------------
	Textbox1 username;
	username.textbox = { 477, 239,558,106 };

	Textbox2 password;
	password.textbox = { 477, 403,558,106 };
	
	Button2 backtopreviouspage;
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

	bool stafforstudent = true;
	////initialize for login--------------------------------------------------------------------------------------------------------------

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
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(backtopreviouspage.button, WHITE);
		DrawText("Back to the previous page", 1200, 20, 20, DARKBLUE);
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


		if (loginbtnAction)
		{
			
			if (LoginFunction(username.text, password.text, stafforstudent)) {
				CurrentUser.password = password.text;
				CurrentUser.userName = username.text;
				EndDrawing();
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
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};

	//Initialize---------------------------------------------------------------------
	Textbox1 username;
	username.textbox = { 471, 200, 558, 112 };

	Textbox2 password;
	password.textbox = { 471, 373, 558, 112 };
	Textbox2 confirmpass;
	confirmpass.textbox = { 471, 546, 558, 112 };

	Button2 backtologinsite;
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
		DrawRectangle(1028, 373, 200, 112, WHITE);
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
			else if (StaffSignup(newinfo, confirmpass.text)) {
				issignupFalseDisplay = false;
				EndDrawing();
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
void ProfilePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	////Initialize variable---------------------------------------------------------------------------------------------
	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

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

	Button1 scoreboard;
	scoreboard.texture = LoadTexture("ScoreboardBtn.png");
	scoreboard.frameHeight = (float)scoreboard.texture.height;
	scoreboard.sourceRec = { 0, 0, (float)scoreboard.texture.width,scoreboard.frameHeight };
	scoreboard.btnBounds = { 1026, 331, (float)scoreboard.texture.width,scoreboard.frameHeight };

	Button1 course;
	course.texture = LoadTexture("StuCourseBtn.png");
	course.frameHeight = (float)course.texture.height;
	course.sourceRec = { 0, 0, (float)course.texture.width,course.frameHeight };
	course.btnBounds = { 1026, 681, (float)course.texture.width,course.frameHeight };

	Texture2D courseIcon = LoadTexture("courseIcon.png");
	Texture2D scoreboardIcon = LoadTexture("scoreboardIcon.png");

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
		DrawText("  STUDENT", 500, 123, 30, DARKBLUE);

		DrawTexture(scoreboardIcon, 595, 216, WHITE);
		DrawTexture(courseIcon, 595, 567, WHITE);

		DrawTexture(avatar, 150, 100, WHITE);
		DrawText("Username: ", 90, 330, 20, DARKBLUE);
		DrawText(CurrentUser.userName, 200, 330, 20, DARKGRAY);

		mousePoint = GetMousePosition();
		////change password button function-----------------------------------------------------------------------------------------------------------
		ChangePass.workbutton(mousePoint, CurrentUser, ChangePasswordPageStudent);
		LogOut.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		scoreboard.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		course.workbutton(mousePoint, CurrentUser, LogInPageStudent);

		//// display schoolyear from createschoolyear page--------------------------------------------------------------------------------------------
		EndDrawing();
	}
	CloseWindow();
}
void CoursePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("COURSE MANAGEMENT SYSTEM", 430, 10, 40, DARKBLUE);

		Rectangle test = { 200,200,300,100 };
		Rectangle list = { 200,300,300,400 };
		DrawRectangleRec(test, WHITE);
		
		bool action = false;
		if (CheckCollisionPointRec(mousePoint,test)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
		}
		else action = false;
		if (action) {
			DrawRectangleRec(list, RED);
		}

		EndDrawing();
	}
	CloseWindow();

}
void ProfilePageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {
	////Initialize variable---------------------------------------------------------------------------------------------
	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};
	
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


	Button1 Classes;
	Classes.texture = LoadTexture("classesBtn.png");
	Classes.frameHeight = (float)Classes.texture.height;
	Classes.sourceRec = { 0, 0, (float)Classes.texture.width, Classes.frameHeight };
	Classes.btnBounds = { 980, 690, (float)Classes.texture.width, Classes.frameHeight };

	Button1 Schoolyears;
	Schoolyears.texture = LoadTexture("schoolyearsBtn.png");
	Schoolyears.frameHeight = (float)Schoolyears.texture.height;
	Schoolyears.sourceRec = { 0, 0, (float)Schoolyears.texture.width, Schoolyears.frameHeight };
	Schoolyears.btnBounds = { 980, 320, (float)Schoolyears.texture.width, Schoolyears.frameHeight };
	
	Texture2D Calendar = LoadTexture("calendar.png");
	Texture2D classimage = LoadTexture("class.png");

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
		DrawText("    STAFF   ", 500, 123, 30, DARKBLUE);

		DrawTexture(avatar, 150, 100, WHITE);
		DrawText("Username: ", 90, 330, 20, DARKBLUE);
		DrawText(CurrentUser.userName, 200, 330, 20, DARKGRAY);

		DrawTexture(Calendar, 560, 220, WHITE);
		DrawTexture(classimage, 560, 580, WHITE);

		mousePoint = GetMousePosition();
		////change password button function-----------------------------------------------------------------------------------------------------------
		ChangePass.workbutton(mousePoint, CurrentUser, ChangePasswordPageStaff);
		LogOut.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		Schoolyears.workbutton(mousePoint, CurrentUser, ViewSchoolYearsPage);
		Classes.workbutton(mousePoint, CurrentUser, ViewClassesPage);

		//// display schoolyear from createschoolyear page--------------------------------------------------------------------------------------------
		EndDrawing();
	}
	CloseWindow();
}
void ChangePasswordPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Textbox2 oldpass;
	oldpass.textbox = { 477, 239, 558, 106 };

	Textbox2 newpass;
	newpass.textbox = { 477, 403, 558, 106 };

	Textbox2 confirmnewpass;
	confirmnewpass.textbox = { 477, 567, 558, 106 };

	Button2 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	bool isChangePassFalseDisplay = false;
	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 710, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated

	bool stafforstudent = false;
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
			if (usechangePassFunction(CurrentUser, oldpass.text, newpass.text, confirmnewpass.text, stafforstudent) && oldpass.text[0] != '\0' && newpass.text[0] != '\0' && confirmnewpass.text[0] != '\0') {
				EndDrawing();
				ProfilePageStudent(screenWidth, screenHeight, CurrentUser);
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
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStudent);
		EndDrawing();
	}
	CloseWindow();
}
void ChangePasswordPageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};
	Vector2 mousePoint = { 0.0f, 0.0f };

	Textbox2 oldpass;
	oldpass.textbox = { 477, 239, 558, 106 };

	Textbox2 newpass;
	newpass.textbox = { 477, 403, 558, 106 };

	Textbox2 confirmnewpass;
	confirmnewpass.textbox = { 477, 567, 558, 106 };

	Button2 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	bool isChangePassFalseDisplay = false;
	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 710, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated

	bool stafforstudent = true;
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
			if (usechangePassFunction(CurrentUser, oldpass.text, newpass.text, confirmnewpass.text, stafforstudent) && oldpass.text[0] != '\0' && newpass.text[0] != '\0' && confirmnewpass.text[0] != '\0') {
				EndDrawing();
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
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};

	Textbox1 schoolyear;
	schoolyear.textbox = { 477, 239, 558, 106 };
	
	Button2 backtoprofilepage;
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
		DrawText("Back to Previous Page", 1250, 20, 20, DARKBLUE);

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
				EndDrawing();
				ViewSchoolYearsPage(screenWidth, screenHeight, CurrentUser);
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawText("Schoolyear must be in right form. Try again!", 500, 360, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ViewSchoolYearsPage);

		EndDrawing();
	}
	CloseWindow();
}
void ViewSchoolYearsPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	int n = countSchoolYear();
	char** Years = getSchoolYearArr();
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};
	Texture2D background2 = LoadTexture("background2.png");
	Texture2D background3 = LoadTexture("background3.png");
	Button2 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };

	Button1 CreateSchoolYear;
	CreateSchoolYear.texture = LoadTexture("createSchoolYearBtn.png");
	CreateSchoolYear.frameHeight = (float)CreateSchoolYear.texture.height;
	CreateSchoolYear.sourceRec = { 0, 0, (float)CreateSchoolYear.texture.width, CreateSchoolYear.frameHeight };
	CreateSchoolYear.btnBounds = { 655, 75, (float)CreateSchoolYear.texture.width, CreateSchoolYear.frameHeight };

	int y_schoolyear = 167;
	int x_schoolyear = 668;
	int scrollspeed = 35;
	while (!WindowShouldClose()) {
		y_schoolyear += (int(GetMouseWheelMove()) * scrollspeed);
		if (y_schoolyear > 167) y_schoolyear = 167;
		if (y_schoolyear + (n*3)*n < 167) {
			y_schoolyear = 167 - (n*3)*n;
		}
		//if (y_schoolyear) y_schoolyear = 881;
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		//DrawRectangleLines(321, 135, 872, 807, BLACK);
		mousePoint = GetMousePosition();
		Button4* schoolyear = new Button4[n];
		int j = 0;
		for (int i = 0; i < n; ++i) {
			schoolyear[i].button = { float(x_schoolyear - 122), float( y_schoolyear + j - 12), 421, 59 };
			DrawRectangleRec(schoolyear[i].button, LIGHTGRAY);
			DrawText(Years[i], x_schoolyear, y_schoolyear + j, 32, DARKBLUE);
			if (y_schoolyear + j - 12 < 77 || y_schoolyear + j - 12 > 942) {
				schoolyear[i].state = false;
			}
			else schoolyear[i].state = true;
			schoolyear[i].workbutton(mousePoint, CurrentUser, Years[i], ViewSemestersPage);
			j += 100;
		}

		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("SCHOOLYEARS", 600, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);
		DrawTexture(background3, 0, 60, WHITE);
		DrawTexture(background2, 320, 941, WHITE);

		delete[] schoolyear;
		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);
		CreateSchoolYear.workbutton(mousePoint, CurrentUser, CreateSchoolYearPage);
		EndDrawing();
	}
	for (int i = 0; i < n; ++i) {
		delete[] Years[i];
	}
	delete[] Years;
	CloseWindow();

}
//void SchoolYearPage(const int screenWidth, const int screenHeight, account& CurrentUser, char* &Year) {
//	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
//	Vector2 mousePoint = { 0.0f, 0.0f };
//
//	Button2 backtoviewschoolyearpage;
//	backtoviewschoolyearpage.button = { 1150, 20, 250, 30 };
//
//	Button3 createsemester;
//	createsemester.texture = LoadTexture("createsemester.png");
//	createsemester.frameHeight = (float)createsemester.texture.height;
//	createsemester.sourceRec = { 0, 0, (float)createsemester.texture.width, createsemester.frameHeight };
//	createsemester.btnBounds = { 350, 496, (float)createsemester.texture.width, createsemester.frameHeight };
//
//	Button3 viewsemester;
//	viewsemester.texture = LoadTexture("viewsemester.png");
//	viewsemester.frameHeight = (float)viewsemester.texture.height;
//	viewsemester.sourceRec = { 0, 0, (float)viewsemester.texture.width, viewsemester.frameHeight };
//	viewsemester.btnBounds = { 866, 496, (float)viewsemester.texture.width, viewsemester.frameHeight };
//
//	while (!WindowShouldClose()) {
//		ClearBackground(WHITE);
//		BeginDrawing();
//		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
//		DrawRectangle(0, 0, screenWidth, 60, WHITE);
//		DrawText(Year, 620, 15, 40, DARKBLUE);
//		DrawRectangleRec(backtoviewschoolyearpage.button, WHITE);
//		DrawText("Back to View School Year Page", 1150, 20, 20, DARKBLUE);
//		DrawRectangle(322, 136, 870, 806, WHITE);
//		DrawRectangleLines(321, 135, 872, 807, BLACK);
//
//		mousePoint = GetMousePosition();
//		backtoviewschoolyearpage.workbutton(mousePoint, CurrentUser, ViewSchoolYearsPage);
//		createsemester.workbutton(mousePoint, CurrentUser, Year, CreateSemesterPage);
//		viewsemester.workbutton(mousePoint, CurrentUser, Year, ViewSemestersPage);
//		EndDrawing();
//	}
//	delete[] Year;
//	CloseWindow();
//}
void createClassPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};

	Textbox1 classname;
	classname.textbox = { 477, 239, 558, 106 };
	

	Button2 backtoprofilepage;
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
		DrawText("Back to Previous Page", 1250, 20, 20, DARKBLUE);

		DrawRectangle(347, 173, 818, 350, WHITE);
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
			if (!CheckClassExisted(classname.text)) {
				confirmBtnFalseDisplay = false;
				CreateAClass(classname.text);
				EndDrawing();
				ViewClassesPage(screenWidth, screenHeight, CurrentUser);
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawText("This class was created before!", 480, 560, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ViewClassesPage);
		EndDrawing();
	}
	CloseWindow();
}
void ViewClassesPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	int n = countClasses(); //countClasses
	Class* Classes = new Class[n];
	Classes = viewClasses();

	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Button2 backtoprofilepage;
	backtoprofilepage.button = { 1270, 20, 200, 30 };
	Texture2D backgroundtmp = LoadTexture("background11.png");


	Button1 CreateClass;
	CreateClass.texture = LoadTexture("createClassBtn.png");
	CreateClass.frameHeight = (float)CreateClass.texture.height;
	CreateClass.sourceRec = { 0, 0, (float)CreateClass.texture.width, CreateClass.frameHeight };
	CreateClass.btnBounds = { 655, 75, (float)CreateClass.texture.width, CreateClass.frameHeight };

	int scrollspeed = 35;
	int y_classes = 210;
	int x_classes = 668;

	while (!WindowShouldClose()) {
		y_classes += (int(GetMouseWheelMove()) * scrollspeed);
		if (y_classes > 167) y_classes = 167;
		if (y_classes + (n * 3) * n < 167) {
			y_classes = 167 - (n * 3) * n;
		}

		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText("CLASSES", 670, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawText("Back to Profile Page", 1280, 20, 20, DARKBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		//DrawRectangleLines(321, 135, 872, 807, BLACK);
		mousePoint = GetMousePosition();
		Button4* Class = new Button4[n];

		int j = 0;
		for (int i = 0; i < n; ++i) {
			Class[i].button = { float(x_classes - 122), float(y_classes + j - 12), 421, 59 };
			DrawRectangleRec(Class[i].button, LIGHTGRAY);
			DrawText(Classes[i].classID, x_classes+40, y_classes + j, 32, DARKBLUE);
			if (y_classes + j - 12 < 77 || y_classes + j - 12 > 942) {
				Class[i].state = false;
			}
			else Class[i].state = true;
			Class[i].workbutton(mousePoint, CurrentUser, Classes[i].classID, ClassPage);
			j += 100;
		}

		DrawTexture(backgroundtmp, 0, 65, WHITE);
		/// Back to profile page button
		
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);
		CreateClass.workbutton(mousePoint, CurrentUser, createClassPage);
		delete[] Class;
		EndDrawing();
	}
	delete [] Classes;
	CloseWindow();

}
void ClassPage(const int screenWidth, const int screenHeight, account& CurrentUser,char*& Classname) {
	int n = countStudentInClass(Classname);
	student* listStudents = viewStudentsInClass(Classname);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Texture2D background2 = LoadTexture("course_background.png");
	Vector2 mousePoint = { 0.0f, 0.0f };

	Button2 backtoViewClasspage;
	backtoViewClasspage.button = { 1190, 20, 250, 30 };

	Button4 AddStuCSV;
	AddStuCSV.button = { 23,94,293,55 };

	Button4 AddAStu;
	AddAStu.button = { 413,94,313,55 };

	int scrollspeed = 35;
	int x_student = 11;
	int y_student = 255;
	while (!WindowShouldClose()) {
		y_student += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_student > 11) x_student = 11;
		if (y_student > 255) y_student = 255;
		ClearBackground(WHITE);
		BeginDrawing();

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 231, screenWidth, 751, WHITE);
		DrawRectangleLines(0, 231, screenWidth, 751, BLACK);
		int j = 0;

		mousePoint = GetMousePosition();
		for (int i = 0; i < n; ++i) {
			DrawLine(x_student + 47, y_student + j - 1, x_student + 47, y_student + j + 61, BLACK);
			DrawLine(x_student + 216, y_student + j - 1, x_student + 216, y_student + j + 61, BLACK);
			DrawLine(x_student + 395, y_student + j - 1, x_student + 395, y_student + j + 61, BLACK);
			DrawLine(x_student + 851, y_student + j - 1, x_student + 851, y_student + j + 61, BLACK);
			DrawLine(x_student + 1039, y_student + j - 1, x_student + 1039, y_student + j + 61, BLACK);
			DrawLine(x_student + 1281, y_student + j - 1, x_student + 1281, y_student + j + 61, BLACK);
			DrawLine(x_student + 1501, y_student + j - 1, x_student + 1501, y_student + j + 61, BLACK);

			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			char* stuNo = new char[10];
			int_to_char(listStudents[i].No,stuNo);
			DrawText(stuNo, x_student + 13 , y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].stuID, x_student + 72, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.lastName, x_student + 260, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.firstName, x_student + 528 , y_student + j + 30, 20, BLACK);

			if(listStudents[i].Student.gender) DrawText("Male", x_student + 912, y_student + j + 30, 20, BLACK);
			else DrawText("Female", x_student + 912, y_student + j + 30, 20, BLACK);

			DrawText(dateToChar(listStudents[i].Student.dob), x_student + 1097, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.socialID, x_student + 1300, y_student + j + 30, 20, BLACK);
			j += 61;
		}
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawText(Classname, 670, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoViewClasspage.button, WHITE);
		DrawText("Back to Classes Page", 1200, 20, 20, DARKBLUE);
		DrawTexture(background2, 0, 60, WHITE);

		DrawRectangleRec(AddStuCSV.button, WHITE);
		DrawText("Add Student with CSV", 42, 108, 24, DARKBLUE);
		DrawRectangleRec(AddAStu.button, WHITE);
		DrawText("Add a Student manually", 430, 108, 24, DARKBLUE);

		DrawRectangle(0, 189, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 58, 65, BLACK);
		DrawText("No", 8, 205, 24, DARKBLUE);

		DrawRectangle(58, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 189, 173, 65, BLACK);
		DrawText("Student ID", 84, 205, 24, DARKBLUE);

		DrawRectangle(227, 189, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 189, 179, 65, BLACK);
		DrawText("Last name", 256,205, 24, DARKBLUE);

		DrawRectangle(406, 189, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 189, 456, 65, BLACK);
		DrawText("First name", 569, 205, 24, DARKBLUE);

		DrawRectangle(862, 189, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 189, 188, 65, BLACK);
		DrawText("Gender", 910, 205, 24, DARKBLUE);

		DrawRectangle(1050, 189, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 189, 242, 65, BLACK);
		DrawText("Date of Birth", 1095, 205, 24, DARKBLUE);

		DrawRectangle(1292, 189, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 189, 220, 65, BLACK);
		DrawText("Social ID", 1345, 205, 24, DARKBLUE);

		backtoViewClasspage.workbutton(mousePoint, CurrentUser, ViewClassesPage);
		AddStuCSV.workbutton(mousePoint, CurrentUser, Classname, addStudentCSV);
		AddAStu.workbutton(mousePoint, CurrentUser, Classname, addStudentPage);

		EndDrawing();
	}
	//delete[] listStudents;
	CloseWindow();
}
void addStudentPage(const int screenWidth, const int screenHeight, account& CurrentUser,char*& classname) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 Gender;
	Gender.textbox = { 284, 627, 283, 84 };
	Textbox1 birth;
	birth.textbox = { 604, 627, 623, 84 };
	Textbox1 Lastname;
	Lastname.textbox = { 284,213,283,84 };
	Textbox1 Firstname;
	Firstname.textbox = { 610,213,617,84 };
	Textbox1 studentID;
	studentID.textbox = { 284,351,943,84 };
	Textbox1 socialID;
	socialID.textbox = { 284,489,943,84 };

	Button4 backtoClasspage;
	backtoClasspage.button = { 1270, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 750, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawText("Back to your class", 1280, 20, 20, DARKBLUE);
		DrawText("Add a student", 620, 12, 40, DARKBLUE);

		DrawRectangle(142, 148, 1227, 720, WHITE);
		DrawRectangleRec(Lastname.textbox, LIGHTGRAY);
		DrawText("* Last name", 284, 174, 30, DARKBLUE);
		DrawRectangleRec(Firstname.textbox, LIGHTGRAY);
		DrawText("* First name", 610, 174, 30, DARKBLUE);
		DrawRectangleRec(studentID.textbox, LIGHTGRAY);
		DrawText("* Student ID", 284, 312, 30, DARKBLUE);
		DrawRectangleRec(socialID.textbox, LIGHTGRAY);
		DrawText("* Social ID", 284, 450, 30, DARKBLUE);
		DrawRectangleRec(birth.textbox, LIGHTGRAY);
		DrawText("* Date of birth", 604, 588, 30, DARKBLUE);
		DrawRectangleRec(Gender.textbox, LIGHTGRAY);
		DrawText("* Gender", 284, 588, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		Lastname.worktextbox(confirmBtnFalseDisplay);
		Firstname.worktextbox(confirmBtnFalseDisplay);
		studentID.worktextbox(confirmBtnFalseDisplay);
		socialID.worktextbox(confirmBtnFalseDisplay);
		birth.worktextbox(confirmBtnFalseDisplay);
		Gender.worktextbox(confirmBtnFalseDisplay);

		DrawText(Lastname.text, 314, 233, 40, DARKBLUE);
		DrawText(Firstname.text, 640, 233, 40, DARKBLUE);
		DrawText(studentID.text, 314, 371, 40, DARKBLUE);
		DrawText(socialID.text, 314, 509, 40, DARKBLUE);
		DrawText(birth.text, 634, 647, 40, DARKBLUE);
		DrawText(Gender.text, 314, 647, 40, DARKBLUE);

		////Function of buttons------------	------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (addAStudentToClass(classname,Firstname.text,Lastname.text,Gender.text,birth.text,socialID.text,studentID.text)) {
				confirmBtnFalseDisplay = false;
				ClassPage(screenWidth, screenHeight, CurrentUser, classname);
			}
			else confirmBtnFalseDisplay = true;
			
		}
		if (confirmBtnFalseDisplay) DrawText("This class was created before!", 480, 560, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoClasspage.workbutton(mousePoint, CurrentUser, classname,ClassPage);
		EndDrawing();
	}
	CloseWindow();
}

void addStudentCSV(const int screenWidth, const int screenHeight, account& CurrentUser, char*& classname) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 filename;
	filename.textbox = { 420,280,650,84 };

	Button4 backtoClasspage;
	backtoClasspage.button = { 1270, 20, 200, 30 };

	student* dupstu = nullptr;
	int numDupStu = 0;

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 420, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawText("Back to your class", 1280, 20, 20, DARKBLUE);
		DrawText("Add student(s)", 620, 12, 40, DARKBLUE);

		DrawRectangle(347, 173, 818, 380, WHITE);
		DrawRectangleRec(filename.textbox, LIGHTGRAY);
		DrawText("* File name", 420, 235, 30, DARKBLUE);

		filename.worktextbox(confirmBtnFalseDisplay);
		DrawText(filename.text, 450, 300, 40, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (checkdata_FileName(filename.text)) {
				confirmBtnFalseDisplay = false;
				if (addStudentsWithCSV(filename.text, classname, dupstu, numDupStu)) {
					ClassPage(screenWidth, screenHeight, CurrentUser, classname);
				}
				else{
					dataExistedPage(screenWidth, screenHeight, CurrentUser, classname, numDupStu, dupstu);
				}
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawText("File name is invalid!!!", 440, 380, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoClasspage.workbutton(mousePoint, CurrentUser,classname, ClassPage);

		EndDrawing();
	}
	CloseWindow();
}
void dataExistedPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& classname, int numDupStu, student* dupstu) {
	int n = numDupStu;
	student* StuExisted = dupstu;
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Button4 backtoClasspage;
	backtoClasspage.button = { 1270, 20, 200, 30 };

	int scrollspeed = 35;
	int x_student = 11;
	int y_student = 126;

	while (!WindowShouldClose()) {
		y_student += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_student > 11) x_student = 11;
		if (y_student > 126) y_student = 126;
		ClearBackground(WHITE);
		BeginDrawing();


		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 125, screenWidth, 900, WHITE);
		int j = 0;

		mousePoint = GetMousePosition();
		for (int i = 0; i < n; ++i) {
			DrawLine(x_student + 47, y_student + j - 1, x_student + 47, y_student + j + 61, BLACK);
			DrawLine(x_student + 216, y_student + j - 1, x_student + 216, y_student + j + 61, BLACK);
			DrawLine(x_student + 395, y_student + j - 1, x_student + 395, y_student + j + 61, BLACK);
			DrawLine(x_student + 851, y_student + j - 1, x_student + 851, y_student + j + 61, BLACK);
			DrawLine(x_student + 1039, y_student + j - 1, x_student + 1039, y_student + j + 61, BLACK);
			DrawLine(x_student + 1281, y_student + j - 1, x_student + 1281, y_student + j + 61, BLACK);
			DrawLine(x_student + 1501, y_student + j - 1, x_student + 1501, y_student + j + 61, BLACK);

			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			char* stuNo = new char[10];
			int_to_char(StuExisted[i].No, stuNo);
			DrawText(stuNo, x_student + 13, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].stuID, x_student + 72, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.lastName, x_student + 260, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.firstName, x_student + 528, y_student + j + 30, 20, BLACK);

			if (StuExisted[i].Student.gender) DrawText("Male", x_student + 912, y_student + j + 30, 20, BLACK);
			else DrawText("Female", x_student + 912, y_student + j + 30, 20, BLACK);

			DrawText(dateToChar(StuExisted[i].Student.dob), x_student + 1097, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.socialID, x_student + 1300, y_student + j + 30, 20, BLACK);
			j += 61;
		}

		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawText("These students have already existed in class", 10, 10, 40, RED);
		DrawText(classname, 970, 10, 40, RED);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawText("Back to your class", 1280, 20, 20, DARKBLUE);

		DrawRectangle(0, 60, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 60, 58, 65, BLACK);
		DrawText("No", 8, 76, 24, DARKBLUE);

		DrawRectangle(58, 60, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 60, 173, 65, BLACK);
		DrawText("Student ID", 84, 76, 24, DARKBLUE);

		DrawRectangle(227, 60, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 60, 179, 65, BLACK);
		DrawText("Last name", 256, 76, 24, DARKBLUE);

		DrawRectangle(406, 60, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 60, 456, 65, BLACK);
		DrawText("First name", 569, 76, 24, DARKBLUE);

		DrawRectangle(862, 60, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 60, 188, 65, BLACK);
		DrawText("Gender", 910, 76, 24, DARKBLUE);

		DrawRectangle(1050, 60, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 60, 242, 65, BLACK);
		DrawText("Date of Birth", 1095, 76, 24, DARKBLUE);

		DrawRectangle(1292, 60, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 60, 220, 65, BLACK);
		DrawText("Social ID", 1345, 76, 24, DARKBLUE);

		backtoClasspage.workbutton(mousePoint, CurrentUser, classname, ClassPage);

		EndDrawing();
	}
	CloseWindow();
}
void CreateSemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char* &Year) {
	int n = countSemester(Year);
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight)};

	Textbox1 startdate;
	startdate.textbox = { 477, 289, 558, 106 };
	Textbox1 enddate;
	enddate.textbox = { 477, 462, 558, 106 };

	Button4 backtoviewsemesterpage;
	backtoviewsemesterpage.button = { 1150, 20, 300, 30 };
	
	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 640, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText(Year, 30, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoviewsemesterpage.button, WHITE);
		DrawText("Back to View Semester Page", 1180, 20, 20, DARKBLUE);
		DrawRectangle(355, 173, 818, 600, WHITE);
		DrawRectangleRec(startdate.textbox, LIGHTGRAY);
		DrawText("* Start date (dd/mm/YYYY): ", 477, 250, 30, DARKBLUE);
		DrawRectangleRec(enddate.textbox, LIGHTGRAY);
		DrawText("* End date (dd/mm/YYYY): ", 477, 423, 30, DARKBLUE);


		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		startdate.worktextbox(confirmBtnFalseDisplay);
		enddate.worktextbox(confirmBtnFalseDisplay);

		DrawText(startdate.text, 500, 320, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", startdate.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		DrawText(enddate.text, 500, 493, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", enddate.lettercount, MAX_INPUT_CHARS), 1050, 503, 20, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (n < 3) {
				if (createASemester(Year, startdate.text, enddate.text)) {
					confirmBtnFalseDisplay = false;
					EndDrawing();
					ViewSemestersPage(screenWidth,screenHeight,CurrentUser,Year);
				}
				else confirmBtnFalseDisplay = false;
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawText("Max semesters created or information must be written in right form!", 430,600, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoviewsemesterpage.workbutton(mousePoint, CurrentUser, Year, ViewSemestersPage);
		EndDrawing();
	}
	delete[] Year;
	CloseWindow();
}
void ViewSemestersPage(const int screenWidth, const int screenHeight, account& CurrentUser, char* &Year) {
	int n = countSemester(Year); // countSemester
	//semester* Semester = getSemester(Year); // getSemesterArr
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Button2 backtoviewschoolyearpage;
	backtoviewschoolyearpage.button = { 1150, 20, 250, 30 };

	Button3 createsemester;
	createsemester.texture = LoadTexture("createsemester.png");
	createsemester.frameHeight = (float)createsemester.texture.height;
	createsemester.sourceRec = { 0, 0, (float)createsemester.texture.width, createsemester.frameHeight };
	createsemester.btnBounds = { 620, 170, (float)createsemester.texture.width, createsemester.frameHeight };


	int scrollspeed = 25;
	int y_semester = 486;
	int x_semester = 680;

	while (!WindowShouldClose()) {
		//y_semester += ((GetMouseWheelMove() * scrollspeed) - (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)));
		if (y_semester > 300) y_semester = 300;
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText(Year, 30, 15, 40, DARKBLUE);
		DrawText("SEMESTERS", 620, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoviewschoolyearpage.button, WHITE);
		DrawText("Back to list School Years", 1200, 20, 20, DARKBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		DrawRectangleLines(321, 135, 872, 807, BLACK);


		mousePoint = GetMousePosition();
		Button6 semester[3];
		char** semestername = new char* [3];
		getsemestername(semestername, n);
		for (int i = 0; i < n; ++i) {
			semester[i].button = {float( x_semester - 122), float(y_semester - 12), 421, 59 };
			DrawRectangleRec(semester[i].button, LIGHTGRAY);
			DrawText(semestername[i], x_semester + 30, y_semester, 32, DARKBLUE);
			semester[i].workbutton(mousePoint, CurrentUser, Year, semestername[i], ViewCoursesPage);
			y_semester += 100;
		}
		for (int i = 0; i < 3; ++i) {
			delete[] semestername[i];
		}
		delete[] semestername;
		/// Back to profile page button
		backtoviewschoolyearpage.workbutton(mousePoint, CurrentUser, ViewSchoolYearsPage);
		createsemester.workbutton(mousePoint, CurrentUser, Year, CreateSemesterPage);
		EndDrawing();
	}
	delete[] Year;
	CloseWindow();

}

//void SemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester) {
//	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
//	Vector2 mousePoint = { 0.0f, 0.0f };
//
//	Button4 backtoviewsemesterpage;
//	backtoviewsemesterpage.button = { 1150, 20, 300, 30 };
//
//	Button5 createcourse;
//	createcourse.texture = LoadTexture("createcourse.png");
//	createcourse.frameHeight = (float)createcourse.texture.height;
//	createcourse.sourceRec = { 0, 0, (float)createcourse.texture.width, createcourse.frameHeight };
//	createcourse.btnBounds = { 350, 496, (float)createcourse.texture.width, createcourse.frameHeight };
//
//	Button5 viewcourse;
//	viewcourse.texture = LoadTexture("viewcourse.png");
//	viewcourse.frameHeight = (float)viewcourse.texture.height;
//	viewcourse.sourceRec = { 0, 0, (float)viewcourse.texture.width, viewcourse.frameHeight };
//	viewcourse.btnBounds = { 866, 496, (float)viewcourse.texture.width, viewcourse.frameHeight };
//
//	while (!WindowShouldClose()) {
//		ClearBackground(WHITE);
//		BeginDrawing();
//		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
//		DrawRectangle(0, 0, screenWidth, 60, WHITE);
//		DrawText(Year, 30, 15, 40, DARKBLUE);
//		DrawText(Semester, 670, 15, 40, DARKBLUE);
//		DrawRectangleRec(backtoviewsemesterpage.button, WHITE);
//		DrawText("Back to View Semester Page", 1180, 20, 20, DARKBLUE);
//		DrawRectangle(322, 136, 870, 806, WHITE);
//		DrawRectangleLines(321, 135, 872, 807, BLACK);
//
//		mousePoint = GetMousePosition();
//		backtoviewsemesterpage.workbutton(mousePoint, CurrentUser, Year, ViewSemestersPage);
//		createcourse.workbutton(mousePoint, CurrentUser, Year, Semester, CreateCoursePage);
//		viewcourse.workbutton(mousePoint, CurrentUser, Year, Semester, ViewCoursesPage);
//		EndDrawing();
//	}
//	delete[] Year;
//	delete[] Semester;
//	CloseWindow();
//}

void CreateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester) {
	//ListCourse list;
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 id;
	id.textbox = { 175, 149, 1064, 47 };
	Textbox1 coursename;
	coursename.textbox = { 175, 262, 1064, 47 };
	Textbox1 classname;
	classname.textbox = { 175, 375, 1064, 47 };
	Textbox1 teachername;
	teachername.textbox = { 175, 488, 1064, 47 };
	Textbox1 nofc;
	nofc.textbox = { 175, 601, 1064, 47 };
	Textbox1 maxstudents;
	maxstudents.textbox = { 175, 714, 1064, 47 };
	Textbox1 courseday;
	courseday.textbox = { 175, 827, 528, 47 };
	Textbox1 sshours;
	sshours.textbox = { 779, 827, 462, 47 };

	Button6 backtocoursepage;
	backtocoursepage.button = { 1200, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn1.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 670, 910, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtocoursepage.button, WHITE);
		DrawText(Year, 30, 15, 40, DARKBLUE);
		DrawText(Semester, 670, 15, 40, DARKBLUE);
		DrawText("Back to Course Page", 1230, 20, 20, DARKBLUE);

		DrawRectangle(126, 92, 1260, 870, WHITE);
		DrawRectangleRec(id.textbox, LIGHTGRAY);
		DrawText("* Course ID: ", 175, 120, 25, DARKBLUE);
		DrawRectangleRec(coursename.textbox, LIGHTGRAY);
		DrawText("* Course name: ", 175, 233, 25, DARKBLUE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawText("* Class name: ", 175, 346, 25, DARKBLUE);
		DrawRectangleRec(teachername.textbox, LIGHTGRAY);
		DrawText("* Teacher name: ", 175, 459, 25, DARKBLUE);
		DrawRectangleRec(nofc.textbox, LIGHTGRAY);
		DrawText("* Number of credits: ", 175, 572, 25, DARKBLUE);
		DrawRectangleRec(maxstudents.textbox, LIGHTGRAY);
		DrawText("* Maximum students: ", 175, 685, 25, DARKBLUE);
		DrawRectangleRec(courseday.textbox, LIGHTGRAY);
		DrawText("* Course day: ", 175, 798, 25, DARKBLUE);
		DrawRectangleRec(sshours.textbox, LIGHTGRAY);
		DrawText("* Session hours: ", 779, 798, 25, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		id.worktextbox(confirmBtnFalseDisplay);
		coursename.worktextbox(confirmBtnFalseDisplay);
		classname.worktextbox(confirmBtnFalseDisplay);
		teachername.worktextbox(confirmBtnFalseDisplay);
		nofc.worktextbox(confirmBtnFalseDisplay);
		maxstudents.worktextbox(confirmBtnFalseDisplay);
		courseday.worktextbox(confirmBtnFalseDisplay);
		sshours.worktextbox(confirmBtnFalseDisplay);



		DrawText(id.text, 198, 162, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", id.lettercount, MAX_INPUT_CHARS), 1270, 172, 20, DARKBLUE);
		DrawText(coursename.text, 198, 275, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", coursename.lettercount, MAX_INPUT_CHARS), 1270, 285, 20, DARKBLUE);
		DrawText(classname.text, 198, 388, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", classname.lettercount, MAX_INPUT_CHARS), 1270, 398, 20, DARKBLUE);
		DrawText(teachername.text, 198, 501, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", teachername.lettercount, MAX_INPUT_CHARS), 1270, 511, 20, DARKBLUE);
		DrawText(nofc.text, 198, 614, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", nofc.lettercount, MAX_INPUT_CHARS), 1270, 624, 20, DARKBLUE);
		DrawText(maxstudents.text, 198, 727, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", maxstudents.lettercount, MAX_INPUT_CHARS), 1270, 727, 20, DARKBLUE);
		if (maxstudents.lettercount == 0) {
			DrawText("50", 198, 727, 25, DARKBLUE);
		}
		DrawText(courseday.text, 198, 840, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", courseday.lettercount, MAX_INPUT_CHARS), 713, 855, 16, DARKBLUE);
		DrawText(sshours.text, 802, 840, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", sshours.lettercount, MAX_INPUT_CHARS), 1270, 855, 16, DARKBLUE);


		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (!CheckValidCourse(coursename.text, id.text, classname.text, Year, Semester) ||
				id.text[0] == '\0' || coursename.text[0] == '\0' || classname.text[0] == '\0' ||
				teachername.text[0] == '\0' || nofc.text[0] == '\0' || courseday.text[0] == '\0' ||
				sshours.text[0] == '\0') {
				confirmBtnFalseDisplay = true;
			}
			else {
				if (maxstudents.lettercount == 0) {
					maxstudents.text[0] = '5';
					maxstudents.text[1] = '0';
					maxstudents.text[2] = '\0';
					AddCourseToFile(coursename.text, id.text, classname.text, teachername.text, nofc.text, maxstudents.text, courseday.text, sshours.text, Year, Semester);
				}
				else AddCourseToFile(coursename.text, id.text, classname.text, teachername.text, nofc.text, maxstudents.text, courseday.text, sshours.text, Year, Semester);
				EndDrawing();
				ViewCoursesPage(screenWidth, screenHeight, CurrentUser, Year, Semester);
			}
		}
		if (confirmBtnFalseDisplay) DrawText("Some textboxes are blank. Please try again!", 582, 888, 15, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtocoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, ViewCoursesPage);

		EndDrawing();
	}
	delete[] Year;
	delete[] Semester;
	CloseWindow();
}

void ViewCoursesPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester) {
	course* courses;
	int n = countCourse(Year, Semester);
	LoadCourseFromFile(Year, Semester, n, courses);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Texture2D background2 = LoadTexture("course_background.png");
	Vector2 mousePoint = { 0.0f, 0.0f };

	Button4 backtoviewsemesterpage;
	backtoviewsemesterpage.button = { 1150, 20, 300, 30 };

	Button5 createcourse;
	createcourse.texture = LoadTexture("createcourse.png");
	createcourse.frameHeight = (float)createcourse.texture.height;
	createcourse.sourceRec = { 0, 0, (float)createcourse.texture.width, createcourse.frameHeight };
	createcourse.btnBounds = { 50, 85, (float)createcourse.texture.width, createcourse.frameHeight };

	Button8* coursebutton = new Button8[n];
	int scrollspeed = 35;
	int x_course = 11;
	int y_course = 255;
	int x = 0;
	int y = 0;
	while (!WindowShouldClose()) {
		y_course += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_course > 11) x_course = 11;
		if (y_course > 255) y_course = 255;
		ClearBackground(WHITE);
		BeginDrawing();

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 231, screenWidth, 751, WHITE);
		DrawRectangleLines(0, 231, screenWidth, 751, BLACK);
		int j = 0;
		mousePoint = GetMousePosition();

		for (int i = 0; i < n; ++i) {
			DrawLine(x_course + 111, y_course + j - 24, x_course + 111, y_course + j + 38, BLACK);
			DrawLine(x_course + 597, y_course + j - 24, x_course + 597, y_course + j + 38, BLACK);
			DrawLine(x_course + 729, y_course + j - 24, x_course + 729, y_course + j + 38, BLACK);
			DrawLine(x_course + 1056, y_course + j - 24, x_course + 1056, y_course + j + 38, BLACK);
			DrawLine(x_course + 1139, y_course + j - 24, x_course + 1139, y_course + j + 38, BLACK);
			DrawLine(x_course + 1283, y_course + j - 24, x_course + 1283, y_course + j + 38, BLACK);
			DrawLine(x_course + 1414, y_course + j - 24, x_course + 1414, y_course + j + 38, BLACK);
			DrawLine(x_course + 1501, y_course + j - 24, x_course + 1501, y_course + j + 38, BLACK);

			DrawRectangleLines(0, y_course + j - 24, 1512, 62, BLACK);
			DrawRectangleLines(0, y_course + j - 24, 1512, 62, BLACK);
			coursebutton[i].button = { 0, float(y_course + j), 1512, 20 };
			DrawText(courses[i].courseID, x_course, y_course + j, 20, BLACK);
			DrawText(courses[i].courseName, x_course + 148, y_course + j, 20, BLACK);
			DrawText(courses[i].className, x_course + 614, y_course + j, 20, BLACK);
			DrawText(courses[i].teacherName, x_course + 742, y_course + j, 20, BLACK);
			char* nofc = new char[10];
			int_to_char(courses[i].numOfCre, nofc);
			DrawText(nofc, x_course + 1087, y_course + j, 20, BLACK);
			char* maxstu = new char[10];
			int_to_char(courses[i].maxStu, maxstu);
			DrawText(maxstu, x_course + 1189, y_course + j, 20, BLACK);
			DrawText(courses[i].dayofweek, x_course + 1320, y_course + j, 20, BLACK);
			DrawText(courses[i].sessionHour, x_course + 1442, y_course + j, 20, BLACK);
			if (y_course + j < 231) coursebutton[i].state = false;
			coursebutton[i].workbutton(mousePoint, CurrentUser, Year, Semester, courses[i], CoursePage);
			j += 61;

			if (coursebutton[i].action1 == true) {
				for (int j = 0; j < n; ++j) {
					if (j != i) coursebutton[j].action1 = false;
				}
				x = coursebutton[i].x;
				y = coursebutton[i].y;
				DrawRectangle(x, y, 160, 50, LIGHTGRAY);
				DrawText("Delete", x + 7, y + 3, 20, MAROON);
				DrawLine(x, y + 25, x + 160, y + 25, BLACK);
				DrawText("Update", x + 7, y + 3 + 25, 20, MAROON);
			}
			if (coursebutton[i].remove == true) {
				deleteCourse(courses, i, n, Year, Semester);
				coursebutton[i].remove = false;
				coursebutton[i].action1 = false;
			}
			if (coursebutton[i].update == true) {
				UpdateCoursePage(screenWidth, screenHeight, CurrentUser, Year, Semester, courses, n, i);
				coursebutton[i].update = false;
				coursebutton[i].action1 = false;
			}

		}
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawText(Year, 30, 15, 40, DARKBLUE);
		DrawText(Semester, 670, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoviewsemesterpage.button, WHITE);
		DrawText("Back to View Semester Page", 1180, 20, 20, DARKBLUE);
		DrawTexture(background2, 0, 60, WHITE);

		DrawRectangle(0, 189, 121, 42, LIGHTGRAY);
		DrawRectangleLines(0, 189, 121, 42, BLACK);
		DrawText("ID", 45, 203, 20, DARKBLUE);

		DrawRectangle(121, 189, 486, 42, LIGHTGRAY);
		DrawRectangleLines(121, 189, 486, 42, BLACK);
		DrawText("Course name", 311, 203, 20, DARKBLUE);

		DrawRectangle(607, 189, 132, 42, LIGHTGRAY);
		DrawRectangleLines(607, 189, 132, 42, BLACK);
		DrawText("Class name", 617, 203, 20, DARKBLUE);

		DrawRectangle(739, 189, 327, 42, LIGHTGRAY);
		DrawRectangleLines(739, 189, 327, 42, BLACK);
		DrawText("Teacher name", 835, 203, 20, DARKBLUE);

		DrawRectangle(1066, 189, 83, 42, LIGHTGRAY);
		DrawRectangleLines(1066, 189, 83, 42, BLACK);
		DrawText("Credits", 1071, 203, 20, DARKBLUE);

		DrawRectangle(1149, 189, 144, 42, LIGHTGRAY);
		DrawRectangleLines(1149, 189, 144, 42, BLACK);
		DrawText("Max students", 1153, 203, 20, DARKBLUE);

		DrawRectangle(1293, 189, 131, 42, LIGHTGRAY);
		DrawRectangleLines(1293, 189, 131, 42, BLACK);
		DrawText("Course day", 1300, 203, 20, DARKBLUE);

		DrawRectangle(1424, 189, 88, 42, LIGHTGRAY);
		DrawRectangleLines(1424, 189, 88, 42, BLACK);
		DrawText("Session", 1430, 203, 20, DARKBLUE);

		backtoviewsemesterpage.workbutton(mousePoint, CurrentUser, Year, ViewSemestersPage);
		createcourse.workbutton(mousePoint, CurrentUser, Year, Semester, CreateCoursePage);
		EndDrawing();
	}
	delete[] coursebutton;
	delete[] courses;
	delete[] Year;
	delete[] Semester;
	CloseWindow();
}
void UpdateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course* &Course, int n, int i) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 id;
	id.textbox = { 175, 149, 1064, 47 };
	Textbox1 coursename;
	coursename.textbox = { 175, 262, 1064, 47 };
	Textbox1 classname;
	classname.textbox = { 175, 375, 1064, 47 };
	Textbox1 teachername;
	teachername.textbox = { 175, 488, 1064, 47 };
	Textbox1 nofc;
	nofc.textbox = { 175, 601, 1064, 47 };
	Textbox1 maxstudents;
	maxstudents.textbox = { 175, 714, 1064, 47 };
	Textbox1 courseday;
	courseday.textbox = { 175, 827, 528, 47 };
	Textbox1 sshours;
	sshours.textbox = { 779, 827, 528, 47 };

	Button6 backtoviewcoursepage;
	backtoviewcoursepage.button = { 1200, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn1.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 670, 910, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoviewcoursepage.button, WHITE);
		DrawText(Year, 30, 15, 40, DARKBLUE);
		DrawText(Semester, 670, 15, 40, DARKBLUE);
		DrawText("Back to View Course Page", 1230, 20, 20, DARKBLUE);

		DrawRectangle(126, 92, 1260, 870, WHITE);
		DrawRectangleRec(id.textbox, LIGHTGRAY);
		DrawText("* Course ID: ", 175, 120, 25, DARKBLUE);
		DrawRectangleRec(coursename.textbox, LIGHTGRAY);
		DrawText("* Course name: ", 175, 233, 25, DARKBLUE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawText("* Class name: ", 175, 346, 25, DARKBLUE);
		DrawRectangleRec(teachername.textbox, LIGHTGRAY);
		DrawText("* Teacher name: ", 175, 459, 25, DARKBLUE);
		DrawRectangleRec(nofc.textbox, LIGHTGRAY);
		DrawText("* Number of credits: ", 175, 572, 25, DARKBLUE);
		DrawRectangleRec(maxstudents.textbox, LIGHTGRAY);
		DrawText("* Maximum students: ", 175, 685, 25, DARKBLUE);
		DrawRectangleRec(courseday.textbox, LIGHTGRAY);
		DrawText("* Course day: ", 175, 798, 25, DARKBLUE);
		DrawRectangleRec(sshours.textbox, LIGHTGRAY);
		DrawText("* Session hours: ", 779, 798, 25, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		id.worktextbox(confirmBtnFalseDisplay);
		coursename.worktextbox(confirmBtnFalseDisplay);
		classname.worktextbox(confirmBtnFalseDisplay);
		teachername.worktextbox(confirmBtnFalseDisplay);
		nofc.worktextbox(confirmBtnFalseDisplay);
		maxstudents.worktextbox(confirmBtnFalseDisplay);
		courseday.worktextbox(confirmBtnFalseDisplay);
		sshours.worktextbox(confirmBtnFalseDisplay);


		if (id.lettercount == 0)			DrawText(Course[i].courseID, 198, 162, 25, BLACK);
		if (coursename.lettercount == 0)	DrawText(Course[i].courseName, 198, 275, 25, BLACK);
		if (classname.lettercount == 0)		DrawText(Course[i].className, 198, 388, 25, BLACK);
		if (teachername.lettercount == 0)	DrawText(Course[i].teacherName, 198, 501, 25, BLACK);
		if (nofc.lettercount == 0) {
			char* nofc = new char[10];
			int_to_char(Course[i].numOfCre, nofc);
			DrawText(nofc, 198, 614, 25, BLACK);
		}
		if (maxstudents.lettercount == 0)	DrawText("50", 198, 727, 25, BLACK);
		if (courseday.lettercount == 0)		DrawText(Course[i].dayofweek, 198, 840, 25, BLACK);
		if (sshours.lettercount == 0)		DrawText(Course[i].sessionHour, 802, 840, 25, BLACK);
		DrawText(id.text, 198, 162, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", id.lettercount, MAX_INPUT_CHARS), 1270, 172, 20, DARKBLUE);
		DrawText(coursename.text, 198, 275, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", coursename.lettercount, MAX_INPUT_CHARS), 1270, 285, 20, DARKBLUE);
		DrawText(classname.text, 198, 388, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", classname.lettercount, MAX_INPUT_CHARS), 1270, 398, 20, DARKBLUE);
		DrawText(teachername.text, 198, 501, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", teachername.lettercount, MAX_INPUT_CHARS), 1270, 511, 20, DARKBLUE);
		DrawText(nofc.text, 198, 614, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", nofc.lettercount, MAX_INPUT_CHARS), 1270, 624, 20, DARKBLUE);
		DrawText(maxstudents.text, 198, 727, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", maxstudents.lettercount, MAX_INPUT_CHARS), 1270, 737, 20, DARKBLUE);
		DrawText(courseday.text, 198, 840, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", courseday.lettercount, MAX_INPUT_CHARS), 713, 855, 16, DARKBLUE);
		DrawText(sshours.text, 802, 840, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", sshours.lettercount, MAX_INPUT_CHARS), 1320, 855, 16, DARKBLUE);


		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (!CheckValidCourse(coursename.text, id.text, classname.text, Year, Semester)) {
				confirmBtnFalseDisplay = true;
			}
			else {
				updateCourse(Year, Semester, Course[i], coursename.text, id.text, classname.text, teachername.text, nofc.text, maxstudents.text, courseday.text, sshours.text);
				ReturnCoursesToFile(Year, Semester, n, Course);
				EndDrawing();
				ViewCoursesPage(screenWidth, screenHeight, CurrentUser, Year, Semester);
			}
		}
		if (confirmBtnFalseDisplay) DrawText("Some textboxes are blank. Please try again!", 582, 888, 15, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoviewcoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, ViewCoursesPage);

		EndDrawing();
	}
	delete[] Year;
	delete[] Semester;
	CloseWindow();
}
void CoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course) {
	student* listStudents;
	int n = countStu(Course, Year, Semester);
	Load_stu(Course, Year, Semester, listStudents);

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Button6 backtoviewcoursespage;
	backtoviewcoursespage.button = { 1160, 25, 250, 30 };
	Texture2D background2 = LoadTexture("course_background.png");


	Button7 addStuCSV;
	addStuCSV.texture = LoadTexture("addstudentwithcsv.png");
	addStuCSV.frameHeight = (float)addStuCSV.texture.height;
	addStuCSV.sourceRec = { 0, 0, (float)addStuCSV.texture.width, addStuCSV.frameHeight };
	addStuCSV.btnBounds = { 170, 94, (float)addStuCSV.texture.width, addStuCSV.frameHeight };

	Button7 addAStu;
	addAStu.texture = LoadTexture("addastudent.png");
	addAStu.frameHeight = (float)addAStu.texture.height;
	addAStu.sourceRec = { 0, 0, (float)addAStu.texture.width, addAStu.frameHeight };
	addAStu.btnBounds = { 599, 94, (float)addAStu.texture.width, addAStu.frameHeight};
	
	Button0 exportListStu; // caution
	exportListStu.texture = LoadTexture("exportlistofstu.png");
	exportListStu.frameHeight = (float)exportListStu.texture.height;
	exportListStu.sourceRec = { 0, 0, (float)exportListStu.texture.width, exportListStu.frameHeight };
	exportListStu.btnBounds = { 1028, 94, (float)exportListStu.texture.width, exportListStu.frameHeight};

	Textbox1 ExportStu;
	ExportStu.textbox = { 237, 377, 950, 47 };
	
	Texture2D confirmBtn = LoadTexture("confirmBtn1.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 670, 470, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	bool confirmBtnFalseDisplay1 = false;

	Rectangle turnOffexport = { 1235, 189, 91, 76 };
	Button8* studentbutton = new Button8[n];
	int scrollspeed = 35;
	int x_student = 11;
	int y_student = 255;
	int x = 0;
	int y = 0;
	while (!WindowShouldClose()) {
		y_student += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_student > 11) x_student = 11;
		if (y_student > 255) y_student = 255;
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);

		DrawRectangle(0, 231, screenWidth, 751, WHITE);
		DrawRectangleLines(0, 231, screenWidth, 751, BLACK);
		int j = 0;
		mousePoint = GetMousePosition();
		
		for (int i = 0; i < n; ++i) {
			DrawLine(x_student + 47, y_student + j - 1, x_student + 47, y_student + j + 61, BLACK);
			DrawLine(x_student + 216, y_student + j - 1, x_student + 216, y_student + j + 61, BLACK);
			DrawLine(x_student + 395, y_student + j - 1, x_student + 395, y_student + j + 61, BLACK);
			DrawLine(x_student + 851, y_student + j - 1, x_student + 851, y_student + j + 61, BLACK);
			DrawLine(x_student + 1008, y_student + j - 1, x_student + 1008, y_student + j + 61, BLACK);
			DrawLine(x_student + 1159, y_student + j - 1, x_student + 1159, y_student + j + 61, BLACK);
			DrawLine(x_student + 1332, y_student + j - 1, x_student + 1332, y_student + j + 61, BLACK);
			DrawLine(x_student + 1501, y_student + j - 1, x_student + 1501, y_student + j + 61, BLACK);

			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			studentbutton[i].button = { 0, float(y_student + j), 1512, 62 };
			char* stuNo = new char[10];
			int_to_char(listStudents[i].No, stuNo);
			DrawText(stuNo, x_student + 13, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].stuID, x_student + 72, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.lastName, x_student + 260, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.firstName, x_student + 528, y_student + j + 30, 20, BLACK);
			char* finalMark = new char[5];
			char* midtermMark = new char[5];
			char* otherMark = new char[5];
			char* totalMark = new char[5];
			double_to_char(listStudents[i].mark.totalMark, totalMark);
			DrawText(totalMark, x_student + 901, y_student + j + 30, 20, BLACK);
			double_to_char(listStudents[i].mark.finalMark, finalMark);
			DrawText(finalMark, x_student + 1055, y_student + j + 30, 20, BLACK);
			double_to_char(listStudents[i].mark.midtermMark, midtermMark);
			DrawText(midtermMark, x_student + 1217, y_student + j + 30, 20, BLACK);
			double_to_char(listStudents[i].mark.otherMark, otherMark);
			DrawText(otherMark, x_student + 1384, y_student + j + 30, 20, BLACK);
			if (y_student + j < 231) studentbutton[i].state = false;
			studentbutton[i].workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);
			j += 61;

			if (studentbutton[i].action1 == true) {
				for (int j = 0; j < n; ++j) {
					if (j != i) studentbutton[j].action1 = false;
				}
				x = studentbutton[i].x;
				y = studentbutton[i].y;
				DrawRectangle(x, y, 160, 25, LIGHTGRAY);
				DrawText("Remove", x + 7, y + 3, 20, MAROON);
			}
			if (studentbutton[i].remove == true) {
				deleteStudent(Course, i, n, Year, Semester);
				studentbutton[i].remove = false;
				studentbutton[i].action1 = false;
			}
			delete [] stuNo;
			delete [] finalMark;
			delete [] midtermMark;
			delete [] totalMark;
			delete [] otherMark;
		}
		DrawRectangle(0, 0, screenWidth, 70, WHITE);
		DrawText(Course.courseID, 30, 10, 20, DARKBLUE);
		DrawText(Course.className, 30, 40, 20, DARKBLUE);
		DrawText(Year, 720, 12, 20, DARKBLUE);
		DrawText(Semester, 720, 35, 30, DARKBLUE);
		DrawRectangleRec(backtoviewcoursespage.button, WHITE);
		DrawText("Back to Courses Page", 1180, 25, 20, DARKBLUE);
		DrawTexture(background2, 0, 70, WHITE);

		DrawRectangle(0, 189, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 58, 65, BLACK);
		DrawText("No", 8, 210, 24, DARKBLUE);

		DrawRectangle(58, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 189, 173, 65, BLACK);
		DrawText("Student ID", 84, 210, 24, DARKBLUE);

		DrawRectangle(227, 189, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 189, 179, 65, BLACK);
		DrawText("Last name", 256, 210, 24, DARKBLUE);

		DrawRectangle(406, 189, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 189, 456, 65, BLACK);
		DrawText("First name", 569, 210, 24, DARKBLUE);

		DrawRectangle(862, 189, 157, 65, LIGHTGRAY);
		DrawRectangleLines(862, 189, 157, 65, BLACK);
		DrawText("Total mark", 878, 210, 24, DARKBLUE);

		DrawRectangle(1019, 189, 151, 65, LIGHTGRAY);
		DrawRectangleLines(1019, 189, 151, 65, BLACK);
		DrawText("Final mark", 1035, 210, 24, DARKBLUE);
		
		DrawRectangle(1170, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(1170, 189, 173, 65, BLACK);
		DrawText("Midterm mark", 1177, 210, 24, DARKBLUE);

		DrawRectangle(1343, 189, 169, 65, LIGHTGRAY);
		DrawRectangleLines(1343, 189, 169, 65, BLACK);
		DrawText("Other mark", 1359, 210, 24, DARKBLUE);

		mousePoint = GetMousePosition();
		addAStu.workbutton(mousePoint, CurrentUser, Course, Year, Semester, addStudentPageForCourse);
		addStuCSV.workbutton(mousePoint, CurrentUser, Course, Year, Semester, addStudentCSVForCourse);
		exportListStu.workbutton(mousePoint);

		string tmp = string(Course.courseName) + "-" + string(Course.className);
		char* filename = (char*)tmp.c_str();

		if (exportListStu.action) {
			for (int i = 0; i < n; ++i) {
				studentbutton[i].state = false;
			}
			DrawRectangle(165, 190, 1161, 618, BLUE);
			DrawText("OUT", 1254, 210, 44, RED);
			DrawText("* Please input the link path to folder you want to export files to: ", 237, 298, 25, BLACK);
			DrawRectangleRec(ExportStu.textbox, LIGHTGRAY);
			ExportStu.worktextbox(confirmBtnFalseDisplay);
			DrawText(ExportStu.text, 260, 390, 25, DARKBLUE);
			DrawText(TextFormat("%i/%i", ExportStu.lettercount, MAX_INPUT_CHARS), 1218, 400, 20, DARKBLUE);

			confirmBtnAction = false;
			if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
			}
			else confirmBtnState = 0;
			if (confirmBtnAction) {
				if (exportStudentsInCourseToFile(ExportStu.text, Year, Semester, filename)) {
					confirmBtnFalseDisplay1 = true;
				}
				else confirmBtnFalseDisplay = true;
			}
			if (confirmBtnFalseDisplay) DrawText("Could not export to the folder", 582, 888, 15, RED);
			if (confirmBtnFalseDisplay1) {
				DrawText("File is exported to the folder! File name is: ", 582, 888, 15, GREEN);
				DrawText(filename, 982, 888, 15, GREEN);
			}
			// Calculate button frame rectangle to draw depending on button state

			if (CheckCollisionPointRec(mousePoint, turnOffexport)) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) exportListStu.action = false;
			}
			sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
			DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame
		}
		backtoviewcoursespage.workbutton(mousePoint, CurrentUser, Year, Semester, ViewCoursesPage);
		EndDrawing();
	}
	delete[] studentbutton;
	//delete[] listStudents;
	delete[] Year;
	delete[] Semester;
	CloseWindow();
}
void addStudentPageForCourse(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course) {
	string tmp = string(Course.courseName) + "-" + string(Course.className);
	char* filename = (char*)tmp.c_str();

	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 Gender;
	Gender.textbox = { 284, 627, 283, 84 };
	Textbox1 birth;
	birth.textbox = { 604, 627, 623, 84 };
	Textbox1 Lastname;
	Lastname.textbox = { 284,213,283,84 };
	Textbox1 Firstname;
	Firstname.textbox = { 610,213,617,84 };
	Textbox1 studentID;
	studentID.textbox = { 284,351,943,84 };
	Textbox1 socialID;
	socialID.textbox = { 284,489,943,84 };

	Button8 backtoCoursepage;
	backtoCoursepage.button = { 1270, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 750, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawText("Back to Course Page", 1280, 20, 20, DARKBLUE);
		DrawText("Add a student", 620, 12, 40, DARKBLUE);

		DrawRectangle(142, 148, 1227, 720, WHITE);
		DrawRectangleRec(Lastname.textbox, LIGHTGRAY);
		DrawText("* Last name", 284, 174, 30, DARKBLUE);
		DrawRectangleRec(Firstname.textbox, LIGHTGRAY);
		DrawText("* First name", 610, 174, 30, DARKBLUE);
		DrawRectangleRec(studentID.textbox, LIGHTGRAY);
		DrawText("* Student ID", 284, 312, 30, DARKBLUE);
		DrawRectangleRec(socialID.textbox, LIGHTGRAY);
		DrawText("* Social ID", 284, 450, 30, DARKBLUE);
		DrawRectangleRec(birth.textbox, LIGHTGRAY);
		DrawText("* Date of birth", 604, 588, 30, DARKBLUE);
		DrawRectangleRec(Gender.textbox, LIGHTGRAY);
		DrawText("* Gender", 284, 588, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		Lastname.worktextbox(confirmBtnFalseDisplay);
		Firstname.worktextbox(confirmBtnFalseDisplay);
		studentID.worktextbox(confirmBtnFalseDisplay);
		socialID.worktextbox(confirmBtnFalseDisplay);
		birth.worktextbox(confirmBtnFalseDisplay);
		Gender.worktextbox(confirmBtnFalseDisplay);

		DrawText(Lastname.text, 314, 233, 40, DARKBLUE);
		DrawText(Firstname.text, 640, 233, 40, DARKBLUE);
		DrawText(studentID.text, 314, 371, 40, DARKBLUE);
		DrawText(socialID.text, 314, 509, 40, DARKBLUE);
		DrawText(birth.text, 634, 647, 40, DARKBLUE);
		DrawText(Gender.text, 314, 647, 40, DARKBLUE);

		////Function of buttons------------	------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (addAStudentToCourse(Year, Semester, filename, Firstname.text, Lastname.text, Gender.text, birth.text, socialID.text, studentID.text)) {
				confirmBtnFalseDisplay = false;
				CoursePage(screenWidth, screenHeight, CurrentUser, Year, Semester, Course);
			}
			else confirmBtnFalseDisplay = true;

		}
		if (confirmBtnFalseDisplay) DrawText("This class was created before!", 480, 560, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoCoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);
		EndDrawing();
	}
	CloseWindow();
}
void addStudentCSVForCourse(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course) {

	string tmp = string(Course.courseName) + "-" + string(Course.className);
	char* fileCourse = (char*)tmp.c_str();

	student* dupstu = nullptr;
	int numDupStu = 0;
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox1 filename;
	filename.textbox = { 420,280,650,84 };

	Button8 backtoCoursepage;
	backtoCoursepage.button = { 1270, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 650, 420, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawText("Back to Course Page", 1280, 20, 20, DARKBLUE);
		DrawText("Add student(s)", 620, 12, 40, DARKBLUE);

		DrawRectangle(347, 173, 818, 380, WHITE);
		DrawRectangleRec(filename.textbox, LIGHTGRAY);
		DrawText("* File name", 420, 235, 30, DARKBLUE);

		filename.worktextbox(confirmBtnFalseDisplay);
		DrawText(filename.text, 450, 300, 40, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (checkdata_FileName(filename.text)) {
				confirmBtnFalseDisplay = false;
				if (addStudentsToCourseWithCSV(filename.text, Year, Semester, fileCourse, dupstu, numDupStu)) {
					CoursePage(screenWidth, screenHeight, CurrentUser, Year, Semester, Course);
				}
				else {
					dataExistedPageforCourse(screenWidth, screenHeight, CurrentUser, Year, Semester, Course, numDupStu, dupstu);
				}
			}
		}
		if (confirmBtnFalseDisplay) DrawText("File name is invalid!!!", 440, 380, 20, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoCoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);

		EndDrawing();
	}
	delete dupstu;
	CloseWindow();
}
void dataExistedPageforCourse(const int screenWidth, const int screenHeight, account& CurrentUser, char* Year, char* Semester, course Course, int numDupStu, student* dupstu) {
	int n = numDupStu;
	student* StuExisted = dupstu;
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Button8 backtoCoursepage;
	backtoCoursepage.button = { 1270, 20, 200, 30 };

	int scrollspeed = 35;
	int x_student = 11;
	int y_student = 126;

	while (!WindowShouldClose()) {
		y_student += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_student > 11) x_student = 11;
		if (y_student > 126) y_student = 126;
		ClearBackground(WHITE);
		BeginDrawing();


		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 125, screenWidth, 900, WHITE);
		int j = 0;

		mousePoint = GetMousePosition();
		for (int i = 0; i < n; ++i) {
			DrawLine(x_student + 47, y_student + j - 1, x_student + 47, y_student + j + 61, BLACK);
			DrawLine(x_student + 216, y_student + j - 1, x_student + 216, y_student + j + 61, BLACK);
			DrawLine(x_student + 395, y_student + j - 1, x_student + 395, y_student + j + 61, BLACK);
			DrawLine(x_student + 851, y_student + j - 1, x_student + 851, y_student + j + 61, BLACK);
			DrawLine(x_student + 1039, y_student + j - 1, x_student + 1039, y_student + j + 61, BLACK);
			DrawLine(x_student + 1281, y_student + j - 1, x_student + 1281, y_student + j + 61, BLACK);
			DrawLine(x_student + 1501, y_student + j - 1, x_student + 1501, y_student + j + 61, BLACK);

			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			DrawRectangleLines(0, y_student + j - 1, 1512, 62, BLACK);
			char* stuNo = new char[10];
			int_to_char(StuExisted[i].No, stuNo);
			DrawText(stuNo, x_student + 13, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].stuID, x_student + 72, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.lastName, x_student + 260, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.firstName, x_student + 528, y_student + j + 30, 20, BLACK);

			if (StuExisted[i].Student.gender) DrawText("Male", x_student + 912, y_student + j + 30, 20, BLACK);
			else DrawText("Female", x_student + 912, y_student + j + 30, 20, BLACK);

			DrawText(dateToChar(StuExisted[i].Student.dob), x_student + 1097, y_student + j + 30, 20, BLACK);
			DrawText(StuExisted[i].Student.socialID, x_student + 1300, y_student + j + 30, 20, BLACK);
			j += 61;
		}

		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawText("These students have already existed in this course", 10, 10, 40, RED);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawText("Back to Course Page", 1280, 20, 20, DARKBLUE);

		DrawRectangle(0, 60, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 60, 58, 65, BLACK);
		DrawText("No", 8, 76, 24, DARKBLUE);

		DrawRectangle(58, 60, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 60, 173, 65, BLACK);
		DrawText("Student ID", 84, 76, 24, DARKBLUE);

		DrawRectangle(227, 60, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 60, 179, 65, BLACK);
		DrawText("Last name", 256, 76, 24, DARKBLUE);

		DrawRectangle(406, 60, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 60, 456, 65, BLACK);
		DrawText("First name", 569, 76, 24, DARKBLUE);

		DrawRectangle(862, 60, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 60, 188, 65, BLACK);
		DrawText("Gender", 910, 76, 24, DARKBLUE);

		DrawRectangle(1050, 60, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 60, 242, 65, BLACK);
		DrawText("Date of Birth", 1095, 76, 24, DARKBLUE);

		DrawRectangle(1292, 60, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 60, 220, 65, BLACK);
		DrawText("Social ID", 1345, 76, 24, DARKBLUE);

		backtoCoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);

		EndDrawing();
	}
	CloseWindow();
}
void updateStudent(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course) {

}


