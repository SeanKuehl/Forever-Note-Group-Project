#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include<direct.h>
#include<filesystem>
#include <cassert>
#include <vector>
#include<stdlib.h>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <vector>

namespace fs = std::experimental::filesystem;
using namespace std;

//---------------------------------------------------------------------------------------------------------------------

bool Create_Category(string Path, string Name);

//---------------------------------------------------------------------------------------------------------------------

bool Delete_Category(string Path);
bool Delete_Content_Category(string Path);

//---------------------------------------------------------------------------------------------------------------------

vector<string> List_CAT(string path);

//---------------------------------------------------------------------------------------------------------------------

bool Merge_Category(string Source, string Destination);


//---------------------------------------------------------------------------------------------------------------------

bool Check_Category(const char* Path);
int confirm(char Input);

//---------------------------------------------------------------------------------------------------------------------
