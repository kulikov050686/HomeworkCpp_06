#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Menu.h"

class MenuController
{
private:

	/// Меню приложения
	Menu* menu;

	/// Количество пунктов меню
	int SizeMenu;

	/// Печать пунктов меню
	void PrintMenu(int selection, const string text);

public:

	/// Создание нового контроллера меню
	MenuController(const string* itemsMenu, const int numberItems);
	
	/// Выбор пункта меню
	int selectedMenuItem(const string text);	

	/// Деструктор
	~MenuController();
};

