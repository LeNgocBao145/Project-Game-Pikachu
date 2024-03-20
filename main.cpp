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



void readFileAccount(Account* &player, int& quantityAccount, fstream& file)
{

	string line;

	file.open("player.txt", ios::in);

	if (file.is_open())
	{
		while (!file.eof())
		{

			getline(file, line);

			if (line.length() == 0)
			{
				break;
			}
			quantityAccount++;
		}

	}
	else
	{
		cout << "File bi loi!" << endl;
	}

	file.close();
	string tmp;
	file.open("player.txt");

	if (file.is_open())
	{
		player = new Account[quantityAccount];
		for (int i = 0; i < quantityAccount; i++)
		{
			getline(file, line);
			istringstream ss(line);
			getline(ss, player[i].username, ',');
			getline(ss, player[i].password, ',');
		}

	}

	file.close();
}

//void writeFileAccount(int& quantityAccount, fstream& Account)
//{
//	quantityAccount++;
//
//	string Username;
//	string Password;
//
//	cin.ignore();
//	cout << "Nhap ten tai khoan: ";
//	getline(cin, Username);
//	cout << "Nhap mat khau: ";
//	getline(cin, Password);
//
//	Account.open("Account.txt", ios::app);
//
//	if (Account.is_open())
//	{
//		Account << endl;
//		Account << Username << "," << Password;
//	}
//
//	Account.close();
//}

bool checkIsExistAccount(Account* player, int quantityAccount, string username, string password)
{
	for (int i = 0; i < quantityAccount; i++)
	{
		if (username.compare(player[i].username) == 0 && password.compare(player[i].password) == 0)
		{
			return true;
		}
	}

	return false;
}

void signInAccount(Account* player, int quantityAccount) {
	createScreen(1);

	string username;
	string password;

	drawRectangle(70, 18, 30, 10);


	moveToPosition(74, 21);
	cout << "Username: ";
	cin.ignore();
	getline(cin, username);

	moveToPosition(74, 24);
	cout << "Password: ";
	getline(cin, password);


	while (checkIsExistAccount(player, quantityAccount, username, password) == false)
	{
		system("cls");

		moveToPosition(55, 12);
		cout << "Username / Password is wrong or The Account does not exist!" << endl;
		moveToPosition(76, 15);
		cout << "Please try again!" << endl;
		drawRectangle(70, 18, 30, 10);


		moveToPosition(74, 21);
		cout << "Username: ";
		cin.ignore();
		getline(cin, username);

		moveToPosition(74, 24);
		cout << "Password: ";
		getline(cin, password);

	}

			
		
}





int main() {
	Account* player{};
	fstream Account;

	int quantityAccount = 0;
	

	while (true)
	{
		createScreen(0);

		readFileAccount(player, quantityAccount, Account);

		int choice = showLogIn();
		
		switch (choice)
		{
			case 1:
				signInAccount(player, quantityAccount);
				break;
			case 2:
				//signUpAccount();
				break;
			default:
				cout << "LUA CHON KHONG HOP LE!" << endl;
		}

		break;
	}

	createScreen(0);

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
