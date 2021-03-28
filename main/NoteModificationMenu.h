#pragma once
#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

class NoteModificationMenu : public Menu {

public:
	NoteModificationMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
private:

};