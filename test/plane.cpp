#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "plane.h" //обь€вление класа
#include "menu.h" // реализацы€ мею
#include <windows.h>	

#define KEY_UP 72 //по стандарту определ€ет что  KEY_UP -- 72
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

	cout << "¬ведите номер рейса\n";
	cin >> nober;
	nomber_reis = nober;


	type_plenet = type_mas_planet[startMenuCycle(type_mas_planet, kolstrokmenu)];
	system("cls");

	string str;//локальна€ переменна€ пункта назначени€
	cout << "¬ведите пункт назначени€" << endl;
	cin >> str;
	point_plein = str;

	system("cls");



	// преобразует врем€ с одного числа с зап€той в 2 целих
	int x, i;
	i = 0;
	float y;
	cout << "¬ведите врем€ вылета." << endl;
	do
	{
		cout << "¬ведите количество часов" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "вы ввели не коректные даные. ¬едите заново" << endl;
		}
		else
		{
			do
			{
				cout << "¬ведите количество минут" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "вы ввели не коректные даные. ¬едите заново" << endl;
				}
				else
				{
					y = y / 100;
					y = x + y;
				}
			} while (y >= 60 || y < 0);
		}

	} while (x >= 24 || x < 0);

	stringstream ss, yy; // дл€ переобразавани€ float в string
	ss << y;
	ss >> str;

	time_vilet = str;


	x = 0;
	y = 0;
	str = "";

	cout << "¬ведите врем€ ѕрибыти€." << endl;
	do
	{
		cout << "¬ведите количество часов" << endl;
		cin >> x;
		if (x >= 24 || x < 0)
		{

			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "вы ввели не коректные даные. ¬едите заново" << endl;
		}
		else
		{
			do
			{
				cout << "¬ведите количество минут" << endl;
				cin >> y;
				if (y >= 60 || y < 0)
				{
					i = i + 1;;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "вы ввели не коректные даные. ¬едите заново" << endl;
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

void plane::save_text(string neme_file)
{


		ofstream file(neme_file, ios::app); // file -переменна€ файла к которому обращ€емс€
		file<< nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_finish << endl;
		file.close();
	
}
void plane::save_text_dop()
{	
	
	fstream filename;
	fstream file("./data/DFD", ios::app);
	
	file << endl << nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_finish << endl;
	file.close();

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

void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data)
{
	int zapis,  gt, gd;

	zapis = 1;


	plane *numbers;
	plane *numbers2;
	numbers = new plane[zapis];
	numbers2 = new plane[zapis];
	delete[]numbers2;
	numbers[0].vvod_nap_klav(type_mas_planet);



	do
	{
		gd = startMenuCycle(yes_no, 3);
		
		
		if (gd == 1)
		{
			gd = 1;
			if (0 == zapis % 2)
			{
				zapis++;
				numbers = new plane[zapis];
				for (int j = 0; j < zapis - 1; j++)
				{
					numbers[j] = numbers2[j];
				}
				numbers[zapis - 1].vvod_nap_klav(type_mas_planet);
				delete[] numbers2;

			}
			else
			{
				zapis++;
				numbers2 = new plane[zapis];
				for (int j = 0; j < zapis - 1; j++)
				{
					numbers2[j] = numbers[j];
				}
				numbers2[zapis - 1].vvod_nap_klav(type_mas_planet);
				delete[] numbers;

			}
		}



	} while (gd == 1);
	(CreateDirectory(L"./data", NULL));//создаЄт папку data (возвращ€ет 1) и не создаЄт папку если она уже создана (возвращ€ет 0)


	gt = startMenuCycle(zapis_data, 3);
	
	switch (gt)
	{
	case 1:
	{
		if (0 == zapis % 2)
		{
			cout << "¬ведите им€ файла" << endl;
			string neme_file1;
			string neme_file;
			cin.get();
			getline(cin,neme_file1);
			
			neme_file.append("./data/"+neme_file1 );
			
	

			for (int i = 0; i < zapis; i++)
			{
				numbers2[i].save_text(neme_file);
			}
			delete[] numbers2;
		}
		else
		{

			cout << "¬ведите им€ файла" << endl;
			string neme_file;
			string neme_file1;
			cin.get();
			getline(cin, neme_file1);
			neme_file.append("./data/" + neme_file1);

			for (int i = 0; i < zapis; i++)
			{
				
				numbers[i].save_text(neme_file);
			}
			delete[] numbers;
		}
	}break;
	case 2:
	{
		if (0 == zapis % 2)
		{
			for (int i = 0; i < zapis; i++)
			{
				

				numbers2[i].save_text_dop();
			}
			delete[] numbers2;
		}
		else
		{


			for (int i = 0; i < zapis; i++)
			{
				numbers[i].save_text_dop();
			}
			delete[] numbers;
		}
	}break;
	}

}
