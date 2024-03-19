#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <winuser.h>


#define PRESS_UP 72
#define PRESS_DOWN 80
#define PRESS_LEFT 75
#define PRESS_RIGHT 77
#define PRESS_ENTER 13
#define PRESS_ESC 27

using namespace std;

void moveToPosition(int x, int y);
int showMainMenu();

void playMusicEffect();
void playMusicBackground();