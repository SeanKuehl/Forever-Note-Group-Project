#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include "CreateAccount.h"
#include <Windows.h>
using namespace std;

class CreateAnAccount : public Menu {
	string username;
	string password;
public:
	CreateAnAccount();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&);
};