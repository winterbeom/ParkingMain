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




//�����
int main()
{

    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 1)
        {
            infoDraw(1);//������Ȳ
        }
        else if (menuCode == 2)
        {
            infoDraw(2); //�����ϱ�
        }
        else if (menuCode == 3)
        {
            infoDraw(3); //����ϱ�

        }
        system("cls");
    }
    return 0;
}
int keyControl() {
    int temp = _getch();
    if (temp == 224)
        temp = _getch(); //224�� ��ȯ�Ǹ� �ٽ��ѹ� ��ȯ���� ��´�
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
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// �ܼ� �ڵ� ��������
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
int menuDraw() {
    int x = 20;
    int y = 12;
    gotoxy(x - 2, y);

    cout << "> ������Ȳ" << endl;

    gotoxy(x, y + 1);
    cout << "�����ϱ�" << endl;

    gotoxy(x, y + 2);
    cout << "����ϱ� " << endl;


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
    cout << "                  �������� �ý���" << endl;
}
void infoDraw(int n) {
    switch (n) {
    case 1: {
        system("cls");
        cout << "������Ȳ" << endl;

        if (keyControl() == ENTER)
            break;

    }
    case 2: {
        system("cls");
        cout << "�����ϱ�" << endl;

        if (keyControl() == ENTER)
            break;

    }
    case 3: {
        system("cls");
        cout << "����ϱ�" << endl;

        if (keyControl() == ENTER)
            break;

    }
    }
}




