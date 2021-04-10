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

	if (LogIntoAccount(this->username, this->password)) {
		cout << endl << "Logging in...";
		Sleep(1000);

		return;
	} else {
		cout << endl << "This Account Does Not Exist!"
			 << endl << "Please Try Again!";
		Sleep(1000);
		displayMessage();
		displayMenu();
	}

}

bool Login::checkMenuOption(string& path, menuType& mType) {
	path = this->username + "\\";
	mType = menuType::CategoryMenu;
	return true;
}

