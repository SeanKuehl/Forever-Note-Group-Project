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
		 << "4) Remove Note Password" << endl
		 << "5) Edit Note" << endl
		 << "6) Delete Note" << endl
		 << "7) Go Back" << endl
		 << "8) Exit" << endl;
}

bool NoteModificationMenu::checkMenuOption(string& path, menuType& mType) {

	this->currNote = Note::Open(path);
	
	do {

		cout << endl << ": ";
		cin >> menuOption;
		checkValidInput();

		switch (menuOption) {
		case 1:
			//View Note
			displayNote();
			break;
		case 2:
			//Lock Note
			lockNote(path);
			break;
		case 3:
			//Unlock Note
			unlockNote();
			break;
		case 4:
			//Remove Note Password
			removeNotePassword();
			break;
		case 5:
			//Edit Note
			editNote();
			break;
		case 6:
			//Delete Note
			if (deleteNote()) {
				removeLastPathEntry(path);
				mType = menuType::NoteMenu;
				return true;
			}
			break;
		case 7:
			//Go Back
			removeLastPathEntry(path);
			mType = menuType::NoteMenu;
			return true;
		case 8:
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
		displayMessage();
		displayMenu();

	} while (true);

}

void NoteModificationMenu::displayNote() {

	system("cls");

	cout << "---View Note---" << endl << endl;

	//print Note Here
	string noteString;

	if(currNote.GetContents(noteString) == PasswordState::Locked){
	//if (!true) {
		cout << "Note must be unlocked before it can be viewed!" << endl << endl
			 << "Enter Any Key to continue...";
		system("pause >nul");
		return;
	} else {
		cout << noteString << endl << endl;
	}

	cout << "Enter any key to return to the Modification Menu...";// << endl << endl;
	//cout << ": ";
	system("pause >nul");

}

void NoteModificationMenu::lockNote(string path) {

	system("cls");

	cout << "---Lock Note---" << endl << endl;

	if (currNote.GetPasswordState() == PasswordState::Locked) {
		cout << "Note must be unlocked before it can be edited!" << endl;
		Sleep(1000);
		return;

	} else {

		cout << "Please enter a new password: " << endl << endl;
		cout << ": ";

		string password;
		cin >> password;
		checkValidInput();

		if (currNote.SetPassword(password) == PasswordState::None) {
			cout << "Password was successfully Removed...";
			Sleep(1000);
		} else {
			cout << "Password was successfully Changed" << endl
				 << "Returning to the menu...";
			Sleep(1000);
		}

		currNote.WritetoFile();

	}

}

void NoteModificationMenu::unlockNote() {

	system("cls");

	cout << "---Unlock Note---" << endl << endl;

	cout << "Please enter the password: " << endl << endl;
	cout << ": ";

	string password;
	cin >> password;
	checkValidInput();

	if (currNote.CheckPassword(password) != PasswordState::Locked) {
		cout << "Note Unlocked Successfully";
		Sleep(1000);
	} else {
		cout << "Invalid Password" << endl
			 << "Returning to the menu...";
		Sleep(1000);
	}

}

void NoteModificationMenu::removeNotePassword() {

	system("cls");

	cout << "---Remove Note Password---" << endl << endl;

	cout << "Are you sure you want to remove the password? (Y/N)" << endl << endl
		<< ": ";

	if (checkYesNo()) {
		if (currNote.GetPasswordState() == PasswordState::Locked) {
			cout << "Note must be unlocked before it can be edited!" << endl;
			Sleep(1000);
			return;
		} else {
			if (currNote.SetPassword("") == PasswordState::None) {
				cout << endl << "Password was removed successfully";
				currNote.WritetoFile();
				Sleep(1000);
			} else {
				cout << endl << "Password was NOT removed";
				Sleep(1000);
			}
		}
	} else {
		cout << endl << "Password removal aborted" << endl
			 << endl << "Returning to the menu...";
		Sleep(1000);
	}

}

void NoteModificationMenu::editNote() {

	system("cls");

	cout << "---Edit Note---" << endl << endl;

	if (currNote.GetPasswordState() == PasswordState::Locked) {
		cout << "Note must be unlocked before it can be edited!" << endl;
		Sleep(1000);
		return;
	} else {
		//edit Note Here
		cout << "Please use the next window to edit the note." << endl << endl;
		cout << "Make sure to SAVE (CTRL+S) before closing the window!" << endl;
		Sleep(1000);
		currNote.Edit();
	}

}

bool NoteModificationMenu::deleteNote() {

	system("cls");

	if (currNote.GetPasswordState() == PasswordState::Locked) {
		cout << "Note must be unlocked before it can be deleted!" << endl;
		Sleep(1000);
		return false;
	} else {
		//delete Note Here
		cout << "Are you sure you want to delete this note? (Y/N)" << endl << endl
			<< ": ";
		if (checkYesNo()) {
			currNote.Delete();
			cout << endl << "Note was deleted" << endl;
			Sleep(1000);
			return true;
		} else {
			cout << endl << "Note deletion canceled" << endl;
			Sleep(1000);
			return false;
		}
	}
}
