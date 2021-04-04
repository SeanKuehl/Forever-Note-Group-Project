#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class NoteModificationMenu : public Menu {
	//Note currNote;
public:
	NoteModificationMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
private:
	bool checkNoteState();
	void displayNote();
	void lockNote();
	void unlockNote();
	void editNote();
	void deleteNote();
};