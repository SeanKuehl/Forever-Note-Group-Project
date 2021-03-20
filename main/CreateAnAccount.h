#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

class CreateAnAccount : public Menu {
	string username;
	string password;
public:
	CreateAnAccount();
	void displayMessage() override;
	void displayMenu() override;
	bool checkFolderCharacters(string);
};