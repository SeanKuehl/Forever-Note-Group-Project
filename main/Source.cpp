#include "Menu.h"
#include "Login.h"
#include "Navigation.h"
#include "menuType.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	
	if (argc > 0) {
		for (int i = 1; i < argc; i++) {
			cout << argv[i] << " ";
		}
		cout << endl << endl;
	}

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

	
	return 0;

}
