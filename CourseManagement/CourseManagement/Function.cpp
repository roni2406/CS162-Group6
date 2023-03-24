#include <iostream>
#include <fstream>
#include <raylib.h>
#include "back_end.h"
#include "Function.h"

using namespace std;
const int MAX_INPUT_CHARS = 18;


//FRONT_END--------------------------------------------------------
void drawloginPage() {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	Rectangle background = { 0,0,1512,982 };
	account CurrentUser;
	//Initialize-------------------------------------------------------
	char name[MAX_INPUT_CHARS + 1] = "\0";
	char pass[MAX_INPUT_CHARS + 1] = "\0";
	char HiddenPass[MAX_INPUT_CHARS + 1] = "\0";
	int letterCountHiddenPass = 0;
	int letterCountUsername = 0;
	int letterCountPassword = 0;
	Rectangle textBoxUsername = { 477, 239,558,106 };
	Rectangle textBoxPassword = { 477, 403,558,106 };
	bool mouseOnTextUsername = false;
	bool mouseOnTextPassword = false;

	////initialize login button---------------------------------------------------------------------------------------------------
	Texture2D loginButton = LoadTexture("loginButton.png");

	float frameHeightloginButton = (float)loginButton.height;
	Rectangle sourceRecloginButton = { 0, 0, (float)loginButton.width, frameHeightloginButton };
	// Define button bounds on screen
	Rectangle btnBoundsloginButton = { (screenWidth / 2.0f - loginButton.width / 2.0f) - 10, 550, (float)loginButton.width, frameHeightloginButton };

	int loginbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool loginbtnAction = false;         // Button action should be activated
	bool isLoginFalseDisplay = false;
    ////----------------------------------------------------------------------------------------------------------------------------------4
	////initialize signup button---------------------------------------------------------------------------------------------------
	Texture2D signupButton = LoadTexture("signupButton.png");
	float frameHeightsignupButton = (float)signupButton.height;
	Rectangle sourceRecsignupButton = { 0, 0, (float)signupButton.width, frameHeightsignupButton };
	Rectangle btnBoundssignupButton = { (screenWidth / 2.0f - loginButton.width / 2.0f) - 10, 650, (float)signupButton.width, frameHeightsignupButton };

	int signupbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool signupbtnAction = false;         // Button action should be activated
	////--------------------------------------------------------------------------------------------------------------------------------
	////initialize for login--------------------------------------------------------------------------------------------------------------
	ifstream fin;
	fin.open("accounts.txt");
	account* login_data = new account[100];         
	int n;
	inputAccounts(login_data, n, fin);
	fin.close();

	account inputLoginData;

	Vector2 mousePoint = { 0.0f, 0.0f };


	SetTargetFPS(40);
	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//Draw--------------------------------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		DrawRectangleGradientEx(background, DARKBLUE, BLUE, SKYBLUE, WHITE);
		DrawRectangle(347, 173, 818, 560, WHITE);
		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawText("You are not logged in.", 1200, 20, 20, DARKBLUE);
		DrawRectangleRec(textBoxUsername, LIGHTGRAY);
		DrawRectangleRec(textBoxPassword, LIGHTGRAY);
		DrawText("* Username", 477, 200, 30, DARKBLUE);
		DrawText("* Password", 477, 364, 30, DARKBLUE);
		DrawText("or", 735, 615, 30,DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		if (CheckCollisionPointRec(GetMousePosition(), textBoxUsername)) mouseOnTextUsername = true;
		else mouseOnTextUsername = false;
		if (CheckCollisionPointRec(GetMousePosition(), textBoxPassword)) mouseOnTextPassword = true;
		else mouseOnTextPassword = false;

		if (mouseOnTextUsername)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountUsername < MAX_INPUT_CHARS))
				{
					name[letterCountUsername] = (char)key;
					name[letterCountUsername + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountUsername++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountUsername--;
				if (letterCountUsername < 0) letterCountUsername = 0;
				name[letterCountUsername] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (mouseOnTextPassword)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountPassword < MAX_INPUT_CHARS))
				{
					pass[letterCountPassword] = (char)key;
					pass[letterCountPassword + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountPassword++;

					HiddenPass[letterCountHiddenPass] = '*';
					HiddenPass[letterCountHiddenPass + 1] = '\0';
					letterCountHiddenPass++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountPassword--;
				if (letterCountPassword < 0) letterCountPassword = 0;
				pass[letterCountPassword] = '\0';

				letterCountHiddenPass--;
				if (letterCountHiddenPass < 0) letterCountHiddenPass = 0;
				HiddenPass[letterCountHiddenPass] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (mouseOnTextUsername) {
			DrawRectangleLines((int)textBoxUsername.x, (int)textBoxUsername.y, (int)textBoxUsername.width, (int)textBoxUsername.height, BLUE);
			DrawRectangleLines((int)textBoxUsername.x - 1, (int)textBoxUsername.y - 1, (int)textBoxUsername.width + 2, (int)textBoxUsername.height + 2, BLUE);
			DrawRectangleLines((int)textBoxUsername.x - 2, (int)textBoxUsername.y - 2, (int)textBoxUsername.width + 4, (int)textBoxUsername.height + 4, BLUE);
			isLoginFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxUsername.x, (int)textBoxUsername.y, (int)textBoxUsername.width, (int)textBoxUsername.height, DARKGRAY);

		if (mouseOnTextPassword) {
			DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, BLUE);
			DrawRectangleLines((int)textBoxPassword.x - 1, (int)textBoxPassword.y - 1, (int)textBoxPassword.width + 2, (int)textBoxPassword.height + 2, BLUE);
			DrawRectangleLines((int)textBoxPassword.x - 2, (int)textBoxPassword.y - 2, (int)textBoxPassword.width + 4, (int)textBoxPassword.height + 4, BLUE);
			isLoginFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, DARKGRAY);

		DrawText(name, 500, 270, 40, DARKBLUE);
		//DrawText(pass, 500, 430, 40, DARKBLUE);
		DrawText(HiddenPass, 500, 440, 40, DARKBLUE);

		DrawText(TextFormat("%i/%i", letterCountUsername, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", letterCountPassword, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);
		////-------------------------------------------------------------------------------------------------------------------------------------------------

		////Function of login button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		loginbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
		}
		else loginbtnState = 0;

		inputLoginData.userName = _strdup(name);
		inputLoginData.password = _strdup(pass);

		if (loginbtnAction)
		{
			
			if (login(login_data, n, inputLoginData) && name[0] != '\0' && pass[0] != '\0') {
				CurrentUser.password = pass;
				CurrentUser.userName = name;
				ProfilePage(screenWidth, screenHeight, CurrentUser);
			}
			else isLoginFalseDisplay = true;
		}
		if (isLoginFalseDisplay) DrawText("Invalid username or password!", 477, 520, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecloginButton.y = loginbtnState * frameHeightloginButton;
		DrawTextureRec(loginButton, sourceRecloginButton, { btnBoundsloginButton.x, btnBoundsloginButton.y }, WHITE); // Draw button frame
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		////Function of signup button-------------------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		signupbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundssignupButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) signupbtnAction = true;
		}
		else signupbtnState = 0;
		if (signupbtnAction) {
			SignUpPage(screenWidth, screenHeight, CurrentUser);
		}

		sourceRecsignupButton.y = signupbtnState * frameHeightsignupButton;
		DrawTextureRec(signupButton, sourceRecsignupButton, { btnBoundssignupButton.x, btnBoundssignupButton.y }, WHITE);

		EndDrawing();
	}
	CloseWindow();
}

void SignUpPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Rectangle background = { 0,0,1512,982 };

	//Initialize---------------------------------------------------------------------
	char name[MAX_INPUT_CHARS + 1] = "\0";
	char pass[MAX_INPUT_CHARS + 1] = "\0";
	char confirmpass[MAX_INPUT_CHARS + 1] = "\0";

	int letterCountUsername = 0;
	int letterCountPassword = 0;
	int letterCountConfirmPassword = 0;

	Rectangle textBoxUsername = { 471, 200, 558, 112 };
	Rectangle textBoxPassword = { 471, 373, 558, 112 };
	Rectangle textBoxConfirmPassword = { 471, 546, 558, 112 };
	Rectangle textBoxBacktoLoginSite = { 1300, 20, 200, 30 };


	bool mouseOnTextUsername = false;
	bool mouseOnTextPassword = false;
	bool mouseOnTextConfirmPassword = false;
	bool mouseOnTextBacktoLoginSite = false;

	int framesCounterUsername = 0;
	int framesCounterPassword = 0;
	int framesCounterConfirmPassword = 0;

	////initialize signup button---------------------------------------------------------------------------------------------------
	Texture2D signupButton = LoadTexture("signupButton.png");
	float frameHeightsignupButton = (float)signupButton.height;
	Rectangle sourceRecsignupButton = { 0, 0, (float)signupButton.width, frameHeightsignupButton };
	Rectangle btnBoundssignupButton = { (screenWidth / 2.0f - signupButton.width / 2.0f) - 10, 700, (float)signupButton.width, frameHeightsignupButton };

	int signupbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool signupbtnAction = false;         // Button action should be activated
	bool issignupFalseDisplay = false;
	//Back to login site 
	bool BacktoLoginSiteAction = false;

	//// initialize for sign up-------------------------------------------------------------------------------------------------------
	account* login_account = new account[100];
	account newinfo;
	int n = 0;
	ifstream fin;
	ofstream fout;
	fin.open("accounts.txt");
	inputAccounts(login_account, n, fin);
	fin.close();

	Vector2 mousePoint = { 0.0f, 0.0f };

	//SetTargetFPS(40);

	//Draw----------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		BeginDrawing();
		DrawRectangleGradientEx(background, DARKBLUE, BLUE, SKYBLUE, WHITE);
		DrawRectangle(348, 110, 800, 680, WHITE);
		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawRectangleRec(textBoxBacktoLoginSite, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawText("Back to Log in Site", 1300, 20, 20, DARKBLUE);
		DrawRectangleRec(textBoxUsername, LIGHTGRAY);
		DrawRectangleRec(textBoxPassword, LIGHTGRAY);
		DrawRectangleRec(textBoxConfirmPassword, LIGHTGRAY);
		DrawText("* Username", 471, 165, 30, DARKBLUE);
		DrawText("* Password", 471, 338, 30, DARKBLUE);
		DrawText("* Confirm Password", 471, 511, 30, DARKBLUE);

		////Function_of_TextInputBoxes_----------------------------------------------------------------------------------------------------------------------
		if (CheckCollisionPointRec(GetMousePosition(), textBoxUsername)) mouseOnTextUsername = true;
		else mouseOnTextUsername = false;
		if (CheckCollisionPointRec(GetMousePosition(), textBoxPassword)) mouseOnTextPassword = true;
		else mouseOnTextPassword = false;
		if (CheckCollisionPointRec(GetMousePosition(), textBoxConfirmPassword)) mouseOnTextConfirmPassword = true;
		else mouseOnTextConfirmPassword = false;

		if (mouseOnTextUsername)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountUsername < MAX_INPUT_CHARS))
				{
					name[letterCountUsername] = (char)key;
					name[letterCountUsername + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountUsername++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountUsername--;
				if (letterCountUsername < 0) letterCountUsername = 0;
				name[letterCountUsername] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextUsername) framesCounterUsername++;
		else framesCounterUsername = 0;

		if (mouseOnTextPassword)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountPassword < MAX_INPUT_CHARS))
				{
					pass[letterCountPassword] = (char)key;
					pass[letterCountPassword + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountPassword++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountPassword--;
				if (letterCountPassword < 0) letterCountPassword = 0;
				pass[letterCountPassword] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextPassword) framesCounterPassword++;
		else framesCounterPassword = 0;

		if (mouseOnTextConfirmPassword)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountConfirmPassword < MAX_INPUT_CHARS))
				{
					confirmpass[letterCountConfirmPassword] = (char)key;
					confirmpass[letterCountConfirmPassword + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountConfirmPassword++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountConfirmPassword--;
				if (letterCountConfirmPassword < 0) letterCountConfirmPassword = 0;
				confirmpass[letterCountConfirmPassword] = '\0';
			}
		}

		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextConfirmPassword) framesCounterConfirmPassword++;
		else framesCounterConfirmPassword = 0;

		if (mouseOnTextUsername) {
			DrawRectangleLines((int)textBoxUsername.x, (int)textBoxUsername.y, (int)textBoxUsername.width, (int)textBoxUsername.height, BLUE);
			DrawRectangleLines((int)textBoxUsername.x - 1, (int)textBoxUsername.y - 1, (int)textBoxUsername.width + 2, (int)textBoxUsername.height + 2, BLUE);
			DrawRectangleLines((int)textBoxUsername.x - 2, (int)textBoxUsername.y - 2, (int)textBoxUsername.width + 4, (int)textBoxUsername.height + 4, BLUE);
			issignupFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxUsername.x, (int)textBoxUsername.y, (int)textBoxUsername.width, (int)textBoxUsername.height, DARKGRAY);

		if (mouseOnTextPassword) {
			DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, BLUE);
			DrawRectangleLines((int)textBoxPassword.x - 1, (int)textBoxPassword.y - 1, (int)textBoxPassword.width + 2, (int)textBoxPassword.height + 2, BLUE);
			DrawRectangleLines((int)textBoxPassword.x - 2, (int)textBoxPassword.y - 2, (int)textBoxPassword.width + 4, (int)textBoxPassword.height + 4, BLUE);
			issignupFalseDisplay = false;

		}
		else DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, DARKGRAY);

		if (mouseOnTextConfirmPassword) {
			DrawRectangleLines((int)textBoxConfirmPassword.x, (int)textBoxConfirmPassword.y, (int)textBoxConfirmPassword.width, (int)textBoxConfirmPassword.height, BLUE);
			DrawRectangleLines((int)textBoxConfirmPassword.x - 1, (int)textBoxConfirmPassword.y - 1, (int)textBoxConfirmPassword.width + 2, (int)textBoxConfirmPassword.height + 2, BLUE);
			DrawRectangleLines((int)textBoxConfirmPassword.x - 2, (int)textBoxConfirmPassword.y - 2, (int)textBoxConfirmPassword.width + 4, (int)textBoxConfirmPassword.height + 4, BLUE);
			issignupFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxConfirmPassword.x, (int)textBoxConfirmPassword.y, (int)textBoxConfirmPassword.width, (int)textBoxConfirmPassword.height, DARKGRAY);

		DrawText(name, 500, 231, 40, DARKBLUE);
		DrawText(pass, 500, 400, 40, DARKBLUE);
		DrawText(confirmpass, 500, 573, 40, DARKBLUE);

		DrawText(TextFormat("%i/%i", letterCountUsername, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", letterCountPassword, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", letterCountConfirmPassword, MAX_INPUT_CHARS), 1050, 620, 20, DARKBLUE);
		////-------------------------------------------------------------------------------------------------------------------------------------------------

		////Function of signup button------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		signupbtnAction = false;

		if (CheckCollisionPointRec(mousePoint, btnBoundssignupButton)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) signupbtnAction = true;
		}
		else signupbtnState = false;

		newinfo.userName = _strdup(name);
		newinfo.password = _strdup(pass);

		if (signupbtnAction)
		{
			for (int i = 0; i < n; ++i) {
				if (strcmp(newinfo.userName, login_account[i].userName) == 0) {
					issignupFalseDisplay = true;
					break;
				}
				if (i == n-1) {
					if (strcmp(confirmpass, pass) == 0) {
						addinfo(newinfo, (char*)"accounts.txt", fout);
						drawloginPage();
					}
					else issignupFalseDisplay = true;
				}
			}
		}
		if (issignupFalseDisplay) DrawText("Username have been used or wrong password! Please try again!", 430, 673, 20, RED);

		if (CheckCollisionPointRec(mousePoint, textBoxBacktoLoginSite)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) BacktoLoginSiteAction = true;
		}
		else BacktoLoginSiteAction = false;


		if (BacktoLoginSiteAction)
		{
			drawloginPage();
		}

		// Calculate button frame rectangle to draw depending on button state
		sourceRecsignupButton.y = signupbtnState * frameHeightsignupButton;
		DrawTextureRec(signupButton, sourceRecsignupButton, { btnBoundssignupButton.x, btnBoundssignupButton.y }, WHITE); // Draw button frame
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		EndDrawing();
	}
	CloseWindow();

}

