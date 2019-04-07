#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream> //���  stringstream  // ��� ��������������� float � string
#include <string>
#include <vector>
#include <stdio.h>//
#include <windows.h>
#include "plane.h" //���������� �����
#include "menu.h" // ���������� ����
#include "dirent.h"//
#include <filesystem>
#include <conio.h>


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

	//!!!!!!!!!!!!!!!!!!!!!!!!
	int nober, kolstrokmenu;
	kolstrokmenu = 4;

	cout << "������� ����� �����\n";
	cin >> nober;
	nomber_reis = nober;
	//!!!!!!!!!!!!!!!!!!!!!!!!

	type_plenet = type_mas_planet[startMenuCycle(type_mas_planet, kolstrokmenu)];
	system("cls");
	//!!!!!!!!!!!!!!!!!!!!!!!!
	string str;//��������� ���������� ������ ����������
	cout << "������� ����� ����������" << endl;
	cin >> str;
	point_plein = str;
	system("cls");
	//!!!!!!!!!!!!!!!!!!!!!!!!

	// ����������� ����� � ������ ����� � ������� � 2 �����
	int x, i;
	i = 0;
	float y;
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

	stringstream ss; // ��� ��������������� float � string
	ss << y;
	ss >> str;

	time_vilet = str;
	//!!!!!!!!!!!!!!!!!!!!!!!!

	x = 0;
	y = 0;
	str = "";

	cout << "������� ����� �������." << endl;
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

	time_plein = y;
	//!!!!!!!!!!!!!!!!!!!!!!!!
	

}
void plane::save_text(string neme_file)
{


		ofstream file(neme_file, ios::app); // file -���������� ����� � �������� ����������
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
	cout << "����� �����: " << nomber_reis << endl;
	cout << "��� �������: " << type_plenet<< endl;
	cout << "����� ����������: " << point_plein << endl;
	cout << "����� ������: " << time_vilet<< endl;
	cout << "����� � ����: " << time_plein << endl;
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
	plane *numbers2=0;//������� �������������
	numbers = new plane[zapis];
	//numbers2 = new plane[zapis];
	//delete[]numbers2;
	numbers[0].vvod_nap_klav(type_mas_planet);



	do
	{
		gd = startMenuCycle(yes_no, 3);//������ ����������?

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
	(CreateDirectory(L"./data", NULL));//������ ����� data (���������� 1) � �� ������ ����� ���� ��� ��� ������� (���������� 0)


	gt = startMenuCycle(zapis_data, 3);//������ �������� ������ � ����� ���� ��� �������� � ������������� �����

	switch (gt)
	{
	case 1:
	{
		cout << "������� ��� �����" << endl;
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
			cout << "� ��� ���� �� ������� �����/n";
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

	//header('Content-Type: text/html; charset=utf-8'); //����������� ��� ����������

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
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!! �� ��� �� �������� ������� ������ ����
		if (size_din_mas_menu <= 1)
		{
			return "*?*";
		}
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		string *lp = new string[size_din_mas_menu];
		lp[0] = "�������� ����:";
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
	string neme_file;//��� ����� � ������� ����� ����������� ����������, ��� ������ 
	neme_file = fynk_read_file(); //����������� ����� � ������� ����� ����������� ����������
	ifstream file(neme_file, ios::in); //�������� ����� � ������� ����� ����������� ����������
	if (!file) exit(1); 
	int n = 0;
	vector<string> mas_neme_pynkt_naznach;
	while (!file.eof())//������ � ������ ������� ����������
	{
		string s,v;
			file >> s >> s >> v >> s >> s;
			mas_neme_pynkt_naznach.emplace_back(v);
			n++;
	}
	file.close();
	//n- ���������� ����� � ����� ������ � ��������� ������

	cout << "++++++++++++++++++++++" << endl;
	cout << size(mas_neme_pynkt_naznach)<<"=="<<n<<" "<< mas_neme_pynkt_naznach[0]<<endl;
	cout << "++++++++++++++++++++++" << endl;
	system("pause");

	//n=size(mas_neme_pynkt_naznach) - ����
	for (int i = 0; i < size(mas_neme_pynkt_naznach); i++) //�������� ������������� ����������� ��� ���� 
	{
		for (int j = 0; j < size(mas_neme_pynkt_naznach); j++)
		{
			if (j == i) 
			{
				continue;
			}
			if (mas_neme_pynkt_naznach[i] == mas_neme_pynkt_naznach[j])
				{
					auto iter = mas_neme_pynkt_naznach.begin(); // ��������� �� ������ �������

					if (j != 0) { iter = iter + j; };

					mas_neme_pynkt_naznach.erase(iter);
					j--;
			}
			
		}
	}
	
	auto iter = mas_neme_pynkt_naznach.end(); // ��������� �� ��������� �������, ��� �������� ������� ��������
	--iter;
	mas_neme_pynkt_naznach.erase(iter);






	//n=size(mas_neme_pynkt_naznach) ���� � ����� ������ ������������� �����������
	//n!=size(mas_neme_pynkt_naznach) ���� � ����� ���� ������������� �����������
	
	cout << "++++++++++++++++++++++" << endl;
	cout << size(mas_neme_pynkt_naznach) << "����������" << n << endl;
	cout << "++++++++++++++++++++++" << endl;
	system("pause");

	//������� � ���_����� ��� ����
	string *point_plane_mas =  new string [size(mas_neme_pynkt_naznach)+1];//�////////////
	point_plane_mas[0]="�������� ����� ���������� �� �������� ����� ����������� ����������:";
	
	for (int i = 0; i < size(mas_neme_pynkt_naznach); i++)
	{
		point_plane_mas[i + 1] = mas_neme_pynkt_naznach[i];
	}
	
	
	int hhh;
	hhh= startMenuCycle(point_plane_mas, size(mas_neme_pynkt_naznach)+1);
	
	//������ ��� ���������� � ���� ��������� ������ ���������� ���� ������������(hhh)
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
	//������� � ������������ �����
	plane*mas_din=new plane[n];
	for (int i = 0;  i < n;  i++)
	{
		mas_din[i] = mas[i];
	}


	//���������� �� ������������ �����
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
	//�����
	for (int i = 0; i < n; i++)
	{
		mas_din[i].vivod_cmd();
	}
	delete[]mas_din;
	int code;
	cout << "������� ESC ��� ������ � ������� ����" << endl;
	do
	{
		code = _getch();
	} while (code!= VK_ESCAPE);

}