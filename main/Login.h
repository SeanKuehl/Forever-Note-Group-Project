#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Login: public Menu {
	string username;
	string password;
public:
	Login();
	void displayMessage() override;
	void displayMenu() override;

};