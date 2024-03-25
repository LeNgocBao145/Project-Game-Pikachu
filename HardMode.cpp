#include "function.h"

hardCell* createCell(char data)
{
	hardCell* pNew = new hardCell;
	pNew->data = data;
	pNew->next = NULL;

	return pNew;
}

void addTailCell(hardCell*& pHead, char data)
{
	hardCell* pNew = createCell(data);
	hardCell* pCurr = pHead;
	if (pCurr == NULL)
	{
		pHead = pNew;
	}

	while (pCurr->next != NULL)
	{
		pCurr = pCurr->next;
	}

	pCurr->next = pNew;
}

void randomHardCell(hardCell* &pHead)
{
	srand(time(0));

	//easyCell** arr = new easyCell * [6];

	char* arr2 = new char[36];

	/*for (int i = 0; i < 6; i++)
	{
		arr[i] = new char[6];
	}*/

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
				
				arr2[index] = lol;

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
			addTailCell(pHead, arr2[nums[pos]]);
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
	while(pCurr != NULL)
	{
			if (pCurr->isChoosen == true)
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
			}

			pCurr = pCurr->next;
	}
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void createHardBoard(hardCell* pHead)
{
	hardCell* pCurr = pHead;

	int x = 20, y = 10;
	int row = 0, col = 0;

	while (pCurr != NULL)
	{
		if (col < 10)
		{
			pCurr->pos.x = x;
			pCurr->pos.y = y;
			drawHardBox(x, y, pCurr);
			x += 10;
			
		}
		else
		{
			x = 20;
			col = 0;
			row++;
			y += 4;
		}

		pCurr = pCurr->next;
	}
	

	drawRectangle(96, 12, 50, 9);

	moveToPosition(100, 14);
	cout << "PLAYER NAME: " << endl;
	moveToPosition(116, 14);
	cout << "Le Bao";
	moveToPosition(100, 16);
	cout << "SCORE: " << endl;
	moveToPosition(116, 16);
	cout << "1000";
	moveToPosition(100, 18);
	cout << "LIFE: " << endl;
	moveToPosition(116, 18);
	cout << "I I I";

	drawRectangle(96, 24, 63, 9);

	moveToPosition(98, 26);
	cout << "! PRESS ARROW KEY TO MOVE ON THE BOARD" << endl;
	moveToPosition(98, 28);
	cout << "! PRESS ENTER TO CHOOSE THE CELL TO DELETE AND EARN POINT" << endl;
	moveToPosition(98, 30);
	cout << "! PRESS ESC KEY TO ESCAPE THE GAME" << endl;


}

void chooseHardCell(easyCell** board, position& pos, int& status)
{
	int temp;
	int key;

	temp = _getch();

	if (temp != 0 && temp != 224)
	{
		if (temp == PRESS_ESC)
		{
			status = 2;
			return;
		}

		if (temp == PRESS_ENTER)
		{

		}
		else
		{

		}
	}
	else
	{
		key = _getch();

		board[pos.y][pos.x].isChoosen = 0;

		switch (key)
		{
		case PRESS_UP:
			/*for (int i = pos.x; i < EASYBOARDLENGTH; i++)
			{*/
			for (int j = pos.y - 1; j >= 0; j--)
			{
				if (board[j][pos.x].isAvailable == true)
				{
					//pos.x = i;
					pos.y = j;
					return;
				}
			}

			//}

			/*for (int i = pos.x - 1; i >= 0; i--)
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

			for (int i = pos.x; i < EASYBOARDLENGTH; i++)
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
			/*for (int i = pos.x; i < EASYBOARDLENGTH; i++)
			{*/
			for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++)
			{
				if (board[j][pos.x].isAvailable)
				{
					//pos.x = i;
					pos.y = j;
					return;
				}
			}
			//}

			/*for (int i = pos.x - 1; i >= 0; i--) {
				for (int j = pos.y + 1; j < EASYBOARDWIDTH; j++) {
					if (board[j][i].isAvailable) {
						pos.x = i;
						pos.y = j;
						return;
					}
				}
			}

			for (int i = pos.x; i < EASYBOARDLENGTH; i++) {
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
			/*for (int i = pos.y; i >= 0; i--)
			{*/
			for (int j = pos.x - 1; j >= 0; j--)
			{
				if (board[pos.y][j].isAvailable)
				{
					pos.x = j;
					//pos.y = i;
					return;
				}
			}
			//}

			/*for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
				for (int j = pos.x - 1; j >= 0; j--) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y; i >= 0; i--) {
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
			/*for (int i = pos.y; i >= 0; i--)
			{*/
			for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++)
			{
				if (board[pos.y][j].isAvailable)
				{
					pos.x = j;
					//pos.y = i;
					return;
				}
			}
			//}

			/*for (int i = pos.y + 1; i < EASYBOARDWIDTH; i++) {
				for (int j = pos.x + 1; j < EASYBOARDLENGTH; j++) {
					if (board[i][j].isAvailable) {
						pos.x = j;
						pos.y = i;
						return;
					}
				}
			}

			for (int i = pos.y; i >= 0; i--) {
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

void createHardRound()
{

	position pos = { 0, 0 };

	hardCell* board = NULL;

	randomHardCell(board);

	createHardBoard(board);

	int status = 1;

	while (status == 1)
	{
		
		selectHardCell(board);
		
	}

}