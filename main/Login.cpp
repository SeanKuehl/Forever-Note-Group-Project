#include "Login.h"

Login::Login(): Menu() {
	username = "";
	password = "";
}

void Login::displayMessage() {
	system("cls");
	cout << "Please Enter Your Credentials" << endl << endl;
}

void Login::displayMenu() {
	cout << "Username: ";
	cin >> this->username;
	cout << "Password: ";
	cin >> this->password;
}

bool Login::checkMenuOption(string& path, menuType& mType) {
	path = this->username;
	mType = menuType::CategoryMenu;
	return true;
}

//string getUserName() {
//	return "";
//}
