#include "ConsoleScreen.h"
#include "function.h"

void hideCursor()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(console, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(console, &cursor);
}


void setSizeOfScreen()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
}


void createScreen()
{
	
	setSizeOfScreen();
	hideCursor();
	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
}
