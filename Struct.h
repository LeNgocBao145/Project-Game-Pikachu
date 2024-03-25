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
	bool isAvailable = 1;
	bool isChoosen = 0;
};

struct hardCell {
	position pos;
	char data;
	hardCell* next;
	bool isAvailable;
	bool isChoosen = 0;
};