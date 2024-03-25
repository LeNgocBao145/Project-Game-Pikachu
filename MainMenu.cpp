#include "function.h"
#include "ConsoleScreen.h"

void moveToPosition(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position{};
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(console, position);
}

int showMainMenu(bool soundBackground, bool soundEffect)
{
	system("cls");

	createScreen(0);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	playMusicBackground(soundBackground);


	showTitlePokemon();


	int choice = 1;
	int key = 0;

	while (true)
	{


		if (choice == 1)
		{
			SetConsoleTextAttribute(console, 7 * 16);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 15 + i);
				cout << "             " << endl;
			}

			moveToPosition(79, 16);
			SetConsoleTextAttribute(console, 7 * 16 + 5);
			cout << "PLAY" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 7);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 15 + i);
				cout << "             " << endl;
			}

			moveToPosition(79, 16);
			SetConsoleTextAttribute(console, 5);
			cout << "PLAY" << endl;
		}

		if (choice == 2)
		{
			SetConsoleTextAttribute(console, 7 * 16);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 19 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 20);
			SetConsoleTextAttribute(console, 7 * 16 + 6);
			cout << "GAME MODE" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 7);


			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 19 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 20);
			SetConsoleTextAttribute(console, 6);
			cout << "GAME MODE" << endl;
		}

		if (choice == 3)
		{
			SetConsoleTextAttribute(console, 7 * 16);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 23 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 24);
			SetConsoleTextAttribute(console, 7 * 16 + 4);
			cout << "SETTINGS" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 7);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 23 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 24);
			SetConsoleTextAttribute(console, 4);
			cout << "SETTINGS" << endl;
		}

		if (choice == 4)
		{
			SetConsoleTextAttribute(console, 7 * 16);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 27 + i);
				cout << "             " << endl;
			}

			moveToPosition(76, 28);
			SetConsoleTextAttribute(console, 7 * 16 + 2);
			cout << "LEADERBOARD" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 7);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 27 + i);
				cout << "             " << endl;
			}

			moveToPosition(76, 28);
			SetConsoleTextAttribute(console, 2);
			cout << "LEADERBOARD" << endl;
		}

		if (choice == 5)
		{
			SetConsoleTextAttribute(console, 7 * 16);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 31 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 32);
			SetConsoleTextAttribute(console, 7 * 16 + 9);
			cout << "EXIT GAME" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 7);



			for (int i = 0; i < 3; i++)
			{
				moveToPosition(75, 31 + i);
				cout << "             " << endl;
			}

			moveToPosition(77, 32);
			SetConsoleTextAttribute(console, 9);
			cout << "EXIT GAME" << endl;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		int tmp = _getch();

		if (tmp != 224 && tmp != 0)
		{
			if (tmp == PRESS_ENTER)
			{
				system("cls");
				return choice;
			}
		}
		else
		{
			key = _getch();

			switch (key)
			{
			case PRESS_UP:

				if (choice > 1)
				{
					choice--;
				}
				else
				{
					choice = 5;
				}

				break;

			case PRESS_DOWN:

				if (choice < 5)
				{
					choice++;
				}
				else
				{
					choice = 1;
				}

				break;

			default:
				break;
			}

		}

	}
}