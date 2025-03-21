#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "Struct.h"
#include <winuser.h>
#include <fstream>
#include <sstream>
#include <string>
#include "EasyMode.h"
#include "HardMode.h"
#include "CheckEasyCell.h"
#include "CheckHardMode.h"
#include "SoundSettings.h"

#define EASYBOARDLENGTH 6
#define EASYBOARDWIDTH 6

#define HARDBOARDLENGTH 8
#define HARDBOARDWIDTH 9

#define PRESS_UP 72
#define PRESS_DOWN 80
#define PRESS_LEFT 75
#define PRESS_RIGHT 77
#define PRESS_ENTER 13
#define PRESS_ESC 27

using namespace std;

//Di chuyen con tro den vi tri co toa do x va y
void moveToPosition(int x, int y);

//Hien thi man hinh menu lua chon
int showMainMenu(bool soundBackground, bool soundEffect);


//Hien thi tieu de chu PIKACHU
void showTitlePikachu();

//Hien thi tieu de chu POKEMON
void showTitlePokemon();

//Hien thi giao dien Dang nhap / Dang ki
int showLogIn();
void signUpAccount(Player& alpha);
void signInAccount(Account* player, Player& rookie, int quantityAccount);

bool checkIsExistAccount(Account* player, int quantityAccount, string username, string password);
void readFileAccount(Account*& player, int& quantityAccount);
void writeFileAccount(string Username, string Password);

//Ve khung hinh chu nhat
void drawRectangle(int x, int y, int width, int height);

//void readFileAccount(AccountVip*& reader, int& quantityAccount, fstream& Account);
//void writeFileAccount(int& quantityAccount, fstream& Account);
//bool checkIsExistAccount(AccountVip* reader, int quantityAccount, string tendangnhap, string matkhau);
//bool Login(AccountVip* reader, int& quantityAccount, fstream& Account);


void readLeaderBoard(Player* &ranker, Player alpha, int& quantity);
void updateNewPlayerLeaderBoard(Player alpha);
void updateScore(Player* &p, Player alpha, int quantity);
void writeLeaderBoard(Player* p, int quantity);
void sortPlayer(Player* p, int quantity);
void showLeaderBoard(Player* ranker, int quantity, Player alpha);

int showSoundSettings();
void editSoundSettings(bool& soundBackground, bool& soundEffect);
void editMusicBackground(bool& soundBackground);
void editSoundEffect(bool& soundEffect);
void showGameMode(Player*& ranker, int quantity, Player& alpha, bool soundEffect, bool soundBackground);
void displayBG(bool win);