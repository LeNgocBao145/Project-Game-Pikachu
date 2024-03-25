#pragma once
#include "function.h"

hardCell* createCell(char data);

void addTailCell(hardCell*& pHead, char data);

void randomHardCell(hardCell*& pHead);

void drawHardBox(int x, int y, hardCell* pHead);

bool checkExist(int* nums, int index, int num);

void selectHardCell(hardCell* pHead);

void createHardBoard(hardCell* pHead);

void chooseCell(easyCell** board, position& pos, int& status);

void createHardRound();