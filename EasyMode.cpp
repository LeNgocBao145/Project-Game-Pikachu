#include "function.h"


easyCell** randomEasyCell()
{
	srand(time(0));

	easyCell** arr = new easyCell * [6];

	easyCell* arr2 = new easyCell[36];

	for (int i = 0; i < 6; i++)
	{
		arr[i] = new easyCell[6];
	}

	int index = 0;

	while (index < 36)
	{

		char lol = 'A' + (rand() % 26);
		int max = rand() % 2 + 1;
		if (max % 2 != 0)
		{
			max++;
		}
		for (int j = 0; j < max; j++)
		{
			if (index < 36)
			{

				arr2[index].data = lol;

				index++;
			}
			else
			{
				break;
			}
		}

	}

	int* nums = new int[36];

	int n = 0;
	for (int i = 0; i < 36; i++)
	{
		int num = rand() % 36;
		while (checkExist(nums, i, num) == true)
		{
			num = rand() % 36;
		}

		nums[i] = num;
	}

	int pos = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr[i][j].data = arr2[nums[pos]].data;
			pos++;
		}
	}

	delete[] nums;
	delete[] arr2;

	return arr;
}

void drawEasyBox(int x, int y, easyCell** arr, int row, int col)
{
	moveToPosition(x, y);
	cout << "+=========+" << endl;
	moveToPosition(x, y + 1);
	cout << "|" << setw(10) << right << "|" << endl;
	moveToPosition(x, y + 2);
	cout << "|" << setw(10) << right << "|" << endl;
	moveToPosition(x, y + 3);
	cout << "|" << setw(10) << right << "|" << endl;
	moveToPosition(x + 5, y + 2);
	cout << arr[row][col].data;
	moveToPosition(x, y + 4);
	cout << "+=========+" << endl;


}

bool checkExist(int* nums, int index, int num)
{
	for (int i = 0; i < index; i++)
	{
		if (nums[i] == num)
		{
			return true;
		}
	}

	return false;
}

void selectedEasyCell(easyCell** arr)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			/*if (arr[i][j].isChoosen == true)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 2);
				for (int a = 1; a <= 3; a++)
				{
					moveToPosition(arr[i][j].pos.x + 1, arr[i][j].pos.y + a);
					cout << "         ";
				}


				moveToPosition(arr[i][j].pos.x + 5, arr[i][j].pos.y + 2);
				cout << arr[i][j].data;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				for (int a = 1; a <= 3; a++)
				{
					moveToPosition(arr[i][j].pos.x + 1, arr[i][j].pos.y + a);
					cout << "         ";
				}

				moveToPosition(arr[i][j].pos.x + 5, arr[i][j].pos.y + 2);
				cout << arr[i][j].data;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}*/

			paintCell(arr, j, i, 112);

		}
	}
}

void displayLifePoint(Player alpha)
{
	moveToPosition(116, 18);
	cout << "      ";

	if (alpha.life == 3)
	{
		moveToPosition(116, 18);
		cout << "I I I";
	}
	else if (alpha.life == 2)
	{
		moveToPosition(116, 18);
		cout << "I I";
	}
	else
	{
		moveToPosition(116, 18);
		cout << "I";
	}
}

void createEasyBoard(easyCell**& board, Player alpha)
{
	int x = 20, y = 10;

	for (int i = 0; i < 6; i++)
	{
		x = 20;
		for (int j = 0; j < 6; j++)
		{
			board[i][j].pos.x = x;
			board[i][j].pos.y = y;
			drawEasyBox(x, y, board, i, j);
			x += 10;

		}
		y += 4;
	}

	drawRectangle(96, 12, 50, 9);

	moveToPosition(100, 14);
	cout << "PLAYER NAME: " << endl;
	moveToPosition(116, 14);
	cout << alpha.name;
	moveToPosition(100, 16);
	cout << "SCORE: " << endl;
	moveToPosition(116, 16);
	cout << alpha.score;
	moveToPosition(100, 18);
	cout << "LIFE: " << endl;
	displayLifePoint(alpha);

	drawRectangle(90, 24, 62, 9);

	moveToPosition(92, 26);
	cout << "! PRESS ARROW KEY TO MOVE ON THE BOARD" << endl;
	moveToPosition(92, 28);
	cout << "! PRESS ENTER TO CHOOSE THE CELL TO DELETE AND EARN POINT" << endl;
	moveToPosition(92, 30);
	cout << "! PRESS ESC KEY TO ESCAPE THE GAME" << endl;


}



