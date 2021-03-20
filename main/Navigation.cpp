#include "Navigation.h"

void selectMenu(menuType type, Menu** m) {
	
	switch (type) {
	case menuType::mMenu:
		*m = new Menu;
		break;
	case menuType::Login:
		//mTemp = new Login;
		*m = new Login;
		break;
	case menuType::CreateAnAccount:
		*m = new CreateAnAccount;
		break;
	default:
		break;
	}
}

void exitApplication(Menu* m) {
	delete m;
	cout << "Good-Bye!" << endl;
	exit(EXIT_SUCCESS);
}