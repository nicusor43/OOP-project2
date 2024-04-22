//
// Created by nicusor43 on 4/22/24.
//

#ifndef OOPPROJ2_MENU_H
#define OOPPROJ2_MENU_H

#include "iostream"
#include "vector"
#include "Card.h"
#include "CardStandard.h"
#include "CardPremium.h"

// singleton
class Menu {
    Menu() = default;
    ~Menu() = default;

    std::vector<Card*> cardVector;

public:
    Menu(Menu& menu) = delete;

    void operator=(Menu& menu) = delete;

    static Menu &getInstance();

    static void init();

    void alegere();

    void adauga();

    void afisareCarduri();

    void extragereBani();

};


#endif //OOPPROJ2_MENU_H
