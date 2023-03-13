#include <iostream>
#include <fstream>
#include "raylib.h"
#include <conio.h>
#include <string> 
#define MAX_INPUT_CHARS 20
using namespace std;

void ProfilePage(const int screenWidth, const int screenHeight);
struct loginData {
    char* userName;
    char* password;
};

void input1Data(loginData& data) {
    data.userName = new char[20];
    cin.get(data.userName, 20, '\n');
    cin.ignore(100, '\n');
    data.password = new char[20];
    cin.get(data.password, 20, '\n');
}

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



int main()
{
    const int screenWidth = 1512;
    const int screenHeight = 982;
    InitWindow(screenWidth, screenHeight, "basic window");

    // Initialization
    //--------------------------------------------------------------------------------------

    char name[21] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    char pass[21] = "\0";
    int letterCount = 0;
    int letterCount2 = 0;

    Rectangle textBox = { screenWidth / 2.0f - 170, 610, 380, 50 };
    Rectangle textBox2 = { screenWidth / 2.0f - 170, 680, 380, 50 };

    bool mouseOnText = false;
    bool mouseOnText2 = false;

    int framesCounter = 0;
    int framesCounter2 = 0;
    SetTargetFPS(40);               // Set our game to run at 10 frames-per-second

    //--------------------------------------------------------------------------------------
    // Define frame rectangle for drawing
    Texture2D button = LoadTexture("loginButton.png");
    float frameHeight = (float)button.height ;
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };
    //--------------------------------------------------------------------------------------
    // Define button bounds on screen
    Rectangle btnBounds = { screenWidth / 2.0f - button.width / 2.0f, 760, (float)button.width, frameHeight };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f };

    ifstream fin;
    fin.open("input.txt");
    loginData login_data[100];
    int n;
    inputData(login_data, n, fin);
    fin.close();

    loginData inputLoginData;


    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangle(0, 0, 1512, 60, DARKGREEN);

        DrawText("  Call us : (028) 3835 4266         E - mail : info@fit.hcmus.edu.vn", 0, 20, 20, WHITE);
        DrawText("You are not logged in.", 1200, 20, 20, WHITE);

        Texture2D logo;
        logo = LoadTexture("logo.png");
        DrawTexture(logo, 35, 75, WHITE);

        DrawRectangle(378, 250, 756, 275, LIGHTGRAY);

        Texture2D logo2;
        logo2 = LoadTexture("logo 2.png");
        DrawTexture(logo2, 520, 260, WHITE);


        // Update
        //----------------------------------------------------------------------------------
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;
        if (CheckCollisionPointRec(GetMousePosition(), textBox2)) mouseOnText2 = true;
        else mouseOnText2 = false;

        if (mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;


        if (mouseOnText2)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount2 < MAX_INPUT_CHARS))
                {
                    pass[letterCount2] = (char)key;
                    pass[letterCount2 + 1] = '\0'; // Add null terminator at the end of the string.
                    letterCount2++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount2--;
                if (letterCount2 < 0) letterCount2 = 0;
                pass[letterCount2] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        if (mouseOnText2) framesCounter2++;
        else framesCounter2 = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        //BeginDrawing();

        //ClearBackground(RAYWHITE);

        DrawText("LOGIN", 705, 550, 40, DARKGREEN);

        DrawRectangleRec(textBox, LIGHTGRAY);
        DrawRectangleRec(textBox2, LIGHTGRAY);

        if (mouseOnText) {
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGREEN);
            DrawRectangleLines((int)textBox.x - 1, (int)textBox.y - 1, (int)textBox.width + 2, (int)textBox.height + 2, DARKGREEN);
            DrawRectangleLines((int)textBox.x - 2, (int)textBox.y - 2, (int)textBox.width + 4, (int)textBox.height + 4, DARKGREEN);
        }
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        if (mouseOnText2) {
            DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, DARKGREEN);
            DrawRectangleLines((int)textBox2.x - 1, (int)textBox2.y - 1, (int)textBox2.width + 2, (int)textBox2.height + 2, DARKGREEN);
            DrawRectangleLines((int)textBox2.x - 2, (int)textBox2.y - 2, (int)textBox2.width + 4, (int)textBox2.height + 4, DARKGREEN);
        }
        else DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, DARKGRAY);

        DrawText(name, (int)textBox.x + 10, (int)textBox.y + 10, 30, DARKGREEN);
        DrawText(pass, (int)textBox2.x + 10, (int)textBox2.y + 10, 30, DARKGREEN);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 1000, 625, 20, DARKGRAY);
        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount2, MAX_INPUT_CHARS), 1000, 695, 20, DARKGRAY);

        if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 12 + MeasureText(name, 30), (int)textBox.y + 10, 30, DARKGREEN);
            }
        }

        if (mouseOnText2)
        {
            if (letterCount2 < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter2 / 20) % 2) == 0) DrawText("_", (int)textBox2.x + 12 + MeasureText(pass, 30), (int)textBox2.y + 10, 30, DARKGREEN);
            }
        }


        mousePoint = GetMousePosition();
        btnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        inputLoginData.userName = _strdup(name);
        inputLoginData.password = _strdup(pass);

        if (btnAction && login(login_data,n,inputLoginData))
        {
            ProfilePage( screenWidth, screenHeight);
        }

        // Calculate button frame rectangle to draw depending on button state
        sourceRec.y = btnState * frameHeight;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        ClearBackground(RAYWHITE);

        DrawTextureRec(button, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame


        EndDrawing();
    }
    CloseWindow();

    return 0;
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

