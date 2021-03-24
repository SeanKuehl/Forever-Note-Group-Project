#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
//this program gets the current working directory
#include<iostream>
#include <Windows.h>
#include <filesystem>
#include <direct.h>
#include <experimental/filesystem>
#define GetCurrentDir _getcwd
#include <vector>

//https://www.codingame.com/playgrounds/5659/c17-filesystem

//I'll need to process the output more, we'll have to hardcode in certain names to avoid etc.

//take the length of the directory path and take that much off of the retrived entries

namespace fs = std::experimental::filesystem;

using namespace std;


string get_current_dir() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}



vector<string> GetCategoriesInDirectory(string path) {

    int pathLength = path.size() + 1;   //if I don't add the +1 it'll keep the last slash
    vector<string> toReturn;

    fs::path pathToShow(path);
    for (auto const& entry : fs::directory_iterator(pathToShow)) {
        string fileName = entry.path().string();

        fileName = fileName.substr(pathLength);     // get from position to the end

        //if there's a '.' in the name then it's a file with an extension, the '.' is illegal in folder names
        //.find returns highest possible for size_t data type if it fails
        if (fileName.find('.') < fileName.size()) {
            //it's a file and a '.' was found
        }
        else {
            //it's a categoriy and a '.' was not found

            toReturn.push_back(fileName);
        }


    }

    //for users, there'll be a problem where there are unwanted things in the directory,
    //but these can be hardcoded to be removed

    //in other things like within a category we made this won't be a problem
    //we should use .txt to seperate notes and categories

    return toReturn;
}

vector<string> GetNotesInDirectory(string path) {

    int pathLength = path.size() + 1;   //if I don't add the +1 it'll keep the last slash
    vector<string> toReturn;

    fs::path pathToShow(path);
    for (auto const& entry : fs::directory_iterator(pathToShow)) {
        string fileName = entry.path().string();

        fileName = fileName.substr(pathLength);     // get from position to the end

        //if there's a '.' in the name then it's a file with an extension, the '.' is illegal in folder names
        //.find returns highest possible for size_t data type if it fails
        if (fileName.find('.') < fileName.size()) {
            //it's a file and a '.' was found
            if (fileName.find(".note") < fileName.size()) {
                //it's a note file we want to use and show to user
                toReturn.push_back(fileName);
            }
        }
        else {
            //it's a categoriy and a '.' was not found


        }


    }

    //for users, there'll be a problem where there are unwanted things in the directory,
    //but these can be hardcoded to be removed

    //in other things like within a category we made this won't be a problem
    //we should use .txt to seperate notes and categories

    return toReturn;
}

