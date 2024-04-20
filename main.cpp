#include <iostream>
#include "Card.h"
#include "CardStandard.h"
#include "CardPremium.h"
#include "vector"

int main() {
    std::vector<Card*> cards;
    CardStandard cardStandard(100, 10, "34232", "Nicusor", "12/24", 100, 10000);
    cardStandard.extragereBani(101);
    cards.push_back(&cardStandard);
    CardPremium cardPremium(5, 100, 10, "34232", "Nicusor", "12/24", 100, 10000);
    cardPremium.extragereBani(101);
    CardPremium cardPremium2;
    std::cin >> cardPremium2;
    std::cout << cardPremium2;

    std::cout << Card::getNrCarduri();
}