void paintCell(easyCell** board, int col, int row, int color)
{
	if (board[row][col].isChoosen == true)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (board[row][col].data % 6 + 1));
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(board[row][col].pos.x + 1, board[row][col].pos.y + a);
			cout << "         ";
		}


		moveToPosition(board[row][col].pos.x + 5, board[row][col].pos.y + 2);
		cout << board[row][col].data;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (board[row][col].isChoosen == false && board[row][col].isAvailable == false)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(board[row][col].pos.x + 1, board[row][col].pos.y + a);
			cout << "         ";
		}
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(board[row][col].pos.x + 1, board[row][col].pos.y + a);
			cout << "         ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[row][col].data % 6 + 1);

		moveToPosition(board[row][col].pos.x + 5, board[row][col].pos.y + 2);
		cout << board[row][col].data;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}



	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 1; i <= 3; i++)
	{
		moveToPosition(board[row][col].pos.x + 1, board[row][col].pos.y + i);
		cout << "         ";
	}*/

}

//void chooseEasyCell(easyCell** board, Player& alpha, position& pos, position& selectedCell1, position& selectedCell2, int& status, int& pair)
//{
//	int temp;
//	int key;
//	
//	temp = _getch();
//
//	if (temp != 0 && temp != 224)
//	{
//		if (temp == PRESS_ESC)
//		{
//			status = 2;
//			return;
//		}
//
//		if (temp == PRESS_ENTER)
//		{
//			if (selectedCell1.x == pos.x && selectedCell1.y == pos.y)
//			{
//				paintCell(board, selectedCell1.x, selectedCell1.y, 70);
//				Sleep(300);
//
//				
//
//				board[selectedCell1.y][selectedCell1.x].isChoosen = false;
//				selectedCell1 = { -1, -1 };
//				pair = 2;
//				alpha.life--;
//			}
//			else
//			{
//				if (pair == 1)
//				{
//					selectedCell2.x = pos.x;
//					selectedCell2.y = pos.y;
//
//					board[selectedCell2.y][selectedCell2.x].isChoosen = true;
//					pair--;
//				}
//				else if(pair == 2)
//				{
//					selectedCell1.x = pos.x;
//					selectedCell1.y = pos.y;
//
//					board[selectedCell1.y][selectedCell1.x].isChoosen = true;
//					pair--;
//				}
//
//				if (pair == 0)
//				{
//					if (board[selectedCell1.y][selectedCell1.x].data == board[selectedCell2.y][selectedCell2.x].data)
//					{
//						if (areAllValid(board, selectedCell1.y, selectedCell1.x, selectedCell2.y, selectedCell2.x) == true)
//						{
//							alpha.score += 10;
//
//							paintCell(board, selectedCell1.x, selectedCell1.y, 40);
//							paintCell(board, selectedCell2.x, selectedCell2.y, 40);
//							Sleep(500);
//
//							board[selectedCell1.y][selectedCell1.x].isAvailable = false;
//
//
//
//							board[selectedCell2.y][selectedCell2.x].isAvailable = false;
//
//							deleteCell(board);
//						}
//						else {
//							paintCell(board, selectedCell1.x, selectedCell1.y, 70);
//							paintCell(board, selectedCell2.x, selectedCell2.y, 70);
//							Sleep(500);
//
//							alpha.life--;
//
//						}
//					}
//					else
//					{
//						paintCell(board, selectedCell1.x, selectedCell1.y, 70);
//						paintCell(board, selectedCell2.x, selectedCell2.y, 70);
//						Sleep(500);
//
//						alpha.life--;
//
//					}
//
//					board[selectedCell1.y][selectedCell1.x].isChoosen = false;
//					board[selectedCell2.y][selectedCell2.x].isChoosen = false;
//					pair = 2;
//					selectedCell1 = { -1, -1 };
//					selectedCell2 = { -1, -1 };
//
//					for (int i = pos.y; i < EASYBOARDWIDTH; i++)
//					{
//						for (int j = pos.x; j < EASYBOARDLENGTH; j++)
//						{
//							if (board[i][j].isAvailable)
//							{
//								pos.x = j;
//								pos.y = i;
//								return;
//							}
//						}
//					}
//
//					for (int i = 0; i <= pos.y; i++)
//					{
//
//						for (int j = 0; j <= pos.x; j++)
//						{
//							if (board[i][j].isAvailable)
//							{
//								pos.x = j;
//								pos.y = i;
//								return;
//							}
//						}
//					}
//				}
//			}
//
//		}
//		else
//		{
//			key = _getch();
//
//			if ((pos.y != selectedCell1.y || pos.x != selectedCell1.x) && (pos.y != selectedCell2.y || pos.x != selectedCell2.x))
//			{
//				board[pos.y][pos.x].isChoosen = false;
//			}
//
//			switch (key)
//			{
//			case PRESS_UP:
//				for (int i = pos.x; i < EASYBOARDLENGTH; i++)
//				{
//					for (int j = pos.y - 1; j >= 0; j--)
//					{
//						if (board[j][i].isAvailable == true)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//
//				}
//
//				for (int i = pos.x - 1; i >= 0; i--)
//				{
//					for (int j = pos.y - 1; j >= 0; j--)
//					{
//						if (board[j][i].isAvailable)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}
//
//				/*for (int i = pos.x; i < EASYBOARDLENGTH; i++)
//				{
//					for (int j = EASYBOARDWIDTH - 1; j > pos.y; j--)
//					{
//						if (board[j][i].isAvailable)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.x; i >= 0; i--)
//				{
//					for (int j = EASYBOARDWIDTH - 1; j > pos.y; j--)
//					{
//						if (board[j][i].isAvailable)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}*/
//
//				break;
//			case PRESS_DOWN:
//				for (int i = pos.x; i < EASYBOARDLENGTH; i++)
//				{
//					for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++)
//					{
//						if (board[j][i].isAvailable)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.x - 1; i >= 0; i--)
//				{
//					for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++)
//					{
//						if (board[j][i].isAvailable)
//						{
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}
//
//				/*for (int i = pos.x; i < EASYBOARDLENGTH; i++) {
//					for (int j = 0; j < pos.y; j++) {
//						if (board[j][i].isAvailable) {
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.x - 1; i >= 0; i--) {
//					for (int j = 0; j < pos.y; j++) {
//						if (board[j][i].isAvailable) {
//							pos.x = i;
//							pos.y = j;
//							return;
//						}
//					}
//				}*/
//				break;
//			case PRESS_LEFT:
//				for (int i = pos.y; i >= 0; i--)
//				{
//					for (int j = pos.x - 1; j >= 0; j--)
//					{
//						if (board[i][j].isAvailable)
//						{
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++)
//				{
//					for (int j = pos.x - 1; j >= 0; j--)
//					{
//						if (board[i][j].isAvailable)
//						{
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				/*for (int i = pos.y; i >= 0; i--) {
//					for (int j = EASYBOARDLENGTH - 1; j > pos.x; j--) {
//						if (board[i][j].isAvailable) {
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
//					for (int j = EASYBOARDLENGTH - 1; j > pos.x; j--) {
//						if (board[i][j].isAvailable) {
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}*/
//				break;
//			case PRESS_RIGHT:
//				for (int i = pos.y; i >= 0; i--)
//				{
//					for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++)
//					{
//						if (board[i][j].isAvailable)
//						{
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++)
//				{
//					for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++)
//					{
//						if (board[i][j].isAvailable)
//						{
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				/*for (int i = pos.y; i >= 0; i--) {
//					for (int j = 0; j < pos.x; j++) {
//						if (board[i][j].isAvailable) {
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}
//
//				for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
//					for (int j = 0; j < pos.x; j++) {
//						if (board[i][j].isAvailable) {
//							pos.x = j;
//							pos.y = i;
//							return;
//						}
//					}
//				}*/
//				break;
//			default:
//				break;
//			}
//		}
//	}
//}

