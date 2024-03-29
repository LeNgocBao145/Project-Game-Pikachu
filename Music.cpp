#include "function.h"

void playMusicBackground(bool soundBackground)
{
	if (soundBackground)
	{
		PlaySound(TEXT("NoiNhoTuaThienHa.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else
	{
		PlaySound(0, 0, 0);
	}
}

void playMusicRound(bool soundBackground)
{
    if (soundBackground)
    {
        PlaySound(TEXT("videoplayback.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else
    {
        PlaySound(0, 0, 0);
    }
}

void playWonEffect(bool soundEffect)
{
    if (soundEffect)
    {
        PlaySound(TEXT("Victory - Sound Effect (Download).wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
        PlaySound(0, 0, 0);
    }
}

void playLoseEffect(bool soundEffect)
{
    if (soundEffect)
    {
        PlaySound(TEXT("Lose sound effects.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
        PlaySound(0, 0, 0);
    }
}

void editSoundEffect(bool& sound)
{
    int choice = 1;
    int key = 0;

    //drawRectangle(36, 5, 100, 30);
    drawRectangle(50, 20, 20, 5);
    drawRectangle(100, 20, 20, 5);



    while (true) {

        if (choice == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(59, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "ON";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(59, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "ON";
        }

        if (choice == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(109, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "OFF";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(109, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "OFF";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        int temp = _getch();

        if (temp != 224 && temp != 0)
        {
            if (temp == PRESS_ENTER) {
                system("cls");
                break;
            }
        }
        else {
            key = _getch();

            switch (key)
            {
            case PRESS_LEFT:

                if (choice > 1)
                {
                    choice--;
                }
                else
                {
                    choice = 2;
                }

                break;

            case PRESS_RIGHT:

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

    if (choice == 1)
    {
        sound = true;
    }
    else
    {
        sound = false;
    }
}

void editMusicBackground(bool& sound)
{
    int choice = 1;
    int key = 0;

    //drawRectangle(36, 5, 100, 30);
    drawRectangle(50, 20, 20, 5);
    drawRectangle(100, 20, 20, 5);



    while (true) {

        if (choice == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(59, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "ON";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(59, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "ON";
        }

        if (choice == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(109, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "OFF";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 21 + i);
                cout << "                  " << endl;
            }

            moveToPosition(109, 22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "OFF";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        int temp = _getch();

        if (temp != 224 && temp != 0)
        {
            if (temp == PRESS_ENTER) {
                system("cls");
                break;
            }
        }
        else {
            key = _getch();

            switch (key)
            {
            case PRESS_LEFT:

                if (choice > 1)
                {
                    choice--;
                }
                else
                {
                    choice = 2;
                }

                break;

            case PRESS_RIGHT:

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

    if (choice == 1)
    {
        sound = true;
    }
    else
    {
        sound = false;
    }
}

void editSoundSettings(bool& soundBackground, bool& soundEffect)
{
    int choice3 = showSoundSettings();

    switch (choice3)
    {
         case 1:
             editMusicBackground(soundBackground);
             break;
         case 2:
             editSoundEffect(soundEffect);
             break;
         case 3:
             break;
         default:
             cout << "LUA CHON KHONG HOP LE!" << endl;
    }
}

int showSoundSettings()
{
    showTitlePikachu();

    int choice = 1;
    int key = 0;

    drawRectangle(50, 25, 20, 5);
    drawRectangle(100, 25, 20, 5);

    while (true) {

        if (choice == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(52, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "MUSIC BACKGROUND";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(52, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "MUSIC BACKGROUND";
        }

        if (choice == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(104, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "SOUND EFFECT";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(104, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "SOUND EFFECT";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        int temp = _getch();

        if (temp != 224 && temp != 0)
        {
            if (temp == PRESS_ENTER) {
                system("cls");
                return choice;
            }
            else if (temp == PRESS_ESC)
            {
                system("cls");
                return 3;
            }
        }
        else {
            key = _getch();

            switch (key)
            {
            case PRESS_LEFT:

                if (choice > 1)
                {
                    choice--;
                }
                else
                {
                    choice = 2;
                }

                break;

            case PRESS_RIGHT:

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