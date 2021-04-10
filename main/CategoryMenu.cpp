#include "CategoryMenu.h"

CategoryMenu::CategoryMenu() : Menu() {
}

void CategoryMenu::displayMessage() {
	system("cls");
	cout << "---Category Menu---" << endl << endl;
}

void CategoryMenu::displayMenu() {
	cout << "1) Create A Category" << endl
		 << "2) Select A Category" << endl
		 << "3) Merge Categories" << endl
		 << "4) Search Existing Categories" << endl
		 << "5) Delete A Category" << endl
		 << "6) Exit" << endl;

}

bool CategoryMenu::checkMenuOption(string& path, menuType& mType) {

	this->catList = GetCategoriesInDirectory(path);

	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//Create A Category
			createACategory(path);
			path = path + this->catName + "\\";
			mType = menuType::NoteMenu;
			return true;
		case 2:
			//Select A Category
			selectACategory(path);
			path = path + this->catName + "\\";
			mType = menuType::NoteMenu;
			return true;
		case 3:
			//Merge Categories
			mergeACategory(path);
			return true;
		case 4:
			//Search Existing Categories
			if (searchACategory(path)) {
				path = path + this->catSearch + "\\";
				mType = menuType::NoteMenu;
			}
			return true;
		case 5:
			//delete A Category
			deleteACategory(path);
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

void CategoryMenu::displayCatOptions(vector<string> catList) {

	int counter = 1;
	for (auto currName = catList.begin(); currName != catList.end(); currName++) {
		cout << counter << ") " << *currName << endl;
		counter++;
	}
}

void CategoryMenu::createACategory(string username) {

	string categoryName;
	bool valid = false;
	do {
		system("cls");
		cout << "What would you like to name your category?" << endl << endl
			 << ": ";
		cin >> categoryName;
		checkValidInput();
		valid = checkCharacters(categoryName);
		
		//if(!valid)

	} while (!valid);

	this->catName = categoryName;

	if (Create_Category(username, categoryName)) {
		cout << endl << "Category creation was successful";
		Sleep(1000);
	} else {
		cout << endl << "Category creation was NOT successful";
		Sleep(1000);
	}
	
}

void CategoryMenu::selectACategory(string username) {

	system("cls");

	bool catExists = true;
	do {

		if (catList.empty()) {
			cout << "No Categories Exist!" << endl;
			Sleep(1000);
			catExists = false;
		} else {

			cout << "Please Select A Category:" << endl << endl;

			displayCatOptions(catList);

			cout << endl << ": ";
			int userOption = 0;
			cin >> userOption;
			checkValidInput();

			if (userOption == 0 || userOption > catList.size()) {

				system("cls");
				cout << "Please enter a valid option: " << endl << endl;

			} else {

				this->catName = catList.at(userOption - 1);
				break;
			}

		}
	} while (catExists);

}

void CategoryMenu::mergeACategory(string username) {

	system("cls");

	bool catExists = true;
	do {

		if (catList.empty()) {
			cout << endl << "No Categories Exist!" << endl;
			Sleep(1000);
			catExists = false;
		} else {

			cout << "Please Select Category #1:" << endl << endl;

			displayCatOptions(catList);

			cout << endl << "Source: ";
			int source = 0;
			cin >> source;
			checkValidInput();

			cout << endl << "Destination: ";
			int destination = 0;
			cin >> destination;
			checkValidInput();

			if (source == 0 || source > catList.size() &&
				destination == 0 || destination > catList.size()) {

				system("cls");
				cout << "Please enter valid options: " << endl << endl;

			} else {

				this->source = username + catList.at(source - 1);
				this->destination = username + catList.at(destination - 1);

				if (Merge_Category(this->source, this->destination)) {
					
					cout << "Merging Successful!" << endl;
					Sleep(1000);
				} else {
					cout << "Merging Was NOT Successful!" << endl;
					Sleep(1000);
				}
				break;

			}
		}

	} while (catExists);

}

bool CategoryMenu::searchACategory(string username) {
	
	system("cls");

	bool catExists = true;

	do {

		if (catList.empty()) {
			cout << endl << "No Categories Exist!" << endl;
			Sleep(1000);
			catExists = false;

		} else {

			cout << "Please enter a search word: " << endl << endl
				 << ": ";
			string userSearch;
			cin >> userSearch;
			checkValidInput();

			vector<string> searchList;

			for (auto currName = catList.begin(); currName != catList.end(); currName++) {

				string tempCurrName = *currName;
				convToUpper(tempCurrName);
				string tempUserSearch = userSearch;
				convToUpper(tempUserSearch);

				if ((tempCurrName).find(tempUserSearch) != string::npos) {
					searchList.push_back(*currName);
				}
			}

			if (searchList.empty()) {
				cout << endl << "No Categories Exist!" << endl;
				Sleep(1000);
				return false;

			} else {
				cout << endl;
				displayCatOptions(searchList);

				cout << endl << ": ";
				int userOption = 0;
				cin >> userOption;
				checkValidInput();

				if (userOption == 0 || userOption > searchList.size()) {

					system("cls");
					cout << "Please enter valid options: " << endl << endl;

				} else {

					this->catSearch = searchList.at(userOption - 1);
					return true;

				}
			}
		}

	} while (catExists);

}

void CategoryMenu::deleteACategory(string username) {

	system("cls");

	bool catExists = true;

	do {

		if (catList.empty()) {
			cout << endl << "No Categories Exist!" << endl;
			Sleep(1000);
			catExists = false;

		} else {
			cout << "Please Select Category to Delete:" << endl << endl;

			displayCatOptions(catList);

			cout << endl << ": ";
			int source = 0;
			cin >> source;
			checkValidInput();

			if (source == 0 || source > catList.size()) {

				system("cls");
				cout << "Please enter valid options: " << endl << endl;

			} else {

				this->catDelete = username + catList.at(source - 1);

				cout << "Are you sure you want to delete this Category and its contents? (Y/N)" << endl << endl
					 << ":";

				if (checkYesNo()) {
					if (Delete_Content_Category(this->catDelete)) {
						cout << endl << "Deleting Successful!";
						Sleep(1000);
					} else {
						cout << endl << "Deleting Was NOT Successful!";
						Sleep(1000);
					}
				} else {
					cout << endl << "Deleting Was Aborted";
					Sleep(1000);
				}

				break;
			}
		}

	} while (catExists);

}