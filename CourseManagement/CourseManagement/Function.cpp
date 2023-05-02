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
	viewPass.btnBounds = { 665, 410, (float)viewPass.texture.width, viewPass.frameHeight };

	Button0 hidePass;
	hidePass.texture = LoadTexture("hidepass.png");
	hidePass.frameHeight = (float)hidePass.texture.height;
	hidePass.sourceRec = { 0, 0, (float)hidePass.texture.width, hidePass.frameHeight };
	hidePass.btnBounds = { 665, 406, (float)hidePass.texture.width, hidePass.frameHeight };

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
		viewPass.workbutton(mousePoint);


		DrawText(username.text, 500, 320, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		if (viewPass.hidden) {
			DrawText(password.hiddentext, 500, 490, 40, DARKBLUE);
		}
		if (!viewPass.hidden) {
			DrawTextureRec(hidePass.texture, hidePass.sourceRec, { hidePass.btnBounds.x,hidePass.btnBounds.y }, WHITE);
			DrawText(password.text, 500, 490, 40, DARKBLUE);
		}
		DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 500, 20, DARKBLUE);

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
	viewPass.btnBounds = { 665, 410, (float)viewPass.texture.width, viewPass.frameHeight };

	Button0 hidePass;
	hidePass.texture = LoadTexture("hidepass.png");
	hidePass.frameHeight = (float)hidePass.texture.height;
	hidePass.sourceRec = { 0, 0, (float)hidePass.texture.width, hidePass.frameHeight };
	hidePass.btnBounds = { 665, 406, (float)hidePass.texture.width, hidePass.frameHeight };

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
		viewPass.workbutton(mousePoint);


		DrawText(username.text, 500, 320, 40, DARKBLUE);
		DrawText(TextFormat("%i/%i", username.lettercount, MAX_INPUT_CHARS), 1050, 330, 20, DARKBLUE);
		if (viewPass.hidden) {
			DrawText(password.hiddentext, 500, 490, 40, DARKBLUE);
		}
		if (!viewPass.hidden) {
			DrawTextureRec(hidePass.texture, hidePass.sourceRec, { hidePass.btnBounds.x,hidePass.btnBounds.y }, WHITE);
			DrawText(password.text, 500, 490, 40, DARKBLUE);
		}
		DrawText(TextFormat("%i/%i", password.lettercount, MAX_INPUT_CHARS), 1050, 500, 20, DARKBLUE);

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
		scoreboard.workbutton(mousePoint, CurrentUser, ScoreboardStudent);
		course.workbutton(mousePoint, CurrentUser, CoursePageStudent);

		//// display schoolyear from createschoolyear page--------------------------------------------------------------------------------------------
		EndDrawing();
	}
	CloseWindow();
}
void CoursePageStudent(const int screenWidth, const int screenHeight, account& CurrentUser) {
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
		DrawText("COURSE MANAGEMENT SYSTEM", 430, 10, 40, DARKBLUE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawText("Years", 420, 115, 20, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawText("Semesters", 105, 115, 20, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawText("OK", 690, 115, 20, WHITE);
		int z = 0, r = 0, j = 0;

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

		DrawRectangle(0, 231, 1512, 751, WHITE);

		DrawText("Back to the previous page", 1200, 20, 20, DARKBLUE);


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
				DrawText(YearName[k], 410, 115, 20, WHITE);
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
			DrawText("Fall", 130, 115, 20, WHITE);
			action = false;
			semesternametmp = (char*)"Fall";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,200,200, 50 }) && action && (n != 2 || n == 3)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionS = true;
		}
		if (actionS) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Summer", 130, 115, 20, WHITE);
			action = false;
			semesternametmp = (char*)"Summer";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,250,200, 50 }) && action && n == 3) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionA = true;
		}
		if (actionA) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Autumn", 130, 115, 20, WHITE);
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
			DrawText("No Data Available !!!", 420, 470, 70, RED);
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
		DrawText("COURSE MANAGEMENT SYSTEM", 430, 10, 40, DARKBLUE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawText("Years", 420, 115, 20, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawText("Semesters", 105, 115, 20, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawText("OK", 690, 115, 20, WHITE);
		int z = 0, r = 0, j = 0;

		DrawRectangle(846, 101, 252, 55, WHITE);
		DrawText("Semester GPA:", 857, 116, 24, DARKBLUE);
		DrawRectangle(1195, 101, 220, 55, WHITE);
		DrawText("Overall GPA:", 1203, 116, 24, DARKBLUE);

		DrawRectangle(0, 189, 231, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 231, 65, BLACK);
		DrawText("Course ID", 56, 210, 24, DARKBLUE);

		DrawRectangle(231, 189, 646, 65, LIGHTGRAY);
		DrawRectangleLines(231, 189, 646, 65, BLACK);
		DrawText("Course Name", 497, 210, 24, DARKBLUE);

		DrawRectangle(877, 189, 124, 65, LIGHTGRAY);
		DrawRectangleLines(877, 189, 124, 65, BLACK);
		DrawText("Credits", 899, 210, 24, DARKBLUE);

		DrawRectangle(1001, 189, 169, 65, LIGHTGRAY);
		DrawRectangleLines(1001, 189, 169, 65, BLACK);
		DrawText("Class", 1055, 210, 24, DARKBLUE);

		DrawRectangle(1170, 189, 231, 65, LIGHTGRAY);
		DrawRectangleLines(1170, 189, 231, 65, BLACK);
		DrawText("Total", 1183, 210, 24, DARKBLUE);

		DrawRectangle(1256, 189, 85, 65, LIGHTGRAY);
		DrawRectangleLines(1256, 189, 85, 65, BLACK);
		DrawText("F", 1290, 210, 24, DARKBLUE);

		DrawRectangle(1341, 189, 85, 65, LIGHTGRAY);
		DrawRectangleLines(1341, 189, 85, 65, BLACK);
		DrawText("M", 1375, 210, 24, DARKBLUE);

		DrawRectangle(1426, 189, 86, 65, LIGHTGRAY);
		DrawRectangleLines(1426, 189, 86, 65, BLACK);
		DrawText("O", 1460, 210, 24, DARKBLUE);

		DrawRectangle(0, 255, 1512, 751, WHITE);

		double_to_char(overallGPAd, overallGPA);
		DrawText(overallGPA, 1360, 116, 24, DARKBLUE);



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
				DrawText(YearName[k], 410, 115, 20, WHITE);
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
			DrawText("Fall", 130, 115, 20, WHITE);
			action = false;
			semesternametmp = (char*)"Fall";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,200,200, 50 }) && action && (n != 2 || n == 3)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionS = true;
		}
		if (actionS) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Summer", 130, 115, 20, WHITE);
			action = false;
			semesternametmp = (char*)"Summer";
		}

		if (CheckCollisionPointRec(mousePoint, { 60,250,200, 50 }) && action && n == 3) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) actionA = true;
		}
		if (actionA) {
			DrawRectangleRec(semesters, DARKBLUE);
			DrawText("Autumn", 130, 115, 20, WHITE);
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
			DrawText(semesterGPA, 1043, 116, 24, DARKBLUE);
		}

		if (cntCourse == 0) {
			DrawText("No Data Available !!!", 420, 470, 70, RED);
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

		DrawText("Back to the previous page", 1200, 20, 20, DARKBLUE);
		backtopreviouspage.workbutton(mousePoint, CurrentUser, ProfilePageStudent);
		EndDrawing();
	}
	 
	
	CloseWindow();
}
void ProfilePageStaff(const int screenWidth, const int screenHeight, account& CurrentUser) {
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
		viewPass1.workbutton(mousePoint);
		viewPass2.workbutton(mousePoint);
		viewPass3.workbutton(mousePoint);

		if (viewPass1.hidden) {
			DrawText(oldpass.hiddentext, 500, 270, 40, DARKBLUE);
		}
		if (!viewPass1.hidden) {
			DrawText(oldpass.text, 500, 270, 40, DARKBLUE);
			DrawTextureRec(hidePass1.texture, hidePass1.sourceRec, { hidePass1.btnBounds.x,hidePass1.btnBounds.y }, WHITE);
		}
		if (viewPass2.hidden) {
			DrawText(newpass.hiddentext, 500, 434, 40, DARKBLUE);
		}
		if (!viewPass2.hidden) {
			DrawText(newpass.text, 500, 434, 40, DARKBLUE);
			DrawTextureRec(hidePass2.texture, hidePass2.sourceRec, { hidePass2.btnBounds.x,hidePass2.btnBounds.y }, WHITE);
		}
		if (viewPass3.hidden) {
			DrawText(confirmnewpass.hiddentext, 500, 598, 40, DARKBLUE);
		}
		if (!viewPass3.hidden) {
			DrawText(confirmnewpass.text, 500, 598, 40, DARKBLUE);
			DrawTextureRec(hidePass3.texture, hidePass3.sourceRec, { hidePass3.btnBounds.x,hidePass3.btnBounds.y }, WHITE);
		}

		DrawText(TextFormat("%i/%i", oldpass.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", newpass.lettercount, MAX_INPUT_CHARS), 1050, 444, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmnewpass.lettercount, MAX_INPUT_CHARS), 1050, 608, 20, DARKBLUE);
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
		viewPass1.workbutton(mousePoint);
		viewPass2.workbutton(mousePoint);
		viewPass3.workbutton(mousePoint);

		if (viewPass1.hidden) {
			DrawText(oldpass.hiddentext, 500, 270, 40, DARKBLUE);
		}
		if (!viewPass1.hidden) {
			DrawText(oldpass.text, 500, 270, 40, DARKBLUE);
			DrawTextureRec(hidePass1.texture, hidePass1.sourceRec, { hidePass1.btnBounds.x,hidePass1.btnBounds.y }, WHITE);
		}
		if (viewPass2.hidden) {
			DrawText(newpass.hiddentext, 500, 434, 40, DARKBLUE);
		}
		if (!viewPass2.hidden) {
			DrawText(newpass.text, 500, 434, 40, DARKBLUE);
			DrawTextureRec(hidePass2.texture, hidePass2.sourceRec, { hidePass2.btnBounds.x,hidePass2.btnBounds.y }, WHITE);
		}
		if (viewPass3.hidden) {
			DrawText(confirmnewpass.hiddentext, 500, 598, 40, DARKBLUE);
		}
		if (!viewPass3.hidden) {
			DrawText(confirmnewpass.text, 500, 598, 40, DARKBLUE);
			DrawTextureRec(hidePass3.texture, hidePass3.sourceRec, { hidePass3.btnBounds.x,hidePass3.btnBounds.y }, WHITE);
		}

		DrawText(TextFormat("%i/%i", oldpass.lettercount, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", newpass.lettercount, MAX_INPUT_CHARS), 1050, 444, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", confirmnewpass.lettercount, MAX_INPUT_CHARS), 1050, 608, 20, DARKBLUE);
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

void CreateSchoolYearPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
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

void createClassPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
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

		DrawText(Classname, 670, 15, 40, DARKBLUE);
		DrawRectangleRec(backtoViewClasspage.button, WHITE);
		DrawText("Back to Classes Page", 1200, 20, 20, DARKBLUE);
		DrawTexture(background2, 0, 60, WHITE);

		DrawRectangleRec(schoolyears, WHITE);
		DrawText("Years", 420, 115, 20, DARKBLUE);
		DrawRectangleRec(semesters, WHITE);
		DrawText("Semesters", 105, 115, 20, DARKBLUE);
		DrawRectangleRec(ok, DARKBLUE);
		DrawText("OK", 690, 115, 20, WHITE);
		int z = 0, r = 0;//, j1 = 0;

		DrawRectangleRec(AddStuCSV.button, WHITE);
		DrawText("Add Student with CSV", 785, 115, 20, DARKBLUE);
		DrawRectangleRec(AddAStu.button, WHITE);
		DrawText("Add a Student manually", 1156, 115, 20, DARKBLUE);

		DrawRectangle(0, 189, 58, 65, LIGHTGRAY);
		DrawRectangleLines(0, 189, 58, 65, BLACK);
		DrawText("No", 8, 205, 24, DARKBLUE);

		DrawRectangle(58, 189, 173, 65, LIGHTGRAY);
		DrawRectangleLines(58, 189, 173, 65, BLACK);
		DrawText("Student ID", 84, 205, 24, DARKBLUE);

		DrawRectangle(227, 189, 179, 65, LIGHTGRAY);
		DrawRectangleLines(227, 189, 179, 65, BLACK);
		DrawText("Last name", 256, 205, 24, DARKBLUE);

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

				DrawText("Back", 1400, 180, 30, WHITE);
				DrawText("Last name:", 34, 209, 24, WHITE);
				DrawText(listStudents[i].Student.lastName, 175, 209, 24, WHITE);
				DrawText("First name:", 34, 249, 24, WHITE);
				DrawText(listStudents[i].Student.firstName, 175, 249, 24, WHITE);
				DrawText("Student ID:", 34, 289, 24, WHITE);
				DrawText(listStudents[i].stuID, 175, 289, 24, WHITE);
				// Calculate button frame rectangle to draw depending on button state

				DrawRectangle(836, 263, 252, 55, WHITE);
				DrawText("Semester GPA:", 847, 278, 24, DARKBLUE);
				char* semestergpa = new char[5];
				char* overallgpa = new char[5];
				if (semesterGPA) {
					double_to_char(semesterGPA[i], semestergpa);
					DrawText(semestergpa, 1028, 278, 24, DARKBLUE);
				}
				DrawRectangle(1190, 263, 252, 55, WHITE);
				DrawText("Overall GPA:", 1201, 278, 24, DARKBLUE);
				if (overallGPA) {
					double_to_char(semesterGPA[i], overallgpa);
					DrawText(overallgpa, 1363, 278, 24, DARKBLUE);
				}

				DrawRectangle(24, 360, 121, 42, LIGHTGRAY);
				DrawRectangleLines(24, 360, 121, 42, BLACK);
				DrawText("Course ID", 35, 372, 20, DARKBLUE);

				DrawRectangle(145, 360, 519, 42, LIGHTGRAY);
				DrawRectangleLines(145, 360, 519, 42, BLACK);
				DrawText("Course name", 339, 372, 20, DARKBLUE);

				DrawRectangle(664, 360, 198, 42, LIGHTGRAY);
				DrawRectangleLines(664, 360, 198, 42, BLACK);
				DrawText("Class name", 705, 372, 20, DARKBLUE);

				DrawRectangle(862, 360, 180, 42, LIGHTGRAY);
				DrawRectangleLines(862, 360, 180, 42, BLACK);
				DrawText("Credits", 914, 372, 20, DARKBLUE);

				DrawRectangle(1042, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1042, 360, 148, 42, BLACK);
				DrawText("Total Mark", 1060, 372, 20, DARKBLUE);

				DrawRectangle(1190, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1190, 360, 148, 42, BLACK);
				DrawText("Final Mark", 1214, 372, 20, DARKBLUE);

				DrawRectangle(1338, 360, 148, 42, LIGHTGRAY);
				DrawRectangleLines(1338, 360, 148, 42, BLACK);
				DrawText("Midterm Mark", 1344, 372, 20, DARKBLUE);
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
					DrawText("No Data Available !!!", 420, 470, 70, RED);
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
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (addAStudentToClass(classname, Firstname.text, Lastname.text, Gender.text, birth.text, socialID.text, studentID.text)) {
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
		backtoClasspage.workbutton(mousePoint, CurrentUser, classname, ClassPage);
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
		if (confirmBtnFalseDisplay) DrawText("File name is invalid!!!", 440, 380, 20, RED);
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
void CreateSemesterPage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year) {
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
		if (confirmBtnFalseDisplay) DrawText("Max semesters created or information must be written in right form!", 430, 600, 20, RED);
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
void UpdateCoursePage(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course*& Course, int n, int i) {
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

			DrawRectangleGradientV(165, 220, 1161, 370, DARKBLUE, BLUE);
			DrawText("Back", 1210, 240, 30, WHITE);
			DrawText("* Please input the link path to folder you want to export files to: ", 237, 330, 25, WHITE);
			DrawRectangleRec(ExportStu.textbox, WHITE);
			ExportStu.worktextbox(confirmBtnFalseDisplay);
			DrawText(ExportStu.text, 260, 390, 25, DARKBLUE);
			DrawText(TextFormat("%i/%i", ExportStu.lettercount, MAX_INPUT_CHARS), 1218, 390, 20, WHITE);

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
				DrawText("Could not export to the folder!", 242, 448, 20, RED);
			}
			if (confirmBtnFalseDisplay1) {
				DrawRectangle(238, 444, 635, 28, WHITE);
				DrawText("File is exported to the folder! File name is: ", 242, 448, 20, GREEN);
				DrawText(filename, 692, 448, 20, GREEN);
			}
			if (ExportStu.mouseontextbox) {
				confirmBtnFalseDisplay1 = false;
			}
			// Calculate button frame rectangle to draw depending on button state

			if (CheckCollisionPointRec(mousePoint, turnOffexport)) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					exportListStu.action = false;
					for (int i = 0; i < n; ++i) {
						studentbutton[i].state = true;
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
		else if (IsKeyPressed(KEY_ENTER)) confirmBtnAction = true;
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
void updateStudent(const int screenWidth, const int screenHeight, account& CurrentUser, char*& Year, char*& Semester, course& Course, student& s) {
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

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, SKYBLUE, DARKBLUE, DARKBLUE, SKYBLUE);
		DrawRectangle(0, 0, screenWidth, 60, WHITE);

		DrawRectangleRec(backtocoursepage.button, WHITE);
		DrawText(Course.courseID, 30, 10, 20, DARKBLUE);
		DrawText(Course.className, 30, 40, 20, DARKBLUE);
		DrawText(s.stuID, 662, 15, 40, DARKBLUE);
		DrawText("Back to Course Page", 1230, 20, 20, DARKBLUE);

		DrawRectangle(126, 264, 1260, 316, WHITE);
		DrawText("* Total Mark: ", 233, 340, 25, DARKBLUE);
		DrawRectangleRec(totalMark.textbox, LIGHTGRAY);
		DrawText("* Final Mark: ", 530, 340, 25, DARKBLUE);
		DrawRectangleRec(finalMark.textbox, LIGHTGRAY);
		DrawText("* Midterm Mark: ", 827, 340, 25, DARKBLUE);
		DrawRectangleRec(midtermMark.textbox, LIGHTGRAY);
		DrawText("* Other Mark: ", 1124, 340, 25, DARKBLUE);
		DrawRectangleRec(otherMark.textbox, LIGHTGRAY);


		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		totalMark.worktextbox(confirmBtnFalseDisplay);
		finalMark.worktextbox(confirmBtnFalseDisplay);
		midtermMark.worktextbox(confirmBtnFalseDisplay);
		otherMark.worktextbox(confirmBtnFalseDisplay);



		if (totalMark.lettercount == 0) {
			char* Total = new char[5];
			double_to_char(s.mark.totalMark, Total);
			DrawText(Total, 256, 382, 25, BLACK);
		}
		if (finalMark.lettercount == 0) {
			char* Final = new char[5];
			double_to_char(s.mark.finalMark, Final);
			DrawText(Final, 553, 382, 25, BLACK);
		}
		if (midtermMark.lettercount == 0) {
			char* Midterm = new char[5];
			double_to_char(s.mark.midtermMark, Midterm);
			DrawText(Midterm, 850, 382, 25, BLACK);
		}
		if (otherMark.lettercount == 0) {
			char* Other = new char[5];
			double_to_char(s.mark.otherMark, Other);
			DrawText(Other, 1147, 382, 25, BLACK);
		}


		DrawText(totalMark.text, 256, 382, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", totalMark.lettercount, 4), 395, 392, 20, DARKBLUE);
		DrawText(finalMark.text, 553, 382, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", finalMark.lettercount, 4), 692, 392, 20, DARKBLUE);
		DrawText(midtermMark.text, 850, 382, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", midtermMark.lettercount, 4), 989, 392, 20, DARKBLUE);
		DrawText(otherMark.text, 1147, 382, 25, DARKBLUE);
		DrawText(TextFormat("%i/%i", otherMark.lettercount, 4), 1286, 392, 20, DARKBLUE);



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
		if (confirmBtnFalseDisplay) DrawText("Some inputs are in wrong format. Please try again!", 505, 431, 20, RED);
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


