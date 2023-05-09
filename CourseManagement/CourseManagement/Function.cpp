#include "Function.h"
#include "users.h"
using namespace std;


//FRONT_END--------------------------------------------------------
void StudentorStaffPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font Title = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };

	Texture2D Student = LoadTexture("Student.png");
	Texture2D Staff = LoadTexture("Staff.png");


	Button2 student;
	student.button = { 23, 295, 645, 518 };

	Button2 staff;
	staff.button = { 839, 295, 645, 518 };

	SetTargetFPS(40);
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawRectangle(552, 148, 408, 59, WHITE);
		DrawText("You are a", 660, 157, 40, DARKBLUE);
		DrawTextEx(Title, "COURSE MANAGEMENT SYSTEM", { 340, 5 }, 60, 1, DARKBLUE);
		DrawRectangle(570, 148, 367, 59, WHITE);
		DrawTextEx(medium, "Welcome", { 635, 150 }, 60, 0, DARKBLUE);
		DrawRectangleRec(student.button, WHITE);
		DrawRectangle(23, 295, 645, 80, DARKBLUE);
		DrawTextEx(medium, "STUDENT", { 255,310 }, 45, 1, WHITE);
		DrawTexture(Student, 140, 390, RAYWHITE);
		DrawRectangleRec(staff.button, WHITE);
		DrawRectangle(839, 295, 645, 80, DARKBLUE);
		DrawTextEx(medium, "STAFF", { 1100,310 }, 45, 1, WHITE);
		DrawTexture(Staff, 966, 390, RAYWHITE);

		mousePoint = GetMousePosition();
		staff.workbutton(mousePoint, CurrentUser, LogInPageStaff);
		student.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		EndDrawing();
	}
	CloseWindow();

}
void LogInPageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	//Initialize textbox-------------------------------------------------------
	Textbox1 username;
	username.textbox = { 477, 289,558,106 };

	Textbox2 password;
	password.textbox = { 477, 453,558,106 };

	Button0 viewPass;
	viewPass.texture = LoadTexture("showpass.png");
	viewPass.frameHeight = (float)viewPass.texture.height;
	viewPass.sourceRec = { 0, 0, (float)viewPass.texture.width, viewPass.frameHeight };
	viewPass.btnBounds = { 650, 410, (float)viewPass.texture.width, viewPass.frameHeight };

	Button0 hidePass;
	hidePass.texture = LoadTexture("hidepass.png");
	hidePass.frameHeight = (float)hidePass.texture.height;
	hidePass.sourceRec = { 0, 0, (float)hidePass.texture.width, hidePass.frameHeight };
	hidePass.btnBounds = { 650, 406, (float)hidePass.texture.width, hidePass.frameHeight };

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
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 },25,0, DARKBLUE);
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(backtopreviouspage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25,0, DARKBLUE);
		DrawRectangleRec(password.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Username", { 477, 245 }, 35,0, DARKBLUE);
		DrawTextEx(medium, "* Password", { 477, 409 }, 35,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		username.worktextbox(isLoginFalseDisplay);
		password.worktextbox(isLoginFalseDisplay);
		viewPass.workbutton(mousePoint);


		DrawTextEx(medium, username.text, { 500, 320 }, 45,0, DARKBLUE);
		//DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		if (viewPass.hidden) {
			DrawTextEx(medium, password.hiddentext, { 500, 490 }, 40,0, DARKBLUE);
		}
		if (!viewPass.hidden) {
			DrawTextureRec(hidePass.texture, hidePass.sourceRec, { hidePass.btnBounds.x,hidePass.btnBounds.y }, WHITE);
			DrawTextEx(medium, password.text, { 500, 485 }, 45, 0, DARKBLUE);
		}
		//DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 500, 20, DARKBLUE);

		////Function of login button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		loginbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) loginbtnAction = true;
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	//Initialize textbox-------------------------------------------------------
	Textbox1 username;
	username.textbox = { 477, 289,558,106 };

	Textbox2 password;
	password.textbox = { 477, 453,558,106 };

	Button0 viewPass;
	viewPass.texture = LoadTexture("showpass.png");
	viewPass.frameHeight = (float)viewPass.texture.height;
	viewPass.sourceRec = { 0, 0, (float)viewPass.texture.width, viewPass.frameHeight };
	viewPass.btnBounds = { 650, 410, (float)viewPass.texture.width, viewPass.frameHeight };

	Button0 hidePass;
	hidePass.texture = LoadTexture("hidepass.png");
	hidePass.frameHeight = (float)hidePass.texture.height;
	hidePass.sourceRec = { 0, 0, (float)hidePass.texture.width, hidePass.frameHeight };
	hidePass.btnBounds = { 650, 406, (float)hidePass.texture.width, hidePass.frameHeight };

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

	bool stafforstudent = true;
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
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 }, 25, 0, DARKBLUE);
		DrawRectangleRec(username.textbox, LIGHTGRAY);
		DrawRectangleRec(backtopreviouspage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25, 0, DARKBLUE);
		DrawRectangleRec(password.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Username", { 477, 245 }, 35, 0, DARKBLUE);
		DrawTextEx(medium, "* Password", { 477, 409 }, 35, 0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		username.worktextbox(isLoginFalseDisplay);
		password.worktextbox(isLoginFalseDisplay);
		viewPass.workbutton(mousePoint);


		DrawTextEx(medium, username.text, { 500, 320 }, 40, 0, DARKBLUE);
		//DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		if (viewPass.hidden) {
			DrawTextEx(medium, password.hiddentext, { 500, 490 }, 40, 0, DARKBLUE);
		}
		if (!viewPass.hidden) {
			DrawTextureRec(hidePass.texture, hidePass.sourceRec, { hidePass.btnBounds.x,hidePass.btnBounds.y }, WHITE);
			DrawTextEx(medium, password.text, { 500, 485 }, 40, 0, DARKBLUE);
		}
		//DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 500, 20, DARKBLUE);

		////Function of login button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		loginbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) loginbtnAction = true;
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
void ProfilePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	////Initialize variable---------------------------------------------------------------------------------------------
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawTextEx(bold, "WELCOME!", { 670, 15 }, 40, 0, DARKBLUE);

		DrawRectangle(70, 170, 360, 750, WHITE);
		DrawRectangleLines(69, 169, 362, 752, BLACK);
		DrawRectangleLines(68, 168, 364, 754, BLACK);

		DrawRectangle(480, 170, 980, 750, WHITE);
		DrawRectangleLines(479, 169, 982, 752, BLACK);
		DrawRectangleLines(478, 168, 984, 754, BLACK);

		DrawRectangle(480, 108, 250, 60, WHITE);
		DrawRectangleLines(479, 107, 252, 62, BLACK);
		DrawRectangleLines(478, 106, 254, 64, BLACK);
		DrawTextEx(bold, "STUDENT", { 525, 118 }, 40,0, DARKBLUE);

		DrawTexture(scoreboardIcon, 595, 216, WHITE);
		DrawTexture(courseIcon, 595, 567, WHITE);

		DrawTexture(avatar, 150, 107, WHITE);
		DrawTextEx(medium, "Username: ", { 118, 337 }, 30,0, DARKBLUE);
		DrawTextEx(medium, CurrentUser.userName, { 268, 337 }, 30,0, DARKGRAY);

		mousePoint = GetMousePosition();
		////change password button function-----------------------------------------------------------------------------------------------------------
		ChangePass.workbutton(mousePoint, CurrentUser, ChangePasswordPageStudent);
		LogOut.workbutton(mousePoint, CurrentUser, LogInPageStudent);
		scoreboard.workbutton(mousePoint, CurrentUser, ScoreboardStudent);
		course.workbutton(mousePoint, CurrentUser, CoursePageStudent);

		//// display schoolyear from createschoolyear page--------------------------------------------------------------------------------------------
		EndDrawing();
	}
	CloseWindow();
}
void CoursePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };
	int cntCourse = 0;
	course* courses = nullptr;
	int cntYears = 0;
	char** YearName = nullptr;
	getStudyingSchoolYear(CurrentUser.userName, cntYears, YearName);

	Button1_5 backtopreviouspage;
	backtopreviouspage.button = { 1200, 20, 300, 30 };

	int n = 3;    //count semester
	Rectangle ok = { 660,100,80,50 };
	Rectangle semesters = { 60,100,200,50 };
	Rectangle schoolyears = { 360,100,200,50 };
	bool action = false;
	bool actionF = false;
	bool actionS = false;
	bool actionA = false;
	bool action1 = false;
	bool* actionYear = new bool[cntYears] {0};
	bool actionOK = false;

	char* yearnametmp = nullptr;
	char* semesternametmp = nullptr;

	int scrollspeed = 35;
	int x_course = 11;
	int y_course = 255;

	while (!WindowShouldClose()) {
		mousePoint = GetMousePosition();
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawTextEx(bold, "COURSE MANAGEMENT SYSTEM", { 430, 10 }, 40,1, DARKBLUE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawTextEx(bold, "Years", { 430 , 113}, 25,0, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawTextEx(bold, "Semesters", { 103, 113}, 25,0, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawTextEx(bold, "OK", { 687, 113 }, 25,0, WHITE);
		int z = 0, r = 0, j = 0;

		DrawRectangleLines(0, 189, 1512, 0, BLACK);
		DrawRectangle(0, 189, 121, 42, LIGHTGRAY);
		DrawRectangleLines(0, 189, 121, 42, BLACK);
		DrawTextEx(bold, "ID", { 43, 198 }, 25,0, DARKBLUE);

		DrawRectangle(121, 189, 486, 42, LIGHTGRAY);
		DrawRectangleLines(121, 189, 486, 42, BLACK);
		DrawTextEx(bold, "Course name", { 309, 198 }, 25,0, DARKBLUE);

		DrawRectangle(607, 189, 132, 42, LIGHTGRAY);
		DrawRectangleLines(607, 189, 132, 42, BLACK);
		DrawTextEx(bold, "Class name", { 613, 198 }, 25,0, DARKBLUE);

		DrawRectangle(739, 189, 327, 42, LIGHTGRAY);
		DrawRectangleLines(739, 189, 327, 42, BLACK);
		DrawTextEx(bold, "Teacher name", { 832, 198 }, 25,0, DARKBLUE);

		DrawRectangle(1066, 189, 83, 42, LIGHTGRAY);
		DrawRectangleLines(1066, 189, 83, 42, BLACK);
		DrawTextEx(bold, "Credits", { 1069, 198 }, 25,0, DARKBLUE);

		DrawRectangle(1149, 189, 144, 42, LIGHTGRAY);
		DrawRectangleLines(1149, 189, 144, 42, BLACK);
		DrawTextEx(bold, "Max students", { 1149, 198 }, 25,0, DARKBLUE);

		DrawRectangle(1293, 189, 131, 42, LIGHTGRAY);
		DrawRectangleLines(1293, 189, 131, 42, BLACK);
		DrawTextEx(bold, "Course day", { 1298, 198 }, 25,0, DARKBLUE);

		DrawRectangle(1424, 189, 88, 42, LIGHTGRAY);
		DrawRectangleLines(1424, 189, 88, 42, BLACK);
		DrawTextEx(bold, "Session", { 1428, 198 }, 25,0, DARKBLUE);

		DrawRectangle(0, 231, 1512, 751, WHITE);

		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25,0, DARKBLUE);


		if (CheckCollisionPointRec(mousePoint, schoolyears)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				action1 = true;
				for (int i = 0; i < cntYears; ++i) {
					actionYear[i] = 0;
				}
			}
		}
		if (action1) {
			for (int i = 0; i < cntYears; ++i) {
				DrawRectangle(360, 150 + r, 200, 50, DARKBLUE);
				DrawText(YearName[i], 410, 165 + r, 20, WHITE);
				r += 50;
			}
		}

		for (int k = 0; k < cntYears; ++k) {
			if (CheckCollisionPointRec(mousePoint, { 420, (float)(150 + 50 * k),200,50 }) && action1) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					actionYear[k] = true;
				}
			}
			if (actionYear[k]) {
				DrawRectangleRec(schoolyears, DARKBLUE);
				DrawTextEx(bold, YearName[k], { 408, 113 }, 25,0, WHITE);
				action1 = false;
				yearnametmp = _strdup(YearName[k]);
			}
		}

		if (CheckCollisionPointRec(mousePoint, semesters)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				action = true;
				actionA = false;
				actionF = false;
				actionS = false;
			}
		}
		if (action) {
			for (int i = 0; i < n; ++i) {
				DrawRectangle(60, 150 + z, 200, 50, DARKBLUE);
				if (i == 0) DrawText("Fall", 130, 165 + z, 20, WHITE);
				else if (i == 1) DrawText("Summer", 130, 165 + z, 20, WHITE);
				else if (i == 2) DrawText("Autumn", 130, 165 + z, 20, WHITE);
				z += 50;
			}
		}

		if (CheckCollisionPointRec(mousePoint, { 60,150,200, 50 }) && action) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionF = true;
		}
		if (actionF) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Fall", { 120, 113 }, 25, 0, WHITE);
			action = false;
			semesternametmp = (char*)"Fall";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,200,200, 50 }) && action && (n != 2 || n == 3)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionS = true;
		}
		if (actionS) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Summer", { 120, 113 }, 25,0, WHITE);
			action = false;
			semesternametmp = (char*)"Summer";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,250,200, 50 }) && action && n == 3) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionA = true;
		}
		if (actionA) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Autumn", { 120, 113 }, 25, 0, WHITE);
			action = false;
			semesternametmp = (char*)"Autumn";
		}

		if (CheckCollisionPointRec(mousePoint, ok)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				actionOK = true;
			}
		}

		if (actionOK && yearnametmp && semesternametmp) {
			if (checkSemesterAndSchoolYear(semesternametmp, yearnametmp)) {
				cntCourse = countCoursesOfAStudent(CurrentUser.userName, yearnametmp, semesternametmp);
				courses = viewCoursesOfAStudent(CurrentUser.userName, yearnametmp, semesternametmp);
			}
			else {
				cntCourse = 0;
				courses = nullptr;
			}
			actionOK = false;
		}

		if (cntCourse == 0) {
			DrawTextEx(bold,"NO DATA AVAILABLE !!!", {410, 450}, 70,0, RED);
		}

		for (int i = 0; i < cntCourse; ++i) {
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
			delete[] nofc;
			delete[] maxstu;
			j += 61;
		}
		backtopreviouspage.workbutton(mousePoint, CurrentUser);
		if (backtopreviouspage.action) {
			//free(yearnametmp);
			//free(semesternametmp);
			delete[] courses;
			for (int i = 0; i < cntYears; ++i) {
				delete[] YearName[i];
			}
			delete[] YearName;
			delete[] actionYear;
			EndDrawing();
			ProfilePageStudent(screenWidth, screenHeight, CurrentUser);
		}
		EndDrawing();
	}
	delete[] courses;
	for (int i = 0; i < cntYears; ++i) {
		delete[] YearName[i];
	}
	delete[] YearName;
	delete[] actionYear;
	//free (yearnametmp);
	//free (semesternametmp);
	 
	 
	CloseWindow();
}
void ScoreboardStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Vector2 mousePoint = { 0.0f, 0.0f };
	int cntCourse = 0;
	course* courses = nullptr;
	scoreboard* ScoreBoard = nullptr;

	int cntYears = 0;
	char** YearName = nullptr;
	getStudyingSchoolYear(CurrentUser.userName, cntYears, YearName);

	int n = 3;    //count semester
	Rectangle ok = { 660,100,80,50 };
	Rectangle semesters = { 60,100,200,50 };
	Rectangle schoolyears = { 360,100,200,50 };
	bool action = false;
	bool actionF = false;
	bool actionS = false;
	bool actionA = false;
	bool action1 = false;
	bool* actionYear = new bool[cntYears] {0};
	bool actionOK = false;
	bool GPA = false;

	double overallGPAd = getOverallGPA(CurrentUser.userName);
	char* yearnametmp = nullptr;
	char* semesternametmp = nullptr;

	char* semesterGPA = new char[5];
	char* overallGPA = new char[5];

	Button2 backtopreviouspage;
	backtopreviouspage.button = { 1200, 20, 300, 30 };

	int scrollspeed = 35;
	int x_course = 42;
	int y_course = 276;
	while (!WindowShouldClose()) {
		mousePoint = GetMousePosition();
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawTextEx(bold, "COURSE MANAGEMENT SYSTEM", { 430, 10 }, 40, 1, DARKBLUE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawTextEx(bold, "Years", { 430 , 113 }, 25, 0, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawTextEx(bold, "Semesters", { 103, 113 }, 25, 0, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawTextEx(bold, "OK", { 687, 113 }, 25, 0, WHITE);
		int z = 0, r = 0, j = 0;

		DrawRectangleLines(0, 189, 1512, 0, BLACK);
		DrawRectangle(846, 101, 252, 55, WHITE);
		DrawTextEx(bold, "Semester GPA:", { 855, 114 }, 25,0, DARKBLUE);
		DrawRectangle(1195, 101, 220, 55, WHITE);
		DrawTextEx(bold, "Overall GPA:", { 1201, 114}, 25,0, DARKBLUE);

		DrawRectangle(0, 189, 231, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 231, 65, BLACK);
		DrawTextEx(bold, "Course ID", { 56, 210 }, 27,0, DARKBLUE);

		DrawRectangle(231, 189, 646, 65, LIGHTGRAY);
		DrawRectangleLines(231, 189, 646, 65, BLACK);
		DrawTextEx(bold, "Course Name", { 497, 210 }, 27,0, DARKBLUE);

		DrawRectangle(877, 189, 124, 65, LIGHTGRAY);
		DrawRectangleLines(877, 189, 124, 65, BLACK);
		DrawTextEx(bold, "Credits", { 899, 210 }, 27,0, DARKBLUE);

		DrawRectangle(1001, 189, 169, 65, LIGHTGRAY);
		DrawRectangleLines(1001, 189, 169, 65, BLACK);
		DrawTextEx(bold, "Class", { 1055, 210 }, 27,0, DARKBLUE);

		DrawRectangle(1170, 189, 231, 65, LIGHTGRAY);
		DrawRectangleLines(1170, 189, 231, 65, BLACK);
		DrawTextEx(bold, "Total", { 1183, 210 }, 27,0, DARKBLUE);

		DrawRectangle(1256, 189, 85, 65, LIGHTGRAY);
		DrawRectangleLines(1256, 189, 85, 65, BLACK);
		DrawTextEx(bold, "F", { 1290, 210 }, 27,0, DARKBLUE);

		DrawRectangle(1341, 189, 85, 65, LIGHTGRAY);
		DrawRectangleLines(1341, 189, 85, 65, BLACK);
		DrawTextEx(bold, "M", { 1375, 210 }, 27,0, DARKBLUE);

		DrawRectangle(1426, 189, 86, 65, LIGHTGRAY);
		DrawRectangleLines(1426, 189, 86, 65, BLACK);
		DrawTextEx(bold, "O", { 1460, 210 }, 27,0, DARKBLUE);

		DrawRectangle(0, 255, 1512, 751, WHITE);

		double_to_char(overallGPAd, overallGPA);
		DrawTextEx(medium, overallGPA, { 1357, 113 }, 27,0, DARKBLUE);



		if (CheckCollisionPointRec(mousePoint, schoolyears)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				action1 = true;
				for (int i = 0; i < cntYears; ++i) {
					actionYear[i] = 0;
				}
			}
		}
		if (action1) {
			for (int i = 0; i < cntYears; ++i) {
				DrawRectangle(360, 150 + r, 200, 50, DARKBLUE);
				DrawText(YearName[i], 410, 165 + r, 20, WHITE);
				r += 50;
			}
		}

		for (int k = 0; k < cntYears; ++k) {
			if (CheckCollisionPointRec(mousePoint, { 420, (float)(150 + 50 * k),200,50 }) && action1) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					actionYear[k] = true;
				}
			}
			if (actionYear[k]) {
				DrawRectangleRec(schoolyears, DARKBLUE);
				DrawTextEx(bold, YearName[k], { 407, 113 }, 25,0, WHITE);
				action1 = false;
				yearnametmp = _strdup(YearName[k]);
			}
		}

		if (CheckCollisionPointRec(mousePoint, semesters)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				action = true;
				actionA = false;
				actionF = false;
				actionS = false;
			}
		}
		if (action) {
			for (int i = 0; i < n; ++i) {
				DrawRectangle(60, 150 + z, 200, 50, DARKBLUE);
				if (i == 0) DrawText("Fall", 130, 165 + z, 20, WHITE);
				else if (i == 1) DrawText("Summer", 130, 165 + z, 20, WHITE);
				else if (i == 2) DrawText("Autumn", 130, 165 + z, 20, WHITE);
				z += 50;
			}
		}

		if (CheckCollisionPointRec(mousePoint, { 60,150,200, 50 }) && action) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionF = true;
		}
		if (actionF) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Fall", { 120, 113 }, 25, 0, WHITE);
			action = false;
			semesternametmp = (char*)"Fall";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,200,200, 50 }) && action && (n != 2 || n == 3)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionS = true;
		}
		if (actionS) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Summer", { 120, 113 }, 25, 0, WHITE);
			action = false;
			semesternametmp = (char*)"Summer";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,250,200, 50 }) && action && n == 3) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionA = true;
		}
		if (actionA) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawTextEx(bold, "Autumn", { 120, 113 }, 25, 0, WHITE);
			action = false;
			semesternametmp = (char*)"Autumn";
		}

		if (CheckCollisionPointRec(mousePoint, ok)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				actionOK = true;
			}
		}
		if (actionOK && yearnametmp && semesternametmp) {
			if (checkSemesterAndSchoolYear(semesternametmp, yearnametmp)) {
				cntCourse = countCoursesOfAStudent(CurrentUser.userName, yearnametmp, semesternametmp);
				courses = viewCoursesOfAStudent(CurrentUser.userName, yearnametmp, semesternametmp);
				ScoreBoard = GetsaveScore(CurrentUser.userName, yearnametmp, semesternametmp);
				double_to_char(getSemesterGPA(CurrentUser.userName, yearnametmp, semesternametmp), semesterGPA);
				GPA = true;
			}
			else {
				cntCourse = 0;
				courses = nullptr;
				ScoreBoard = nullptr;
				GPA = false;
			}
			actionOK = false;
		}

		if (GPA) {
			DrawTextEx(medium, semesterGPA, { 1040, 113 }, 27,0, DARKBLUE);
		}

		if (cntCourse == 0) {
			DrawTextEx(bold, "NO DATA AVAILABLE !!!", { 410, 450 }, 70, 0, RED);
		}

		for (int i = 0; i < cntCourse; ++i) {
			DrawLine(x_course + 190, y_course + j - 24, x_course + 190, y_course + j + 38, BLACK);
			DrawLine(x_course + 836, y_course + j - 24, x_course + 836, y_course + j + 38, BLACK);
			DrawLine(x_course + 960, y_course + j - 24, x_course + 960, y_course + j + 38, BLACK);
			DrawLine(x_course + 1129, y_course + j - 24, x_course + 1129, y_course + j + 38, BLACK);
			DrawLine(x_course + 1215, y_course + j - 24, x_course + 1215, y_course + j + 38, BLACK);
			DrawLine(x_course + 1300, y_course + j - 24, x_course + 1300, y_course + j + 38, BLACK);
			DrawLine(x_course + 1385, y_course + j - 24, x_course + 1385, y_course + j + 38, BLACK);
			DrawLine(x_course + 1471, y_course + j - 24, x_course + 1471, y_course + j + 38, BLACK);
			DrawLine(x_course + 189, y_course + j - 24, x_course + 189, y_course + j + 38, BLACK);
			DrawLine(x_course + 835, y_course + j - 24, x_course + 835, y_course + j + 38, BLACK);
			DrawLine(x_course + 959, y_course + j - 24, x_course + 959, y_course + j + 38, BLACK);
			DrawLine(x_course + 1128, y_course + j - 24, x_course + 1128, y_course + j + 38, BLACK);
			DrawLine(x_course + 1214, y_course + j - 24, x_course + 1214, y_course + j + 38, BLACK);
			DrawLine(x_course + 1299, y_course + j - 24, x_course + 1299, y_course + j + 38, BLACK);
			DrawLine(x_course + 1384, y_course + j - 24, x_course + 1384, y_course + j + 38, BLACK);
			DrawLine(x_course + 1470, y_course + j - 24, x_course + 1470, y_course + j + 38, BLACK);

			DrawRectangleLines(0, y_course + j - 24, 1512, 62, BLACK);
			DrawRectangleLines(0, y_course + j - 24, 1512, 62, BLACK);
			DrawText(courses[i].courseID, x_course, y_course + j, 20, BLACK);
			DrawText(courses[i].courseName, x_course + 241, y_course + j, 20, BLACK);
			char* nofc = new char[10];
			int_to_char(courses[i].numOfCre, nofc);
			DrawText(nofc, x_course + 880, y_course + j, 20, BLACK);
			DrawText(courses[i].className, x_course + 992, y_course + j, 20, BLACK);
			char* tmp1 = new char[10];
			double_to_char(ScoreBoard[i].totalMark, tmp1);
			DrawText(tmp1, x_course + 1150, y_course + j, 20, BLACK);
			char* tmp2 = new char[10];
			double_to_char(ScoreBoard[i].finalMark, tmp2);
			DrawText(tmp2, x_course + 1239, y_course + j, 20, BLACK);
			char* tmp3 = new char[10];
			double_to_char(ScoreBoard[i].midtermMark, tmp3);
			DrawText(tmp3, x_course + 1324, y_course + j, 20, BLACK);
			char* tmp4 = new char[10];
			double_to_char(ScoreBoard[i].otherMark, tmp4);
			DrawText(tmp4, x_course + 1406, y_course + j, 20, BLACK);

			j += 61;
			delete[] nofc;
			delete[] tmp1;
			delete[] tmp2;
			delete[] tmp3;
			delete[] tmp4;
		}

		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25,0, DARKBLUE);
		backtopreviouspage.workbutton(mousePoint, CurrentUser, ProfilePageStudent);
		EndDrawing();
	}
	 
	
	CloseWindow();
}
void ProfilePageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	////Initialize variable---------------------------------------------------------------------------------------------
	Texture2D avatar;
	avatar = LoadTexture("avatar.png");

	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Button1 ChangePass;
	ChangePass.texture = LoadTexture("changePassBtn.png");
	ChangePass.frameHeight = (float)ChangePass.texture.height;
	ChangePass.sourceRec = { 0, 0, (float)ChangePass.texture.width, ChangePass.frameHeight };
	ChangePass.btnBounds = { 170, 500, (float)ChangePass.texture.width, ChangePass.frameHeight };

	Button1 LogOut;
	LogOut.texture = LoadTexture("logOutBtn.png");
	LogOut.frameHeight = (float)LogOut.texture.height;
	LogOut.sourceRec = { 0, 0, (float)LogOut.texture.width,LogOut.frameHeight };
	LogOut.btnBounds = { 170, 430, (float)LogOut.texture.width,LogOut.frameHeight };


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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawTextEx(bold, "WELCOME!", { 670, 15 }, 40, 0, DARKBLUE);

		DrawRectangle(70, 170, 360, 450, WHITE);
		DrawRectangleLines(69, 169, 362, 452, BLACK);
		DrawRectangleLines(68, 168, 364, 454, BLACK);

		DrawRectangle(480, 170, 980, 750, WHITE);
		DrawRectangleLines(479, 169, 982, 752, BLACK);
		DrawRectangleLines(478, 168, 984, 754, BLACK);

		DrawRectangle(480, 108, 250, 60, WHITE);
		DrawRectangleLines(479, 107, 252, 62, BLACK);
		DrawRectangleLines(478, 106, 254, 64, BLACK);
		DrawTextEx(bold, "STAFF", { 555, 118 }, 40, 0, DARKBLUE);

		DrawTexture(avatar, 150, 107, WHITE);
		DrawTextEx(medium, "Username: ", { 118, 337 }, 30, 0, DARKBLUE);
		DrawTextEx(medium, CurrentUser.userName, { 268, 337 }, 30, 0, DARKGRAY);

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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

	Button0 viewPass1;
	viewPass1.texture = LoadTexture("showpass.png");
	viewPass1.frameHeight = (float)viewPass1.texture.height;
	viewPass1.sourceRec = { 0, 0, (float)viewPass1.texture.width, viewPass1.frameHeight };
	viewPass1.btnBounds = { 965, 200, (float)viewPass1.texture.width, viewPass1.frameHeight };

	Button0 viewPass2;
	viewPass2.texture = LoadTexture("showpass.png");
	viewPass2.frameHeight = (float)viewPass2.texture.height;
	viewPass2.sourceRec = { 0, 0, (float)viewPass2.texture.width, viewPass2.frameHeight };
	viewPass2.btnBounds = { 965, 362, (float)viewPass2.texture.width, viewPass2.frameHeight };

	Button0 viewPass3;
	viewPass3.texture = LoadTexture("showpass.png");
	viewPass3.frameHeight = (float)viewPass3.texture.height;
	viewPass3.sourceRec = { 0, 0, (float)viewPass3.texture.width, viewPass3.frameHeight };
	viewPass3.btnBounds = { 965, 526, (float)viewPass3.texture.width, viewPass3.frameHeight };

	Button0 hidePass1;
	hidePass1.texture = LoadTexture("hidepass.png");
	hidePass1.frameHeight = (float)hidePass1.texture.height;
	hidePass1.sourceRec = { 0, 0, (float)hidePass1.texture.width, hidePass1.frameHeight };
	hidePass1.btnBounds = { 965, 196, (float)hidePass1.texture.width, hidePass1.frameHeight };

	Button0 hidePass2;
	hidePass2.texture = LoadTexture("hidepass.png");
	hidePass2.frameHeight = (float)hidePass2.texture.height;
	hidePass2.sourceRec = { 0, 0, (float)hidePass2.texture.width, hidePass2.frameHeight };
	hidePass2.btnBounds = { 965, 358, (float)hidePass2.texture.width, hidePass2.frameHeight };

	Button0 hidePass3;
	hidePass3.texture = LoadTexture("hidepass.png");
	hidePass3.frameHeight = (float)hidePass3.texture.height;
	hidePass3.sourceRec = { 0, 0, (float)hidePass3.texture.width, hidePass3.frameHeight };
	hidePass3.btnBounds = { 965, 522, (float)hidePass3.texture.width, hidePass3.frameHeight };

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
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 }, 25, 0, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25, 0, DARKBLUE);

		DrawRectangle(347, 173, 818, 630, WHITE);
		DrawRectangleRec(oldpass.textbox, LIGHTGRAY);
		DrawRectangleRec(newpass.textbox, LIGHTGRAY);
		DrawRectangleRec(confirmnewpass.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Old Password", { 477, 195 }, 35,0, DARKBLUE);
		DrawTextEx(medium, "* New Password", { 477, 356 }, 35,0, DARKBLUE);
		DrawTextEx(medium, "* Confirm New Password", { 477, 523 }, 35,0, DARKBLUE);

		////Textbox function-----------------------------------------------------------------------------------------------------------------------------------------
		oldpass.worktextbox(isChangePassFalseDisplay);
		newpass.worktextbox(isChangePassFalseDisplay);
		confirmnewpass.worktextbox(isChangePassFalseDisplay);
		viewPass1.workbutton(mousePoint);
		viewPass2.workbutton(mousePoint);
		viewPass3.workbutton(mousePoint);

		if (viewPass1.hidden) {
			DrawTextEx(medium, oldpass.hiddentext, { 500, 270 }, 40,0, DARKBLUE);
		}
		if (!viewPass1.hidden) {
			DrawTextEx(medium, oldpass.text, { 500, 270 }, 40,0, DARKBLUE);
			DrawTextureRec(hidePass1.texture, hidePass1.sourceRec, { hidePass1.btnBounds.x,hidePass1.btnBounds.y }, WHITE);
		}
		if (viewPass2.hidden) {
			DrawTextEx(medium, newpass.hiddentext, { 500, 434 }, 40,0, DARKBLUE);
		}
		if (!viewPass2.hidden) {
			DrawTextEx(medium, newpass.text, { 500, 434 }, 40,0, DARKBLUE);
			DrawTextureRec(hidePass2.texture, hidePass2.sourceRec, { hidePass2.btnBounds.x,hidePass2.btnBounds.y }, WHITE);
		}
		if (viewPass3.hidden) {
			DrawTextEx(medium, confirmnewpass.hiddentext, { 500, 598 }, 40,0, DARKBLUE);
		}
		if (!viewPass3.hidden) {
			DrawTextEx(medium, confirmnewpass.text, { 500, 598 }, 40,0, DARKBLUE);
			DrawTextureRec(hidePass3.texture, hidePass3.sourceRec, { hidePass3.btnBounds.x,hidePass3.btnBounds.y }, WHITE);
		}

		/*DrawText(TextFormat("%i/%i", oldpass.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", newpass.lettercount, MAX_INPUT_CHARS), 1050, 444, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmnewpass.lettercount, MAX_INPUT_CHARS), 1050, 608, 20, DARKBLUE);*/
		////-------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		////Button function----------------------------------------------------------------------------------------------------------
		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
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
		if (isChangePassFalseDisplay) DrawTextEx(bold, "Please try again!", { 477, 685 }, 20,0, RED);

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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

	Button0 viewPass1;
	viewPass1.texture = LoadTexture("showpass.png");
	viewPass1.frameHeight = (float)viewPass1.texture.height;
	viewPass1.sourceRec = { 0, 0, (float)viewPass1.texture.width, viewPass1.frameHeight };
	viewPass1.btnBounds = { 965, 200, (float)viewPass1.texture.width, viewPass1.frameHeight };

	Button0 viewPass2;
	viewPass2.texture = LoadTexture("showpass.png");
	viewPass2.frameHeight = (float)viewPass2.texture.height;
	viewPass2.sourceRec = { 0, 0, (float)viewPass2.texture.width, viewPass2.frameHeight };
	viewPass2.btnBounds = { 965, 362, (float)viewPass2.texture.width, viewPass2.frameHeight };

	Button0 viewPass3;
	viewPass3.texture = LoadTexture("showpass.png");
	viewPass3.frameHeight = (float)viewPass3.texture.height;
	viewPass3.sourceRec = { 0, 0, (float)viewPass3.texture.width, viewPass3.frameHeight };
	viewPass3.btnBounds = { 965, 526, (float)viewPass3.texture.width, viewPass3.frameHeight };

	Button0 hidePass1;
	hidePass1.texture = LoadTexture("hidepass.png");
	hidePass1.frameHeight = (float)hidePass1.texture.height;
	hidePass1.sourceRec = { 0, 0, (float)hidePass1.texture.width, hidePass1.frameHeight };
	hidePass1.btnBounds = { 965, 196, (float)hidePass1.texture.width, hidePass1.frameHeight };

	Button0 hidePass2;
	hidePass2.texture = LoadTexture("hidepass.png");
	hidePass2.frameHeight = (float)hidePass2.texture.height;
	hidePass2.sourceRec = { 0, 0, (float)hidePass2.texture.width, hidePass2.frameHeight };
	hidePass2.btnBounds = { 965, 358, (float)hidePass2.texture.width, hidePass2.frameHeight };

	Button0 hidePass3;
	hidePass3.texture = LoadTexture("hidepass.png");
	hidePass3.frameHeight = (float)hidePass3.texture.height;
	hidePass3.sourceRec = { 0, 0, (float)hidePass3.texture.width, hidePass3.frameHeight };
	hidePass3.btnBounds = { 965, 522, (float)hidePass3.texture.width, hidePass3.frameHeight };

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
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 }, 25, 0, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25, 0, DARKBLUE);

		DrawRectangle(347, 173, 818, 630, WHITE);
		DrawRectangleRec(oldpass.textbox, LIGHTGRAY);
		DrawRectangleRec(newpass.textbox, LIGHTGRAY);
		DrawRectangleRec(confirmnewpass.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Old Password", { 477, 195 }, 35, 0, DARKBLUE);
		DrawTextEx(medium, "* New Password", { 477, 356 }, 35, 0, DARKBLUE);
		DrawTextEx(medium, "* Confirm New Password", { 477, 523 }, 35, 0, DARKBLUE);

		////Textbox function-----------------------------------------------------------------------------------------------------------------------------------------
		oldpass.worktextbox(isChangePassFalseDisplay);
		newpass.worktextbox(isChangePassFalseDisplay);
		confirmnewpass.worktextbox(isChangePassFalseDisplay);
		viewPass1.workbutton(mousePoint);
		viewPass2.workbutton(mousePoint);
		viewPass3.workbutton(mousePoint);

		if (viewPass1.hidden) {
			DrawTextEx(medium, oldpass.hiddentext, { 500, 270 }, 40, 0, DARKBLUE);
		}
		if (!viewPass1.hidden) {
			DrawTextEx(medium, oldpass.text, { 500, 270 }, 40, 0, DARKBLUE);
			DrawTextureRec(hidePass1.texture, hidePass1.sourceRec, { hidePass1.btnBounds.x,hidePass1.btnBounds.y }, WHITE);
		}
		if (viewPass2.hidden) {
			DrawTextEx(medium, newpass.hiddentext, { 500, 434 }, 40, 0, DARKBLUE);
		}
		if (!viewPass2.hidden) {
			DrawTextEx(medium, newpass.text, { 500, 434 }, 40, 0, DARKBLUE);
			DrawTextureRec(hidePass2.texture, hidePass2.sourceRec, { hidePass2.btnBounds.x,hidePass2.btnBounds.y }, WHITE);
		}
		if (viewPass3.hidden) {
			DrawTextEx(medium, confirmnewpass.hiddentext, { 500, 598 }, 40, 0, DARKBLUE);
		}
		if (!viewPass3.hidden) {
			DrawTextEx(medium, confirmnewpass.text, { 500, 598 }, 40, 0, DARKBLUE);
			DrawTextureRec(hidePass3.texture, hidePass3.sourceRec, { hidePass3.btnBounds.x,hidePass3.btnBounds.y }, WHITE);
		}

		/*DrawText(TextFormat("%i/%i", oldpass.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", newpass.lettercount, MAX_INPUT_CHARS), 1050, 444, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmnewpass.lettercount, MAX_INPUT_CHARS), 1050, 608, 20, DARKBLUE);*/
		////-------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		////Button function----------------------------------------------------------------------------------------------------------
		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
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
		if (isChangePassFalseDisplay) DrawTextEx(bold, "Please try again!", { 477, 685 }, 20, 0, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoprofilepage.workbutton(mousePoint, CurrentUser, ProfilePageStaff);
		EndDrawing();
	}
	 
	
	CloseWindow();
}

void CreateSchoolYearPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 }, 25, 0, DARKBLUE);

		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25, 0, DARKBLUE);

		DrawRectangle(347, 173, 818, 373, WHITE);
		DrawRectangleRec(schoolyear.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* School Year (YYYY-YYYY)", { 473, 186 }, 33,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		schoolyear.worktextbox(confirmBtnFalseDisplay);

		DrawTextEx(medium, schoolyear.text, { 500, 270 }, 40,0, DARKBLUE);
		//DrawText(TextFormat("%i/%i", schoolyear.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (createASchoolYear(schoolyear.text)) {
				confirmBtnFalseDisplay = false;
				EndDrawing();
				ViewSchoolYearsPage(screenWidth, screenHeight, CurrentUser);
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Invalid data or this year already existed. Try again!", { 495, 359 }, 25,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	int n = countSchoolYear();
	char** Years = getSchoolYearArr();
	Vector2 mousePoint = { 0.0f, 0.0f };

	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
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
		if (y_schoolyear + (n * 3) * n < 167) {
			y_schoolyear = 167 - (n * 3) * n;
		}
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		//DrawRectangleLines(321, 135, 872, 807, BLACK);
		mousePoint = GetMousePosition();
		Button4* schoolyear = new Button4[n];
		int j = 0;
		for (int i = 0; i < n; ++i) {
			schoolyear[i].button = { float(x_schoolyear - 122), float(y_schoolyear + j - 12), 421, 59 };
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
		DrawTextEx(bold, "SCHOOL YEARS", { 625, 13 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to Profile Page", { 1280, 20 }, 25,0, DARKBLUE);
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

void createClassPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawTextEx(medium, "  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", { 5, 20 }, 25, 0, DARKBLUE);

		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to the previous page", { 1200, 20 }, 25, 0, DARKBLUE);

		DrawRectangle(347, 173, 818, 350, WHITE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Class Name", { 474, 197 }, 33,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		classname.worktextbox(confirmBtnFalseDisplay);

		DrawTextEx(medium, classname.text, { 500, 270 }, 40,0, DARKBLUE);
		//DrawText(TextFormat("%i/%i", classname.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
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
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "This class was created before!", { 500, 360 }, 25,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
		DrawTextEx(bold, "CLASSES", { 670, 15 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoprofilepage.button, WHITE);
		DrawTextEx(bold, "Back to Profile Page", { 1280, 20 }, 25,0, DARKBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		//DrawRectangleLines(321, 135, 872, 807, BLACK);
		mousePoint = GetMousePosition();
		Button4* Class = new Button4[n];

		int j = 0;
		for (int i = 0; i < n; ++i) {
			Class[i].button = { float(x_classes - 122), float(y_classes + j - 12), 421, 59 };
			DrawRectangleRec(Class[i].button, LIGHTGRAY);
			DrawText(Classes[i].classID, x_classes + 40, y_classes + j, 32, DARKBLUE);
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
	delete[] Classes;
	 
	
	CloseWindow();

}
void ClassPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Classname) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	int n = countStudentInClass(Classname);
	student* listStudents = viewStudentsInClass(Classname);
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };
	Texture2D background2 = LoadTexture("course_background.png");
	Vector2 mousePoint = { 0.0f, 0.0f };

	int* cntCourse = nullptr;
	course** SemesterCourses_Class = nullptr;
	scoreboard** SemesterScore_Class = nullptr;
	double* semesterGPA = nullptr;
	double* overallGPA = nullptr;

	int cntYears = 0;
	char** YearName = nullptr;
	getStudyingSchoolYear(Classname, cntYears, YearName);

	Button2 backtopreviouspage;
	backtopreviouspage.button = { 1200, 20, 300, 30 };

	int n1 = 3;    //count semester
	Rectangle ok = { 660,100,80,50 };
	Rectangle semesters = { 60,100,200,50 };
	Rectangle schoolyears = { 360,100,200,50 };
	bool action0 = false;
	bool actionF = false;
	bool actionS = false;
	bool actionA = false;
	bool action1 = false;
	bool* actionYear = new bool[cntYears] {0};
	bool actionOK = false;

	bool state0 = true;
	bool state1 = true;
	bool stateOK = true;
	bool scroll = true;

	char* yearnametmp = nullptr;
	char* semesternametmp = nullptr;

	Button2 backtoViewClasspage;
	backtoViewClasspage.button = { 1190, 20, 250, 30 };

	Button4 AddStuCSV;
	AddStuCSV.button = { 766, 100,293,50 };

	Button4 AddAStu;
	AddAStu.button = { 1137, 100,313,50 };

	Rectangle turnOffScore = { 1400, 180, 91, 76 };
	Button10* studentbutton = new Button10[n];

	int scrollspeed = 35;
	int x_student = 11;
	int y_student = 255;

	int x_course = 11;
	int y_course = 255;
	while (!WindowShouldClose()) {
		if (scroll) y_student += (int(GetMouseWheelMove()) * scrollspeed);
		if (x_student > 11) x_student = 11;
		if (y_student > 255) y_student = 255;
		ClearBackground(WHITE);
		BeginDrawing();

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 231, screenWidth, 751, WHITE);
		DrawRectangleLines(0, 231, screenWidth, 751, BLACK);

		if (actionOK && yearnametmp && semesternametmp){
			if (checkSemesterAndSchoolYear(semesternametmp, yearnametmp)) {
				cntCourse = GetNumOfCoursesPerStudent(Classname, yearnametmp, semesternametmp);
				SemesterCourses_Class = GetSemesterCourses_Class(Classname, yearnametmp, semesternametmp);
				SemesterScore_Class = GetSemesterScore_Class(Classname, yearnametmp, semesternametmp);
				semesterGPA = GetSemesterGPA_Class(Classname, yearnametmp, semesternametmp);
				overallGPA = GetOverallGPA_Class(Classname);
			}
			else {
				cntCourse = nullptr;
				SemesterCourses_Class = nullptr;
				SemesterScore_Class = nullptr;
				semesterGPA = nullptr;
				overallGPA = nullptr;
			}
			actionOK = false;
		}
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
			studentbutton[i].button = { 0, float(y_student + j), 1512, 62 };
			char* stuNo = new char[10];
			int_to_char(listStudents[i].No, stuNo);
			DrawText(stuNo, x_student + 13, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].stuID, x_student + 72, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.lastName, x_student + 260, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.firstName, x_student + 528, y_student + j + 30, 20, BLACK);

			if (listStudents[i].Student.gender) DrawText("Male", x_student + 912, y_student + j + 30, 20, BLACK);
			else DrawText("Female", x_student + 912, y_student + j + 30, 20, BLACK);

			DrawText(dateToChar(listStudents[i].Student.dob), x_student + 1097, y_student + j + 30, 20, BLACK);
			DrawText(listStudents[i].Student.socialID, x_student + 1300, y_student + j + 30, 20, BLACK);

			if (y_student + j < 231) studentbutton[i].state = false;
			else studentbutton[i].state = true;
			//if (SemesterCourses_Class && SemesterScore_Class && cntCourse) {
				studentbutton[i].workbutton(mousePoint);
			//}
			j += 61;
		}
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawTextEx(bold, Classname, { 670, 15 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoViewClasspage.button, WHITE);
		DrawTextEx(bold, "Back to Classes Page", { 1200, 20 }, 25,0, DARKBLUE);
		DrawTexture(background2, 0, 60, WHITE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawTextEx(bold, "Years", { 430, 113 }, 25,0, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawTextEx(bold,"Semesters", { 105, 113 }, 25, 0, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawTextEx(bold, "OK", { 685, 113 }, 25,0, WHITE);
		int z = 0, r = 0;//, j1 = 0;

		DrawRectangleRec(AddStuCSV.button, WHITE);
		DrawTextEx(bold, "Add Student with CSV", { 786, 113 }, 25,0, DARKBLUE);
		DrawRectangleRec(AddAStu.button, WHITE);
		DrawTextEx(bold, "Add a Student manually", { 1157, 113 }, 25,0, DARKBLUE);

		DrawRectangleLines(0, 189, 1512, 0,BLACK);
		DrawRectangle(0, 189, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 58, 65, BLACK);
		DrawTextEx(bold, "No", { 8, 205 }, 24,0, DARKBLUE);

		DrawRectangle(58, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 189, 173, 65, BLACK);
		DrawTextEx(bold, "Student ID", { 84, 205 }, 24,0, DARKBLUE);

		DrawRectangle(227, 189, 179, 65, LIGHTGRAY);
		DrawRectangleLines(225, 189, 181, 65, BLACK);
		DrawTextEx(bold, "Last name", { 256, 205 }, 24,0, DARKBLUE);

		DrawRectangle(406, 189, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 189, 456, 65, BLACK);
		DrawTextEx(bold, "First name", { 569, 205 }, 24,0, DARKBLUE);

		DrawRectangle(862, 189, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 189, 188, 65, BLACK);
		DrawTextEx(bold, "Gender", { 910, 205 }, 24,0, DARKBLUE);

		DrawRectangle(1050, 189, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 189, 242, 65, BLACK);
		DrawTextEx(bold, "Date of Birth", { 1095, 205 }, 24,0, DARKBLUE);

		DrawRectangle(1292, 189, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 189, 220, 65, BLACK);
		DrawTextEx(bold, "Social ID", { 1345, 205 }, 24,0, DARKBLUE);

		if (CheckCollisionPointRec(mousePoint, schoolyears)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && state1) {
				action1 = true;
				for (int i = 0; i < cntYears; ++i) {
					actionYear[i] = 0;
				}
			}
		}
		if (action1) {
			for (int i = 0; i < cntYears; ++i) {
				DrawRectangle(360, 150 + r, 200, 50, DARKBLUE);
				DrawText(YearName[i], 410, 165 + r, 20, WHITE);
				r += 50;
			}
		}

		for (int k = 0; k < cntYears; ++k) {
			if (CheckCollisionPointRec(mousePoint, { 420, (float)(150 + 50 * k),200,50 }) && action1) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					actionYear[k] = true;
				}
			}
			if (actionYear[k]) {
				DrawRectangleRec(schoolyears, DARKBLUE);
				DrawText(YearName[k], 410, 115, 20, WHITE);
				action1 = false;
				yearnametmp = _strdup(YearName[k]);
			}
		}

		if (CheckCollisionPointRec(mousePoint, semesters)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && state0) {
				action0 = true;
				actionA = false;
				actionF = false;
				actionS = false;
			}
		}
		if (action0) {
			for (int i = 0; i < n1; ++i) {
				DrawRectangle(60, 150 + z, 200, 50, DARKBLUE);
				if (i == 0) DrawText("Fall", 130, 165 + z, 20, WHITE);
				else if (i == 1) DrawText("Summer", 130, 165 + z, 20, WHITE);
				else if (i == 2) DrawText("Autumn", 130, 165 + z, 20, WHITE);
				z += 50;
			}
		}

		if (CheckCollisionPointRec(mousePoint, { 60,150,200, 50 }) && action0) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionF = true;
		}
		if (actionF) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Fall", 130, 115, 20, WHITE);
			action0 = false;
			semesternametmp = (char*)"Fall";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,200,200, 50 }) && action0 && (n1 != 2 || n1 == 3)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionS = true;
		}
		if (actionS) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Summer", 130, 115, 20, WHITE);
			action0 = false;
			semesternametmp = (char*)"Summer";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,250,200, 50 }) && action0 && n1 == 3) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				actionA = true;
				for (int i = 0; i < n; ++i) {
					studentbutton[i].action = false;
				}
			}
		}
		if (actionA) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Autumn", 130, 115, 20, WHITE);
			action0 = false;
			semesternametmp = (char*)"Autumn";
		}

		if (CheckCollisionPointRec(mousePoint, ok)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				actionOK = true;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (studentbutton[i].action) {
				for (int i2 = 0; i2 < n; ++i2) {
					studentbutton[i2].state1 = false;
				}
				AddStuCSV.state = false;
				AddAStu.state = false;
				state0 = false;
				state1 = false;
				stateOK = false;
				scroll = false;

				DrawRectangleGradientV(24, 160, 1462, 878, DARKBLUE, BLUE);
				DrawRectangleLines(23, 159, 1464, 880, BLACK);
				DrawRectangleLines(23 - 1, 159 - 1, 1464 + 2, 880 + 2, BLACK);
				DrawRectangleLines(23 - 2, 159 - 2, 1464 + 4, 880 + 4, BLACK);
				DrawRectangleLines(23 - 3, 159 - 3, 1464 + 6, 880 + 6, BLACK);
				DrawRectangle(24, 402, 1462, 580, WHITE);

				DrawTextEx(bold, "BACK", { 1400, 180 }, 30,0, WHITE);
				DrawTextEx(bold, "Last name:", { 34, 209 }, 24,0, WHITE);
				DrawTextEx(medium, listStudents[i].Student.lastName, { 175, 209 }, 27,0, WHITE);
				DrawTextEx(bold, "First name:", { 34, 249 }, 24,0, WHITE);
				DrawTextEx(medium, listStudents[i].Student.firstName, { 175, 249 }, 27,0, WHITE);
				DrawTextEx(bold, "Student ID:", { 34, 289 }, 24,0, WHITE);
				DrawTextEx(medium, listStudents[i].stuID, { 175, 289 }, 27,0, WHITE);
				// Calculate button frame rectangle to draw depending on button state

				DrawRectangle(836, 263, 252, 55, WHITE);
				DrawTextEx(bold, "Semester GPA:", { 847, 278 }, 24,0, DARKBLUE);
				char* semestergpa = new char[5];
				char* overallgpa = new char[5];
				if (semesterGPA) {
					double_to_char(semesterGPA[i], semestergpa);
					DrawTextEx(medium, semestergpa, { 1028, 273 }, 30,0, DARKBLUE);
				}
				DrawRectangle(1190, 263, 252, 55, WHITE);
				DrawTextEx(bold, "Overall GPA:", { 1201, 278 }, 24,0, DARKBLUE);
				if (overallGPA) {
					double_to_char(semesterGPA[i], overallgpa);
					DrawTextEx(medium, overallgpa, { 1363, 273 }, 30,0, DARKBLUE);
				}

				DrawRectangle(24, 360, 121, 42, LIGHTGRAY);
				DrawRectangleLines(24, 360, 121, 42, BLACK);
				DrawTextEx(bold, "Course ID", { 35, 372 }, 24,0, DARKBLUE);

				DrawRectangle(145, 360, 519, 42, LIGHTGRAY);
				DrawRectangleLines(145, 360, 519, 42, BLACK);
				DrawTextEx(bold, "Course name", { 339, 372 }, 24,0, DARKBLUE);

				DrawRectangle(664, 360, 198, 42, LIGHTGRAY);
				DrawRectangleLines(664, 360, 198, 42, BLACK);
				DrawTextEx(bold, "Class name", { 705, 372 }, 24,0, DARKBLUE);

				DrawRectangle(862, 360, 180, 42, LIGHTGRAY);
				DrawRectangleLines(862, 360, 180, 42, BLACK);
				DrawTextEx(bold, "Credits", { 914, 372 }, 24,0, DARKBLUE);

				DrawRectangle(1042, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1042, 360, 148, 42, BLACK);
				DrawTextEx(bold, "Total Mark", { 1060, 372 }, 24,0, DARKBLUE);

				DrawRectangle(1190, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1190, 360, 148, 42, BLACK);
				DrawTextEx(bold, "Final Mark", { 1214, 372 }, 24,0, DARKBLUE);

				DrawRectangle(1338, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1338, 360, 148, 42, BLACK);
				DrawTextEx(bold, "Midterm Mark", { 1340, 372 }, 24,0, DARKBLUE);
				if (SemesterCourses_Class && SemesterScore_Class) {
					for (int i1 = 0; i1 < cntCourse[i]; ++i1) {
						DrawLine(x_course + 134, y_course + 147, x_course + 134, y_course + 209, BLACK);
						DrawLine(x_course + 653, y_course + 147, x_course + 653, y_course + 209, BLACK);
						DrawLine(x_course + 851, y_course + 147, x_course + 851, y_course + 209, BLACK);
						DrawLine(x_course + 1031, y_course + 147, x_course + 1031, y_course + 209, BLACK);
						DrawLine(x_course + 1179, y_course + 147, x_course + 1179, y_course + 209, BLACK);
						DrawLine(x_course + 1327, y_course + 147, x_course + 1327, y_course + 209, BLACK);
						DrawLine(x_course + 1475, y_course + 147, x_course + 1475, y_course + 209, BLACK);

						DrawRectangleLines(24, y_course + 147, 1464, 62, BLACK);
						DrawText(SemesterCourses_Class[i][i1].courseID, x_course + 23, y_course + 167, 20, BLACK);
						DrawText(SemesterCourses_Class[i][i1].courseName, x_course + 160, y_course + 167, 20, BLACK);
						DrawText(SemesterCourses_Class[i][i1].className, x_course + 709, y_course + 167, 20, BLACK);
						char* nofc = new char[10];
						int_to_char(SemesterCourses_Class[i][i1].numOfCre, nofc);
						DrawText(nofc, x_course + 930, y_course + 167, 20, BLACK);
						char* total = new char[10];
						double_to_char(SemesterScore_Class[i][i1].totalMark, total);
						DrawText(total, x_course + 1102, y_course + 167, 20, BLACK);
						char* Final = new char[10];
						double_to_char(SemesterScore_Class[i][i1].finalMark, Final);
						DrawText(Final, x_course + 1240, y_course + 167, 20, BLACK);
						char* Midterm = new char[10];
						double_to_char(SemesterScore_Class[i][i1].midtermMark, Midterm);
						DrawText(Midterm, x_course + 1384, y_course + 167, 20, BLACK);

						delete[] nofc;
						delete[] total;
						delete[] Final;
						delete[] Midterm;
					}
				}
				if ((!cntCourse || !SemesterCourses_Class || !SemesterScore_Class || !overallGPA || !semesterGPA) || (cntCourse && cntCourse[i] == 0)) {
					DrawTextEx(bold, "NO DATA AVAILABLE !!!", { 420, 470 }, 70,0, RED);
				}

				if (CheckCollisionPointRec(mousePoint, turnOffScore)) {
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
						studentbutton[i].action = false;
						for (int i2 = 0; i2 < n; ++i2) {
							studentbutton[i2].state1 = true;
						}
						AddStuCSV.state = true;
						AddAStu.state = true;
						state0 = true;
						state1 = true;
						stateOK = true;
						scroll = true;
					}
				}
				delete[] semestergpa;
				delete[] overallgpa;
			}
		}
		backtoViewClasspage.workbutton(mousePoint, CurrentUser, ViewClassesPage);
		AddStuCSV.workbutton(mousePoint, CurrentUser, Classname, addStudentCSV);
		AddAStu.workbutton(mousePoint, CurrentUser, Classname, addStudentPage);

		EndDrawing();
	}
	delete[] studentbutton;
	delete[] SemesterCourses_Class;
	delete[] SemesterScore_Class;
	//delete[] listStudents;
	 
	 
	CloseWindow();
}
void addStudentPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& classname) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawTextEx(bold, "Back to your class", { 1280, 20 }, 25,0, DARKBLUE);
		DrawTextEx(bold, "Add a student", { 620, 12 }, 40,0, DARKBLUE);

		DrawRectangle(142, 148, 1227, 720, WHITE);
		DrawRectangleRec(Lastname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Last name", { 284, 174 }, 35,0, DARKBLUE);
		DrawRectangleRec(Firstname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* First name", { 610, 174 }, 35,0, DARKBLUE);
		DrawRectangleRec(studentID.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Student ID", { 284, 312 }, 35,0, DARKBLUE);
		DrawRectangleRec(socialID.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Social ID", { 284, 450 }, 35,0, DARKBLUE);
		DrawRectangleRec(birth.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Date of birth", { 604, 588 }, 35,0, DARKBLUE);
		DrawRectangleRec(Gender.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Gender", { 284, 588 }, 35,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		Lastname.worktextbox(confirmBtnFalseDisplay);
		Firstname.worktextbox(confirmBtnFalseDisplay);
		studentID.worktextbox(confirmBtnFalseDisplay);
		socialID.worktextbox(confirmBtnFalseDisplay);
		birth.worktextbox(confirmBtnFalseDisplay);
		Gender.worktextbox(confirmBtnFalseDisplay);

		DrawTextEx(medium, Lastname.text, { 314, 233 }, 40,0, DARKBLUE);
		DrawTextEx(medium, Firstname.text, { 640, 233 }, 40,0, DARKBLUE);
		DrawTextEx(medium, studentID.text, { 314, 371 }, 40,0, DARKBLUE);
		DrawTextEx(medium, socialID.text, { 314, 509 }, 40,0, DARKBLUE);
		DrawTextEx(medium, birth.text, { 634, 647 }, 40,0, DARKBLUE);
		DrawTextEx(medium, Gender.text, { 314, 647 }, 40,0, DARKBLUE);

		////Function of buttons------------	------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (addAStudentToClass(classname, Firstname.text, Lastname.text, Gender.text, birth.text, socialID.text, studentID.text)) {
				confirmBtnFalseDisplay = false;
				ClassPage(screenWidth, screenHeight, CurrentUser, classname);
			}
			else confirmBtnFalseDisplay = true;

		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Invalid Data !", { 310, 720 }, 25,0, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoClasspage.workbutton(mousePoint, CurrentUser, classname, ClassPage);
		EndDrawing();
	}
	 
	 
	CloseWindow();
}

void addStudentCSV(const int screenWidth, const int screenHeight, account& CurrentUser, char*& classname) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawTextEx(bold, "Back to your class", { 1280, 20 }, 25,0, DARKBLUE);
		DrawTextEx(bold, "Add student(s)", { 620, 12 }, 40,0, DARKBLUE);

		DrawRectangle(347, 173, 818, 380, WHITE);
		DrawRectangleRec(filename.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* File name", { 420, 235 },35,0, DARKBLUE);

		filename.worktextbox(confirmBtnFalseDisplay);
		DrawTextEx(medium, filename.text, { 450, 300 }, 40,0, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (checkdata_FileName(filename.text)) {
				confirmBtnFalseDisplay = false;
				if (addStudentsWithCSV(filename.text, classname, dupstu, numDupStu)) {
					ClassPage(screenWidth, screenHeight, CurrentUser, classname);
				}
				else {
					dataExistedPage(screenWidth, screenHeight, CurrentUser, classname, numDupStu, dupstu);
				}
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "File name is invalid!!!", { 440, 380 }, 25,0, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtoClasspage.workbutton(mousePoint, CurrentUser, classname, ClassPage);

		EndDrawing();
	}
	CloseWindow();
}
void dataExistedPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& classname, int numDupStu, student* dupstu) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
		DrawTextEx(bold, "These students have already existed in class", { 10, 10 }, 40,0, RED);
		DrawText(classname, 970, 10, 40, RED);

		DrawRectangleRec(backtoClasspage.button, WHITE);
		DrawTextEx(bold, "Back to your class", { 1280, 20 }, 25, 0, DARKBLUE);

		DrawRectangle(0, 60, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 60, 58, 65, BLACK);
		DrawTextEx(bold, "No", { 8, 76 }, 24,0, DARKBLUE);

		DrawRectangle(58, 60, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 60, 173, 65, BLACK);
		DrawTextEx(bold, "Student ID", { 84, 76 }, 24,0, DARKBLUE);

		DrawRectangle(227, 60, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 60, 179, 65, BLACK);
		DrawTextEx(bold, "Last name", { 256, 76 }, 24,0, DARKBLUE);

		DrawRectangle(406, 60, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 60, 456, 65, BLACK);
		DrawTextEx(bold, "First name", { 569, 76 }, 24,0, DARKBLUE);

		DrawRectangle(862, 60, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 60, 188, 65, BLACK);
		DrawTextEx(bold, "Gender", { 910, 76 }, 24,0, DARKBLUE);

		DrawRectangle(1050, 60, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 60, 242, 65, BLACK);
		DrawTextEx(bold, "Date of Birth", { 1095, 76 }, 24,0, DARKBLUE);

		DrawRectangle(1292, 60, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 60, 220, 65, BLACK);
		DrawTextEx(bold, "Social ID", { 1345, 76 }, 24,0, DARKBLUE);

		backtoClasspage.workbutton(mousePoint, CurrentUser, classname, ClassPage);

		EndDrawing();
	}
	 
	 
	CloseWindow();
}
void CreateSemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	int n = countSemester(Year);
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);
		DrawTextEx(bold, Year, { 30, 15 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoviewsemesterpage.button, WHITE);
		DrawTextEx(bold, "Back to View Semester Page", { 1180, 20 }, 25,0, DARKBLUE);
		DrawRectangle(355, 173, 818, 600, WHITE);
		DrawRectangleRec(startdate.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Start date (dd/mm/YYYY): ", { 477, 250 }, 30,0, DARKBLUE);
		DrawRectangleRec(enddate.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* End date (dd/mm/YYYY): ", { 477, 423 }, 30,0, DARKBLUE);


		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		startdate.worktextbox(confirmBtnFalseDisplay);
		enddate.worktextbox(confirmBtnFalseDisplay);

		DrawTextEx(medium, startdate.text, { 500, 320 }, 40,0, DARKBLUE);

		DrawTextEx(medium, enddate.text, { 500, 493 }, 40,0, DARKBLUE);


		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (n < 3) {
				if (createASemester(Year, startdate.text, enddate.text)) {
					confirmBtnFalseDisplay = false;
					EndDrawing();
					ViewSemestersPage(screenWidth, screenHeight, CurrentUser, Year);
				}
				else confirmBtnFalseDisplay = false;
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Max semesters created or information must be written in right form!", { 430, 600 }, 25,0, RED);
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
void ViewSemestersPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
		DrawTextEx(bold, Year, { 30, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, "SEMESTERS", { 660, 15 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoviewschoolyearpage.button, WHITE);
		DrawTextEx(bold, "Back to list School Years", { 1200, 20 }, 25,0, DARKBLUE);
		DrawRectangle(322, 136, 870, 806, WHITE);
		DrawRectangleLines(321, 135, 872, 807, BLACK);


		mousePoint = GetMousePosition();
		Button6 semester[3];
		char** semestername = new char* [3];
		getsemestername(semestername, n);
		for (int i = 0; i < n; ++i) {
			semester[i].button = { float(x_semester - 122), float(y_semester - 12), 421, 59 };
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


void CreateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtocoursepage.button, WHITE);
		DrawTextEx(bold, Year, { 30, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, Semester, { 670, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, "Back to Course Page", { 1230, 20 }, 25,0, DARKBLUE);

		DrawRectangle(126, 92, 1260, 870, WHITE);
		DrawRectangleRec(id.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course ID: ", { 175, 115 }, 30,0, DARKBLUE);
		DrawRectangleRec(coursename.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course name: ", { 175, 228 }, 30,0, DARKBLUE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Class name: ", { 175, 341 }, 30,0, DARKBLUE);
		DrawRectangleRec(teachername.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Teacher name: ", { 175, 454 }, 30,0, DARKBLUE);
		DrawRectangleRec(nofc.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Number of credits: ", { 175, 567 }, 30,0, DARKBLUE);
		DrawRectangleRec(maxstudents.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Maximum students: ", { 175, 680 }, 30,0, DARKBLUE);
		DrawRectangleRec(courseday.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course day: ", { 175, 793 }, 30,0, DARKBLUE);
		DrawRectangleRec(sshours.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Session hours: ", { 779, 793 }, 30,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		id.worktextbox(confirmBtnFalseDisplay);
		coursename.worktextbox(confirmBtnFalseDisplay);
		classname.worktextbox(confirmBtnFalseDisplay);
		teachername.worktextbox(confirmBtnFalseDisplay);
		nofc.worktextbox(confirmBtnFalseDisplay);
		maxstudents.worktextbox(confirmBtnFalseDisplay);
		courseday.worktextbox(confirmBtnFalseDisplay);
		sshours.worktextbox(confirmBtnFalseDisplay);



		DrawTextEx(medium, coursename.text, { 198, 270 }, 30,0, DARKBLUE);
		DrawTextEx(medium, id.text, { 198, 157 }, 30,0, DARKBLUE);
		DrawTextEx(medium, classname.text, { 198, 383}, 30,0, DARKBLUE);
		DrawTextEx(medium, teachername.text, { 198, 496 }, 30,0, DARKBLUE);
		DrawTextEx(medium, nofc.text, { 198, 609 }, 30,0, DARKBLUE);
		DrawTextEx(medium, maxstudents.text, { 198, 722 }, 30,0, DARKBLUE);
		if (maxstudents.lettercount == 0) {
			DrawTextEx(medium, "50", { 198, 722 }, 30,0, DARKBLUE);
		}
		DrawTextEx(medium, courseday.text, { 198, 835 }, 30,0, DARKBLUE);
		DrawTextEx(medium, sshours.text, { 802, 835 }, 30,0, DARKBLUE);


		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (!CheckValidCourse(coursename.text, id.text, classname.text, nofc.text, maxstudents.text, Year, Semester) ||
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
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Invalid data or some textboxes are blank. Please try again!", { 482, 888 }, 20,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
			else coursebutton[i].state = true;
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
		DrawTextEx(bold, Year, { 30, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, Semester, { 690, 15 }, 40,0, DARKBLUE);
		DrawRectangleRec(backtoviewsemesterpage.button, WHITE);
		DrawTextEx(bold, "Back to View Semester Page", { 1180, 20 }, 25,0, DARKBLUE);
		DrawTexture(background2, 0, 60, WHITE);

		DrawRectangle(0, 189, 121, 42, LIGHTGRAY);
		DrawRectangleLines(0, 189, 121, 42, BLACK);
		DrawTextEx(bold, "ID", { 45, 203 }, 22,0, DARKBLUE);

		DrawRectangle(121, 189, 486, 42, LIGHTGRAY);
		DrawRectangleLines(121, 189, 486, 42, BLACK);
		DrawTextEx(bold, "Course name", { 311, 203 }, 22,0, DARKBLUE);

		DrawRectangle(607, 189, 132, 42, LIGHTGRAY);
		DrawRectangleLines(607, 189, 132, 42, BLACK);
		DrawTextEx(bold, "Class name", { 617, 203 }, 22,0, DARKBLUE);

		DrawRectangle(739, 189, 327, 42, LIGHTGRAY);
		DrawRectangleLines(739, 189, 327, 42, BLACK);
		DrawTextEx(bold, "Teacher name", { 835, 203 }, 22,0, DARKBLUE);

		DrawRectangle(1066, 189, 83, 42, LIGHTGRAY);
		DrawRectangleLines(1066, 189, 83, 42, BLACK);
		DrawTextEx(bold, "Credits", { 1071, 203 }, 22,0, DARKBLUE);

		DrawRectangle(1149, 189, 144, 42, LIGHTGRAY);
		DrawRectangleLines(1149, 189, 144, 42, BLACK);
		DrawTextEx(bold, "Max students", { 1153, 203 }, 22,0, DARKBLUE);

		DrawRectangle(1293, 189, 131, 42, LIGHTGRAY);
		DrawRectangleLines(1293, 189, 131, 42, BLACK);
		DrawTextEx(bold, "Course day", { 1300, 203 }, 22,0, DARKBLUE);

		DrawRectangle(1424, 189, 88, 42, LIGHTGRAY);
		DrawRectangleLines(1424, 189, 88, 42, BLACK);
		DrawTextEx(bold, "Session", { 1430, 203 }, 22,0, DARKBLUE);

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
void UpdateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course*& Course, int n, int i) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
	sshours.textbox = { 779, 827, 460, 47 };

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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoviewcoursepage.button, WHITE);
		DrawTextEx(bold, Year, { 30, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, Semester, { 670, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, "Back to View Course Page", { 1220, 20 }, 25,0, DARKBLUE);

		DrawRectangle(126, 92, 1260, 870, WHITE);
		DrawRectangleRec(id.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course ID: ", { 175, 115 }, 30,0, DARKBLUE);
		DrawRectangleRec(coursename.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course name: ", { 175, 228 }, 30,0, DARKBLUE);
		DrawRectangleRec(classname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Class name: ", { 175, 341}, 30,0, DARKBLUE);
		DrawRectangleRec(teachername.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Teacher name: ", { 175, 454 }, 30,0, DARKBLUE);
		DrawRectangleRec(nofc.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Number of credits: ", { 175, 567 }, 30,0, DARKBLUE);
		DrawRectangleRec(maxstudents.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Maximum students: ", { 175, 680 }, 30,0, DARKBLUE);
		DrawRectangleRec(courseday.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Course day: ", { 175, 793 }, 30,0, DARKBLUE);
		DrawRectangleRec(sshours.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Session hours: ", { 779, 793 }, 30,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		id.worktextbox(confirmBtnFalseDisplay);
		coursename.worktextbox(confirmBtnFalseDisplay);
		classname.worktextbox(confirmBtnFalseDisplay);
		teachername.worktextbox(confirmBtnFalseDisplay);
		nofc.worktextbox(confirmBtnFalseDisplay);
		maxstudents.worktextbox(confirmBtnFalseDisplay);
		courseday.worktextbox(confirmBtnFalseDisplay);
		sshours.worktextbox(confirmBtnFalseDisplay);


		if (id.lettercount == 0)			DrawTextEx(medium, Course[i].courseID, { 198, 162 }, 30,0, BLACK);
		if (coursename.lettercount == 0)	DrawTextEx(medium, Course[i].courseName, { 198, 275 }, 30,0, BLACK);
		if (classname.lettercount == 0)		DrawTextEx(medium, Course[i].className, { 198, 388 }, 30,0, BLACK);
		if (teachername.lettercount == 0)	DrawTextEx(medium, Course[i].teacherName, { 198, 501 }, 30,0, BLACK);
		if (nofc.lettercount == 0) {
			char* nofc = new char[10];
			int_to_char(Course[i].numOfCre, nofc);
			DrawText(nofc, 198, 614, 25, BLACK);
		}
		if (maxstudents.lettercount == 0)	DrawTextEx(medium, "50", { 198, 727 }, 30,0, BLACK);
		if (courseday.lettercount == 0)		DrawTextEx(medium, Course[i].dayofweek, { 198, 840 }, 30,0, BLACK);
		if (sshours.lettercount == 0)		DrawTextEx(medium, Course[i].sessionHour, { 802, 840 }, 30,0, BLACK);
		DrawTextEx(medium, id.text, { 198, 162 }, 30,0, DARKBLUE);
		DrawTextEx(medium, coursename.text, { 198, 275 }, 30,0, DARKBLUE);
		DrawTextEx(medium, classname.text, { 198, 388 }, 30,0, DARKBLUE);
		DrawTextEx(medium, teachername.text, { 198, 501 }, 30,0, DARKBLUE);
		DrawTextEx(medium, nofc.text, { 198, 614 }, 30,0, DARKBLUE);
		DrawTextEx(medium, maxstudents.text, { 198, 727 }, 30,0, DARKBLUE);
		DrawTextEx(medium, courseday.text, { 198, 840 }, 30,0, DARKBLUE);
		DrawTextEx(medium, sshours.text, { 802, 840 }, 30,0, DARKBLUE);


		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (!CheckValidCourse(coursename.text, id.text, classname.text, nofc.text, maxstudents.text, Year, Semester)) {
				confirmBtnFalseDisplay = true;
			}
			else {
				updateCourse(Year, Semester, Course[i], coursename.text, id.text, classname.text, teachername.text, nofc.text, maxstudents.text, courseday.text, sshours.text);
				ReturnCoursesToFile(Year, Semester, n, Course);
				EndDrawing();
				ViewCoursesPage(screenWidth, screenHeight, CurrentUser, Year, Semester);
			}
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Invalid data. Please try again!", { 602, 888 }, 20,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);

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
	addAStu.btnBounds = { 599, 94, (float)addAStu.texture.width, addAStu.frameHeight };

	Button0 exportListStu;
	exportListStu.texture = LoadTexture("exportlistofstu.png");
	exportListStu.frameHeight = (float)exportListStu.texture.height;
	exportListStu.sourceRec = { 0, 0, (float)exportListStu.texture.width, exportListStu.frameHeight };
	exportListStu.btnBounds = { 1028, 94, (float)exportListStu.texture.width, exportListStu.frameHeight };

	Textbox1 ExportStu;
	ExportStu.textbox = { 237, 377, 950, 47 };

	Texture2D confirmBtn = LoadTexture("ConfirmBtn2.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 620, 490, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	bool confirmBtnFalseDisplay1 = false;

	Rectangle turnOffexport = { 1235, 189, 91, 76 };
	Button9* studentbutton = new Button9[n];
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
			else studentbutton[i].state = true;
			studentbutton[i].workbutton(mousePoint, CurrentUser, Year, Semester, Course, listStudents[i], updateStudent);
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
			delete[] stuNo;
			delete[] finalMark;
			delete[] midtermMark;
			delete[] totalMark;
			delete[] otherMark;
		}
		DrawRectangle(0, 0, screenWidth, 70, WHITE);
		DrawTextEx(medium, Course.courseID, { 30, 10 }, 25,0, DARKBLUE);
		DrawTextEx(medium, Course.className, { 30, 40 }, 25,0, DARKBLUE);
		DrawTextEx(medium, Year, { 720, 12 }, 25,0, DARKBLUE);
		DrawTextEx(bold, Semester, { 720, 35 }, 30,0, DARKBLUE);
		DrawRectangleRec(backtoviewcoursespage.button, WHITE);
		DrawTextEx(bold, "Back to Courses Page", { 1180, 25 }, 25,0, DARKBLUE);
		DrawTexture(background2, 0, 70, WHITE);

		DrawRectangle(0, 189, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 58, 65, BLACK);
		DrawTextEx(bold, "No", { 8, 210 }, 24,0, DARKBLUE);

		DrawRectangle(58, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 189, 173, 65, BLACK);
		DrawTextEx(bold, "Student ID", { 84, 210 }, 24,0, DARKBLUE);

		DrawRectangle(227, 189, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 189, 179, 65, BLACK);
		DrawTextEx(bold, "Last name", { 256, 210 }, 24,0, DARKBLUE);

		DrawRectangle(406, 189, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 189, 456, 65, BLACK);
		DrawTextEx(bold, "First name", { 569, 210 }, 24,0, DARKBLUE);

		DrawRectangle(862, 189, 157, 65, LIGHTGRAY);
		DrawRectangleLines(862, 189, 157, 65, BLACK);
		DrawTextEx(bold, "Total mark", { 878, 210 }, 24,0, DARKBLUE);

		DrawRectangle(1019, 189, 151, 65, LIGHTGRAY);
		DrawRectangleLines(1019, 189, 151, 65, BLACK);
		DrawTextEx(bold, "Final mark", { 1035, 210 },24,0, DARKBLUE);

		DrawRectangle(1170, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(1170, 189, 173, 65, BLACK);
		DrawTextEx(bold, "Midterm mark", { 1177, 210 }, 24,0, DARKBLUE);

		DrawRectangle(1343, 189, 169, 65, LIGHTGRAY);
		DrawRectangleLines(1343, 189, 169, 65, BLACK);
		DrawTextEx(bold, "Other mark", { 1359, 210 }, 24,0, DARKBLUE);

		mousePoint = GetMousePosition();
		addAStu.workbutton(mousePoint, CurrentUser, Course, Year, Semester, addStudentPageForCourse);
		addStuCSV.workbutton(mousePoint, CurrentUser, Course, Year, Semester, addStudentCSVForCourse);
		exportListStu.workbutton(mousePoint);

		string tmp = string(Course.courseName) + "-" + string(Course.className);
		char* filename = (char*)tmp.c_str();

		if (exportListStu.action) {
			for (int i = 0; i < n; ++i) {
				studentbutton[i].state1 = false;
			}

			DrawRectangleGradientV(165, 220, 1161, 370, DARKBLUE, BLUE);
			DrawTextEx(bold, "Back", { 1210, 240 }, 30,0, WHITE);
			DrawTextEx(medium, "* Please input the link path to folder you want to export files to: ", { 237, 330 }, 30,0, WHITE);
			DrawRectangleRec(ExportStu.textbox, WHITE);
			ExportStu.worktextbox(confirmBtnFalseDisplay);
			DrawTextEx(medium, ExportStu.text, { 260, 385 }, 30,0, DARKBLUE);
			//DrawText(TextFormat("%i/%i", ExportStu.lettercount, MAX_INPUT_CHARS), 1218, 390, 20, WHITE);

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
			if (confirmBtnFalseDisplay) {
				DrawRectangle(238, 444, 335, 28, YELLOW);
				DrawTextEx(bold, "Could not export to the folder!", { 242, 448 }, 25,0, RED);
			}
			if (confirmBtnFalseDisplay1) {
				DrawRectangle(238, 444, 949, 28, WHITE);
				DrawTextEx(bold, "File is exported to the folder! File name is: ", { 242, 448 }, 25,0, GREEN);
				DrawTextEx(bold, filename, { 692, 448 }, 25,0, GREEN);
			}
			if (ExportStu.mouseontextbox) {
				confirmBtnFalseDisplay1 = false;
			}
			// Calculate button frame rectangle to draw depending on button state

			if (CheckCollisionPointRec(mousePoint, turnOffexport)) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					exportListStu.action = false;
					for (int i = 0; i < n; ++i) {
						studentbutton[i].state1 = true;
					}
				}
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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

		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawTextEx(bold, "Back to Course Page", { 1280, 20 }, 25,0, DARKBLUE);
		DrawTextEx(bold, "Add a student", { 620, 12 }, 40,0, DARKBLUE);

		DrawRectangle(142, 148, 1227, 720, WHITE);
		DrawRectangleRec(Lastname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Last name", { 284, 174 }, 30,0, DARKBLUE);
		DrawRectangleRec(Firstname.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* First name", { 610, 174 }, 30,0, DARKBLUE);
		DrawRectangleRec(studentID.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Student ID", { 284, 312 }, 30,0, DARKBLUE);
		DrawRectangleRec(socialID.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Social ID", { 284, 450 }, 30,0, DARKBLUE);
		DrawRectangleRec(birth.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Date of birth", { 604, 588 }, 30,0, DARKBLUE);
		DrawRectangleRec(Gender.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Gender", { 284, 588 }, 30,0, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		Lastname.worktextbox(confirmBtnFalseDisplay);
		Firstname.worktextbox(confirmBtnFalseDisplay);
		studentID.worktextbox(confirmBtnFalseDisplay);
		socialID.worktextbox(confirmBtnFalseDisplay);
		birth.worktextbox(confirmBtnFalseDisplay);
		Gender.worktextbox(confirmBtnFalseDisplay);

		DrawTextEx(medium, Lastname.text, { 314, 233 }, 40,0, DARKBLUE);
		DrawTextEx(medium, Firstname.text, { 640, 233 }, 40,0, DARKBLUE);
		DrawTextEx(medium, studentID.text, { 314, 371 }, 40,0, DARKBLUE);
		DrawTextEx(medium, socialID.text, { 314, 509 }, 40,0, DARKBLUE);
		DrawTextEx(medium, birth.text, { 634, 647 }, 40,0, DARKBLUE);
		DrawTextEx(medium, Gender.text, { 314, 647 }, 40,0, DARKBLUE);

		////Function of buttons------------	------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (addAStudentToCourse(Year, Semester, filename, Firstname.text, Lastname.text, Gender.text, birth.text, socialID.text, studentID.text)) {
				confirmBtnFalseDisplay = false;
				CoursePage(screenWidth, screenHeight, CurrentUser, Year, Semester, Course);
			}
			else confirmBtnFalseDisplay = true;

		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Invalid data!", { 330, 720 }, 25,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
	
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawTextEx(bold, "Back to Course Page", { 1280, 20 }, 25,0, DARKBLUE);
		DrawTextEx(bold, "Add student(s)", { 620, 12 }, 40,0, DARKBLUE);

		DrawRectangle(347, 173, 818, 380, WHITE);
		DrawRectangleRec(filename.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* File name", { 420, 235 }, 30,0, DARKBLUE);

		filename.worktextbox(confirmBtnFalseDisplay);
		DrawTextEx(medium, filename.text, { 450, 300 }, 40,0, DARKBLUE);

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
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
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "File name is invalid!!!", { 440, 380 }, 25,0, RED);
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
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
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
		DrawTextEx(bold, "These students have already existed in this course", { 10, 10 }, 40,0, RED);

		DrawRectangleRec(backtoCoursepage.button, WHITE);
		DrawTextEx(bold, "Back to Course Page", { 1280, 20 }, 25,0, DARKBLUE);

		DrawRectangle(0, 60, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 60, 58, 65, BLACK);
		DrawTextEx(bold, "No", { 8, 76 }, 24,0, DARKBLUE);

		DrawRectangle(58, 60, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 60, 173, 65, BLACK);
		DrawTextEx(bold, "Student ID", { 84, 76 }, 24,0, DARKBLUE);

		DrawRectangle(227, 60, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 60, 179, 65, BLACK);
		DrawTextEx(bold, "Last name", { 256, 76 }, 24,0, DARKBLUE);

		DrawRectangle(406, 60, 456, 65, LIGHTGRAY);
		DrawRectangleLines(406, 60, 456, 65, BLACK);
		DrawTextEx(bold, "First name", { 569, 76 }, 24,0, DARKBLUE);

		DrawRectangle(862, 60, 188, 65, LIGHTGRAY);
		DrawRectangleLines(862, 60, 188, 65, BLACK);
		DrawTextEx(bold, "Gender", { 910, 76 }, 24,0, DARKBLUE);

		DrawRectangle(1050, 60, 242, 65, LIGHTGRAY);
		DrawRectangleLines(1050, 60, 242, 65, BLACK);
		DrawTextEx(bold, "Date of Birth", { 1095, 76 }, 24,0, DARKBLUE);

		DrawRectangle(1292, 60, 220, 65, LIGHTGRAY);
		DrawRectangleLines(1292, 60, 220, 65, BLACK);
		DrawTextEx(bold, "Social ID", { 1345, 76 }, 24,0, DARKBLUE);

		backtoCoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);

		EndDrawing();
	}
	CloseWindow();
}
void updateStudent(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course, student& s) {
	Font bold = LoadFontEx("../Montserrat/static/Montserrat-Bold.ttf", 120, 0, 250);
	Font light = LoadFontEx("../Montserrat/static/Montserrat-Light.ttf", 120, 0, 250);
	Font medium = LoadFontEx("../Montserrat/static/Montserrat-Medium.ttf", 120, 0, 250);
	Vector2 mousePoint = { 0.0f, 0.0f };
	Rectangle background = { 0,0,float(screenWidth),float(screenHeight) };

	Textbox3 totalMark;
	totalMark.textbox = { 233, 369, 137, 47 };
	Textbox3 finalMark;
	finalMark.textbox = { 530, 369, 137, 47 };
	Textbox3 midtermMark;
	midtermMark.textbox = { 827, 369, 137, 47 };
	Textbox3 otherMark;
	otherMark.textbox = { 1124, 369, 137, 47 };

	Button8 backtocoursepage;
	backtocoursepage.button = { 1200, 20, 200, 30 };

	Texture2D confirmBtn = LoadTexture("confirmBtn1.png");
	float frameHeightconfirmBtn = (float)confirmBtn.height;
	Rectangle sourceRecconfirmBtn = { 0, 0, (float)confirmBtn.width,frameHeightconfirmBtn };
	// Define button bounds on screen
	Rectangle btnBoundsconfirmBtn = { 670, 456, (float)confirmBtn.width, frameHeightconfirmBtn };
	int confirmBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool confirmBtnAction = false;         // Button action should be activated
	bool confirmBtnFalseDisplay = false;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtocoursepage.button, WHITE);
		DrawTextEx(medium, Course.courseID, { 30, 05 }, 25,0, DARKBLUE);
		DrawTextEx(medium, Course.className, { 30, 35 }, 25,0, DARKBLUE);
		DrawTextEx(bold, s.stuID, { 662, 15 }, 40,0, DARKBLUE);
		DrawTextEx(bold, "Back to Course Page", { 1230, 20 }, 25,0, DARKBLUE);

		DrawRectangle(126, 264, 1260, 316, WHITE);
		DrawTextEx(medium, "* Total Mark: ", { 233, 335 }, 30,0, DARKBLUE);
		DrawRectangleRec(totalMark.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Final Mark: ", { 530, 335 }, 30,0, DARKBLUE);
		DrawRectangleRec(finalMark.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Midterm Mark: ", { 827, 335 }, 30,0, DARKBLUE);
		DrawRectangleRec(midtermMark.textbox, LIGHTGRAY);
		DrawTextEx(medium, "* Other Mark: ", { 1124, 335 }, 30,0, DARKBLUE);
		DrawRectangleRec(otherMark.textbox, LIGHTGRAY);


		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		totalMark.worktextbox(confirmBtnFalseDisplay);
		finalMark.worktextbox(confirmBtnFalseDisplay);
		midtermMark.worktextbox(confirmBtnFalseDisplay);
		otherMark.worktextbox(confirmBtnFalseDisplay);


		DrawTextEx(medium, totalMark.text, { 256, 377 }, 30,0, DARKBLUE);
		DrawTextEx(medium, TextFormat("%i/%i", totalMark.lettercount, 4), { 395, 387 }, 25,0, DARKBLUE);
		DrawTextEx(medium, finalMark.text, { 553, 377 }, 30,0, DARKBLUE);
		DrawTextEx(medium, TextFormat("%i/%i", finalMark.lettercount, 4), { 692, 387 }, 25,0, DARKBLUE);
		DrawTextEx(medium, midtermMark.text, { 850, 377 }, 30,0, DARKBLUE);
		DrawTextEx(medium, TextFormat("%i/%i", midtermMark.lettercount, 4), { 989, 387 }, 25,0, DARKBLUE);
		DrawTextEx(medium, otherMark.text, { 1147, 377 }, 30,0, DARKBLUE);
		DrawTextEx(medium, TextFormat("%i/%i", otherMark.lettercount, 4), { 1286, 387 }, 25,0, DARKBLUE);

		if (totalMark.lettercount == 0) {
			char* Total = new char[5];
			double_to_char(s.mark.totalMark, Total);
			DrawTextEx(medium, Total, { 256, 377 }, 30,0, BLACK);
		}
		if (finalMark.lettercount == 0) {
			char* Final = new char[5];
			double_to_char(s.mark.finalMark, Final);
			DrawTextEx(medium, Final, { 553, 377 }, 30,0, BLACK);
		}
		if (midtermMark.lettercount == 0) {
			char* Midterm = new char[5];
			double_to_char(s.mark.midtermMark, Midterm);
			DrawTextEx(medium, Midterm, { 850, 377 }, 30,0, BLACK);
		}
		if (otherMark.lettercount == 0) {
			char* Other = new char[5];
			double_to_char(s.mark.otherMark, Other);
			DrawTextEx(medium, Other, { 1147, 377 }, 30,0, BLACK);
		}

		////Function of buttons------------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();

		///Confirm button
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (UpdateStudentMark(s, totalMark.text, finalMark.text, midtermMark.text, otherMark.text)) {
				Return_stu(Course, Year, Semester);
				confirmBtnFalseDisplay = false;
				EndDrawing();
				CoursePage(screenWidth, screenHeight, CurrentUser, Year, Semester, Course);
			}
			else confirmBtnFalseDisplay = true;
		}
		if (confirmBtnFalseDisplay) DrawTextEx(bold, "Some inputs are in wrong format. Please try again!", { 505, 426 }, 25,0, RED);
		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame

		/// Back to profile page button
		backtocoursepage.workbutton(mousePoint, CurrentUser, Year, Semester, Course, CoursePage);

		EndDrawing();
	}
	delete[] Year;
	delete[] Semester;
	 
	 
	CloseWindow();
}


