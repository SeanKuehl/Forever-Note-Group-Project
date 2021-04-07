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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool Check_Category(const char* Path)
{
    struct stat info;

    if (stat(Path, &info) != 0)
        return false;
    else if (info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}



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

int confirm(char Input)                              // SUPPORT FUNCTION FOR ACTION CONFIRMATIONS
{
    if (&Input == "Y")
    {
        return 1;
    }
    else if (&Input == "N")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}


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


bool Merge_Category(string Source, string Destination)
{
    vector<string> catList = List_CAT(Source);
    string Com2;

    for (auto i = catList.begin(); i != catList.end(); i++)
    {
        Com2 = "move " + Source + "\\" + *i + " " + Destination + " >nul";
        const char* COM1 = Com2.c_str();

        system(COM1);
        //cout <<  *i << endl;

    }

    Delete_Category(Source);

    const char* Source_path = Source.c_str();
    if (!Check_Category(Source_path))
    {
        //cout << "Folder " << Name << " Deleted Successfully.";
        return true;
    }
    else
    {
        return false;
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    string Mpath = "C:/Users/arunp/Desktop/Winter_Sem/TB/Hello/";
    string MINPUT = "OOOlala";

    Create_Category(Mpath, MINPUT);

    getchar();

    Delete_Category(Mpath);

    getchar();

    /* string NPATH1= "C:/Users/arunp/Desktop/Winter Sem/6_Tem Based Software Dev/Omg/";
     string NPATH2 = "C:/Users/arunp/Desktop/Winter Sem/6_Tem Based Software Dev/Hello";

     Merge_Category(NPATH1, NPATH2);




     NPATH1.c_str
     */

    string File = "C:\\Users\\arunp\\Desktop\\Winter_Sem\\TB\\Omg\\test1";
    //string File = "C:/Users/arunp/Desktop/Winter_Sem/TB/Omg/File2";
    string File2 = "C:\\Users\\arunp\\Desktop\\Winter_Sem\\TB\\Omg\\test2";


   // merge_Category(File, File2);
    
    getchar();
    Merge_Category(File, File2);
    getchar();
    string Filee = "C:\\Users\\arunp\\source\\repos\\CategoryPorject\\MoveFolder\\Storage";
    //ListContents(Filee);

    return 0;
}