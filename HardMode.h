#pragma once
#include "function.h"

hardCell* createCell(char data);

void addTailCell(hardCell*& pHead, int row, int col, char data);

void randomHardCell(hardCell*& pHead);

void drawHardBox(int x, int y, hardCell* pHead);

bool checkExist(int* nums, int index, int num);

void selectHardCell(hardCell* pHead);

void createHardBoard(hardCell* pHead, Player alpha);

void chooseHardCell(hardCell* board, Player& alpha, position& pos, position& selectedCell1, position& selectedCell2, int& status, int& pair);

void createHardRound(Player& alpha, bool soundEffect, bool soundBackground);

void paintHardCell(hardCell* board, int row, int col, int color);

void chooseToPlayHardMode(Player& alpha, bool soundEffect, bool soundBackground);

hardCell* findNode(hardCell* pHead, int row, int col);

void deleteHardCell(hardCell* board, int row, int col);

bool checkAnyAvailable(hardCell* board);