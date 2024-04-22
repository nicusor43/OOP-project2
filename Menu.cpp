//
// Created by nicusor43 on 4/22/24.
//

#include "Menu.h"

Menu &Menu::getInstance() {
    static Menu menu;
    return menu;
}

void Menu::init() {
    std::cout << "Bine te-am regasit la banca UB. " << std::endl
              << "Acesta este meniul interactiv" << std::endl;
}

void Menu::alegere() {
    std::cout << "Te afli in meniul principal. " << std::endl
              << "Poți alege una dintre 3 operații: " << std::endl
              << "Scrie 1 pentru a adauga un card, " << std::endl
              << "      2 pentru a vedea ce carduri ai in cont," << std::endl
              << "      3 pentru a face actiuni pe un card," << std::endl
              << "      4 pentru a opri programul: " << std::endl;

    int meniu_ales;
    std::cin >> meniu_ales;

    while (meniu_ales != 1 && meniu_ales != 2 && meniu_ales != 3 && meniu_ales != 4 ) {
        std::cout << "Ai introdus un număr greșit. Incearca din nou: ";
        std::cin >> meniu_ales;
    }

    switch (meniu_ales) {
        case 1: {
            adauga();
            break;
        }
        case 2: {
            afisareCarduri();
            break;
        }
        case 3: {
            extragereBani();
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            // idk
        }
    }
}

void Menu::adauga() {
    int card_ales;

    std::cout << "Ce tip de card vrei? " << std::endl
              << "Scrie 1 pentru standard sau 2 pentru premium: ";
    std::cin >> card_ales;

    if (card_ales == 1) {
        auto *cardDeAdaugat = new CardStandard;
        std::cin >> *cardDeAdaugat;
        cardVector.push_back(cardDeAdaugat);
    } else if (card_ales == 2) {
        auto *cardDeAdaugat = new CardPremium;
        std::cin >> *cardDeAdaugat;
        cardVector.push_back(cardDeAdaugat);
    } else {
        std::cout << "Ai introdus gresit. Se face intoarcerea la meniul principal" << std::endl;
        return;
    }
}

void Menu::afisareCarduri() {
    std::cout << "Se afiseaza toate cardurile: " << std::endl;
    for (ulong i = 0; i < cardVector.size(); i++) {
        std::cout << "Al " << i + 1 << "-lea card" << std::endl;

        if (typeid(*cardVector.at(i)) == typeid(CardStandard)) {
            std::cout << "Card de tip standard." << std::endl;
        } else {
            std::cout << "Card de tip premium." << std::endl;
        }

        std::cout << *cardVector.at(i);
    }
}

void Menu::extragereBani() {
    ulong index_card;
    std::cout << "Alege indexul cardului din care extragi bani: ";
    std::cin >> index_card;
    std::cout << std::endl;

    if (index_card > cardVector.size()) {
        std::cout << "Indexul e prea mare.";
        return;
    }

    std::cout << "Ai ales cardul " << index_card << std::endl;
    std::cout << "Se vor afisa informatiile cardului: " << std::endl;
    std::cout << *cardVector.at(index_card-1);

    std::cout << "Scrie cati bani vrei sa extragi: ";
    int suma;
    std::cin >> suma;
    std::cout << std::endl;

    cardVector.at(index_card-1)->extragereBani(suma);
}









