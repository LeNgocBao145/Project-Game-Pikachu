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
int showMainMenu();

//Phat nhac hieu ung khi chien thang, thua hay an 
void playMusicEffect();

//Phat nhac nen
void playMusicBackground();

//Hien thi tieu de chu PIKACHU
void showTitlePikachu();

//Hien thi tieu de chu POKEMON
void showTitlePokemon();

//Hien thi giao dien Dang nhap / Dang ki
int showLogIn();
void signUpAccount();
void signInAccount(Account* player, int quantityAccount);

//Ve khung hinh chu nhat
void drawRectangle(int x, int y, int width, int height);

//void readFileAccount(AccountVip*& reader, int& quantityAccount, fstream& Account);
//void writeFileAccount(int& quantityAccount, fstream& Account);
//bool checkIsExistAccount(AccountVip* reader, int quantityAccount, string tendangnhap, string matkhau);
//bool Login(AccountVip* reader, int& quantityAccount, fstream& Account);
