#include "pch.h"
#include <iostream>
#include <string>
#include <istream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <cstring>
#include "menu.h"
#include "plane.h"
#include "text_mas_menu.h"


#define KEY_UP 72 //по стандарту определяет что  KEY_UP -- 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13

; using namespace std;


int kolstrokmenu;
int main()
{ 
	


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int zapis, g,i;
	

	kolstrokmenu = size(mas_menu);// <-  ето для С++ V.17 или через sizeof(mas_menu)/sizeof(*mas_menu);
	g = startMenuCycle(mas_menu, kolstrokmenu); // меню 
	
//cout << g;		

switch (g)
{  
case 1:

	zapis = 1;
	
			//ccccccccccccccccccccccc
			//ccccccccccccccccccccccccм
			plane *numbers;
			plane *numbers2;
			numbers=new plane[zapis];
			numbers2 = new plane[zapis];
			delete[]numbers2;
			numbers[0].vvod_nap_klav(type_mas_planet);
			
			
			
	do
	{
		g = startMenuCycle(yes_no, 3);
			if(g==1)
			{
				if (0==zapis%2)
				{
					zapis++;
					numbers  = new plane[zapis];
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
			
		

	} while (g == 1);
	
	if (0 == zapis % 2)
	{
		for (int i = 0; i < zapis; i++)
		{
			numbers2[i].save_text();
		}
		delete[] numbers2;
	}
	else
	{
		

		for (int i = 0; i < zapis; i++)
		{
			numbers[i].save_text();
		}
		delete[] numbers;
	}

	


	break;

case 2:
	return 0;
	break;
case 3:
	return 0;
break;
}

	
	

system("pause");

}

