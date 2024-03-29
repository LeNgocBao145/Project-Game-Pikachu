#include "function.h"

hardCell* createCell(char data)
{
	hardCell* pNew = new hardCell;
	pNew->data = data;
	pNew->next = NULL;

	return pNew;
}

void addTailCell(hardCell*& pHead, int row, int col, char data)
{
	hardCell* pNew = createCell(data);
	pNew->row = row;
	pNew->col = col;
	hardCell* pCurr = pHead;
	if (pCurr == NULL)
	{
		pHead = pNew;
		return;
	}

	while (pCurr->next != NULL)
	{
		pCurr = pCurr->next;
	}

	pCurr->next = pNew;
}

void deleteList(hardCell*& pHead)
{
	hardCell* pCurr = pHead;



	if (pCurr == NULL)
	{
		return;
	}
	else
	{
		delete pCurr;
		pCurr = NULL;
	}
}

hardCell* findNode(hardCell* pHead, int row, int col)
{
	hardCell* pCurr = pHead;

	while(pCurr != NULL)
	{
		if (pCurr->row == row && pCurr->col == col)
		{
			return pCurr;
		}

		pCurr = pCurr->next;
	}

	return NULL;
}

void randomHardCell(hardCell*& pHead)
{
	srand(time(0));


	char* arr2 = new char[HARDBOARDLENGTH * HARDBOARDWIDTH];


	int index = 0;

	while (index < HARDBOARDLENGTH * HARDBOARDWIDTH)
	{

		char lol = 'A' + (rand() % 26);
		int max = rand() % 2 + 1;
		if (max % 2 != 0)
		{
			max++;
		}
		for (int j = 0; j < max; j++)
		{
			if (index < HARDBOARDLENGTH * HARDBOARDWIDTH)
			{

				arr2[index] = lol;

				index++;
			}
			else
			{
				break;
			}
		}

	}

	int* nums = new int[HARDBOARDLENGTH * HARDBOARDWIDTH];


	for (int i = 0; i < HARDBOARDLENGTH * HARDBOARDWIDTH; i++)
	{
		int num = rand() % (HARDBOARDLENGTH * HARDBOARDWIDTH);
		while (checkExist(nums, i, num) == true)
		{
			num = rand() % (HARDBOARDLENGTH * HARDBOARDWIDTH);
		}

		nums[i] = num;
	}

	int pos = 0;

	for (int i = 0; i < HARDBOARDWIDTH; i++)
	{
		for (int j = 0; j < HARDBOARDLENGTH; j++)
		{
			addTailCell(pHead, i, j, arr2[nums[pos]]);
			pos++;
		}
	}

	delete[] nums;
	delete[] arr2;

}

void drawHardBox(int x, int y, hardCell* pHead)
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
	cout << pHead->data;
	moveToPosition(x, y + 4);
	cout << "+=========+" << endl;


}


