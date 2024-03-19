#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ConsoleScreen.h"
#include "function.h"


using namespace std;




int main() {

	createScreen();

	int choice;

	while ((choice = showMainMenu()) != 5)
	{
		switch (choice)
		{
			case 1:

			case 2:

			case 3:

			case 4:

			case 5:

			default:
				cout << "LUA CHON KHONG HOP LE!" << endl;
		}
	}
	


	return 0;
}
