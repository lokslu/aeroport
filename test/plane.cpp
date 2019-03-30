#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream> //для  stringstream  // для переобразавания float в string
#include <string>
#include <vector>
#include <stdio.h>//
#include <windows.h>
#include "plane.h" //обьявление класа
#include "menu.h" // реализацыя меню
#include "dirent.h"//
#include <filesystem>


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
	float y;
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
void plane::save_text(string neme_file)
{


		ofstream file(neme_file, ios::app); // file -переменная файла к которому обращяемся
		file<< nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_finish << endl;
		file.close();
	
}
void plane::save_text_dop(string neme_file)
{	
	
	
	fstream file(neme_file, ios::app);
	
	file << nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_finish << endl;
	file.close();

}
void plane::read_text(string name_str)
{
	string pyth_k_file=fynk_read_file();
	ifstream file(pyth_k_file, ios::in);
	

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
	int zapis, gt, gd;

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
	(CreateDirectory(L"./data", NULL));//создаёт папку data (возвращяет 1) и не создаёт папку если она уже создана (возвращяет 0)


	gt = startMenuCycle(zapis_data, 3);

	switch (gt)
	{
	case 1:
	{
		cout << "Введите имя файла" << endl;
		string neme_file;
		string neme_file1;
		cin.get();
		getline(cin, neme_file1);
		neme_file.append("./data/" + neme_file1);
		if (0 == zapis % 2)
		{
			for (int i = 0; i < zapis; i++)
			{
				numbers2[i].save_text(neme_file);
			}
			delete[] numbers2;
		}
		else
		{
			for (int i = 0; i < zapis; i++)
			{
				numbers[i].save_text(neme_file);
			}
			delete[] numbers;
		}
	}
	break;
	case 2:
	{


		string neme_file = fynk_read_file();

		if (neme_file == "%$%")
		{
			system("cls");
			cout << "У вас нету не единого файла/n";
			system("pause");
			break;
		}

			if (0 == zapis % 2)
			{
				for (int i = 0; i < zapis; i++)
				{
					numbers2[i].save_text_dop(neme_file);
				}
				delete[] numbers2;
			}
			else
			{


				for (int i = 0; i < zapis; i++)
				{
					numbers[i].save_text_dop(neme_file);
				}
				delete[] numbers;
			}

		

	}
	break;
	}

}

string fynk_read_file()
{



	vector<string> l;

	//header('Content-Type: text/html; charset=utf-8'); //ПЕРЕКЛЮЧАЕТ ТИП ШИФРОВАНИЯ

	namespace fs = std::experimental::filesystem;
	{

		int h = 0;
		fs::path p;
		for (const auto & entry : fs::directory_iterator("./data"))
		{
			p = entry.path();

			//ff[h]= p.string();
			l.emplace_back(p.string());
			//h++;
		}



		int size_din_mas_menu = size(l) + 1;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!! то что не позволит вивести пустое меню
		if (size_din_mas_menu <= 1)
		{
			return "%$%";
		}
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		string *lp = new string[size_din_mas_menu];
		lp[0] = "Выбирете файл:";
		h = 0;
		for (int i = 1; i < size_din_mas_menu; i++)
		{

			lp[i] = l[h];
			lp[i].erase(0, 7);
			h++;
		}



		int menunom;
		menunom = startMenuCycle(lp, size_din_mas_menu);

		string neme_file;

		neme_file.append("./data/" + lp[menunom]);
		delete[] lp;
		return neme_file;
	}
}