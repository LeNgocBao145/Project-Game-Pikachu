#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ConsoleScreen.h"
#include "function.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 13

using namespace std;

int main() {
	Account* player;
	
	Player alpha;

	Player* ranker{};

	int quantity = 0;

	bool soundBackground = 1, soundEffect = 1;

	int quantityAccount = 0;
	
	createScreen(0);

	readFileAccount(player, quantityAccount);
	

	int choice1 = showLogIn();
	
	switch (choice1)
	{
		case 1:
			signInAccount(player, alpha, quantityAccount);
			break;
		case 2:
			signUpAccount(alpha);
			break;
		default:
			cout << "LUA CHON KHONG HOP LE!" << endl;
	}

	readLeaderBoard(ranker, alpha, quantity);
	
	system("cls");

	int choice;

	while ((choice = showMainMenu(soundBackground, soundEffect)) != 5)
	{
		switch (choice)
		{
			case 1:
				createEasyRound(ranker, quantity, alpha, soundEffect, soundBackground);
				break;
			case 2:
				showGameMode(ranker, quantity, alpha, soundEffect, soundBackground);
				break;
			case 3:
				editSoundSettings(soundBackground, soundEffect);
				break;
			case 4:
				showLeaderBoard(ranker, quantity, alpha);
				break;
			case 5:
				return 0;
				
			default:
				cout << "LUA CHON KHONG HOP LE!" << endl;
		}

	}
	
	delete[] player;

	return 0;
}
