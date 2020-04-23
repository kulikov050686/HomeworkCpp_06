#include "MenuController.h"

MenuController::MenuController(const string* itemsMenu, const int numberItems)
{
	SizeMenu = numberItems;
	menu = new Menu(itemsMenu, SizeMenu);
}

int MenuController::selectedMenuItem(const string text)
{
    int selection = 0;
    PrintMenu(selection, text);

    do
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 72:
                //Up
                if (selection > 0) selection--;
                break;
            case 80:
                //Down
                if (selection < SizeMenu - 1) selection++;
                break;            
            }
        }       
        
        PrintMenu(selection, text);
    }
    while (_getch() != 13);

    system("cls");

    return selection;
}

void MenuController::PrintMenu(int selection, const string text)
{
	system("cls");

    cout << text << endl;

    for (int i = 0; i < SizeMenu; i++)
    {
        if (i == selection)
        {            
            cout << "->" + menu->getItemMenu(i) << endl;                  
        }
        else
        {
            cout << menu->getItemMenu(i) << endl;           
        }
    }
}

MenuController::~MenuController()
{
	if (menu != nullptr)
	{
		delete menu;
	}
}

