#include <iostream>

#include "Menu.h"

int main() {
    Menu& menu = Menu::getInstance();
    Menu::init();
    while(true) {
        menu.alegere();
    }
}
