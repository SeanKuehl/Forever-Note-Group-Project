#include"Category.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


vector<string> List_CAT(string path) {

    int Len = path.size() + 1;

    vector<string> Return_Vector;

    fs::path New_Path(path);

    for (auto const& entry : fs::directory_iterator(New_Path))
    {
        string fileName = entry.path().string();

        fileName = fileName.substr(Len);

        Return_Vector.push_back(fileName);


    }

    return Return_Vector;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
