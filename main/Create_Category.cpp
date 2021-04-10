#include"Category.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool Create_Category(string Path, string Name)                  // CPP FUNCTION TO CREATE A CATEGORY
{

    string Npath = Path + Name + +"//";


    //cout << Npath; 
    const char* Opath = Npath.c_str();

    _mkdir(Opath);

    if (Check_Category(Opath))
    {
        //cout << "\nCreated new Directory \n" << Path << endl;
        return true;
    }
    else
    {

        //cout << "\nCan't create Folder\n";
        return false;
    }


}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
