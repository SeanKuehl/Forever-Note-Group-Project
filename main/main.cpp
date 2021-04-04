#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include<direct.h>
#include<filesystem>
#include <cassert>
#include <vector>
#include<stdlib.h>


using namespace std;

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

void Create_Category(string Path, string Name)           // Create Cat
{
    /*cout << "Enter New Folder's Name : ";
    string INPUT;
    cin >> INPUT;*/
    string Npath = Path + Name + +"//";


    cout << Npath; //888888888888888888888888888888888
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
int confirm(char Input)
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

void Delete_Category(string Path, string Name)
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

void merge_Category(string Source, string Destination)
{

    string Com2 = "move " + Source + " " + Destination;
    string COM = Com2;
    const char* COMMAND = COM.c_str();

    system(COMMAND);

    string COMMAND2 = "for %F in (" + Source + "\*.*) do move /Y %F " + Destination;
    const char* COM_2 = COMMAND2.c_str();
    system(COM_2);

}


void ListContents(string Path)
{
    system("cd C:\\Users\\arunp\\source\\repos\\CategoryPorject\\MoveFolder\\Storage\\Hello && dir > texyt.txt");
    //if (fopen("text.txt", "r")==0)
    //{

    //}
    //string Command1 = "dir > texyt.txt";

    //const char* Command = Command1.c_str();
    //system(Command);
}

/*
void Merge_Category(string F1, string F2)
{
    string NPath1 = F1;
    string NPath2 = F2;
    const char* Opath1 = NPath1.c_str();
    const char* Opath2 = NPath2.c_str();

    rename(Opath1, Opath2);

    //system(move();



}
*/


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


    merge_Category(File, File2);
    getchar();

    string Filee = "C:\\Users\\arunp\\source\\repos\\CategoryPorject\\MoveFolder\\Storage";
    ListContents(Filee);

    return 0;
}