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
			path = path + "/" + this->catName;
			mType = menuType::NoteMenu;
			return true;
		case 2:
			//Select A Category
			selectACategory(path);
			path = path + "/" +this->catName;
			mType = menuType::NoteMenu;
			return true;
		case 3:
			//Merge Categories
			return true;
		case 4:
			//Search Existing Categories
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

void CategoryMenu::createACategory(string username) {

	string categoryName;
	bool valid = false;
	do {
		system("cls");
		cout << "What would you like to name your category?" << endl << endl
			 << ": ";
		cin >> categoryName;
		checkValidInput();
		valid = checkFolderCharacters(categoryName);
		
	} while (!valid);

	this->catName = categoryName;
	//Category(username, categoryName)
}

void CategoryMenu::selectACategory(string username) {

	system("cls");

	//This should recieve a vector
	//vector<string> catList = listCategories(username);
	vector<string> catList;
	catList.push_back("Islam");
	catList.push_back("Kevin");
	catList.push_back("Sean");
	catList.push_back("Arun");
	catList.push_back("Elliot");

	//-------------------------
	bool catExists = true;
	do {

		if (catList.empty()) {
			cout << "No Categories Exist!" << endl;
			catExists = false;
		} else {

			cout << "Please Select A Category:" << endl << endl;

			int counter = 1;
			for (auto currName = catList.begin(); currName != catList.end(); currName++) {
				cout << counter << ") " << *currName << endl;
				counter++;
			}

			cout << endl << ": ";
			int userOption = 0;
			cin >> userOption;
			checkValidInput();

			if (userOption == 0 || userOption > catList.size()) {

				system("cls");
				cout << "Please enter a valid option: " << endl << endl;

			} else {
				counter = 1;
				for (auto currName = catList.begin(); currName != catList.end(); currName++, counter++) {
					if (counter == userOption) {
						this->catName = *currName;
						break;
					}
				}
				break;
			}

		}
	} while (catExists);
	

}