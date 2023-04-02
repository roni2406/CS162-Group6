#include "Function.h"

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

void Button4::workbutton(Vector2 mousePoint, account& CurrentUser, char*& a, void(*func)(const int screenWidth, const int screenHeight, account& CurrentUser, char*& a)) {
	if (CheckCollisionPointRec(mousePoint, button)) {          // Check button state
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
	}
	else action = false;
	if (action)
	{
		EndDrawing();
		func(screenWidth, screenHeight, CurrentUser, a);
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