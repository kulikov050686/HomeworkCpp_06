#pragma once
#include <string>
using namespace std;

class Menu
{
private:

	/// Количество пунктов меню
	int SizeMenu = 1;

	/// Название пунктов меню
	string* ItemsName = nullptr;

public:

	/// Конструктор меню
	Menu(const string* nameItemsMenu, const int NumberItems);

	/// Конструктор копирования
	Menu(const Menu& object);

	/// Получить название пункта меню по номеру
	string getItemMenu(const int menuItemNumber);

	/// Деструктор
	~Menu();
};
