#include "Function.h"
void Button0::workbutton(Vector2 mousePoint) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && hidden) {
			action = true;
			hidden = false;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !hidden) {
			hidden = true;
		}
	}
	else state = 0;
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}
void Button1::workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser)) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else state = 0;
	if (action) {
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser);
	}
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}
void Button1_5::workbutton(Vector2 mousePoint, account& CurrentUser) {
	if (CheckCollisionPointRec(mousePoint, button)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else action = false;
}
void Button2::workbutton(Vector2 mousePoint, account& CurrentUser, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser)) {
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
void Button3::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a)) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else state = 0;
	if (action) {
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a);
	}
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}
void Button4::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a)) {
	if (CheckCollisionPointRec(mousePoint, button) && state) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else action = false;
	if (action && state)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a);
	}
}

void Button5::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b)) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else state = 0;
	if (action) {
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a, b);
	}
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}
void Button6::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b)) {
	if (CheckCollisionPointRec(mousePoint, button)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else action = false;
	if (action)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a, b);
	}
}
void Button7::workbutton(Vector2 mousePoint, account& CurrentUser, course& d, char*& a, char*& b, 
	void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b, course& d)) {
	if (CheckCollisionPointRec(mousePoint, btnBounds)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else state = 0;
	if (action) {
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a, b, d);
	}
	// Calculate button frame rectangle to draw depending on button state
	sourceRec.y = state * frameHeight;
	DrawTextureRec(texture, sourceRec, { btnBounds.x, btnBounds.y }, WHITE); // Draw button frame
}
void Button8::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, course& c, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b, course& c)) {
	if (CheckCollisionPointRec(mousePoint, button) && state) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			action = true;
			action1 = false;
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
			x = GetMouseX();
			y = GetMouseY();
			action1 = true;
			action = false;
		}
	}
	else {
		action = false;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { float(x),float(y),160,25 })) {
		action = false;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			remove = true;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), { float(x),float(y) + 25,160,25 })) {
		action = false;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			update = true;
		}
	}
	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action1 = false;
	if (action && state)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a, b, c);
	}
}

void Button9::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, char*& b, course& c, student& s, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a, char*& b, course& c, student& s)) {
	if (CheckCollisionPointRec(mousePoint, button) && state && state1) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			action = true;
			action1 = false;
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
			x = GetMouseX();
			y = GetMouseY();
			action1 = true;
			action = false;
		}
	}
	else {
		action = false;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { float(x),float(y),160,25 })) {
		action = false;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			remove = true;
		}
	}
	else if (CheckCollisionPointRec(GetMousePosition(), { float(x),float(y) + 25,160,25 })) {
		action = false;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			update = true;
		}
	}
	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action1 = false;
	if (action && state)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a, b, c, s);
	}
}

void Button10::workbutton(Vector2 mousePoint) {
	if (CheckCollisionPointRec(mousePoint, button)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && state && state1) {
			action = true;
		}
	}
}
// Textbox
void Textbox1::worktextbox(bool& somethingfalsedisplay) {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) mouseontextbox = true;
	else mouseontextbox = false;
	if (mouseontextbox)
	{
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
		if (IsKeyDown(KEY_BACKSPACE)) {
			if (delay_time < BACKSPACE_DELAY) {
				delay_time += GetFrameTime();
			}
			else {
				lettercount--;
				if (lettercount < 0) lettercount = 0;
				text[lettercount] = '\0';
			}
		}
		else delay_time = 0.0f;
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_V)) {
			lettercount = 0;
			const char* a = GetClipboardText();
			if (a[0] == '\'') {
				for (int i = 1; i < strlen(a) - 1; ++i) {
					text[lettercount++] = a[i];
				}
				text[lettercount] = '\0';
			}
			else {
				for (int i = 0; i < strlen(a); ++i) {
					text[lettercount++] = a[i];
				}
				text[lettercount] = '\0';
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_Z)) {
			text[0] = '\0';
			lettercount = 0;
		}
	}
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
		if (IsKeyDown(KEY_BACKSPACE)) {
			if (delay_time < BACKSPACE_DELAY) {
				delay_time += GetFrameTime();
			}
			else {
				lettercount--;
				if (lettercount < 0) lettercount = 0;
				text[lettercount] = '\0';

				lettercounthidden--;
				if (lettercounthidden < 0) lettercounthidden = 0;
				hiddentext[lettercounthidden] = '\0';
			}
		}
		else delay_time = 0.0f;
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_V)) {
			lettercounthidden = 0;
			lettercount = 0;
			const char* a = GetClipboardText();
			if (a[0] == '\'') {
				for (int i = 1; i < strlen(a) - 1; ++i) {
					text[lettercount++] = a[i];
					hiddentext[lettercounthidden++] = '*';
				}
				text[lettercount] = '\0';
				hiddentext[lettercounthidden] = '\0';
			}
			else {
				for (int i = 0 ; i < strlen(a); ++i) {
					text[lettercount++] = a[i];
					hiddentext[lettercounthidden++] = '*';
				}
				text[lettercount] = '\0';
				hiddentext[lettercounthidden] = '\0';
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_Z)) {
			text[0] = '\0';
			hiddentext[0] = '\0';
			lettercount = 0;
			lettercounthidden = 0;
		}
	}

	if (mouseontextbox) {
		DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, BLUE);
		DrawRectangleLines((int)textbox.x - 1, (int)textbox.y - 1, (int)textbox.width + 2, (int)textbox.height + 2, BLUE);
		DrawRectangleLines((int)textbox.x - 2, (int)textbox.y - 2, (int)textbox.width + 4, (int)textbox.height + 4, BLUE);
		somethingfalsedisplay = false;
	}
	else DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, DARKGRAY);
}

void Textbox3::worktextbox(bool& somethingfalsedisplay) {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) mouseontextbox = true;
	else mouseontextbox = false;
	if (mouseontextbox)
	{
		// Get char pressed (unicode character) on the queue
		int key = GetCharPressed();

		// Check if more characters have been pressed on the same frame
		while (key > 0)
		{
			// NOTE: Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125) && (lettercount < 4))
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
		if (IsKeyDown(KEY_BACKSPACE)) {
			if (delay_time < BACKSPACE_DELAY) {
				delay_time += GetFrameTime();
			}
			else {
				lettercount--;
				if (lettercount < 0) lettercount = 0;
				text[lettercount] = '\0';
			}
		}
		else delay_time = 0.0f;
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_V)) {
			lettercount = 0;
			const char* a = GetClipboardText();
			if (a[0] == '\'') {
				for (int i = 1; i < strlen(a) - 1; ++i) {
					text[lettercount++] = a[i];
				}
				text[lettercount] = '\0';
			}
			else {
				for (int i = 0; i < strlen(a); ++i) {
					text[lettercount++] = a[i];
				}
				text[lettercount] = '\0';
			}
		}
		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_Z)) {
			text[0] = '\0';
			lettercount = 0;
		}

	}
	if (mouseontextbox) {
		DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, BLUE);
		DrawRectangleLines((int)textbox.x - 1, (int)textbox.y - 1, (int)textbox.width + 2, (int)textbox.height + 2, BLUE);
		DrawRectangleLines((int)textbox.x - 2, (int)textbox.y - 2, (int)textbox.width + 4, (int)textbox.height + 4, BLUE);
		somethingfalsedisplay = false;
	}
	else DrawRectangleLines((int)textbox.x, (int)textbox.y, (int)textbox.width, (int)textbox.height, DARKGRAY);

}