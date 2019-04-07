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
#include <conio.h>


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

	//!!!!!!!!!!!!!!!!!!!!!!!!
	int nober, kolstrokmenu;
	kolstrokmenu = 4;

	cout << "Введите номер рейса\n";
	cin >> nober;
	nomber_reis = nober;
	//!!!!!!!!!!!!!!!!!!!!!!!!

	type_plenet = type_mas_planet[startMenuCycle(type_mas_planet, kolstrokmenu)];
	system("cls");
	//!!!!!!!!!!!!!!!!!!!!!!!!
	string str;//локальная переменная пункта назначения
	cout << "Введите пункт назначения" << endl;
	cin >> str;
	point_plein = str;
	system("cls");
	//!!!!!!!!!!!!!!!!!!!!!!!!

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

	stringstream ss; // для переобразавания float в string
	ss << y;
	ss >> str;

	time_vilet = str;
	//!!!!!!!!!!!!!!!!!!!!!!!!

	x = 0;
	y = 0;
	str = "";

	cout << "Введите время Польота." << endl;
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

	time_plein = y;
	//!!!!!!!!!!!!!!!!!!!!!!!!
	

}
void plane::save_text(string neme_file)
{


		ofstream file(neme_file, ios::app); // file -переменная файла к которому обращяемся
		file<< nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_plein
		<< endl;
		file.close();
	
}
void plane::save_text_dop(string neme_file)
{	
	
	
	fstream file(neme_file, ios::app);
	
	file << nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_plein << endl;
	file.close();

}
void plane::read_text(int nomber_reis1,string type_plenet1, string point_plein1, string time_vilet1, float time_plein1)
{
	nomber_reis = nomber_reis1;
	type_plenet = type_plenet1;
	point_plein = point_plein1;
	time_vilet = time_vilet1;
	time_plein = time_plein1;

}
float plane::search_for_dest()
{
	return time_plein;
}
void plane::vivod_cmd()
{
	cout << "Номер рейса: " << nomber_reis << endl;
	cout << "Тип самолёта: " << type_plenet<< endl;
	cout << "Пункт назначения: " << point_plein << endl;
	cout << "Время вылета: " << time_vilet<< endl;
	cout << "Время в пути: " << time_plein << endl;
	cout << "---------------------------------------------" << endl;
}	

plane::~plane()
{
}

void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!
	int zapis, gt, gd;

	zapis = 1;

	plane *numbers;
	plane *numbers2=0;//требует иницыализацыи
	numbers = new plane[zapis];
	//numbers2 = new plane[zapis];
	//delete[]numbers2;
	numbers[0].vvod_nap_klav(type_mas_planet);



	do
	{
		gd = startMenuCycle(yes_no, 3);//хотите продолжить?

		if (gd == 1)
		{
			//gd = 1;
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


	gt = startMenuCycle(zapis_data, 3);//Хотите записать данные в НОВЫЙ файл или ДОБАВИТЬ к существуещему файлу

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

		fstream file(neme_file, ios::out);
		file.close();

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

		if (neme_file == "*?*")
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
			return "*?*";
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

void read_and_sotr() 
{
	string neme_file;//имя файла в котором будет проводиться сортировка, она пустая 
	neme_file = fynk_read_file(); //определение файла в котором будет проводиться сортировка
	ifstream file(neme_file, ios::in); //открытие файла в котором будет проводиться сортировка
	if (!file) exit(1); 
	int n = 0;
	vector<string> mas_neme_pynkt_naznach;
	while (!file.eof())//запись в вектор пунктов назначений
	{
		string s,v;
			file >> s >> s >> v >> s >> s;
			mas_neme_pynkt_naznach.emplace_back(v);
			n++;
	}
	file.close();
	//n- количество строк в файле считая с последней пустой

	cout << "++++++++++++++++++++++" << endl;
	cout << size(mas_neme_pynkt_naznach)<<"=="<<n<<" "<< mas_neme_pynkt_naznach[0]<<endl;
	cout << "++++++++++++++++++++++" << endl;
	system("pause");

	//n=size(mas_neme_pynkt_naznach) - факт
	for (int i = 0; i < size(mas_neme_pynkt_naznach); i++) //убирание повторяющихся направлений для меню 
	{
		for (int j = 0; j < size(mas_neme_pynkt_naznach); j++)
		{
			if (j == i) 
			{
				continue;
			}
			if (mas_neme_pynkt_naznach[i] == mas_neme_pynkt_naznach[j])
				{
					auto iter = mas_neme_pynkt_naznach.begin(); // указатель на первый элемент

					if (j != 0) { iter = iter + j; };

					mas_neme_pynkt_naznach.erase(iter);
					j--;
			}
			
		}
	}
	
	auto iter = mas_neme_pynkt_naznach.end(); // указатель на последний элемент, для удаления пустого значения
	--iter;
	mas_neme_pynkt_naznach.erase(iter);






	//n=size(mas_neme_pynkt_naznach) если в файле НЕБЫЛО повторяющихся направлений
	//n!=size(mas_neme_pynkt_naznach) если в файле БЫЛИ повторяющихся направлений
	
	cout << "++++++++++++++++++++++" << endl;
	cout << size(mas_neme_pynkt_naznach) << "количество" << n << endl;
	cout << "++++++++++++++++++++++" << endl;
	system("pause");

	//перенос в дин_масив для меню
	string *point_plane_mas =  new string [size(mas_neme_pynkt_naznach)+1];//м////////////
	point_plane_mas[0]="Выберите пункт назначения по которому будет произведена сортировка:";
	
	for (int i = 0; i < size(mas_neme_pynkt_naznach); i++)
	{
		point_plane_mas[i + 1] = mas_neme_pynkt_naznach[i];
	}
	
	
	int hhh;
	hhh= startMenuCycle(point_plane_mas, size(mas_neme_pynkt_naznach)+1);
	
	//вектор для добовления в него елементов масива содержашик одно направлениее(hhh)
	vector<plane> mas;

	 file.open(neme_file, ios::in);
	for (int i = 0; i < n; i++)
	{
		int nober;
		string type_plenet,
			point_plein,
			time_vilet;
			float time_finish;
		file >> nober >> type_plenet >> point_plein >> time_vilet >> time_finish;
		if (point_plein== point_plane_mas[hhh])
		{
			plane d;
			d.read_text(nober, type_plenet, point_plein, time_vilet, time_finish);
			mas.emplace_back(d);
		}
	}
	file.close();
	delete []point_plane_mas;
	n=size(mas);
	//перевод в динамический масив
	plane*mas_din=new plane[n];
	for (int i = 0;  i < n;  i++)
	{
		mas_din[i] = mas[i];
	}


	//сортировка по длительности полёта
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n-1; i++)
		{
			
			if (mas_din[i].search_for_dest() > mas_din[i + 1].search_for_dest())
			{
				plane f=mas_din[i];
				mas_din[i] = mas_din[i + 1];
				mas_din[i + 1] = f;
			}
		}
	}
	//вивод
	for (int i = 0; i < n; i++)
	{
		mas_din[i].vivod_cmd();
	}
	delete[]mas_din;
	int code;
	cout << "Нажмите ESC для выхода в главное меню" << endl;
	do
	{
		code = _getch();
	} while (code!= VK_ESCAPE);

}