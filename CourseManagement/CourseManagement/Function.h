#pragma once

#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>
#include "back_end.h"
using namespace std;

void drawloginPage();
void SignUpPage(const int screenWidth, const int screenHeight, account& CurrentUser);
void ProfilePage(const int screenWidth, const int screenHeight, account CurrentUser);
void ChangePasswordPage(const int screenWidth, const int screenHeight, account& CurrentUser);

