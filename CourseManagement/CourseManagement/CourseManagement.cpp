#include <iostream>
#include <raylib.h>
#define MAX_INPUT_CHARS 20

void drawloginPage();
void ProfilePage(const int screenWidth, const int screenHeight);

int main()
{

    drawloginPage();

    return 0;
}

void drawloginPage() {
    const int screenWidth = 1512;
    const int screenHeight = 982;
    InitWindow(screenWidth, screenHeight, "MainPage");
    //Initialize-------------------------------------------------------
    char name[21] = "\0";
    char pass[21] = "\0";
    int letterCountUsername = 0;
    int letterCountPassword = 0;

    Rectangle textBoxUsername = { 477, 239,558,106};
    Rectangle textBoxPassword = { 477, 403,558,106};

    Texture2D background;
    background = LoadTexture("background.png");
    
    bool mouseOnTextUsername = false;
    bool mouseOnTextPassword = false;

    int framesCounterUsername = 0;
    int framesCounterPassword = 0;

    Texture2D loginButton;
    loginButton = LoadTexture("loginButton.png");

    float frameHeightloginButton = (float)loginButton.height;
    Rectangle sourceRecloginButton = { 0, 0, (float)loginButton.width, frameHeightloginButton };
    //--------------------------------------------------------------------------------------
    // Define button bounds on screen
    Rectangle btnBoundsloginButton = { (screenWidth / 2.0f - loginButton.width / 2.0f)-10, 550, (float)loginButton.width, frameHeightloginButton };

    int loginbtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool loginbtnAction = false;         // Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f };


    SetTargetFPS(40);

    //Draw-------------------------------------------------------------
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
        }
        else DrawRectangleLines((int)textBoxUsername.x, (int)textBoxUsername.y, (int)textBoxUsername.width, (int)textBoxUsername.height, DARKGRAY);

        if (mouseOnTextPassword) {
            DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, BLUE);
            DrawRectangleLines((int)textBoxPassword.x - 1, (int)textBoxPassword.y - 1, (int)textBoxPassword.width + 2, (int)textBoxPassword.height + 2, BLUE);
            DrawRectangleLines((int)textBoxPassword.x - 2, (int)textBoxPassword.y - 2, (int)textBoxPassword.width + 4, (int)textBoxPassword.height + 4, BLUE);
        }
        else DrawRectangleLines((int)textBoxPassword.x, (int)textBoxPassword.y, (int)textBoxPassword.width, (int)textBoxPassword.height, DARKGRAY);

        DrawText(name, 500, 270, 40, DARKBLUE);
        DrawText(pass, 500, 430, 40, DARKBLUE);

        DrawText(TextFormat("%i/%i", letterCountUsername, MAX_INPUT_CHARS), 1050, 280, 20, DARKBLUE);
        DrawText(TextFormat("%i/%i", letterCountPassword, MAX_INPUT_CHARS), 1050, 450, 20, DARKBLUE);

        mousePoint = GetMousePosition();
        loginbtnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, btnBoundsloginButton))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) loginbtnState = 2;
            else loginbtnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) loginbtnAction = true;
        }
        else loginbtnState = 0;

       /* inputLoginData.userName = _strdup(name);
        inputLoginData.password = _strdup(pass);*/

        if (loginbtnAction)
        {
            ProfilePage(screenWidth, screenHeight);
        }

        // Calculate button frame rectangle to draw depending on button state
        sourceRecloginButton.y = loginbtnState * frameHeightloginButton;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        ClearBackground(RAYWHITE);

        DrawTextureRec(loginButton, sourceRecloginButton, { btnBoundsloginButton.x, btnBoundsloginButton.y }, WHITE); // Draw button frame
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