#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CategoryMenu : public Menu {
	string catName;
public:
	CategoryMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
	void createACategory(string);
	void selectACategory(string);
};
