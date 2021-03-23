#pragma once
#include "menuType.h"
#include "Menu.h"
#include "Login.h"
#include "CreateAnAccount.h"
#include "CategoryMenu.h"
#include "NoteMenu.h"

void selectMenu(menuType, Menu**);
void exitApplication(Menu*);