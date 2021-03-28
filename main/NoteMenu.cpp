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

	this->noteList.push_back("pizza");
	this->noteList.push_back("soup");
	this->noteList.push_back("sauce");

}

bool NoteMenu::checkMenuOption(string& path, menuType& mType) {
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
			mType = menuType::NoteModificationMenu;
			return true;
		case 3:
			//Search Existing Notes
			searchANote(path);
			mType = menuType::NoteModificationMenu;
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

void NoteMenu::createANote(string path) {

	string noteName;
	
		
	cout << "What would you like to name your note?" << endl << endl
		<< ": ";
	cin >> noteName;
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
			checkValidInput();
			if (password.size() > 0) {
				//Note(noteName, contents, password);
				break;
			} else {
				cout << "Invalid Password" << endl << endl;
			}
		} else {
			//Note(noteName, contents);
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

	string tempContents = "";
	string currLine;

	cout << "Please enter the contents of your note:" << endl;

	do {
		cin >> currLine;
		checkValidInput();
		tempContents += currLine + "\n";

	}while (currLine.compare("DONE"));

	tempContents = tempContents.substr(0, tempContents.find_last_of("\n"));
	tempContents = tempContents.substr(0, tempContents.find_last_of("\n"));

	return tempContents;
}

void NoteMenu::displayNoteOptions(string path, vector<string> noteList) {

	int counter = 1;
	for (auto currName = noteList.begin(); currName != noteList.end(); currName++) {
		//Note currNote = Note.Open( path + *currName + ".note");
		//cout << counter << ") " << currNote.getTitle() << endl;
		cout << counter << ") " << *currName << endl;
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

			string tempCurrName = *currName;
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
				cout << "Please enter valid options: " << endl << endl;

			} else {

				this->noteSearch = searchList.at(userOption - 1);
				return true;

			}
		}

	} while (true);

}
