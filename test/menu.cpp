#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>//??????
#include <conio.h>
#include "menu.h"

//#include "text_mas_menu.h"

#define KEY_UP 72 //�� ��������� ���������� ���  KEY_UP -- 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13

using namespace std;

int nomerstrokimenu = 1;  

int startMenuCycle(string *mas_menu,  int kolstrokmenu)// ������� ���������� ����� � ������������ ������� ����
{
	system("cls");
	{
		string result;
		for (int i = 0; i < kolstrokmenu; i++)
		{
			if (i == nomerstrokimenu)

				result.append("-> " + mas_menu[i] + "\n");    //append ��������� ->
			else result.append(mas_menu[i] + "\n");
		}

		cout << result; //����� ����
	}
	int code;
	code = _getch(); //����� ������� �����
	switch (code)
	{
	case KEY_DOWN:
		if (nomerstrokimenu == kolstrokmenu - 1) break;
		else nomerstrokimenu++;
		break;

	case KEY_UP:
		if (nomerstrokimenu == 1) break; //����������� if, ����� �� ������ ���������� ����� �������� ����� ���� � ����� �����
		else nomerstrokimenu--;
		break;

	case KEY_RETURN:
		system("cls");
		return nomerstrokimenu;
		break;
	}

	//cout << sizeof(mas_menu) / sizeof(*mas_menu);
	startMenuCycle(mas_menu, kolstrokmenu);
}
