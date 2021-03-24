#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

class NoteMenu : public Menu {
public:
	NoteMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
private:
	void removeCategoryFromPath(string&);
};