#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

class CategoryMenu : public Menu {
	string catName;
	string source;
	string destination;
	string catSearch;
	vector<string> catList;
	
public:
	CategoryMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
protected:
	void displayCatOptions(vector<string>);
	void createACategory(string);
	void selectACategory(string);
	void mergeACategory(string);
	bool searchACategory(string);
};
