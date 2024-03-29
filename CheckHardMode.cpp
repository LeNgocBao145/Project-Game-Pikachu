#include "function.h"

bool checkLineHardCell(hardCell* board, int row1, int col1, int row2, int col2)
{
	if (col1 != col2 && row1 != row2)
	{
		return false;
	}

	if (col1 == col2)
	{
		if (row1 > row2)
		{
			for (int i = row1 - 1; i > row2; i--)
			{
				if (findNode(board, i, col1)->isAvailable == true)
				{
					
					return false;
				}
			}
		}
		else
		{
			for (int i = row1 + 1; i < row2; i++)
			{
				if (findNode(board, i, col1)->isAvailable == true)
				{
					return false;
				}
			}
		}
	}
	else if (row1 == row2)
	{
		if (col1 > col2)
		{
			for (int i = col1 - 1; i > col2; i--)
			{
				if (findNode(board, row1, i)->isAvailable == true)
				{
					
					return false;
				}
			}
		}
		else
		{
			for (int i = col1 + 1; i < col2; i++)
			{
				if (findNode(board, row1, i)->isAvailable == true)
				{
					
					return false;
				}
			}
		}
	}
	
	return true;
}

bool checkLHardCell(hardCell* board, int row1, int col1, int row2, int col2)
{
	if (row1 > row2)
	{
		if (col2 > col1)
		{
			if (findNode(board, row1 - 1, col1)->isAvailable == true)
			{
				for (int i = col1 + 1; i <= col2; i++)
				{
					
						if (findNode(board, row1, i)->isAvailable == true)
						{
							return false;
						}
					
				}

				for (int j = row1 - 1; j > row2; j--)
				{
					if (findNode(board, j, col2)->isAvailable == true)
					{
						return false;
					}
				}
			}
			else
			{
				for (int j = row1 - 1; j >= row2; j--)
				{
					if (findNode(board, j, col1)->isAvailable == true)
					{
						return false;
					}
				}

				for (int i = col1 + 1; i < col2; i++)
				{

					if (findNode(board, row2, i)->isAvailable == true)
					{
						return false;
					}

				}
			}

		}
		else
		{
			if (findNode(board, row1 - 1, col1)->isAvailable == true)
			{
				for (int i = col1 - 1; i >= col2; i--)
				{
					if (findNode(board, row1, i)->isAvailable == true)
					{
						return false;
					}

				}

				for (int j = row1 - 1; j > row2; j--)
				{
					if (findNode(board, j, col2)->isAvailable == true)
					{
						return false;
					}
				}
			}
			else
			{
				for (int j = row1 - 1; j >= row2; j--)
				{
					if (findNode(board, j, col1)->isAvailable == true)
					{
						return false;
					}
				}

				for (int i = col1 - 1; i > col2; i--)
				{
					if (findNode(board, row2, i)->isAvailable == true)
					{
						return false;
					}

				}
			}
		}
	}
	else
	{
		if (col2 > col1)
		{
			if (row1 + 1 < HARDBOARDWIDTH)
			{
				if (findNode(board, row1 + 1, col1)->isAvailable == true)
				{
					for (int i = col1 + 1; i <= col2; i++)
					{

						if (findNode(board, row1, i)->isAvailable == true)
						{
							return false;
						}

					}

					for (int j = row1 + 1; j < row2; j++)
					{
						if (findNode(board, j, col2)->isAvailable == true)
						{
							return false;
						}
					}
				}
				else
				{
					for (int j = row1 + 1; j <= row2; j++)
					{
						if (findNode(board, j, col1)->isAvailable == true)
						{
							return false;
						}
					}

					for (int i = col1 + 1; i < col2; i++)
					{

						if (findNode(board, row2, i)->isAvailable == true)
						{
							return false;
						}

					}
				}
			}
		}
		else
		{
			if (row1 + 1 < HARDBOARDWIDTH)
			{
				if (findNode(board, row1 + 1, col1)->isAvailable == true)
				{
					for (int i = col1 - 1; i >= col2; i--)
					{
						if (findNode(board, row1, i)->isAvailable == true)
						{
							return false;
						}

					}

					for (int j = row1 + 1; j < row2; j++)
					{
						if (findNode(board, j, col2)->isAvailable == true)
						{
							return false;
						}
					}
				}
				else
				{
					for (int j = row1 + 1; j >= row2; j--)
					{
						if (findNode(board, j, col1)->isAvailable == true)
						{
							return false;
						}
					}

					for (int i = col1 - 1; i > col2; i--)
					{
						if (findNode(board, row2, i)->isAvailable == true)
						{
							return false;
						}

					}
				}
			}
		}
	}

	return true;
}

