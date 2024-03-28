#include "menu.h"

Menu::Menu(QString iname, QStringList items, Menu* iparent){

    name = iname;
    menuItems = items;
    parent = iparent;
}

Menu::~Menu(){
    int i = 0;
    while( subMenus.size() > 0){
        delete subMenus[i];
    }
}

QString Menu::getName(){ return name; }
QStringList Menu::getMenuItems(){ return menuItems; }
Menu* Menu::getParent(){ return parent; }
int Menu::getPosition(){ return position; }

void Menu::addChildMenu(Menu* newMenu){
    subMenus.push_back(newMenu);
}

Menu *Menu::get(int i){
    return subMenus[i];
}
