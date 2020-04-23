#include "Menu.h"

Menu::Menu(const string* nameItemsMenu, const int NumberItems)
{
	if (NumberItems > 0 && nameItemsMenu != nullptr)
	{
		SizeMenu = NumberItems;
		ItemsName = new string[SizeMenu];

		for (int i = 0; i < SizeMenu; i++)
		{
			ItemsName[i] = nameItemsMenu[i];
		}
	}
}

Menu::Menu(const Menu& object)
{
	this->SizeMenu = object.SizeMenu;

	if (object.ItemsName != nullptr)
	{
		this->ItemsName = new string[object.SizeMenu];

		for (int i = 0; i < object.SizeMenu; i++)
		{
			this->ItemsName[i] = object.ItemsName[i];
		}
	}
}

string Menu::getItemMenu(const int menuItemNumber)
{
	if (0 <= menuItemNumber && menuItemNumber < SizeMenu && ItemsName != nullptr)
	{
		return ItemsName[menuItemNumber];
	}

	return "Error!";
}

Menu::~Menu()
{
	delete[] ItemsName;	
}
