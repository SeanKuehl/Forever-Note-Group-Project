#include "CreateAnAccount.h"

CreateAnAccount::CreateAnAccount() : Menu() {
	username = "";
	password = "";
}

void CreateAnAccount::displayMessage() {
	system("cls");
	cout << "Create an Account: " << endl << endl;
}

void CreateAnAccount::displayMenu() {
	string username;
	string reUsername;
	string password;
	string rePassword;

	cout << "Please Enter a Username: ";
	cin >> username;

	if (!checkFolderCharacters(username)) {
		displayMessage();
		cout << "Please Use Appropriate Characters: " << endl << endl;
		displayMenu();
		return;
	}

	cout << "Please Re-Enter Your Username: ";
	cin >> reUsername;

	if (username.compare(reUsername) == 0) {
		this->username = username;
	} else {
		displayMessage();
		cout << "Please Enter Matching Credentials: " << endl << endl;
		displayMenu();
		return;
	}

	cout << "Please Enter a Password: ";
	cin >> password;

	if (!checkFolderCharacters(password)) {
		displayMessage();
		cout << "Please Use Appropriate Characters: " << endl << endl;
		displayMenu();
		return;
	}

	cout << "Please Re-Enter a Password: ";
	cin >> rePassword;

	if (password.compare(rePassword) == 0) {
		this->password = password;
	} else {
		displayMessage();
		cout << "Please Enter Matching Credentials: " << endl << endl;
		displayMenu();
		return;
	}

	/*if (CreateAccount(this->username, this->password)) {
		cout << "Account Creation Was Successful!" << endl;
	} else {
		system("cls");
		cout << "Username Already Exists!" << endl
			 << "Account Creation Was NOT Successful!" <<  endl;
			 displayMenu();
	}*/

}



bool CreateAnAccount::checkMenuOption(string& path, menuType& mType) {
	path = this->username + "/";
	mType = menuType::CategoryMenu;
	return true;
}