#pragma once
#include <string>

using namespace std;
class plane
{
private:
	int nomber_reis; //����� �����
	string type_plenet,//��� �����
		point_plein,//����� �����������
		time_vilet;//��� �������
	float time_plein; // ��� �������
public:
	plane();//����������� 

	void vvod_nap_klav(string*type_mas_planet);//�������� �������� � ���������;	
	void save_text(string neme_file);//���������� � ���������� ����;
	void read_text(int nomber_reis1,
		string type_plenet1,
		string point_plein1,
		string time_vilet1,
		float time_plein1);//���������� ���������� � ����� �� ���� ����� � ������ ��������;	
	float search_for_dest();//����� ����� � ��������� ����� ������� � �������� ��������;
	void vivod_cmd();//���� � ��������� ���� ������� ����� � �������� �������� �� ���������� ���� �������.

	~plane();//����������

};

int startMenuCycle(string *mas_menu, int kolstrokmenu);

void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data);//������� ����������

string fynk_read_file();//������� ������ � �����

void flight_search(); //������� ����� ����� � ��������� ����� ������� � �������� ��������;