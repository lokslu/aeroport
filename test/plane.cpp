#include "pch.h"
#include <iostream>
//#include <istream>
#include <fstream>
#include <sstream> //���  stringstream  // ��� ��������������� float � string
#include <string>
#include <vector>
#include <windows.h>
#include "plane.h" //���������� �����
#include <filesystem>
#include <conio.h>// ��� _geth()

#define KEY_UP 72 //�� ��������� ���������� ���  KEY_UP -- 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13


using namespace std;


plane::plane()
{
	nomber_reis = 0;
	type_plenet = "";
	point_plein = "";
	time_vilet = "";
	time_plein = 0;

}


void plane::vvod_nap_klav(string*type_mas_planet)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!
	int kolstrokmenu;

	string nober1;
	cout << "������� ����� �����\n";

	bool repit=false;
	do {
		cin >> nober1;
		int f = nober1.length();
			for (int i = 0; i < f; i++)
			{
				if (isdigit(nober1[i]))
				{
					repit = true;
				}
				else
				{
					cout << "����� ������ �������� ������ �� ����. ��������� �������" << endl;
					repit = false;
					break;
				}
			}
	} while (repit==false);

		nomber_reis = stoi(nober1);

	//!!!!!!!!!!!!!!!!!!!!!!!!

	kolstrokmenu = 4;
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
	
	
	int i;
	i = 0;
	
	string str3,str2;
	str = "";
	cout << "������� ����� ������." << endl;
	cout << "� ������� ��.��" << endl;


	do
	{
		cin >> str;
		if (str.length()==5)
		{
			str2 = ".";
			char h1 = str[0],
				h2= str[1],
				h3= str[3],
				h4= str[4];

			if (isdigit(h1)
				&& isdigit(h2)
				&& str[2] == str2[0]
				&& isdigit(h3)
				&& isdigit(h4))
			{
				str2 = str.substr(0, 2);
				str3 = str.substr(3, 2);
				if ((stoi(str3) >= 60 || stoi(str3) < 0) || (stoi(str2) >= 24 || stoi(str2) < 0))
				{
					i = i + 1;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "�� ����� �� ��������� �����. ��������� ����� � �� ���������. ������ ������" << endl;
				}
				else
				{
					
					break;
				}
			}
			else
			{
				i = i + 1;
				if (i == 7)
				{
					system("cls");
					i = 0;
				}
				cout << "�� ����� �� ��������� �����.������ ���� � ��� ����� ��� ����������� �����. ������ ������" << endl;
			}
		}
		else
		{
			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "�� ����� �� ��������� �����. ������ ������ �� �������������. ������ ������" << endl;
				
			

			
		}

	} while (true);

	time_vilet = str;

	system("cls");
	
	//!!!!!!!!!!!!!!!!!!!!!!!!
	
	float x=0, y=0;
	str = "";

	cout << "������� ����� � ����." << endl;
	cout << "� ������� ��.��" << endl;

	do
	{
		cin >> str;
		if (str.length() == 5)
		{
			str2 = ".";
			char h1 = str[0],
				h2 = str[1],
				h3 = str[3],
				h4 = str[4];

			if (isdigit(h1)
				&& isdigit(h2)
				&& str[2] == str2[0]
				&& isdigit(h3)
				&& isdigit(h4))
			{
				str2 = str.substr(0, 2);
				str3 = str.substr(3, 2);
				if ((stoi(str3) >= 60 || stoi(str3) < 0) || (stoi(str2) >= 24 || stoi(str2) < 0))
				{
					i = i + 1;
					if (i == 7)
					{
						system("cls");
						i = 0;
					}
					cout << "�� ����� �� ��������� �����. ��������� ����� � �� ���������. ������ ������" << endl;
				}
				else
				{
					x = stoi(str3);
					x = x * 0.01;
					y=stoi(str2)+x;
					break;
				}
			}
			else
			{
				i = i + 1;
				if (i == 7)
				{
					system("cls");
					i = 0;
				}
				cout << "�� ����� �� ��������� �����.������ ���� � ��� ����� ��� ����������� �����. ������ ������" << endl;
			}
		}
		else
		{
			i = i + 1;
			if (i == 7)
			{
				system("cls");
				i = 0;
			}
			cout << "�� ����� �� ��������� �����. ������ ������ �� �������������. ������ ������" << endl;




		}

	} while (true);

	stringstream ss; // ��� ��������������� float � string
	ss << y;
	ss >> str;

	time_plein = y;
}
void plane::save_text(string neme_file)
{


	ofstream file(neme_file, ios::app); // file -���������� ����� � �������� ����������
	file << nomber_reis << " " << type_plenet << " " << point_plein << " " << time_vilet << " " << time_plein
		<< endl;
	file.close();

}

void plane::read_text(int nomber_reis1, string type_plenet1, string point_plein1, string time_vilet1, float time_plein1)
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
	cout << "��� �������: " << type_plenet << endl;
	cout << "����� ����������: " << point_plein << endl;
	cout << "����� ������: " << time_vilet << endl;
	cout << "����� � ����: " << time_plein << endl;
	cout << "---------------------------------------------" << endl;
}

