#include "board.h"
#include "color.h"
#include <iostream>
#include "C:\raylib\raylib\src\raylib.h"

using namespace std;

Board::Board() {
    rows = 20;
    cols = 10;
    cellSz = 30; 
    Initialize();
    color = getCellColor();
}

void Board::Initialize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 0;
        }
    }
}

void Board::displayPrint() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Board::drawBoard() {
    int startX = (GetScreenWidth() - cols * cellSz) / 2;
    int startY = (GetScreenHeight() - rows * cellSz) / 2;
    int borderWidth = 20; 
    int borderPad = 10; 
    Color borderColor = lightgray; 
    DrawRectangleRounded(
        Rectangle{ float(startX - borderPad), float(startY - borderPad), 
                   float(cols * cellSz + 2 * borderPad), float(rows * cellSz + 2 * borderPad) },
        0.05f,
        borderWidth,
        borderColor
    );
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            DrawRectangle(startX + j * cellSz + 1, startY + i * cellSz + 1, cellSz - 1, cellSz - 1, color[board[i][j]]);
        }
    }
}

bool Board::checkBounds(int x, int y) {
    return !(x >= 0 && x < rows && y >= 0 && y < cols);
}

bool Board::checkCollision(int x, int y) {
    if (board[x][y] == 0) {
        return true;
    }
    return false;
}

bool Board::checkLine(int x) {
    for (int i = 0; i < cols; i++) {
        if (board[x][i] == 0) {
            return false;
        }
    }
    return true;
}

int Board::clearLineAll() {
    int linesCleared = 0;
    for (int i = rows - 1; i >= 0; i--) {
        if (checkLine(i)) {
            clearLine(i);
            linesCleared++;
        }
        else if (linesCleared > 0) {
            moveLineDown(i, linesCleared);
        }
    }
    return linesCleared;
}

void Board::clearLine(int x) {
    for (int i = 0; i < cols; i++) {
        board[x][i] = 0;
    }
}

void Board::moveLineDown(int x, int rows) {
    for (int i = 0; i < cols; i++) {
        board[x + rows][i] = board[x][i];
        board[x][i] = 0;
    }
}
