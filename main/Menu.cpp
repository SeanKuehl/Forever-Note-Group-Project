#include "Menu.h"

Menu::Menu() {
	menuOption = 0;
}

void Menu::displayMessage() {
	cout << "Welcome to Forever Note" << endl << endl;
}

void Menu::displayMenu() {
	cout << "1) Login" << endl
		 << "2) Create An Account" << endl
		 << "3) Exit" << endl;
}

bool Menu::checkMenuOption(string& path, menuType &mType) {
	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//Login
			mType = menuType::Login;
			return true;
		case 2:
			//Create An Account
			mType = menuType::CreateAnAccount;
			return true;
		case 3:
			//Exit
			exit(EXIT_SUCCESS);
		default:
			system("cls");
			cout << "Please Enter a Valid Option: " << endl << endl;
			displayMenu();
			cin >> menuOption;
			checkValidInput();
			break;
		}
	} while (true);
}

void Menu::checkValidInput() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
}

bool Menu::checkFolderCharacters(string cred) {
	for (int i = 0; i < cred.length(); i++) {
		//invalid folder creation characters
		if (cred[i] == '.' ||
			cred[i] == '\\' ||
			cred[i] == '/' ||
			cred[i] == ':' ||
			cred[i] == '*' ||
			cred[i] == '?' ||
			cred[i] == '"' ||
			cred[i] == '<' ||
			cred[i] == '>' ||
			cred[i] == '|') {
			return false;
		}
	}
	return true;
}