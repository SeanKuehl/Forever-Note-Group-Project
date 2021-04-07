#include"Category.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool Delete_Category(string Path)                // CPP FUNCTION FOR DELETING A CATEGORY
{
    string NPath = Path;
    const char* Opath = NPath.c_str();
    if (_rmdir(Opath) != -1)
    {
        //cout << "Folder " << Name << " Deleted Succesfully" << endl;
        return true;

    }
    else {
        // cout << "Folder Can't be Deleted because it has files in it.\nDo you want to delete folder with files?(Y/N)" << endl;
        return false;

    }// Must Add one more case for Can't be deleted
}

bool Delete_Content_Category(string Path)
{
    char Inp;   // Doubt PART
    cin >> Inp;
    if (confirm(Inp) == 1)
    {
        string DelPath = "RMDIR /Q/S " + Path;
        const char* Del_Path = DelPath.c_str();
        system(Del_Path);
        if (!Check_Category(Del_Path))
        {
            //cout << "Folder " << Name << " Deleted Successfully.";
            return true;
        }
        else
        {
            return false;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


