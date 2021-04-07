#include"Category.h"


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