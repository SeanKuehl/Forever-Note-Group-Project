#include"Category.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool Merge_Category(string Source, string Destination)
{
    vector<string> catList = List_CAT(Source);
    string Com2;

    for (auto i = catList.begin(); i != catList.end(); i++)
    {
        Com2 = "move \"" + Source + "\\" + *i + "\" \"" + Destination + "\" >nul";
        const char* COM1 = Com2.c_str();

        system(COM1);

    }

    Delete_Category(Source);

    const char* Source_path = Source.c_str();
    if (!Check_Category(Source_path))
    {
        return true;
    }
    else
    {
        return false;
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
