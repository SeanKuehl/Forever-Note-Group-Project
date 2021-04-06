#pragma once
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>

using namespace std;

class NoteMenu : public Menu {
	string noteName;
	string noteContent;
	string password;
	string noteSearch;
	vector<string> noteList;
public:
	NoteMenu();
	void displayMessage() override;
	void displayMenu() override;
	bool checkMenuOption(string&, menuType&) override;
private:
	void createANote(string);
	bool yesNoPassword();
	string enterContents();
	void selectANote(string);
	void displayNoteOptions(string path, vector<string> noteList);
	bool searchANote(string);
};