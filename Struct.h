#pragma once
#include <string>
#include <iostream>

using namespace std;

struct position {
	int x;
	int y;
};

struct Player {
	string name;
	int score = 0;
	int life = 3;
};

struct Account {
	string username;
	string password;
};

struct easyCell {
	position pos;
	char data;
	bool isAvailable = true;
	bool isChoosen = false;
};

struct hardCell {
	position pos;
	int row;
	int col;
	char data;
	hardCell* next;
	bool isAvailable = true;
	bool isChoosen = false;
};