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

int Check_Category(const char* Path)
{
    struct stat info;

    if (stat(Path, &info) != 0)
        return 0;
    else if (info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Create_Category(string Path, string Name)           // CPP FUNCTION TO CREATE A CATEGORY
{
    
    string Npath = Path + Name + +"//";


    cout << Npath; 
    const char* Opath = Npath.c_str();

    _mkdir(Opath);

    if (Check_Category(Opath) == 1)
    {
        cout << "\nCreated new Directory \n" << Path << endl;
        
    }
    else if (Check_Category(Opath) == 0)
    {

        cout << "\nCan't create Folder\n";
    }


}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int confirm(char Input) // SUPPORT FUNCTION FOR ACTION CONFIRMATIONS
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

void Delete_Category(string Path, string Name)      // CPP FUNCTION FOR DELETING A CATEGORY
{
    string NPath = Path + Name;
    const char* Opath = NPath.c_str();
    if (_rmdir(Opath) != -1)
    {
        cout << "Folder " << Name << " Deleted Succesfully" << endl;
    }
    else {
        cout << "Folder " << Name << " Can't be Deleted because it has files in it.\nDo you want to delete folder with files?(Y/N)" << endl;
        char Inp;
        cin >> Inp;
        if (confirm(Inp) == 1)
        {
            string DelPath = "RMDIR /Q/S " + NPath;
            const char* Del_Path = DelPath.c_str();
            system(Del_Path);
            if (Check_Category(Del_Path) == 0)
            {
                cout << "Folder " << Name << " Deleted Successfully.";
            }
        }

    }
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


std::string Get_Parent(const std::string& fname)    
{
    size_t pos = fname.find_last_of("\\/");
    return (std::string::npos == pos)
        ? ""
        : fname.substr(0, pos);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void merge_Category(string Source, string Destination)
{

    
    
        string Com2 = "move " + Source + "\*  " + Destination;
    string COM = Com2;
    const char* COMMAND = COM.c_str();
    string COM_New = " for /f %a IN ('dir %" + Source + "% /b') do move %" + Source + "%\%a " + Destination +"%";
    const char* COM_New1 = COM_New.c_str();
    //system(COM_New1);
    /**/
    string COMMAND2 = "for %F in (" + Source + "\*.*) do move /Y %F " + Destination;
    const char* COM_2 = COMMAND2.c_str();
    //system(COM_2);
    
    //string SETCOM = "SET src_folder=" + Source;
    string TARCOM = Destination + "\\";
    string MAIN_COM = "for /f %a IN ('dir " + Source + " /b') do move %" + Source + "%\%a %" + TARCOM + "\\";
        
        //"for /f %a IN ('dir "+ Source +" /b') do move %"+ Source +"%\%a %"+TARCOM+ "\\";
        //"FOR / R " + Source + " % i IN(*.png) DO MOVE ""%i"" ""C:\Staging Folder";
        
        //const char* SETCOM1 = SETCOM.c_str();
    //const char* TARCOM1 = TARCOM.c_str();
    const char* MAIN_COM1 = MAIN_COM.c_str();

    //system(SETCOM1);
    //system(TARCOM1);
    system(MAIN_COM1);
}

void Merge_CAT2(string Source, string Destination)
{
    //string COMMAND = "for /f %a IN ('dir %"+Source +"%  /b') do move %"+Source+"%\%a "+Destination+"%\"";
    //const char* CMD1 = COMMAND.c_str();
    //system(CMD1);

   /* string COOM2 = "move "+ Source + " "+Destination;
    const char* COOMA = COOM2.c_str();

    system(COOMA);
    string PATH = get_current_dir();
    cout << PATH;
    */

    string COM1 = "SET src_folder =" + Source;
    const char* COM11 = COM1.c_str();

    string COM2 = "SET des_folder =" + Destination;
    const char* COM22 = COM2.c_str();

    string COM3 = "for /f %a IN ('dir ""%src_folder%"" /b') do move ""%src_folder%\%%a"" ""%tar_folder%\"" "";
    const char* COM33 = COM3.c_str();

    string MAIN_COM = COM1 + ";" + COM2 + ";" + COM3;

    const char* MAINCOM=MAIN_COM.c_str();

    system(COM11);
    system(COM22);
    system(COM33);

    system(MAINCOM);
    //system(MAINCOM);
    /*
    system();
        SET tar_folder = c:\tarfold

        for / f % %a IN('dir "%src_folder%" /b') do move "%src_folder%\%%a" "%tar_folder%\"
        */
}


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

int main()
{
    string Mpath = "C:/Users/arunp/Desktop/Winter_Sem/TB/Hello/";
    string MINPUT = "OOOlala";

    Create_Category(Mpath, MINPUT);

    getchar();

    Delete_Category(Mpath, MINPUT);

    getchar();

    /* string NPATH1= "C:/Users/arunp/Desktop/Winter Sem/6_Tem Based Software Dev/Omg/";
     string NPATH2 = "C:/Users/arunp/Desktop/Winter Sem/6_Tem Based Software Dev/Hello";

     Merge_Category(NPATH1, NPATH2);




     NPATH1.c_str
     */

    string File = "C:\\Users\\arunp\\Desktop\\Winter_Sem\\TB\\Omg\\File2";
    string File2 = "C:\\Users\\arunp\\Desktop\\Winter_Sem\\TB\\Omg\\Sugun";


   // merge_Category(File, File2);
    
    getchar();
    Merge_CAT2(File, File2);
    getchar();
    string Filee = "C:\\Users\\arunp\\source\\repos\\CategoryPorject\\MoveFolder\\Storage";
    //ListContents(Filee);

    return 0;
}