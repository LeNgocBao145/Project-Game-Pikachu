#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Player {
	string name;
	int score = 0;
	int life = 3;
};

struct Account {
	string username;
	string password;
};