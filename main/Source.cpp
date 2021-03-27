#include <iostream>
#include <vector>
#include "Note.h"

int main() {
	Note note = Note("New title", "contents", true, "pa$$");
	string someString;

	std::cout << note.GetTitle() << std::endl;
	note.GetContents(someString);
	std::cout << someString << std::endl;

	note.WritetoFile("C:\\Users\\Kevin\\Documents\\Schooling\\College 2\\Classes\\Semester 2\\CSCN71030-Proj2-Team Based Software");
	note.Delete();



	string path = "C:\\Users\\Kevin\\Documents\\Schooling\\College 2\\Classes\\Semester 2\\CSCN71030-Proj2-Team Based Software\\test.note";
	note = Note::Open(path);

	vector<string> strings;

	std::cout << note.GetTitle() << std::endl;
	strings.push_back(someString);
	note.GetContents(someString);
	std::cout << someString << std::endl;
	strings.push_back(someString);

	cout << "vector: ";
	for (std::vector<string>::iterator i = strings.begin(); i != strings.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	note.Edit();
	note.GetContents(someString);
	std::cout << someString << std::endl;

	return 0;
}