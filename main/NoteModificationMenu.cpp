#include "NoteModificationMenu.h"

NoteModificationMenu::NoteModificationMenu(): Menu() {
}

void NoteModificationMenu::displayMessage() {
	system("cls");
	cout << "---Note Modification Menu---" << endl << endl;
}

void NoteModificationMenu::displayMenu() {
	cout << "1) View Note" << endl
		 << "2) Lock Note" << endl
		 << "3) Unlock Note" << endl
		 << "4) Edit Note" << endl
		 << "5) Delete Note" << endl
		 << "6) Go Back" << endl
		 << "7) Exit" << endl;
}

bool NoteModificationMenu::checkMenuOption(string& path, menuType& mType) {

	//this->currNote = Note::Open(path);

	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//View Note
			
			displayNote();
			
			mType = menuType::NoteModificationMenu;
			return true;
		case 2:
			//Lock Note

			lockNote();

			mType = menuType::NoteModificationMenu;
			return true;
		case 3:
			//Unlock Note

			unlockNote();
			mType = menuType::NoteModificationMenu;
			return true;
		case 4:
			//Edit Note
			editNote();
			
			mType = menuType::NoteModificationMenu;
			return true;
		case 5:
			//Delete Note
			deleteNote();
			mType = menuType::NoteMenu;
			return true;
		case 6:
			//Go Back
			mType = menuType::NoteMenu;
			return true;
		case 7:
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

bool NoteModificationMenu::checkNoteState() {

	/*if (CurrNote.passwordState == Locked) {
		return true;
	} else {
		return false;
	}*/
	return false;
}

void NoteModificationMenu::displayNote() {

	system("cls");

	cout << "---View Note---" << endl << endl;

	if (checkNoteState()) {
		cout << "Note must be unlocked before it can be viewed!" << endl;
		Sleep(1000);
		return;
	} else {
		//print Note Here
	}

	cout << "Enter any key to return to the Modification Menu" << endl << endl;
	cout << ": ";
	getchar();

}

void NoteModificationMenu::lockNote() {

	system("cls");

	cout << "---Lock Note---" << endl << endl;

	cout << "Please enter a new password: " << endl << endl;
	cout << ": ";

	string password;
	cin >> password;
	checkValidInput();

	

	/*if (currNote.setPassword(password)) {
		cout << "Password was set successfully" << endl;
		Sleep(1000);
	} else {
		cout << "Password was NOT set successfully" << endl
			 << "Returning to the menu" << endl;
		Sleep(1000);
	}*/

}

void NoteModificationMenu::unlockNote() {

	system("cls");

	cout << "---Unlock Note---" << endl << endl;

	cout << "Please enter the password: " << endl << endl;
	cout << ": ";

	string password;
	cin >> password;
	checkValidInput();

	/*if (currNote.setPassword(password)) {
		cout << "Note Unlocked Successfully" << endl;
		Sleep(1000);
	} else {
		cout << "Invalid Password" << endl
			 << "Returning to the menu" << endl;
		Sleep(1000);
	}*/

}

void NoteModificationMenu::editNote() {

	system("cls");

	cout << "---Edit Note---" << endl << endl;

	if (checkNoteState()) {
		cout << "Note must be unlocked before it can be edited!" << endl;
		Sleep(1000);
		return;
	} else {
		//edit Note Here
		cout << "Please use the next window to edit the note." << endl << endl;
		cout << "Make sure to SAVE (CTRL+S) before closing the window!" << endl;
		Sleep(1000);
		//currNote.Edit();
	}

}

void NoteModificationMenu::deleteNote() {

	system("cls");

	if (checkNoteState()) {
		cout << "Note must be unlocked before it can be deleted!" << endl;
		Sleep(1000);
		return;
	} else {
		//delete Note Here
		cout << "Are you sure you want to delete this note? (Y/N)" << endl << endl
			 << ": ";
		if (checkYesNo()) {
			//currNote.Delete();
			cout << endl << "Note was deleted" << endl;
			Sleep(1000);
		} else {
			cout << endl << "Note deletion canceled" << endl;
			Sleep(1000);
		}
		
	}

}
