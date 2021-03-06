#include "NoteMenu.h"

NoteMenu::NoteMenu() : Menu() {
}

void NoteMenu::displayMessage() {
	system("cls");
	cout << "---Note Menu---" << endl << endl;
}

void NoteMenu::displayMenu() {
	cout << "1) Create A Note" << endl
		 << "2) Select A Note" << endl
		 << "3) Search Existing Notes" << endl
		 << "4) Go Back" << endl
		 << "5) Exit" << endl;

}

bool NoteMenu::checkMenuOption(string& path, menuType& mType) {

	this->noteList = List_CAT(path);

	cout << endl << ": ";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//Create a Note
			system("cls");
			createANote(path);
			return true;
		case 2:
			//Select A Note
			selectANote(path);
			path = path + this->noteName;
			mType = menuType::NoteModificationMenu;
			return true;
		case 3:
			//Search Existing Notes
			if (searchANote(path)) {
				path = path + this->noteName;
				mType = menuType::NoteModificationMenu;
			}
			return true;
		case 4:
			//Go Back
			removeLastPathEntry(path);
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



void NoteMenu::createANote(string path) {

	string noteName;
		
	cout << "What would you like to name your note?" << endl << endl
		<< ": ";
	do {
		getline(cin, noteName);
	} while (noteName.length() <= 0);

	checkValidInput();

	if (!checkCharacters(noteName)) {
		system("cls");
		cout << "Please Use Appropriate Characters: " << endl << endl;
		createANote(path);
	}

	this->noteName = noteName;
	this->noteContent = enterContents();

	system("cls");
	cout << "Would you like to protect your note?" << endl << endl
		 << ": ";

	do {
		string password = "";

		if (checkYesNo()) {
			system("cls");
			cout << "Please Enter a Password (No Spaces):" << endl << endl
				<< ": ";
			cin >> password;
			this->password = password;
			checkValidInput();
			if (password.size() > 0) {
				Note tempNote = Note(this->noteName, this->noteContent, this->password);
				tempNote.WritetoFile(path);
				break;
			} else {
				cout << "Invalid Password" << endl << endl;
			}
		} else {
			Note tempNote = Note(this->noteName, this->noteContent);
			tempNote.WritetoFile(path);
			break;
		}
	} while (true);

	cout << endl << "Note Successfully Created" << endl << endl;
	Sleep(1000);

}

bool NoteMenu::yesNoPassword() {

	do {
		system("cls");
		cout << "Would you like to protect your note?" << endl << endl
			<< ": ";
		if (checkYesNo()) {
			return true;
		} else {
			return false;
		}

	} while (true);

}

string NoteMenu::enterContents() {

	system("cls");
	string tempContents = "";
	string currLine;

	cout << "Please enter the contents of your note:" << endl
		 << "Type 'DONE' (all caps) on a new line" << endl << endl;

	do {
		getline(cin, currLine);
		if (currLine.length() > 0) {
			tempContents += currLine + "\n";
		}
		
	}while (currLine.compare("DONE"));

	tempContents = tempContents.substr(0, tempContents.find_last_of("\n"));
	tempContents = tempContents.substr(0, tempContents.find_last_of("\n"));

	return tempContents;
}

void NoteMenu::displayNoteOptions(string path, vector<string> noteList) {

	int counter = 1;
	for (auto currName = noteList.begin(); currName != noteList.end(); currName++) {
		Note currNote = Note::Open( path + *currName);
		cout << counter << ") " << currNote.GetTitle() << endl;
		counter++;
	}
}

void NoteMenu::selectANote(string path) {

	system("cls");

	bool noteExists = true;

	do {

		if (noteList.empty()) {
			cout << "No Notes Exist!" << endl;
			noteExists = false;
		} else {

			cout << "Please Select A Note:" << endl << endl;

			displayNoteOptions(path, noteList);

			cout << endl << ": ";
			int userOption = 0;
			cin >> userOption;
			checkValidInput();

			if (userOption == 0 || userOption > noteList.size()) {

				system("cls");
				cout << "Please enter a valid option: " << endl << endl;

			} else {

				this->noteName = noteList.at(userOption - 1);
				break;
			}

		}
	} while (noteExists);

}

bool NoteMenu::searchANote(string path) {

	system("cls");

	do {

		cout << "Please enter a search word: " << endl << endl
			<< ": ";
		string userSearch;
		cin >> userSearch;
		checkValidInput();

		vector<string> searchList;

		for (auto currName = noteList.begin(); currName != noteList.end(); currName++) {
			Note currNote = Note::Open(path + *currName);
			string tempCurrName = currNote.GetTitle();
			convToUpper(tempCurrName);
			string tempUserSearch = userSearch;
			convToUpper(tempUserSearch);

			if ((tempCurrName).find(tempUserSearch) != string::npos) {
				searchList.push_back(*currName);
			}
		}

		if (searchList.empty()) {
			cout << endl << "No Notes Exist!" << endl;
			Sleep(1000);
			return false;

		} else {
			cout << endl;
			displayNoteOptions(path, searchList);

			cout << endl << ": ";
			int userOption = 0;
			cin >> userOption;
			checkValidInput();

			if (userOption == 0 || userOption > searchList.size()) {

				system("cls");
				cout << "Please enter a valid option..." << endl << endl;
				Sleep(1000);
				return false;

			} else {

				this->noteSearch = searchList.at(userOption - 1);
				return true;

			}
		}

	} while (true);

}