bool checkZHardCell(hardCell* board, int row1, int col1, int row2, int col2)
{

	for (int i = col1 + 1; i < col2; i++)
	{
		if (checkLineHardCell(board, row1, i, row2, i) == true)
		{
			if (checkLineHardCell(board, row1, col1, row1, i + 1) == true && checkLineHardCell(board, row2, i - 1, row2, col2) == true)
			{
				return true;
			}
		}
	}

	for (int i = row1 - 1; i > row2; i--)
	{
		if (checkLineHardCell(board, i, col1, i, col2) == true)
		{
			if (checkLineHardCell(board, row1, col1, i - 1, col1) == true && checkLineHardCell(board, i + 1, col2, row2, col2) == true)
			{
				return true;
			}
		}
	}

	for (int i = col1 - 1; i > col2; i--)
	{
		if (checkLineHardCell(board, row1, i, row2, i) == true)
		{
			if (checkLineHardCell(board, row1, col1, row1, i - 1) == true && checkLineHardCell(board, row2, i + 1, row2, col2) == true)
			{
				return true;
			}
		}
	}


	for (int i = row1 + 1; i < row2; i++)
	{
		if (checkLineHardCell(board, i, col1, i, col2) == true)
		{
			if (checkLineHardCell(board, row1, col1, i + 1, col1) == true && checkLineHardCell(board, i - 1, col2, row2, col2) == true)
			{
				return true;
			}
		}
	}

	/*if (row1 > row2)
	{
		if (col2 > col1)
		{
			if (findNode(board, row1 - 1, col1)->isAvailable == true)
			{
				for (int i = col1 + 1; i < col2; i++)
				{
					if (checkLineHardCell(board, row1 + 1, i, row2 - 1, i) == true)
					{
						if (checkLineHardCell(board, row1, col1, row1, i + 1) == true && checkLineHardCell(board, row2, i, row2, col2) == true)
						{
							return true;
						}
					}
				}
			}
			else
			{
				for (int i = row1 - 1; i > row2; i--)
				{
					if (checkLineHardCell(board, i, col1 - 1, i, col2 + 1) == true)
					{
						if (checkLineHardCell(board, row1, col1, i - 1, col1) == true && checkLineHardCell(board, i, col2, row2, col2) == true)
						{
							return true;
						}
					}
				}
			}

		}
		else
		{
			if (findNode(board, row1 - 1, col1)->isAvailable == true)
			{
				for (int i = col1 - 1; i > col2; i++)
				{
					if (checkLineHardCell(board, row1 - 1, i, row2 + 1, i) == true)
					{
						if (checkLineHardCell(board, row1, col1, row1, i + 1) == true && checkLineHardCell(board, row2, i, row2, col2) == true)
						{
							return true;
						}
					}
				}
			}
			else
			{
				for (int i = row1 - 1; i > row2; i--)
				{
					if (checkLineHardCell(board, i, col1 + 1, i, col2 - 1) == true)
					{
						if (checkLineHardCell(board, row1, col1, i - 1, col1) == true && checkLineHardCell(board, i, col2, row2, col2) == true)
						{
							return true;
						}
					}
				}
			}
		}
	}
	else
	{
		if (col2 > col1)
		{
			if (findNode(board, row1 + 1, col1)->isAvailable == true)
			{

			}
			else
			{

			}
		}
		else
		{
			if (findNode(board, row1 + 1, col1)->isAvailable == true)
			{

			}
			else
			{
				for (int i = row1 + 1; i < row2; i++)
				{
					if (checkLineHardCell(board, i, col1 - 1, i, col2 + 1) == true)
					{
						if (checkLineHardCell(board, row1, col1, i, col1) == true && checkLineHardCell(board, i, col2, row2, col2) == true)
						{
							return true;
						}
					}
				}
			}
		}

		
	}*/

	return false;
}

