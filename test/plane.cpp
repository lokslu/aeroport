#include "pch.h"
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include "plane.h" //���������� �����
#include "menu.h" // ���������� ���
#include <istream>


#define KEY_UP 72 //�� ��������� ���������� ���  KEY_UP -- 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13


using namespace std;


plane::plane()
{
}


void plane::vvod_nap_klav(string*type_mas_planet)
{


	{
	int nober, kolstrokmenu;
	kolstrokmenu = 4;

	cout << "������� ����� �����\n";
	cin >> nober;
	nomber_reis = nober;


	type_plenet = type_mas_planet[startMenuCycle(type_mas_planet, kolstrokmenu)];
	system("cls");

	string str;//��������� ���������� ������ ����������
	cout << "������� ����� ����������" << endl;
	cin >> str;
	point_plein = str;

	system("cls");



	// ����������� ����� � ������ ����� � ������� � 2 �����
	int x, i;
	i = 0;
	float y, z;
	cout << "������� ����� ������." << endl;
	do
	{
		cout << "������� ���������� �����" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "�� ����� �� ��������� �����. ������ ������" << endl;
		}
		else
		{
			do
			{
				cout << "������� ���������� �����" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "�� ����� �� ��������� �����. ������ ������" << endl;
				}
				else
				{
					y = y / 100;
					y = x + y;
				}
			} while (y >= 60 || y < 0);
		}

	} while (x >= 24 || x < 0);

	stringstream ss, yy; // ��� ��������������� float � string
	ss << y;
	ss >> str;

	time_vilet = str;


	x = 0;
	y = 0;
	str = "";

	cout << "������� ����� ��������." << endl;
	do
	{
		cout << "������� ���������� �����" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "�� ����� �� ��������� �����. ������ ������" << endl;
		}
		else
		{
			do
			{
				cout << "������� ���������� �����" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "�� ����� �� ��������� �����. ������ ������" << endl;
				}
				else
				{
					y = y / 100;
					y = x + y;
				}
			} while (y >= 60 || y < 0);
		}

	} while (x >= 24 || x < 0);

	yy << y;
	yy >> str;

	time_finish = str;

}

}

void plane::save_text()
{
		system("cls");
	cout << nomber_reis << ",\n" << type_plenet << ",\n" << point_plein << ",\n" << time_vilet << ",\n" << time_finish <<endl;
	system("pause");




}

void plane::read_text()
{
}


void plane::search_for_dest()
{
}

void plane::vivod_cmd()
{
}

	
plane::~plane()
{
}
