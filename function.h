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

#define EASYBOARDLENGTH 6
#define EASYBOARDWIDTH 6

#define HARDBOARDLENGTH 10
#define HARDBOARDWIDTH 10

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

//Phat nhac hieu ung khi chien thang, thua hay an 
void playMusicEffect(bool soundEffect);

//Phat nhac nen
void playMusicBackground(bool soundBackground);

//Hien thi tieu de chu PIKACHU
void showTitlePikachu();

//Hien thi tieu de chu POKEMON
void showTitlePokemon();

//Hien thi giao dien Dang nhap / Dang ki
int showLogIn();
void signUpAccount();
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

void writeLeaderBoard(Player p);
void readLeaderBoard();

int showSoundSettings();
void editSoundSettings(bool& soundBackground, bool& soundEffect);
void editMusicBackground(bool& soundBackground);
void editSoundEffect(bool& soundEffect);
void showGameMode();