bool checkUHardCell(hardCell* board, int row1, int col1, int row2, int col2)
{
	/*if ((row1 == row2 && (row2 == 0 || row2 == HARDBOARDWIDTH + 1)) || (col1 == col2 && (col2 == 0 || col2 == HARDBOARDLENGTH - 1)))
	{
		return true;
	}*/

	if (checkLineHardCell(board, row1, col1, row1, HARDBOARDLENGTH) == true && checkLineHardCell(board, row2, col2, row2, HARDBOARDLENGTH) == true)
	{
		return true;
	}

	if (checkLineHardCell(board, row1, col1, row1, -1) == true && checkLineHardCell(board, row2, col2, row2, -1) == true)
	{
		return true;
	}

	if (checkLineHardCell(board, row1, col1, -1, col1) == true && checkLineHardCell(board, row2, col2, -1, col2) == true)
	{
		return true;
	}

	if (checkLineHardCell(board, row1, col1, HARDBOARDWIDTH, col1) == true && checkLineHardCell(board, row2, col2, HARDBOARDWIDTH, col2) == true)
	{
		return true;
	}

	if (col2 > col1)
	{
		for (int i = col2 + 1; i < HARDBOARDLENGTH; i++)
		{

			if (checkLineHardCell(board, row1, i, row2, i) == true)
			{
				if (checkLineHardCell(board, row1, col1, row1, i + 1) == true && checkLineHardCell(board, row2, col2, row2, i + 1) == true)
				{
					return true;
				}
			}

		}
	}

	for (int i = col2 - 1; i > 0; i--)
	{

		if (checkLineHardCell(board, row1, i, row2, i) == true)
		{
			if (checkLineHardCell(board, row1, col1, row1, i - 1) == true && checkLineHardCell(board, row2, col2, row2, i - 1) == true)
			{
				return true;
			}
		}

	}

	for (int i = row2 + 1; i < HARDBOARDWIDTH; i++)
	{
		
		if (checkLineHardCell(board, i, col1, i, col2) == true)
		{
			if (checkLineHardCell(board, row1, col1, i + 1, col1) == true && checkLineHardCell(board, row2, col2, i + 1, col2) == true)
			{
				return true;
			}
		}
		
	}

	for (int i = row2 - 1; i > 0; i--)
	{

		if (checkLineHardCell(board, i, col1, i, col2) == true)
		{
			if (checkLineHardCell(board, row1, col1, i - 1, col1) == true && checkLineHardCell(board, row2, col2, i - 1, col2) == true)
			{
				return true;
			}
		}

	}

	/*if (col2 > col1)
	{

		for (int i = 0; i < HARDBOARDLENGTH; i++)
		{
			if (i < col1 || i > col2)
			{
				if (checkLineHardCell(board, row1, i, row2, i) == true)
				{
					if (checkLineHardCell(board, row1, col1, row1, i + 1) == true && checkLineHardCell(board, row2, col2, row2, i + 1) == true)
					{
						return true;
					}
				}
			}
		}

		
	}
	else
	{
		for (int i = 0; i < HARDBOARDLENGTH; i++)
		{
			if (i < col2 || i > col1)
			{
				if (checkLineHardCell(board, row1, i, row2, i) == true)
				{
					if (checkLineHardCell(board, row1, col1, row1, i - 1) == true && checkLineHardCell(board, row2, col2, row2, i - 1) == true)
					{
						return true;
					}
				}
			}
		}
	}

	if (row1 > row2)
	{
		for (int i = 0; i < HARDBOARDWIDTH; i++)
		{
			if (i < row2 || i > row1)
			{
				if (checkLineHardCell(board, i, col1, i, col2) == true)
				{
					if (checkLineHardCell(board, row1, col1, i - 1, col1) == true && checkLineHardCell(board, row2, col2, i - 1, col2) == true)
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < HARDBOARDWIDTH; i++)
		{
			if (i < row1 || i > row2)
			{
				if (checkLineHardCell(board, i, col1, i, col2) == true)
				{
					if (checkLineHardCell(board, i + 1, col1, row1, col1) == true && checkLineHardCell(board, row2, col2, i + 1, col2) == true)
					{
						return true;
					}
				}
			}
		}
	}*/

	return false;
}

bool areAllHardCellValid(hardCell* board, int row1, int col1, int row2, int col2)
{
	if (checkLineHardCell(board, row1, col1, row2, col2))
	{
		return true;
	}
	else if (checkLHardCell(board, row1, col1, row2, col2))
	{
		return true;
	}
	else if (checkZHardCell(board, row1, col1, row2, col2))
	{
		return true;
	}
	else if (checkUHardCell(board, row1, col1, row2, col2))
	{
		return true;
	}

	return false;
}