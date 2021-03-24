#include "NoteMenu.h"

NoteMenu::NoteMenu() : Menu() {
}

void NoteMenu::displayMessage() {
	system("cls");
	cout << "---Note Menu---" << endl << endl;
}

void NoteMenu::displayMenu() {
	cout << "1) Create A Note" << endl
		 << "2) View A Note" << endl
		 << "3) Search Existing Notes" << endl
		 << "4) Go Back" << endl
		 << "5) Exit" << endl;
}

bool NoteMenu::checkMenuOption(string& path, menuType& mType) {
	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//Create a Note
			return true;
		case 2:
			//View A Note
			return true;
		case 3:
			//Search Existing Notes
			return true;
		case 4:
			//Go Back
			removeCategoryFromPath(path);
			mType = menuType::CategoryMenu;
			return true;
		case 5:
			//Exit
			return false;
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

void NoteMenu::removeCategoryFromPath(string& path) {
	int firstindexOfSlash = path.find_first_of("/");
	path = path.substr(0, firstindexOfSlash + 1);
}