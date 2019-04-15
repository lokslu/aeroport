#pragma once
#include <string>

using namespace std;
class plane
{
private:
	int nomber_reis; //Номер рейсу
	string type_plenet,//Тип літака
		point_plein,//Пункт призначення
		time_vilet;//Час вильоту
	float time_plein; // час польота
public:
	plane();//конструктор 

	void vvod_nap_klav(string*type_mas_planet);//Введення напрямку з клавіатури;	
	void save_text(string neme_file);//Збереження у текстовому файлі;
	void read_text(int nomber_reis1,
		string type_plenet1,
		string point_plein1,
		string time_vilet1,
		float time_plein1);//Зчитування інформації з файлу та відбір рейсів у даному напрямку;	
	float search_for_dest();//Пошук рейсів з мінімальним часом польоту у заданому напрямку;
	void vivod_cmd();//Вивід у консольне вікно переліку рейсів у заданому напрямку за збільшенням часу польоту.

	~plane();//деструктор

};

int startMenuCycle(string *mas_menu, int kolstrokmenu);

void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data);//функцыя сохранения

string fynk_read_file();//функцыя чтения с папки

void flight_search(); //функцыя Пошук рейсів з мінімальним часом польоту у заданому напрямку;