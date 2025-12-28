#include <iostream>
#include <windows.h> // Sleep()
using namespace std;

// 遊戲大小
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
                field[y][x] = 1;  // 牆壁
            else
                field[y][x] = 0;  // 空白
        }
    }
}

// 畫出場地
void drawField() {
    system("cls"); // 清畫面

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

// 畫出方塊（直線 4 格）
void drawBlock() {
    for (int i = 0; i < 4; i++) {
        field[blockY + i][blockX] = 1;
    }
}

// 清掉方塊（移動前用）
void clearBlock() {
    for (int i = 0; i < 4; i++) {
        field[blockY + i][blockX] = 0;
    }
}

// 檢查能不能往下
bool canMoveDown() {
    if (blockY + 4 >= HEIGHT - 1)
        return false;
    return true;
}

// 主程式
int main() {
    initField();

    while (true) {
        clearBlock();

        if (canMoveDown())
            blockY++;
        else
            break; // 碰到底，結束遊戲

        drawBlock();
        drawField();

        Sleep(300); // 控制下落速度
    }

    cout << "Game Over!" << endl;
    system("pause");
    return 0;
}

