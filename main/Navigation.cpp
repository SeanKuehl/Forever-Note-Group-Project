#include "Navigation.h"

void selectMenu(menuType type, Menu** m) {
	
	switch (type) {
	case menuType::mMenu:
		*m = new Menu;
		break;
	case menuType::Login:
		*m = new Login;
		break;
	case menuType::CreateAnAccount:
		*m = new CreateAnAccount;
		break;
	case menuType::CategoryMenu:
		*m = new CategoryMenu;
		break;
	case menuType::NoteMenu:
		*m = new NoteMenu;
	default:
		break;
	}
}

void exitApplication(Menu* m) {
	delete m;
	cout << endl << "Good-Bye!" << endl;
	exit(EXIT_SUCCESS);
}