
#include "Menu.h"
#include "Login.h"
#include "Navigation.h"
#include "menuType.h"
#include <iostream>

using namespace std;

int main() {


	Menu* m = new Menu;
	menuType mType = menuType::mMenu;
	string path = "";

	m->displayMessage();
	m->displayMenu();
	m->checkMenuOption(path, mType);

	do {
		selectMenu(mType, &m);
		m->displayMessage();
		m->displayMenu();

		if (!(m->checkMenuOption(path, mType))) {
			exitApplication(m);
		}

	} while (true);


	//#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
	//#include <experimental/filesystem>
	//it said there was a way to do it with just filesystem but I couldn't get it to work
	//this works!
	//std::experimental::filesystem::remove("hello");
	
	//this only works for empty directories which is fine because that's all they'll be for testing
	
	
	return 0;

}
