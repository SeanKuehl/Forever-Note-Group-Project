#pragma once


#include <string>
#include <vector>

using namespace std;


string get_current_dir();




vector<string> GetCategoriesInDirectory(string path);

vector<string> GetNotesInDirectory(string path);


vector<string> GetNotesInDirectoryTestingStub(vector<string> files);




vector<string> GetCategoriesInDirectoryTestingStub(vector<string> files);


