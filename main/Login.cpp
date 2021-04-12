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

}

bool Login::checkMenuOption(string& path, menuType& mType) {

	cout << "Username: ";
	cin >> this->username;
	checkValidInput();
	cout << "Password: ";
	cin >> this->password;
	checkValidInput();

	if (LogIntoAccount(this->username, this->password)) {
		cout << endl << "Logging in...";
		Sleep(1000);
		path = this->username + "\\";
		mType = menuType::CategoryMenu;
		return true;

	} else {
		cout << endl << "This Account Does Not Exist!"
			<< endl << "Would You like to Try Again? (Y/N)" << endl
			<< endl << ": ";
		if (checkYesNo()) {
			system("cls");
			displayMessage();
			displayMenu();
		} else {
			system("cls");
			mType = menuType::mMenu;
		}
	}
	return true;
}

