#pragma once
#include <string>

using namespace std;
class plane
{
private:
	int nomber_reis; //Номер рейсу
		string	type_plenet,//Тип літака
		point_plein,//Пункт призначення
		time_vilet,//Час вильоту
		time_finish; // час прильота
public:
	plane();//конструктор 
	float plane_time;//час польоту

	void vvod_nap_klav(string*type_mas_planet);//Введення напрямку з клавіатури;	
	void save_text(string neme_file);//Збереження у текстовому файлі;
	void save_text_dop(string neme_file);
	void read_text();//Зчитування інформації з файлу та відбір рейсів у даному напрямку;	
	void search_for_dest();//Пошук рейсів з мінімальним часом польоту у заданому напрямку;
	void vivod_cmd();//Вивід у консольне вікно переліку рейсів у заданому напрямку за збільшенням часу польоту.

	~plane();//деструктор
	
};
void fynk_save(string*type_mas_planet, string*yes_no, string*zapis_data);

