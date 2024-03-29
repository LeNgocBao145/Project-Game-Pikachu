#include "function.h"
#include "ConsoleScreen.h"
void showTitlePikachu()
{
    moveToPosition(52, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    cout << " ______    __   __  ___      ___       ______   __    __   __    __";
    moveToPosition(52, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      | |  |  |  | |  |  |  |";
    moveToPosition(52, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |   ----' |  |__|  | |  |  |  |";
    moveToPosition(52, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |      |   __   | |  |  |  |";
    moveToPosition(52, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |   ----. |  |  |  | |   --   |";
    moveToPosition(52, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______| |__|  |__|  \\______/";
}

void showTitlePokemon()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "		 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "		| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "		| |   ______     | || |     ____     | || |  ___  ____   | || |  _________   | || | ____    ____ | || |     ____     | || | ____  _____  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "		| |  |_   __ \\   | || |   .'    `.   | || | |_  ||_  _|  | || | |_   ___  |  | || ||_   \\  /   _|| || |   .'    `.   | || ||_   \\ | _ _| | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "		| |    | |__) |  | || |  /  .--.  \\  | || |   | |_/ /    | || |   | |_  \\_|  | || |  |   \\/   |  | || |  /  .--.  \\  | || |  |   \\ | |   | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    cout << "		| |    |  ___/   | || |  | |    | |  | || |   |  __'.    | || |   |  _|  _   | || |  | |\\  /| |  | || |  | |    | |  | || |  | |\\ \\| |   | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "		| |   _| |_      | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |  _| |___/ |  | || | _| |_\\/_| |_ | || |  \\  `--'  /  | || | _| |_\\   |_  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "		| |  |_____|     | || |   `.____.'   | || | |____||____| | || | |_________|  | || ||_____||_____|| || |   `.____.'   | || ||_____|\\____| | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "		| |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "		| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "		 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
}

int showLogIn()
{
    showTitlePikachu();
    drawRectangle(76, 18, 19, 8);

    int choice = 1;
    int key = 0;

    while (true) {

        if (choice == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(78, 19 + i);
                cout << "               " << endl;
            }

            moveToPosition(82, 20);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "Sign In";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(77, 19 + i);
                cout << "                " << endl;
            }

            moveToPosition(82, 20);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "Sign In";
        }

        if (choice == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(78, 22 + i);
                cout << "               " << endl;
            }

            moveToPosition(82, 23);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "Sign Up";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(78, 22 + i);
                cout << "               " << endl;
            }

            moveToPosition(82, 23);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Sign Up";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        int temp = _getch();

        if (temp != 224 && temp != 0)
        {
            if (temp == PRESS_ENTER) {
                system("cls");
                return choice;
            }
        }
        else {
            key = _getch();

            switch (key)
            {
            case PRESS_UP:

                if (choice > 1)
                {
                    choice--;
                }
                else
                {
                    choice = 2;
                }

                break;

            case PRESS_DOWN:

                if (choice < 2)
                {
                    choice++;
                }
                else
                {
                    choice = 1;
                }

                break;

            default:
                break;
            }
        }
    }
}

void drawRectangle(int x, int y, int width, int height) {
    moveToPosition(x, y);
    cout << char(201);  // góc trên bên trái

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205);  // du?ng ngang
    }

    cout << char(187);  // góc trên bên ph?i

    for (int i = 1; i < height - 1; ++i) {
        moveToPosition(x, y + i);
        cout << char(186);  // du?ng d?c bên trái
        moveToPosition(x + width - 1, y + i);
        cout << char(186);  // du?ng d?c bên ph?i
    }

    moveToPosition(x, y + height - 1);
    cout << char(200);  // góc du?i bên trái

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205);  // du?ng ngang
    }

    cout << char(188);  // góc du?i bên ph?i
}

void readFileAccount(Account*& player, int& quantityAccount)
{
    fstream file;
    string line;

    file.open("Player.txt", ios::in);

    if (file.is_open())
    {
        while (!file.eof())
        {

            getline(file, line);

            if (line.length() == 0)
            {
                break;
            }
            quantityAccount++;
        }

    }
    else
    {
        cout << "File bi loi!" << endl;
    }

    file.close();

    file.open("Player.txt");

    if (file.is_open())
    {
        player = new Account[quantityAccount];
        for (int i = 0; i < quantityAccount; i++)
        {
            getline(file, line);
            istringstream ss(line);
            getline(ss, player[i].username, ',');
            getline(ss, player[i].password, ',');
        }

    }

    file.close();

}


void displayBG(bool win)
{
    if (win) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        moveToPosition(57, 15);
        cout << " __   _____  _   _      _    ____  _____  __        _____ _   _ _   _ _____ ____  ";
        moveToPosition(57, 16);
        cout << " \\ \\ / / _ \\| | | |    / \\  |  _ \\| ____| \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\ ";
        moveToPosition(57, 17);
        cout << "  \\ V / | | | | | |   / _ \\ | |_) |  _|    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |";
        moveToPosition(57, 18);
        cout << "   | || |_| | |_| |  / ___ \\|  _ <| |___    \\ V  V /  | || |\\  | |\\  | |___|  _ < ";
        moveToPosition(57, 19);
        cout << "   |_| \\___/ \\___/  /_/   \\_\\_| \\_\\_____|    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        moveToPosition(37, 16);
        cout << " __   _____  _   _      _    ____  _____   _     ___  ____  _____ ____  ";
        moveToPosition(37, 17);
        cout << " \\ \\ / / _ \\| | | |    / \\  |  _ \\| ____| | |   / _ \\/ ___|| ____|  _ \\ ";
        moveToPosition(37, 18);
        cout << "  \\ V / | | | | | |   / _ \\ | |_) |  _|   | |  | | | \\___ \\|  _| | |_) |";
        moveToPosition(37, 19);
        cout << "   | || |_| | |_| |  / ___ \\|  _ <| |___  | |__| |_| |___) | |___|  _ < ";
        moveToPosition(37, 20);
        cout << "   |_| \\___/ \\___/  /_/   \\_\\_| \\_\\_____| |____\\___/|____/|_____|_| \\_\\";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

bool checkIsExistAccount(Account* player, int quantityAccount, string username, string password)
{
    for (int i = 0; i < quantityAccount; i++)
    {
        if (player[i].username.compare(username) == 0 && player[i].password.compare(password) == 0)
        {
            return true;
        }
    }

    return false;
}

void signInAccount(Account* player, Player& rookie, int quantityAccount) {
    createScreen(1);

    string username;
    string password;

    drawRectangle(70, 18, 30, 10);


    moveToPosition(74, 21);
    cout << "Username: ";
    getline(cin, username);

    moveToPosition(74, 24);
    cout << "Password: ";
    getline(cin, password);


    while (checkIsExistAccount(player, quantityAccount, username, password) == false)
    {
        system("cls");

        moveToPosition(55, 12);
        cout << "Username / Password is wrong or The Account does not exist!" << endl;
        moveToPosition(76, 15);
        cout << "Please try again!" << endl;
        drawRectangle(70, 18, 30, 10);


        moveToPosition(74, 21);
        cout << "Username: ";
        getline(cin, username);

        moveToPosition(74, 24);
        cout << "Password: ";
        getline(cin, password);

    }

    rookie.name = username;
}

void showLeaderBoard(Player* ranker, int quantity, Player alpha)
{

    moveToPosition(60, 3);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "LEADERBOARD";
    moveToPosition(30, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "NAME";
    moveToPosition(100, 6);
    cout << "Score";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    moveToPosition(30, 7);
    for (int i = 0; i < 75; i++) {
        cout << char(196);
    }

    for (int i = 0; i < quantity; i++)
    {
        cout << quantity << endl;
        cout << ranker[i].name << " " << ranker[i].score << endl;
    }

    Sleep(1000);

    system("cls");
}

void readLeaderBoard(Player* &ranker, Player alpha, int &quantity)
{

    ifstream f;
    f.open("Player.txt", ios::in);
    
    string line;

    if (f.is_open())
    {
        while (!f.eof())
        {
            getline(f, line);
            istringstream ss(line);
            quantity++;
        }
    }

    f.close();
    
    ifstream rank;
    rank.open("LeaderBoard.txt", ios::in);


    ranker = new Player[quantity];

    if (rank.is_open())
    {
       for(int i = 0; i < quantity; i++)
       {
            getline(rank, line);
            istringstream ss(line);
            getline(ss, ranker[i].name, ' ');
            string tmp;
            getline(ss, tmp, ' ');
            ranker[i].score = stoi(tmp);
       }
    }


    rank.close();

 


}

void updateNewPlayerLeaderBoard(Player alpha)
{
    fstream rank;
    rank.open("LeaderBoard.txt", ios::app);

    if (rank.is_open())
    {
        rank << endl;
        rank << alpha.name << " " << alpha.score;
    }


    rank.close();
}

void sortPlayer(Player* p, int quantity)
{

    for (int j = quantity - 1; j >= 0; j--)
    {
        for (int i = 0; i < quantity; i++)
        {
            if (p[i].score < p[i + 1].score)
            {
                swap(p[i].score, p[i + 1].score);
                swap(p[i].name, p[i + 1].name);
            }
        }
    }
}

void updateScore(Player* &p, Player alpha, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        if (p[i].name.compare(alpha.name) == 0)
        {
            if (p[i].score < alpha.score)
            {
                p[i].score = alpha.score;
                sortPlayer(p, quantity);
                break;
            }
        }
    }
}

void writeLeaderBoard(Player* p, int quantity)
{
    fstream rank;

    rank.open("LeaderBoard.txt", ios::out);

    if (rank.is_open())
    {
        for (int i = 0; i < quantity; i++)
        {
            rank << p[i].name << " " << p[i].score << endl;
        }
    }

    rank.close();
}

//void readLeaderBoard()
//{
//    moveToPosition(60, 3);
//
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//    cout << "LEADERBOARD";
//    moveToPosition(30, 6);
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//    cout << "NAME";
//    moveToPosition(100, 6);
//    cout << "Score";
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    moveToPosition(30, 7);
//    for (int i = 0; i < 75; i++) {
//        cout << char(196);
//    }
//
//    ifstream f;
//    f.open("leaderboard.txt");
//    if (f) {
//        Player p;
//
//        int i = 0;
//        while (getline(f, p.name, ' ')) {
//            f >> p.score;
//            f.get();
//            moveToPosition(30, 7 + i);
//            for (int j = 0; j < 75; j++)    cout << char(196);
//
//            if (i <= 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 - i / 2);
//            moveToPosition(30, 8 + i);
//            cout << p.name;
//            moveToPosition(100, 8 + i);
//            cout << p.score;
//            if (i <= 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//            i += 2;
//        }
//        f.close();
//    }
//    _getch();
//    system("cls");
//}

//void writeLeaderBoard(Player p)
//{
//    ifstream fin("leaderboard.txt");
//    if (fin) {
//        Player* rank = new Player[10];
//        int n = 0;
//        string s;
//
//        while (getline(fin, s, ' ')) {
//            rank[n].name = s;
//            fin >> rank[n].score;
//            fin.get();
//            n++;
//        }
//
//        int index = n - 1;
//        for (index; index >= 0; index--) {
//            if (p.score <= rank[index].score) {
//                break;
//            }
//        }
//
//        if (n < 10) {
//            for (int i = n; i > index + 1; i--) {
//                rank[i] = rank[i - 1];
//            }
//            rank[index + 1] = p;
//            n++;
//        }
//        else {
//            if (index != n - 1) {
//                for (int i = n - 1; i > index + 1; i--) {
//                    rank[i] = rank[i - 1];
//                }
//                rank[index + 1] = p;
//            }
//        }
//        fin.close();
//
//
//        ofstream fout("leaderboard.txt");
//
//        for (int i = 0; i < n; i++) {
//            fout << rank[i].name << " " << rank[i].score << endl;
//        }
//
//        fout.close();
//
//        delete[]rank;
//    }
//    else {
//        ofstream fout("leaderboard.txt");
//        fout << p.name << " " << p.score << endl;
//        fout.close();
//    }
//}

void signUpAccount(Player& alpha)
{

    createScreen(1);

    string username;
    string password;

    drawRectangle(70, 18, 30, 10);


    moveToPosition(74, 21);
    cout << "Username: ";
    getline(cin, username);

    moveToPosition(74, 24);
    cout << "Password: ";
    getline(cin, password);

    writeFileAccount(username, password);

    alpha.name = username;
    updateNewPlayerLeaderBoard(alpha);
}

void writeFileAccount(string Username, string Password)
{

    fstream Account;

    Account.open("Player.txt", ios::app);

    if (Account.is_open())
    {
        Account << endl;
        Account << Username << "," << Password;
    }

    Account.close();
}



void showGameMode(Player*& ranker, int quantity, Player& alpha, bool soundEffect, bool soundBackground)
{
    showTitlePikachu();

    int choice = 1;
    int key = 0;

    drawRectangle(50, 25, 20, 5);
    drawRectangle(100, 25, 20, 5);

    while (true) {

        if (choice == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(58, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 3);
            cout << "EASY";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(51, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(58, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "EASY";
        }

        if (choice == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(108, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112 + 4);
            cout << "HARD";
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++) {
                moveToPosition(101, 26 + i);
                cout << "                  " << endl;
            }

            moveToPosition(108, 27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "HARD";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        int temp = _getch();

        if (temp != 224 && temp != 0)
        {
            if (temp == PRESS_ENTER) {
                system("cls");
                break;
            }
        }
        else {
            key = _getch();

            switch (key)
            {
            case PRESS_LEFT:

                if (choice > 1)
                {
                    choice--;
                }
                else
                {
                    choice = 2;
                }

                break;

            case PRESS_RIGHT:

                if (choice < 2)
                {
                    choice++;
                }
                else
                {
                    choice = 1;
                }

                break;

            default:
                break;
            }
        }
    }

    if (choice == 1)
    {
        createEasyRound(ranker, quantity, alpha, soundEffect, soundBackground);
    }
    else
    {
        createHardRound(alpha, soundEffect, soundBackground);
    }
}