void selectHardCell(hardCell* pHead)
{
	hardCell* pCurr = pHead;
	while (pCurr != NULL)
	{
		/*if (pCurr->isChoosen == true)
		{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 2);
			for (int a = 1; a <= 3; a++)
			{
				moveToPosition(pCurr->pos.x + 1, pCurr->pos.y + a);
				cout << "         ";
			}


			moveToPosition(pCurr->pos.x + 5, pCurr->pos.y + 2);
			cout << pCurr->data;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			for (int a = 1; a <= 3; a++)
			{
				moveToPosition(pCurr->pos.x + 1, pCurr->pos.y + a);
				cout << "         ";
			}

			moveToPosition(pCurr->pos.x + 5, pCurr->pos.y + 2);
			cout << pCurr->data;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}*/
		for (int i = 0; i < HARDBOARDWIDTH; i++)
		{
			for (int j = 0; j < HARDBOARDLENGTH; j++)
			{
				paintHardCell(pHead, i, j, 112);
				pCurr = pCurr->next;
			}
		}
		
	}


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void createHardBoard(hardCell* pHead, Player alpha)
{
	hardCell* pCurr = pHead;

	int x = 4, y = 4;
	int row = 0, col = 0;

	while (pCurr != NULL)
	{
		if (col < HARDBOARDLENGTH)
		{
			pCurr->pos.x = x;
			pCurr->pos.y = y;
			drawHardBox(x, y, pCurr);
			x += 10;

		}
		else
		{
			x = 4;
			col = 0;

			y += 4;

			pCurr->pos.x = x;
			pCurr->pos.y = y;
			drawHardBox(x, y, pCurr);
			x += 10;
		}

		pCurr = pCurr->next;
		col++;
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
	moveToPosition(116, 18);
	displayLifePoint(alpha);

	drawRectangle(92, 24, 63, 9);

	moveToPosition(94, 26);
	cout << "! PRESS ARROW KEY TO MOVE ON THE BOARD" << endl;
	moveToPosition(94, 28);
	cout << "! PRESS ENTER TO CHOOSE THE CELL TO DELETE AND EARN POINT" << endl;
	moveToPosition(94, 30);
	cout << "! PRESS ESC KEY TO ESCAPE THE GAME" << endl;


}

int sizeList(hardCell* pHead)
{
	int count = 0;

	hardCell* pCurr = pHead;

	while (pCurr != NULL)
	{
		count++;
		pCurr = pCurr->next;
	}

	return count;
}

void chooseHardCell(hardCell* board, Player& alpha, position& pos, position& selectedCell1, position& selectedCell2, int& status, int& pair)
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
				paintHardCell(board, selectedCell1.x, selectedCell1.y, 70);
				Sleep(300);



				findNode(board, selectedCell1.y, selectedCell1.x)->isChoosen = false;
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

					findNode(board, selectedCell2.y, selectedCell2.x)->isChoosen = true;
					pair--;
				}
				else if (pair == 2)
				{
					selectedCell1.x = pos.x;
					selectedCell1.y = pos.y;

					findNode(board, selectedCell1.y, selectedCell1.x)->isChoosen = true;
					pair--;
				}

				if (pair == 0)
				{
					if (findNode(board, selectedCell1.y, selectedCell1.x)->data == findNode(board, selectedCell2.y, selectedCell2.x)->data)
					{
						if (areAllHardCellValid(board, selectedCell1.y, selectedCell1.x, selectedCell2.y, selectedCell2.x) == true)
						{
							alpha.score += 10;
							moveToPosition(116, 16);
							cout << alpha.score;

							paintHardCell(board, selectedCell1.y, selectedCell1.x, 40);
							paintHardCell(board, selectedCell2.y, selectedCell2.x, 40);
							Sleep(500);

							findNode(board, selectedCell1.y, selectedCell1.x)->isAvailable = false;

							deleteHardCell(board, selectedCell1.y, selectedCell1.x);

							findNode(board, selectedCell2.y, selectedCell2.x)->isAvailable = false;

							deleteHardCell(board, selectedCell2.y, selectedCell2.x);
						}
						else {
							paintHardCell(board, selectedCell1.y, selectedCell1.x, 70);
							paintHardCell(board, selectedCell2.y, selectedCell2.x, 70);
							Sleep(500);

							alpha.life--;
							displayLifePoint(alpha);
						}
					}
					else
					{
						paintHardCell(board, selectedCell1.y, selectedCell1.x, 70);
						paintHardCell(board, selectedCell2.y, selectedCell2.x, 70);
						Sleep(500);

						alpha.life--;
						displayLifePoint(alpha);
					}

					findNode(board, selectedCell1.y, selectedCell1.x)->isChoosen = false;
					findNode(board, selectedCell2.y, selectedCell2.x)->isChoosen = false;
					pair = 2;
					selectedCell1 = { -1, -1 };
					selectedCell2 = { -1, -1 };

					for (int i = pos.y; i < HARDBOARDWIDTH; i++)
					{
						for (int j = pos.x; j < HARDBOARDLENGTH; j++)
						{
							if (findNode(board, i, j)->isAvailable == true)
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
							if (findNode(board, i, j)->isAvailable == true)
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
			findNode(board, pos.y, pos.x)->isChoosen = false;
		}

		switch (key)
		{
		case PRESS_UP:
			for (int i = pos.x; i < HARDBOARDLENGTH; i++)
			{
				for (int j = pos.y - 1; j >= 0; j--)
				{
					if (findNode(board, j, i)->isAvailable == true)
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
					if (findNode(board, j, i)->isAvailable)
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
			for (int i = pos.x; i < HARDBOARDLENGTH; i++)
			{
				for (int j = pos.y + 1; j < HARDBOARDWIDTH; j++)
				{
					if (findNode(board, j, i)->isAvailable)
					{
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x - 1; i >= 0; i--)
			{
				for (int j = pos.y + 1; j < HARDBOARDWIDTH; j++)
				{
					if (findNode(board, j, i)->isAvailable)
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
					if (findNode(board, i, j)->isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < HARDBOARDWIDTH; i++)
			{
				for (int j = pos.x - 1; j >= 0; j--)
				{
					if (findNode(board, i, j)->isAvailable)
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
				for (int j = pos.x + 1; j < HARDBOARDLENGTH; j++)
				{
					if (findNode(board, i, j)->isAvailable)
					{
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y + 1; i < HARDBOARDWIDTH; i++)
			{
				for (int j = pos.x + 1; j < HARDBOARDLENGTH; j++)
				{
					if (findNode(board, i, j)->isAvailable)
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

void paintHardCell(hardCell* board, int row, int col, int color)
{
	hardCell* temp = findNode(board, row, col);

	if (temp->isChoosen == true)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (temp->data % 6 + 1));
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(temp->pos.x + 1, temp->pos.y + a);
			cout << "         ";
		}


		moveToPosition(temp->pos.x + 5, temp->pos.y + 2);
		cout << temp->data;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (temp->isChoosen == false && temp->isAvailable == false)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(temp->pos.x + 1, temp->pos.y + a);
			cout << "         ";
		}
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int a = 1; a <= 3; a++)
		{
			moveToPosition(temp->pos.x + 1, temp->pos.y + a);
			cout << "         ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), temp->data % 6 + 1);

		moveToPosition(temp->pos.x + 5, temp->pos.y + 2);
		cout << temp->data;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}



	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 1; i <= 3; i++)
	{
		moveToPosition(board[row][col].pos.x + 1, board[row][col].pos.y + i);
		cout << "         ";
	}*/

}



void printList(hardCell* board)
{
	hardCell* pCurr = board;

	while (pCurr != NULL)
	{
		cout << pCurr->data << " ";
		pCurr = pCurr->next;
	}
}


void chooseToPlayHardMode(Player& alpha, bool soundEffect, bool soundBackground)
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
		createHardRound(alpha, editSoundEffect, soundBackground);
	}
	else
	{
		return;
	}
}

void deleteHardCell(hardCell* board, int row, int col)
{
	hardCell* temp = findNode(board, row, col);
	
	if (temp->isAvailable == false)
	{
		for (int h = 1; h <= 3; h++)
		{
			moveToPosition(temp->pos.x + 1, temp->pos.y + h);
			cout << "         ";
		}
	}

	
}

bool checkAnyAvailable(hardCell* board)
{
	hardCell* pCurr = board;

	while (pCurr != NULL)
	{
		if (pCurr->isAvailable == true)
		{
			return true;
		}

		pCurr = pCurr->next;
	}

	return false;
}

void createHardRound(Player& alpha, bool soundEffect, bool soundBackground)
{
	playMusicRound(soundBackground);

	position selectedCell1 = { -1, -1 };
	position selectedCell2 = { -1, -1 };

	position pos = { 0, 0 };

	int pair = 2;

	
	hardCell* board = NULL;

	randomHardCell(board);

	
	createHardBoard(board, alpha);
	

	int status = 1;


	while (status == 1 && alpha.life != 0)
	{
		findNode(board, pos.y, pos.x)->isChoosen = true;
		selectHardCell(board);
		chooseHardCell(board, alpha, pos, selectedCell1, selectedCell2, status, pair);

		if (checkAnyAvailable(board) == false)
		{
			status = 2;
			break;
		}
	}

	deleteList(board);

	if (status == 2 && alpha.life != 0)
	{
		playWonEffect(soundEffect);


		alpha.life = 3;
		alpha.score = 0;
		chooseToPlayHardMode(alpha, soundEffect, soundBackground);
	}

	if (alpha.life == 0)
	{
		playLoseEffect(soundEffect);

		alpha.life = 3;
		alpha.score = 0;
		chooseToPlayHardMode(alpha, soundEffect, soundBackground);
	}
}