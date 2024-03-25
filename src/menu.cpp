#include "menu.h"

Menu::Menu(QString name, QStringList items, Menu* parent){

    name = name;
    menuItems = items;
    parent = parent;
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
