#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>//��� _getch()
#include "plane.h"

#define KEY_UP 72 //�� ��������� ���������� ���  KEY_UP -- 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13

using namespace std;


int startMenuCycle(string *mas_menu, int kolstrokmenu)// ������� ���������� ����� � ������������ ������� ����
{
	int nomerstrokimenu = 1;
	do
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
		code = _getch(); //���������� ������� ������
		switch (code)
		{
		case KEY_DOWN:
			if (nomerstrokimenu == kolstrokmenu - 1)
			{
				nomerstrokimenu = 1;
				break;
			}
			else nomerstrokimenu++;
			break;

		case KEY_UP:
			if (nomerstrokimenu == 1)
			{
				nomerstrokimenu =kolstrokmenu - 1;
				break; //����������� if, ����� �� ������ ���������� ����� �������� ����� ���� � ����� �����
			}
			else nomerstrokimenu--;
			break;

		case KEY_RETURN:
			system("cls");
			return nomerstrokimenu;
			break;
		}

	} while (true);

}