void chooseEasyCell(easyCell** board, Player& alpha, position& pos, position& selectedCell1, position& selectedCell2, int& status, int& pair)
{
	int temp;
	int key;

	temp = _getch();

	if (temp != 0 && temp != 224)
	{
		if (temp == PRESS_ESC)
		{
			status = -1;
			return;
		}

		if (temp == PRESS_ENTER)
		{
			if (selectedCell1.x == pos.x && selectedCell1.y == pos.y)
			{
				paintCell(board, selectedCell1.x, selectedCell1.y, 70);
				Sleep(300);



				board[selectedCell1.y][selectedCell1.x].isChoosen = false;
				selectedCell1 = { -1, -1 };
				pair = 2;
				alpha.life--;
				displayLifePoint(alpha);
			}
			else
			{
				if (pair == 1)
				{
					selectedCell2.x = pos.x;
					selectedCell2.y = pos.y;

					board[selectedCell2.y][selectedCell2.x].isChoosen = true;
					pair--;
				}
				else if (pair == 2)
				{
					selectedCell1.x = pos.x;
					selectedCell1.y = pos.y;

					board[selectedCell1.y][selectedCell1.x].isChoosen = true;
					pair--;
				}

				if (pair == 0)
				{
					if (board[selectedCell1.y][selectedCell1.x].data == board[selectedCell2.y][selectedCell2.x].data)
					{
						if (areAllValid(board, selectedCell1.y, selectedCell1.x, selectedCell2.y, selectedCell2.x) == true)
						{
							alpha.score += 10;
							moveToPosition(116, 16);
							cout << alpha.score;

							paintCell(board, selectedCell1.x, selectedCell1.y, 40);
							paintCell(board, selectedCell2.x, selectedCell2.y, 40);
							Sleep(500);

							board[selectedCell1.y][selectedCell1.x].isAvailable = false;



							board[selectedCell2.y][selectedCell2.x].isAvailable = false;

							deleteCell(board);
						}
						else {
							paintCell(board, selectedCell1.x, selectedCell1.y, 70);
							paintCell(board, selectedCell2.x, selectedCell2.y, 70);
							Sleep(500);

							alpha.life--;
							displayLifePoint(alpha);
						}
					}
					else
					{
						paintCell(board, selectedCell1.x, selectedCell1.y, 70);
						paintCell(board, selectedCell2.x, selectedCell2.y, 70);
						Sleep(500);

						alpha.life--;
						displayLifePoint(alpha);
					}

					board[selectedCell1.y][selectedCell1.x].isChoosen = false;
					board[selectedCell2.y][selectedCell2.x].isChoosen = false;
					pair = 2;
					selectedCell1 = { -1, -1 };
					selectedCell2 = { -1, -1 };

					for (int i = pos.y; i < EASYBOARDWIDTH; i++)
					{
						for (int j = pos.x; j < EASYBOARDLENGTH; j++)
						{
							if (board[i][j].isAvailable)
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}

					for (int i = 0; i <= pos.y; i++)
					{

						for (int j = 0; j <= pos.x; j++)
						{
							if (board[i][j].isAvailable)
							{
								pos.x = j;
								pos.y = i;
								return;
							}
						}
					}
				}
			}
		}

	}
	else
	{
		key = _getch();

		if ((pos.y != selectedCell1.y || pos.x != selectedCell1.x) && (pos.y != selectedCell2.y || pos.x != selectedCell2.x))
		{
			board[pos.y][pos.x].isChoosen = false;
		}

		switch (key)
		{
		case PRESS_UP:
			for (int i = pos.x; i < EASYBOARDLENGTH; i++)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (board[j][i].isAvailable == true)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}

			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (board[j][i].isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			/*for (int i = pos.x; i < EASYBOARDLENGTH; i++)
			{
				for (int j = EASYBOARDWIDTH - 1; j > pos.y; j--)
				{
					if (board[j][i].isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i >= 0; i--)
			{
				for (int j = EASYBOARDWIDTH - 1; j > pos.y; j--)
				{
					if (board[j][i].isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}*/

			break;
		case PRESS_DOWN:
			for (int i = pos.x; i < EASYBOARDLENGTH; i++)
			{
				for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++)
				{
					if (board[j][i].isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++)
				{
					if (board[j][i].isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			/*for (int i = pos.x; i < EASYBOARDLENGTH; i++) {
				for (int j = 0; j < pos.y; j++) {
					if (board[j][i].isAvailable) {
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--) {
				for (int j = 0; j < pos.y; j++) {
					if (board[j][i].isAvailable) {
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}*/
			break;
		case PRESS_LEFT:
			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = pos.x - 1; j >= 0; j--)
				{
					if (board[i][j].isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++)
			{
				for (int j = pos.x - 1; j >= 0; j--)
				{
					if (board[i][j].isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			/*for (int i = pos.y; i >= 0; i--) {
				for (int j = EASYBOARDLENGTH - 1; j > pos.x; j--) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
				for (int j = EASYBOARDLENGTH - 1; j > pos.x; j--) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}*/
			break;
		case PRESS_RIGHT:
			for (int i = pos.y; i >= 0; i--)
			{
				for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++)
				{
					if (board[i][j].isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++)
			{
				for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++)
				{
					if (board[i][j].isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			/*for (int i = pos.y; i >= 0; i--) {
				for (int j = 0; j < pos.x; j++) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
				for (int j = 0; j < pos.x; j++) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}*/
			break;
		default:
			break;
		}
	}
}

void deleteCell(easyCell** board)
{

	for (int i = 0; i < EASYBOARDWIDTH; i++)
	{
		for (int j = 0; j < EASYBOARDLENGTH; j++)
		{
			if (board[i][j].isAvailable == false)
			{
				for (int h = 1; h <= 3; h++)
				{
					moveToPosition(board[i][j].pos.x + 1, board[i][j].pos.y + h);
					cout << "         ";
				}
			}
		}
	}
}

bool checkAnyAvailable(easyCell** board)
{
	for (int i = 0; i < EASYBOARDWIDTH; i++)
	{
		for (int j = 0; j < EASYBOARDLENGTH; j++)
		{
			if (board[i][j].isAvailable == true)
			{
				return true;
			}
		}
	}

	return false;
}

void chooseToPlayEasyMode(Player*& ranker, int quantity, Player& alpha, bool soundEffect, bool soundBackground)
{


	int choice = 1;
	int key = 0;

	system("cls");
	//drawRectangle(36, 5, 100, 30);
	drawRectangle(50, 20, 20, 5);
	drawRectangle(100, 20, 20, 5);

	moveToPosition(72, 20);
	cout << "DO YOU WANT TO PLAY AGAIN?";

	while (true) {

		if (choice == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

			for (int i = 0; i < 3; i++) {
				moveToPosition(51, 21 + i);
				cout << "                  " << endl;
			}

			moveToPosition(59, 22);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
			cout << "YES";
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			for (int i = 0; i < 3; i++) {
				moveToPosition(51, 21 + i);
				cout << "                  " << endl;
			}

			moveToPosition(59, 22);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "YES";
		}

		if (choice == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

			for (int i = 0; i < 3; i++) {
				moveToPosition(101, 21 + i);
				cout << "                  " << endl;
			}

			moveToPosition(109, 22);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
			cout << "NO";
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			for (int i = 0; i < 3; i++) {
				moveToPosition(101, 21 + i);
				cout << "                  " << endl;
			}

			moveToPosition(109, 22);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "NO";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

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
		createEasyRound(ranker, quantity, alpha, editSoundEffect, soundBackground);
	}
	else
	{
		return;
	}
}

void createEasyRound(Player* &ranker, int quantity, Player& alpha, bool soundEffect, bool soundBackground)
{
	playMusicRound(soundBackground);

	position selectedCell1 = { -1, -1 };
	position selectedCell2 = { -1, -1 };

	position pos = { 0, 0 };

	int pair = 2;

	easyCell** board = randomEasyCell();

	createEasyBoard(board, alpha);

	int status = 1;


	while (status == 1 && alpha.life != 0)
	{
		board[pos.y][pos.x].isChoosen = true;
		selectedEasyCell(board);
		chooseEasyCell(board, alpha, pos, selectedCell1, selectedCell2, status, pair);

		if (checkAnyAvailable(board) == false)
		{
			status = 2;
			break;
		}
	}

	updateScore(ranker, alpha, quantity);
	writeLeaderBoard(ranker, quantity);

	Sleep(500);
	system("cls");

	if (status == 2 && alpha.life != 0)
	{
		playWonEffect(soundEffect);


		alpha.life = 3;
		alpha.score = 0;
		displayBG(1);
		Sleep(2000);
		chooseToPlayEasyMode(ranker, quantity, alpha, soundEffect, soundBackground);
	}

	if (alpha.life == 0)
	{
		playLoseEffect(soundEffect);

		alpha.life = 3;
		alpha.score = 0;
		displayBG(0);
		Sleep(2000);
		chooseToPlayEasyMode(ranker, quantity, alpha, soundEffect, soundBackground);
	}

	for (int i = 0; i < EASYBOARDWIDTH; i++)
	{
		delete[] board[i];
	}

	delete[] board;

}