#include "ConsoleScreen.h"
#include "function.h"

void hideCursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(console, &cursor);
	cursor.bVisible = visible;
	SetConsoleCursorInfo(console, &cursor);
}


void setSizeOfScreen()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
}


void createScreen(bool visible)
{
	
	setSizeOfScreen();
	hideCursor(visible);
	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
}
