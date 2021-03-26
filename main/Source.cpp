#include "Menu.h"
#include "Login.h"
#include "Navigation.h"
#include "menuType.h"
#include <iostream>
using namespace std;

int main() {

	Menu* m = new Menu;
	menuType mType;
	string path = "";

	/*m->displayMessage();
	m->displayMenu();
	m->checkMenuOption(path, mType);*/

	do {
		
		m->displayMessage();
		m->displayMenu();

		if (!(m->checkMenuOption(path, mType))) {
			exitApplication(m);
		}

		selectMenu(mType, &m);

	} while (true);

	return 0;

}
