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

	bool credExists = false;

	cout << "Username: ";
	cin >> this->username;
	checkValidInput();
	cout << "Password: ";
	cin >> this->password;
	checkValidInput();

	/*if (LogIntoAccount(this->username, this->password)) {
		return;
	} else {
		system("cls");
		cout << "This Account Does Not Exist!" << endl << endl;
		displayMenu();
	}*/

}

bool Login::checkMenuOption(string& path, menuType& mType) {
	path = this->username + "/";
	mType = menuType::CategoryMenu;
	return true;
}

