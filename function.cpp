#include "function.h"

void showTitlePikachu()
{
	moveToPosition(52, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << " ______    __   __  ___      ___       ______   __    __   __    __";
	moveToPosition(52, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "|   _  \\  |  | |  |/  /     /   \\     /      | |  |  |  | |  |  |  |";
	moveToPosition(52, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "|  |_)  | |  | |  '  /     /  ^  \\   |   ----' |  |__|  | |  |  |  |";
	moveToPosition(52, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |      |   __   | |  |  |  |";
	moveToPosition(52, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "|  |      |  | |  .  \\   /  _____  \\ |   ----. |  |  |  | |   --   |";
	moveToPosition(52, 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______| |__|  |__|  \\______/";
}

void showTitlePokemon()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "		 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "		| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "		| |   ______     | || |     ____     | || |  ___  ____   | || |  _________   | || | ____    ____ | || |     ____     | || | ____  _____  | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "		| |  |_   __ \\   | || |   .'    `.   | || | |_  ||_  _|  | || | |_   ___  |  | || ||_   \\  /   _|| || |   .'    `.   | || ||_   \\ | _ _| | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "		| |    | |__) |  | || |  /  .--.  \\  | || |   | |_/ /    | || |   | |_  \\_|  | || |  |   \\/   |  | || |  /  .--.  \\  | || |  |   \\ | |   | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << "		| |    |  ___/   | || |  | |    | |  | || |   |  __'.    | || |   |  _|  _   | || |  | |\\  /| |  | || |  | |    | |  | || |  | |\\ \\| |   | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "		| |   _| |_      | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |  _| |___/ |  | || | _| |_\\/_| |_ | || |  \\  `--'  /  | || | _| |_\\   |_  | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "		| |  |_____|     | || |   `.____.'   | || | |____||____| | || | |_________|  | || ||_____||_____|| || |   `.____.'   | || ||_____|\\____| | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "		| |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "		| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "		 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
}

int showLogIn()
{
    showTitlePikachu();
	drawRectangle(76, 18, 19, 8);

    int choice = 1;
    int key = 0;

    while (true) {

           

            if (choice == 1) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

                for (int i = 0; i < 3; i++) {
                    moveToPosition(78, 19 + i);
                    cout << "               " << endl;
                }

                moveToPosition(82, 20);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
                cout << "Sign In";
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                for (int i = 0; i < 3; i++) {
                    moveToPosition(77, 19 + i);
                    cout << "                " << endl;
                }

                moveToPosition(82, 20);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                cout << "Sign In";
            }

            if (choice == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

                for (int i = 0; i < 3; i++) {
                    moveToPosition(78, 22 + i);
                    cout << "               " << endl;
                }

                moveToPosition(82, 23);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
                cout << "Sign Up";
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                for (int i = 0; i < 3; i++) {
                    moveToPosition(78, 22 + i);
                    cout << "               " << endl;
                }

                moveToPosition(82, 23);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Sign Up";
            }
            

            int temp = _getch();
            
                if (temp != 224 && temp != 0)
                {
                    if (temp == PRESS_ENTER) {
                        system("cls");
                        return choice;
                    }
                }
                else {
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
							choice = 2;
						}

						break;

					case PRESS_DOWN:

						if (choice < 2)
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

void drawRectangle(int x, int y, int width, int height) {
    moveToPosition(x, y);
    cout << char(201);  // góc trên bên trái

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205);  // du?ng ngang
    }

    cout << char(187);  // góc trên bên ph?i

    for (int i = 1; i < height - 1; ++i) {
        moveToPosition(x, y + i);
        cout << char(186);  // du?ng d?c bên trái
        moveToPosition(x + width - 1, y + i);
        cout << char(186);  // du?ng d?c bên ph?i
    }

    moveToPosition(x, y + height - 1);
    cout << char(200);  // góc du?i bên trái

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205);  // du?ng ngang
    }

    cout << char(188);  // góc du?i bên ph?i
}