plane::~plane()
{
}

void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!
	int gt, gd;//���������� ������� ���������� ����� ����


	vector<plane> vect_mas_objekt; //���������� ������ ������������� ������ ��������

	do
	{
		plane g;
		g.vvod_nap_klav(type_mas_planet);
		vect_mas_objekt.emplace_back(g);

		gd = startMenuCycle(yes_no, 3);//������ ����������?

	} while (gd == 1);

	int size_din_mas = size(vect_mas_objekt);

	plane *din_mas_objekt = new plane[size_din_mas]; //���������� ������������� ������ ��������

	for (int i = 0; i < size(vect_mas_objekt); i++)
	{
		din_mas_objekt[i] = vect_mas_objekt[i];
	}


	

	string neme_file;
	do
	{
		gt = startMenuCycle(zapis_data, 3);//������ �������� ������ � ����� ���� ��� �������� � ������������� �����

		switch (gt)
		{
			case 1:
			{
				cout << "������� ��� �����" << endl;
				string neme_file1;
				cin.get();
				getline(cin, neme_file1);
				neme_file.append("./data/" + neme_file1);

				fstream file(neme_file, ios::out);
				file.close();


				for (int i = 0; i < size_din_mas; i++)
				{
					din_mas_objekt[i].save_text(neme_file);
				}

			}
			break;
			case 2:
			{
				neme_file = fynk_read_file();

				if (neme_file == "*?*")
				{
					system("cls");
					cout << "� ��� ���� �� ������� �����\n";
					int code;
					cout << "������� ESC ��� �����������" << endl;
					do
					{
						code = _getch();
					} while (code != VK_ESCAPE);
				}
				else
				{
					for (int i = 0; i < size_din_mas; i++)
					{
						din_mas_objekt[i].save_text(neme_file);
					}
				}
			}
			break;
		}
	} while (neme_file == "*?*");
}

string fynk_read_file()
{
	vector<string> l;


	namespace fs = std::experimental::filesystem;
	{

		fs::path p;
		for (const auto & entry : fs::directory_iterator("./data"))
		{
			p = entry.path();

			
			l.emplace_back(p.string());
			
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

		int h = 0;
		for (int i = 1; i < size_din_mas_menu; i++)
		{

			lp[i] = l[i - 1];
			lp[i].erase(0, 7);

		}



		int menunom;
		menunom = startMenuCycle(lp, size_din_mas_menu);

		string neme_file;

		neme_file.append("./data/" + lp[menunom]);
		delete[] lp;
		return neme_file;
	}
}

void flight_search()
{
	string neme_file;//��� ����� � ������� ����� ����������� ����������, ��� ������ 

	neme_file = fynk_read_file(); //����������� ����� � ������� ����� ����������� ����������
	


	ifstream file(neme_file, ios::in); //�������� ����� � ������� ����� ����������� ����������
	if (!file) 
	{
		cout << "� ���� ��� ������ � �����������" << endl;
		int code;
		cout << "������� ESC ��� �����������" << endl;
		do
		{
			code = _getch();
		} while (code != VK_ESCAPE);
		return;
	
	}

	int n = 0;
	vector<string> mas_neme_pynkt_naznach;
	while (!file.eof())//������ � ������ ������� ����������
	{
		string s, v;
		file >> s >> s >> v >> s >> s;
		mas_neme_pynkt_naznach.emplace_back(v);
		n++;
	}
	file.close();
	//n- ���������� ����� � ����� ������ � ��������� ������

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



	//������� � ���_����� ��� ����
	string *point_plane_mas = new string[size(mas_neme_pynkt_naznach) + 1];//�////////////
	point_plane_mas[0] = "�������� ����� ���������� �� �������� ����� ����������� ����������:";

	for (int i = 0; i < size(mas_neme_pynkt_naznach); i++)
	{
		point_plane_mas[i + 1] = mas_neme_pynkt_naznach[i];
	}


	int hhh;
	hhh = startMenuCycle(point_plane_mas, size(mas_neme_pynkt_naznach) + 1);



	//111111111111111111111111111111111111111111111111111111111111111111111111111111111111



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
		if (point_plein == point_plane_mas[hhh])
		{
			plane d;
			d.read_text(nober, type_plenet, point_plein, time_vilet, time_finish);
			mas.emplace_back(d);
		}
	}
	file.close();
	delete[]point_plane_mas;
	n = size(mas);
	//������� � ������������ �����
	plane*mas_din = new plane[n];
	for (int i = 0; i < n; i++)
	{
		mas_din[i] = mas[i];
	}


	//���������� �� ������������ �����
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{

			if (mas_din[i].search_for_dest() > mas_din[i + 1].search_for_dest())
			{
				plane f = mas_din[i];
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
	} while (code != VK_ESCAPE);

}