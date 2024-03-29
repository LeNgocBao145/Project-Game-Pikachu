#pragma once
#include "function.h"

easyCell** randomEasyCell();

void drawEasyBox(int x, int y, easyCell** arr, int row, int col);

bool checkExist(int* nums, int index, int num);

void selectEasyCell(easyCell** arr);

void chooseEasyCell(easyCell** board, Player& alpha, position& pos, position& selectedCell1, position& selectedCell2, int& status, int& pair);

void createEasyBoard(easyCell**& board, Player alpha);

void createEasyRound(Player* &ranker, int quantity, Player& alpha, bool soundEffect, bool soundBackground);

void deleteCell(easyCell** board);

void paintCell(easyCell** board, int col, int row, int color);

void displayLifePoint(Player alpha);

bool checkAnyAvailable(easyCell** board);


