#pragma once
#include <iostream>
#include <string>
#include "menuType.h"
using namespace std;

class Menu {
protected:
	int menuOption;

public:
	Menu();
	virtual void displayMessage();
	virtual void displayMenu();
	virtual bool checkMenuOption(menuType&);
	
};

void checkValidInput();

//void displayMainMenu();