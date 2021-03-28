#include "NoteModificationMenu.h"

NoteModificationMenu::NoteModificationMenu(): Menu() {
}

void NoteModificationMenu::displayMessage() {
	system("cls");
	cout << "---Note Modification Menu---" << endl << endl;
}

void NoteModificationMenu::displayMenu() {
	cout << "1) View Note" << endl
		 << "2) Protect Note" << endl
		 << "3) Unlock Note" << endl
		 << "4) Edit Note" << endl
		 << "5) Go Back" << endl
		 << "6) Exit" << endl;
}

bool NoteModificationMenu::checkMenuOption(string& path, menuType& mType) {

	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//View Note
			
			//displayNote(path);
			
			//path = path + this->catName + "/";
			mType = menuType::NoteMenu;
			return true;
		case 2:
			//Protect Note

			//protectNote(path);

			//path = path + this->catName + "/";
			mType = menuType::NoteMenu;
			return true;
		case 3:
			//Unlock Note

			//unlockNote(path);
			mType = menuType::NoteMenu;
			return true;
		case 4:
			//Edit Note
			//editNote(path);
			
			//path = path + this->catSearch + "/";
			mType = menuType::NoteMenu;
			return true;
		case 5:
			//Go Back
			mType = menuType::NoteMenu;
			return true;
		case 6:
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