void ProfilePage(const int screenWidth, const int screenHeight, account CurrentUser) {
	//Initialize variable---------------------------------------------------------------------------------------------
	Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();

	Rectangle background = { 0,0,1512,982 };

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

	Texture2D createSchoolYearBtn = LoadTexture("createSchoolYearBtn.png");
	float frameHeightcreateSchoolYearBtn = (float)createSchoolYearBtn.height;
	Rectangle sourceReccreateSchoolYearBtn = { 0, 0, (float)createSchoolYearBtn.width,frameHeightcreateSchoolYearBtn };
	// Define button bounds on screen
	Rectangle btnBoundscreateSchoolYearBtn = { 544, 200, (float)createSchoolYearBtn.width, frameHeightcreateSchoolYearBtn };
	int createSchoolYearBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
	bool createSchoolYearBtnAction = false;         // Button action should be activated
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		BeginDrawing();
		DrawText("WELCOME!", 670, 15, 40, DARKBLUE);

		DrawRectangleGradientEx(background, DARKBLUE, BLUE, SKYBLUE, WHITE);
		DrawRectangle(70, 170, 360, 750, WHITE);
		DrawRectangle(480, 170, 980, 750, WHITE);
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
			drawloginPage();
		}
		// Calculate button frame rectangle to draw depending on button state
		sourceReclogOutBtn.y = logOutBtnState * frameHeightlogOutBtn;
		DrawTextureRec(logOutBtn, sourceReclogOutBtn, { btnBoundslogOutBtn.x, btnBoundslogOutBtn.y }, WHITE); // Draw button frame
		////Create School Year Button Function------------------------------------------------------------------------------------------------------------
		mousePoint = GetMousePosition();
		createSchoolYearBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundscreateSchoolYearBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) createSchoolYearBtnAction = true;
		}
		else createSchoolYearBtnState = 0;
		if (createSchoolYearBtnAction) {
			createSchoolYearPage();
		}
		// Calculate button frame rectangle to draw depending on button state
		sourceReccreateSchoolYearBtn.y = createSchoolYearBtnState * frameHeightcreateSchoolYearBtn;
		DrawTextureRec(createSchoolYearBtn, sourceReccreateSchoolYearBtn, { btnBoundscreateSchoolYearBtn.x, btnBoundscreateSchoolYearBtn.y }, WHITE); // Draw button frame
		EndDrawing();
	}
	CloseWindow();
}

