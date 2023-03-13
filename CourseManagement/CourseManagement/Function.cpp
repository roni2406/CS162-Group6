#include <iostream>
#include <fstream>
#include <raylib.h>
#include "Function.h"

using namespace std;
#define MAX_INPUT_CHARS 20

//FRONT_END--------------------------------------------------------
void drawloginPage() {
	const int screenWidth = 1512;
	const int screenHeight = 982;
	InitWindow(screenWidth, screenHeight, "MainPage");
	//Initialize-------------------------------------------------------
	char name[21] = "\0";
	char pass[21] = "\0";
	int letterCountUsername = 0;
	int letterCountPassword = 0;

	Rectangle textBoxUsername = { 477, 239,558,106 };
	Rectangle textBoxPassword = { 477, 403,558,106 };

	Texture2D background;
	background = LoadTexture("background.png");

	bool mouseOnTextUsername = false;
	bool mouseOnTextPassword = false;

	int framesCounterUsername = 0;
	int framesCounterPassword = 0;

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
	fin.open("input.txt");
	loginData* login_data = new loginData[100];
	int n;
	inputData(login_data, n, fin);
	fin.close();

	loginData inputLoginData;

	Vector2 mousePoint = { 0.0f, 0.0f };


	SetTargetFPS(40);
	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//Draw--------------------------------------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose()) {
		BeginDrawing();

		DrawTexture(background, 0, 60, WHITE);
		DrawRectangle(347, 173, 818, 540, WHITE);
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
		DrawText(pass, 500, 430, 40, DARKBLUE);

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
			if (login(login_data, n, inputLoginData)) {
				ProfilePage(screenWidth, screenHeight);
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
			SignUpPage(screenWidth, screenHeight);
		}

		sourceRecsignupButton.y = signupbtnState * frameHeightsignupButton;
		DrawTextureRec(signupButton, sourceRecsignupButton, { btnBoundssignupButton.x, btnBoundssignupButton.y }, WHITE);

		EndDrawing();
	}

	CloseWindow();
}

void ProfilePage(const int screenWidth, const int screenHeight) {
	CloseWindow();
	InitWindow(screenWidth, screenHeight, "profile");
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();

		DrawRectangle(0, 0, 1512, 60, DARKGREEN);
		DrawText(" Welcome, Khang!", 30, 20, 20, WHITE);
		DrawText("Log Out", 1300, 20, 20, WHITE);
		DrawText("Change Password", 1000, 20, 20, WHITE);


		Texture2D avatar;
		avatar = LoadTexture("avatar.png");
		DrawTexture(avatar, 45, 80, WHITE);

		DrawText("NGUYEN VINH KHANG", 260, 140, 50, BLACK);
		DrawText("nvk01052004@gmail.com", 260, 190, 28, BLACK);

		EndDrawing();
	}
	CloseWindow();
}

void SignUpPage(const int screenWidth, const int screenHeight) {
	CloseWindow();
	InitWindow(screenWidth, screenHeight, "Sign Up");
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		EndDrawing();
	}
	CloseWindow();
}




//BACK_END---------------------------------------------------------
////For login and sign up-------------------------------------------------------------------------------------
void input1Data(loginData& data, ifstream& fin) {
	data.userName = new char[20];
	fin.get(data.userName, 20, '\n');
	fin.ignore(100, '\n');
	data.password = new char[20];
	fin.get(data.password, 20, '\n');
}

void inputData(loginData login_data[], int& n, ifstream& fin) {
	n = 0;
	while (!fin.eof()) {
		input1Data(login_data[n], fin);
		fin.ignore(100, '\n');
		++n;
	}
}

bool checkLoginData(loginData data1, loginData data2) {
	bool checkUserName = false;
	if (strcmp(data1.userName, data2.userName) == 0) {
		checkUserName = true;
	}
	bool checkPassword = false;
	if (strcmp(data1.password, data2.password) == 0) {
		checkPassword = true;
	}
	if (checkUserName && checkPassword) {
		return true;
	}
	else {
		return false;
	}
}

bool login(loginData login_data[], int n, loginData inputLoginData) {
	for (int i = 0; i < n; i++) {
		if (checkLoginData(login_data[i], inputLoginData)) {
			return true;
		}
	}
	return false;
}

void addinfo(loginData person, char* filename, ofstream& fout)
{
	fout.open(filename, ios::app);
	fout << person.userName << endl;
	fout << person.password << endl;
}