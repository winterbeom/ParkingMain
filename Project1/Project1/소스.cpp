#include <iostream>
#include <conio.h>
#include <Windows.h>
#define UP 1
#define DOWN 2
#define ENTER 3

using namespace std;
int keyControl();
int menuDraw();
void gotoxy(int, int);
void titleDraw();
void infoDraw(int);




//→←↑↓
int main()
{

    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 1)
        {
            infoDraw(1);//주차현황
        }
        else if (menuCode == 2)
        {
            infoDraw(2); //주차하기
        }
        else if (menuCode == 3)
        {
            infoDraw(3); //대기하기

        }
        system("cls");
    }
    return 0;
}
int keyControl() {
    int temp = _getch();
    if (temp == 224)
        temp = _getch(); //224가 반환되면 다시한번 반환값을 얻는다
    if (temp == 72)
        return UP;
    else if (temp == 80)
        return DOWN;
    else if (temp == 13)
        return ENTER;
    /*else if (temp == 's')
        return DOWN;
    else if (temp == 'd')
        return RIGHT;
        */
}
void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// 콘솔 핸들 가져오기
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
int menuDraw() {
    int x = 20;
    int y = 12;
    gotoxy(x - 2, y);

    cout << "> 주차현황" << endl;

    gotoxy(x, y + 1);
    cout << "주차하기" << endl;

    gotoxy(x, y + 2);
    cout << "대기하기 " << endl;


    while (1)
    {
        int num = keyControl();
        switch (num)
        {
        case UP: {
            if (y > 12)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");

            }
            break;
        }

        case DOWN: {
            if (y < 14)
            {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");

            }
            break;
        }
        case ENTER: {
            return y - 11;

        }
        }
    }
}
void titleDraw()
{
    cout << "\n" << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    cout << "                  무인주차 시스템" << endl;
}
void infoDraw(int n) {
    switch (n) {
    case 1: {
        system("cls");
        cout << "주차현황" << endl;

        if (keyControl() == ENTER)
            break;

    }
    case 2: {
        system("cls");
        cout << "주차하기" << endl;

        if (keyControl() == ENTER)
            break;

    }
    case 3: {
        system("cls");
        cout << "대기하기" << endl;

        if (keyControl() == ENTER)
            break;

    }
    }
}