void ChangePasswordPage(const int screenWidth, const int screenHeight, account& CurrentUser) {
	Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();

	char OldPass[MAX_INPUT_CHARS + 1] = "\0";
	char NewPass[MAX_INPUT_CHARS + 1] = "\0";
	char NewPassConfirm[MAX_INPUT_CHARS + 1] = "\0";
	int letterCountOldPass = 0;
	int letterCountNewPass = 0;
	int letterCountNewPassConfirm = 0;
	Rectangle textBoxOldPass = { 477, 239,558,106 };
	Rectangle textBoxNewPass = { 477, 403,558,106 };
	Rectangle textBoxNewPassConfirm{ 477, 567, 558, 106 };
	bool mouseOnTextOldPass = false;
	bool mouseOnTextNewPass = false;
	bool mouseOnTextNewPassConfirm = false;
	int framesCounterOldPass = 0;
	int framesCounterNewPass = 0;
	int framesCounterNewPassConfirm = 0;

	bool isChangePassFalseDisplay = false;

	Rectangle background = { 0,0,1512,982 };

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

		DrawRectangleGradientEx(background, DARKBLUE, BLUE, SKYBLUE, WHITE);
		DrawRectangle(347, 173, 818, 630, WHITE);
		DrawRectangle(0, 0, 1512, 60, WHITE);
		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleRec(textBoxOldPass, LIGHTGRAY);
		DrawRectangleRec(textBoxNewPass, LIGHTGRAY);
		DrawRectangleRec(textBoxNewPassConfirm, LIGHTGRAY);
		DrawText("* Old Password", 477, 200, 30, DARKBLUE);
		DrawText("* New Password", 477, 364, 30, DARKBLUE);
		DrawText("* Confirm New Password", 477, 528, 30, DARKBLUE);

		////Buttons function-----------------------------------------------------------------------------------------------------------------------------------------
		if (CheckCollisionPointRec(GetMousePosition(), textBoxOldPass)) mouseOnTextOldPass = true;
		else mouseOnTextOldPass = false;
		if (CheckCollisionPointRec(GetMousePosition(), textBoxNewPass)) mouseOnTextNewPass = true;
		else mouseOnTextNewPass = false;
		if (CheckCollisionPointRec(GetMousePosition(), textBoxNewPassConfirm)) mouseOnTextNewPassConfirm = true;
		else mouseOnTextNewPassConfirm = false;

		if (mouseOnTextOldPass)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountOldPass < MAX_INPUT_CHARS))
				{
					OldPass[letterCountOldPass] = (char)key;
					OldPass[letterCountOldPass + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountOldPass++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountOldPass--;
				if (letterCountOldPass < 0) letterCountOldPass = 0;
				OldPass[letterCountOldPass] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextOldPass) framesCounterOldPass++;
		else framesCounterOldPass = 0;

		if (mouseOnTextNewPass)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountNewPass < MAX_INPUT_CHARS))
				{
					NewPass[letterCountNewPass] = (char)key;
					NewPass[letterCountNewPass + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountNewPass++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountNewPass--;
				if (letterCountNewPass < 0) letterCountNewPass = 0;
				NewPass[letterCountNewPass] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextNewPass) framesCounterNewPass++;
		else framesCounterNewPass = 0;

		if (mouseOnTextNewPassConfirm)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCountNewPassConfirm < MAX_INPUT_CHARS))
				{
					NewPassConfirm[letterCountNewPassConfirm] = (char)key;
					NewPassConfirm[letterCountNewPassConfirm + 1] = '\0'; // Add null terminator at the end of the string.
					letterCountNewPassConfirm++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountNewPassConfirm--;
				if (letterCountNewPassConfirm < 0) letterCountNewPassConfirm = 0;
				NewPassConfirm[letterCountNewPassConfirm] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextNewPassConfirm) framesCounterNewPassConfirm++;
		else framesCounterNewPassConfirm = 0;

		if (mouseOnTextOldPass) {
			DrawRectangleLines((int)textBoxOldPass.x, (int)textBoxOldPass.y, (int)textBoxOldPass.width, (int)textBoxOldPass.height, BLUE);
			DrawRectangleLines((int)textBoxOldPass.x - 1, (int)textBoxOldPass.y - 1, (int)textBoxOldPass.width + 2, (int)textBoxOldPass.height + 2, BLUE);
			DrawRectangleLines((int)textBoxOldPass.x - 2, (int)textBoxOldPass.y - 2, (int)textBoxOldPass.width + 4, (int)textBoxOldPass.height + 4, BLUE);
			isChangePassFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxOldPass.x, (int)textBoxOldPass.y, (int)textBoxOldPass.width, (int)textBoxOldPass.height, DARKGRAY);

		if (mouseOnTextNewPass) {
			DrawRectangleLines((int)textBoxNewPass.x, (int)textBoxNewPass.y, (int)textBoxNewPass.width, (int)textBoxNewPass.height, BLUE);
			DrawRectangleLines((int)textBoxNewPass.x - 1, (int)textBoxNewPass.y - 1, (int)textBoxNewPass.width + 2, (int)textBoxNewPass.height + 2, BLUE);
			DrawRectangleLines((int)textBoxNewPass.x - 2, (int)textBoxNewPass.y - 2, (int)textBoxNewPass.width + 4, (int)textBoxNewPass.height + 4, BLUE);
			isChangePassFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxNewPass.x, (int)textBoxNewPass.y, (int)textBoxNewPass.width, (int)textBoxNewPass.height, DARKGRAY);

		if (mouseOnTextNewPassConfirm) {
			DrawRectangleLines((int)textBoxNewPassConfirm.x, (int)textBoxNewPassConfirm.y, (int)textBoxNewPassConfirm.width, (int)textBoxNewPassConfirm.height, BLUE);
			DrawRectangleLines((int)textBoxNewPassConfirm.x - 1, (int)textBoxNewPassConfirm.y - 1, (int)textBoxNewPassConfirm.width + 2, (int)textBoxNewPassConfirm.height + 2, BLUE);
			DrawRectangleLines((int)textBoxNewPassConfirm.x - 2, (int)textBoxNewPassConfirm.y - 2, (int)textBoxNewPassConfirm.width + 4, (int)textBoxNewPassConfirm.height + 4, BLUE);
			isChangePassFalseDisplay = false;
		}
		else DrawRectangleLines((int)textBoxNewPassConfirm.x, (int)textBoxNewPassConfirm.y, (int)textBoxNewPassConfirm.width, (int)textBoxNewPassConfirm.height, DARKGRAY);

		DrawText(OldPass, 500, 270, 40, DARKBLUE);
		DrawText(NewPass, 500, 435, 40, DARKBLUE);
		DrawText(NewPassConfirm, 500, 600, 40, DARKBLUE);

		DrawText(TextFormat("%i/%i", letterCountOldPass, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", letterCountNewPass, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);
		DrawText(TextFormat("%i/%i", letterCountNewPassConfirm, MAX_INPUT_CHARS), 1050, 620, 20, DARKBLUE);
		////-------------------------------------------------------------------------------------------------------------------------

		mousePoint = GetMousePosition();
		confirmBtnAction = false;
		if (CheckCollisionPointRec(mousePoint, btnBoundsconfirmBtn)) {          // Check button state
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) confirmBtnAction = true;
		}
		else confirmBtnState = 0;
		if (confirmBtnAction) {
			if (usechangePassFunction(CurrentUser, OldPass, NewPass, NewPassConfirm) && OldPass[0] != '\0' && NewPass[0] != '\0' && NewPassConfirm[0] != '\0') {
				ProfilePage(screenWidth, screenHeight, CurrentUser);
			}
			else {
				isChangePassFalseDisplay = true;
			}
		}
		if (isChangePassFalseDisplay) DrawText("Please try again!", 477, 685, 20, RED);

		// Calculate button frame rectangle to draw depending on button state
		sourceRecconfirmBtn.y = confirmBtnState * frameHeightconfirmBtn;
		DrawTextureRec(confirmBtn, sourceRecconfirmBtn, { btnBoundsconfirmBtn.x, btnBoundsconfirmBtn.y }, WHITE); // Draw button frame
		EndDrawing();
	}
	CloseWindow();
}

void createSchoolYearPage() {
	Rectangle background = { 0,0,1512,982 };

	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, DARKBLUE);
		DrawRectangleGradientEx(background, DARKBLUE, BLUE, SKYBLUE, WHITE);

		DrawRectangleGradientH(347, 173, 818, 560, DARKBLUE,DARKPURPLE);

		EndDrawing();
	}
	CloseWindow();
}
