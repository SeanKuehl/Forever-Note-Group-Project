#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CategoryMenu : public Menu {
	string catName;
	string catMerge1;
	string catMerge2;
	string catSearch;
	vector<string> catList;
	
public:
	CategoryMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
protected:
	void displayCatOptions(vector<string>);
	string selectCatOption(vector<string>, int);
	void createACategory(string);
	void selectACategory(string);
	void mergeACategory(string);
	bool searchACategory(string);
	void convToUpper(string&);
};
