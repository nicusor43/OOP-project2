//
// Created by nicusor43 on 4/20/24.
//

#include "CardPremium.h"

CardPremium::~CardPremium() = default;

CardPremium::CardPremium() : CardStandard() {
    cashback = 0;
}

CardPremium::CardPremium(double cashback, int limitaExtragere,
                         double comisionDepasireLimita, const std::string &nrCard,
                         const std::string &nrDetinator,
                         const std::string &data_expirare,
                         int CVV, double credit) : CardStandard(limitaExtragere,
                                                                comisionDepasireLimita, nrCard,
                                                                nrDetinator,
                                                                data_expirare, CVV, credit) {
    this->cashback = cashback;
}

CardPremium::CardPremium(const CardPremium &other) : CardStandard(other) {
    this->cashback = other.cashback;
}

CardPremium &CardPremium::operator=(const CardPremium &cardPremium2) {
    if (this == &cardPremium2) {
        return *this;
    }

    CardStandard::operator=(cardPremium2);
    this->cashback = cardPremium2.cashback;

    return *this;
}

std::istream &operator>>(std::istream &in, CardPremium &newCardPremium) {
    in >> dynamic_cast<CardStandard &>(newCardPremium);

    std::cout << "Cardul premium conține și un cashback"
              << "\nScrie cashback-ul (procentaj):\n";
    in >> newCardPremium.cashback;
    return in;
}

std::ostream &operator<<(std::ostream &out, const CardPremium &newCardPremium) {
    out << dynamic_cast<const CardStandard &>(newCardPremium);

    out << "Cashback: " << newCardPremium.cashback;
    out << std::endl;

    return out;
}

double CardPremium::getCashback() const {
    return cashback;
}

void CardPremium::setCashback(double newCashback) {
    this->cashback = newCashback;
}

bool CardPremium::extragereBani(double suma) {
    bool possible = CardStandard::extragereBani(suma);

    if (!possible) {
        return false;
    } else {
        setCredit(getCredit() + cashback * suma);
        std::cout << "Ai primit cashback de " << cashback * suma << " lei\n";
        std::cout << "Creditul tau este acum de " << getCredit() << " lei\n";
        return true;
    }
}




