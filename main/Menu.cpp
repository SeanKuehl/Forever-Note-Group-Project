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
	cout << endl << ": ";
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

bool Menu::checkCharacters(string cred) {
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

void Menu::convToUpper(string& s) {
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
}

bool Menu::checkYesNo() {

	bool yesNo = false;
	bool validInput = false;

	do {
		string userInput;
		cin >> userInput;
		checkValidInput();
		convToUpper(userInput);

		//bug here

		if (userInput.find("NO") != string::npos) {
			yesNo = false;
			validInput = true;
		} else if (userInput.find("YES") != string::npos) {
			cout << "Your Input Was Invalid" << endl << endl
				 << "Please Enter Yes or No (Y/N): ";
			validInput = false;
		} else {
			yesNo = true;
			validInput = true;
		}

	} while (!validInput);

	return yesNo;
}