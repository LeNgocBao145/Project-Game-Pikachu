#pragma once
#include "Struct.h"
#include "function.h"
bool areAdjacent(easyCell** board, int p1, int p2, int q1, int q2);
bool isLineValid(easyCell** board, int p1, int p2, int q1, int q2);
bool Icheck(easyCell**, int p1, int p2, int q1, int q2);
bool Lcheck(easyCell**, int p1, int p2, int q1, int q2);
bool Zcheck(easyCell**, int p1, int p2, int q1, int q2);
bool Ucheck(easyCell**, int p1, int p2, int q1, int q2);
bool areAllValid(easyCell** board, int p1, int p2, int q1, int q2);
bool hasValidPairs(easyCell** board);
