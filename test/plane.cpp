#include "pch.h"
#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include "plane.h" //обьявление класа
#include "menu.h" // реализацыя мею
#include <istream>


#define KEY_UP 72 //по стандарту определяет что  KEY_UP -- 72
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

	cout << "Введите номер рейса\n";
	cin >> nober;
	nomber_reis = nober;


	type_plenet = type_mas_planet[startMenuCycle(type_mas_planet, kolstrokmenu)];
	system("cls");

	string str;//локальная переменная пункта назначения
	cout << "Введите пункт назначения" << endl;
	cin >> str;
	point_plein = str;

	system("cls");



	// преобразует время с одного числа с запятой в 2 целих
	int x, i;
	i = 0;
	float y, z;
	cout << "Введите время вылета." << endl;
	do
	{
		cout << "Введите количество часов" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "вы ввели не коректные даные. Ведите заново" << endl;
		}
		else
		{
			do
			{
				cout << "Введите количество минут" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "вы ввели не коректные даные. Ведите заново" << endl;
				}
				else
				{
					y = y / 100;
					y = x + y;
				}
			} while (y >= 60 || y < 0);
		}

	} while (x >= 24 || x < 0);

	stringstream ss, yy; // для переобразавания float в string
	ss << y;
	ss >> str;

	time_vilet = str;


	x = 0;
	y = 0;
	str = "";

	cout << "Введите время Прибытия." << endl;
	do
	{
		cout << "Введите количество часов" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "вы ввели не коректные даные. Ведите заново" << endl;
		}
		else
		{
			do
			{
				cout << "Введите количество минут" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "вы ввели не коректные даные. Ведите заново" << endl;
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
