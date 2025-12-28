#include <iostream>
#include <windows.h> // Sleep()
#include <conio.h>   // _kbhit(), _getch()
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;

// 遊戲場地
int field[HEIGHT][WIDTH];

// 方塊位置
int blockX = WIDTH / 2;
int blockY = 0;

// 初始化場地
void initField() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
                field[y][x] = 1;  // 牆
            else
                field[y][x] = 0;  // 空白
        }
    }
}

// 畫場地
void drawField() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x] == 1)
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }
}

// 畫直線方塊（4 格）
void drawBlock() {
    for (int i = 0; i < 4; i++) {
        field[blockY + i][blockX] = 1;
    }
}

// 清除方塊
void clearBlock() {
    for (int i = 0; i < 4; i++) {
        field[blockY + i][blockX] = 0;
    }
}

// 能不能往下
bool canMoveDown() {
    return (blockY + 4 < HEIGHT - 1);
}

// 能不能往左
bool canMoveLeft() {
    return (blockX - 1 > 0);
}

// 能不能往右
bool canMoveRight() {
    return (blockX + 1 < WIDTH - 1);
}

int main() {
    initField();
    drawBlock();
    drawField();

    while (true) {
        // 鍵盤控制
        if (_kbhit()) {
            char key = _getch();
            clearBlock();

            if (key == 'a' || key == 'A') {
                if (canMoveLeft())
                    blockX--;
            }
            else if (key == 'd' || key == 'D') {
                if (canMoveRight())
                    blockX++;
            }

            drawBlock();
            drawField();
        }

        // 自動下落
        Sleep(300);
        clearBlock();

        if (canMoveDown())
            blockY++;
        else
            break; // 碰到底

        drawBlock();
        drawField();
    }

    cout << "Game Over!" << endl;
    system("pause");
    return 0;
}


