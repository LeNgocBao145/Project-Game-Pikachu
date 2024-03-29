#pragma once
#include "function.h"
bool checkLineHardCell(hardCell* board, int row1, int col1, int row2, int col2);

bool checkLHardCell(hardCell* board, int row1, int col1, int row2, int col2);

bool checkZHardCell(hardCell* board, int row1, int col1, int row2, int col2);

bool checkUHardCell(hardCell* board, int row1, int col1, int row2, int col2);

bool areAllHardCellValid(hardCell* board, int row1, int col1, int row2, int col2);