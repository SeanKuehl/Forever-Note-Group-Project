#pragma once
#include <iostream>
#include <string>
#include "menuType.h"
using namespace std;

class Menu {
protected:
	int menuOption;

	void checkValidInput();
	bool checkFolderCharacters(string);

public:
	Menu();
	virtual void displayMessage();
	virtual void displayMenu();
	virtual bool checkMenuOption(string&, menuType&);
	
};

//void checkValidInput();