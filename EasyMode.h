#pragma once
#include "function.h"

easyCell** randomEasyCell();

void drawEasyBox(int x, int y, easyCell** arr, int row, int col);

bool checkExist(int* nums, int index, int num);

void selectEasyCell(easyCell** arr);

void createEasyBoard(easyCell**& board);

void createEasyRound();


