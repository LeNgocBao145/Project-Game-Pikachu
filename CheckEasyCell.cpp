#include "CheckEasyCell.h"

using namespace std;

// Kiểm tra xem hai ô có nằm kế nhau và có cùng giá trị không
bool areAdjacent(easyCell** board, int p1, int p2, int q1, int q2) 
{
    if ((p1 == q1 + 1 || p1 == q1 - 1) && (p2 == q2)) {
        if (board[p1][p2].data == board[q1][q2].data)
            return true;
    }
    if ((p2 == q2 + 1 || p2 == q2 - 1) && (p1 == q1)) {
        if (board[p1][p2].data == board[q1][q2].data)
            return true;
    }
    return false;
}

// Kiểm tra xem các ô trên cùng một hàng hoặc cùng một cột có thể tạo thành đường đi hợp lệ không
bool isLineValid(easyCell** board, int p1, int p2, int q1, int q2) 
{
    if (p1 == q1) {
        int y, x, count = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x; i <= y; i++) {
            if (board[p1][i].isAvailable) {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[p1][p2].isAvailable && board[q1][q2].isAvailable) || (board[p1][p2].isAvailable && !board[q1][q2].isAvailable))) {
            return true;
        }
        else if (count == 0) {
            return true;
        }
        return false;
    }
    if (p2 == q2) {
        int x, y, count = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x; i <= y; i++) {
            if (board[i][p2].isAvailable) {
                count++;
                if (count == 2) return false;
            }
        }
        if ((count == 1) && ((!board[p1][p2].isAvailable && board[q1][q2].isAvailable) || (board[p1][p2].isAvailable && !board[q1][q2].isAvailable))) {
            return true;
        }
        else if (count == 0) {
            return true;
        }
        return false;
    }
    return false;
}

// Kiểm tra xem hai ô có tạo thành đường thẳng không
bool Icheck(easyCell** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1) {
        int y, x, dem = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[p1][i].isAvailable) {
                return false;
            }
        }
        return true;
    }
    if (p2 == q2) {
        int x, y, dem = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[i][p2].isAvailable) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Kiểm tra xem hai ô có tạo thành hình L không
bool Lcheck(easyCell** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2;
    if (!board[p1][q2].isAvailable) {
        c1 = isLineValid(board, p1, p2, p1, q2);
        c2 = isLineValid(board, q1, q2, p1, q2);
        if (c1 && c2) {
            return true;
        }
    }
    if (!board[q1][p2].isAvailable) {
        c1 = isLineValid(board, p1, p2, q1, p2);
        c2 = isLineValid(board, q1, q2, q1, p2);
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}

// Kiểm tra xem hai ô có tạo thành hình Z không
bool Zcheck(easyCell** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = isLineValid(board, p1, i, q1, i);
        if (c3) {
            c1 = isLineValid(board, p1, p2, p1, i);
            c2 = isLineValid(board, q1, q2, q1, i);
            if (c1 && c2)
                return true;
        }
    }
    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = isLineValid(board, i, p2, i, q2);
        if (c3) {
            c1 = isLineValid(board, p1, p2, i, p2);
            c2 = isLineValid(board, q1, q2, i, q2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}

// Kiểm tra xem hai ô có tạo thành hình U không
bool Ucheck(easyCell** board, int p1, int p2, int q1, int q2) {
    if (((p1 == q1) && (p1 == 0 || p1 == EASYBOARDLENGTH - 1) || ((p2 == q2) && (p2 == 0 || q2 == EASYBOARDWIDTH - 1)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = 0; i < EASYBOARDWIDTH; i++) {
        if (i <= x || i >= y) {
            c3 = isLineValid(board, p1, i, q1, i);
            if (c3) {
                c1 = isLineValid(board, p1, p2, p1, i);
                c2 = isLineValid(board, q1, q2, q1, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (EASYBOARDWIDTH - 1)) {
                c1 = isLineValid(board, p1, p2, p1, i);
                c2 = isLineValid(board, q1, q2, q1, i);
                if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
                    return true;
                }
            }
        }
    }

    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = 0; i < EASYBOARDLENGTH; i++) {
        if (i <= x || i >= y) {
            c3 = isLineValid(board, i, p2, i, q2);
            if (c3) {
                c1 = isLineValid(board, p1, p2, i, p2);
                c2 = isLineValid(board, q1, q2, i, q2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (EASYBOARDLENGTH - 1)) {
                c1 = isLineValid(board, p1, p2, i, p2);
                c2 = isLineValid(board, q1, q2, i, q2);
                if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Kiểm tra xem hai ô có thể tạo thành đường đi hợp lệ không
bool areAllValid(easyCell** board, int p1, int p2, int q1, int q2) 
{
    if (areAdjacent(board, p1, p2, q1, q2)) 
        return true;

    if (Icheck(board, p1, p2, q1, q2)) 
        return true;
 
    if (Lcheck(board, p1, p2, q1, q2)) 
        return true;

    if (Zcheck(board, p1, p2, q1, q2)) 
        return true;

    if (Ucheck(board, p1, p2, q1, q2)) 
        return true;
    
    return false;
}

// Kiểm tra xem các cặp ô có thể tạo thành đường đi hợp lệ không
bool hasValidPairs(easyCell** board) 
{
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int count = 0;
        int* pos = new int[EASYBOARDLENGTH * EASYBOARDWIDTH];
        for (int i = 0; i < EASYBOARDLENGTH; i++) {
            for (int j = 0; j < EASYBOARDWIDTH; j++) {
                if (board[i][j].data == check && board[i][j].isAvailable) {
                    pos[count++] = i;
                    pos[count++] = j;
                }
            }
        }
        for (int i = 0; i < count - 2; i += 2) {
            for (int j = i + 2; j < count; j += 2) {
                if (areAllValid(board, pos[i], pos[i + 1], pos[j], pos[j + 1]) == true) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}
