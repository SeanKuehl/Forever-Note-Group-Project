#include "Menu.h"
#include "Login.h"
#include "Navigation.h"
#include "menuType.h"
#include <iostream>
using namespace std;

int main() {

	Menu* m = new Menu;
	menuType mType = menuType::mMenu;

	m->displayMessage();
	m->displayMenu();

	if (m->checkMenuOption(mType)) {
		selectMenu(mType, &m);
		m->displayMessage();
		m->displayMenu();
	} else {
		exitApplication(m);
	}

	return 0;

}
