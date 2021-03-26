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
		 << "5) Exit" << endl;

	//this->catList = listCategories(username);

	this->catList.push_back("Cookies");
	this->catList.push_back("Dating");
	this->catList.push_back("Fun");
	this->catList.push_back("Cooking");
	this->catList.push_back("Other");

}

bool CategoryMenu::checkMenuOption(string& path, menuType& mType) {

	cout << endl << ":";
	cin >> menuOption;
	checkValidInput();
	do {
		switch (menuOption) {
		case 1:
			//Create A Category
			createACategory(path);
			path = path + this->catName + "/";
			mType = menuType::NoteMenu;
			return true;
		case 2:
			//Select A Category
			selectACategory(path);
			path = path + this->catName + "/";
			mType = menuType::NoteMenu;
			return true;
		case 3:
			//Merge Categories
			mergeACategory(path);
			return true;
		case 4:
			//Search Existing Categories
			if (searchACategory(path)) {
				path = path + this->catSearch + "/";
				mType = menuType::NoteMenu;
			}
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

void CategoryMenu::displayCatOptions(vector<string> catList) {

	int counter = 1;
	for (auto currName = catList.begin(); currName != catList.end(); currName++) {
		cout << counter << ") " << *currName << endl;
		counter++;
	}
}

string CategoryMenu::selectCatOption(vector<string> catList, int userOption) {

	int counter = 1;
	for (auto currName = catList.begin(); currName != catList.end(); currName++, counter++) {
		if (counter == userOption) {
			return *currName;
		}
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
		
	} while (!valid);

	this->catName = categoryName;

	/*if (Create_Category(username, categoryName)) {
		cout << "Category creation was successful" << endl;
	} else {
		cout << "Category creation was NOT successful" << endl;
	}*/
	
}

void CategoryMenu::selectACategory(string username) {

	system("cls");

	bool catExists = true;
	do {

		if (catList.empty()) {
			cout << "No Categories Exist!" << endl;
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

				this->catName = selectCatOption(catList, userOption);
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

			cout << endl << "1: ";
			int userOption1 = 0;
			cin >> userOption1;
			checkValidInput();

			cout << endl << "2: ";
			int userOption2 = 0;
			cin >> userOption2;
			checkValidInput();

			if (userOption1 == 0 || userOption1 > catList.size() &&
			    userOption2 == 0 || userOption2 > catList.size()) {

				system("cls");
				cout << "Please enter valid options: " << endl << endl;

			} else {

				this->catMerge1 = selectCatOption(catList, userOption1);
				this->catMerge2 = selectCatOption(catList, userOption2);

				/*if (mergeCategories(username, this->catMerge1, this->catMerge2)) {
					cout << "Merging Successful!" << endl;
				} else {
					cout << "Merging Was NOT Successful!" << endl;
				}*/
				break;

			}
		}

	} while (catExists);

}

bool CategoryMenu::searchACategory(string username) {
	
	system("cls");

	do {

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

				this->catSearch = selectCatOption(searchList, userOption);
				return true;

			}
		}

	} while (true);

}

