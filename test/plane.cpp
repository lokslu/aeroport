#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "plane.h" //���������� �����
#include "menu.h" // ���������� ���
#include <windows.h>	

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

void plane::save_text(string neme_file)
{


		ofstream file(neme_file, ios::app); // file -���������� ����� � �������� ����������
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
	(CreateDirectory(L"./data", NULL));//������ ����� data (���������� 1) � �� ������ ����� ���� ��� ��� ������� (���������� 0)


	gt = startMenuCycle(zapis_data, 3);
	
	switch (gt)
	{
	case 1:
	{
		if (0 == zapis % 2)
		{
			cout << "������� ��� �����" << endl;
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

			cout << "������� ��� �����" << endl;
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
