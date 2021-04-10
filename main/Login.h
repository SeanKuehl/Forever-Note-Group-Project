#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include "LogIntoAccount.h"
#include <Windows.h>
using namespace std;

class Login: public Menu {
	string username;
	string password;
public:
	Login();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&);
};