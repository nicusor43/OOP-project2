//
// Created by nicusor43 on 4/19/24.
//

#include "CardStandard.h"

CardStandard::CardStandard() : Card() {
    limitaExtragere = 0;
    comisionDepasireLimita = 0.0;
}

CardStandard::CardStandard(int limitaExtragere, double comisionDepasireLimita,
                           const std::string &nrCard,
                           const std::string &nrDetinator,
                           const std::string &data_expirare, int CVV,
                           double credit) : Card(nrCard, nrDetinator,
                                                 data_expirare, CVV, credit) {
    this->limitaExtragere = limitaExtragere;
    this->comisionDepasireLimita = comisionDepasireLimita;
}

CardStandard::CardStandard(const CardStandard &other) : Card(other) {
    this->comisionDepasireLimita = other.comisionDepasireLimita;
    this->limitaExtragere = other.limitaExtragere;
}

CardStandard &CardStandard::operator=(const CardStandard &cardStandard2) {
    if (this == &cardStandard2) {
        return *this;
    }

    Card::operator=(cardStandard2);

    this->comisionDepasireLimita = cardStandard2.comisionDepasireLimita;
    this->limitaExtragere = cardStandard2.limitaExtragere;

    return *this;
}

std::istream &operator>>(std::istream &in, CardStandard &newCardStandard) {
    in >> dynamic_cast<Card &>(newCardStandard);

    std::cout << "Cardul standard conține și o limita de extragere și un comision la "
              << "depășirea limitei"
              << "\nScrie limita de extragere: \n";
    in >> newCardStandard.limitaExtragere;

    std::cout << "\nScrie comisionul pentru depășirea limitei:\n";
    in >> newCardStandard.comisionDepasireLimita;

    return in;
}

std::ostream &operator<<(std::ostream &out, const CardStandard &newCardStandard) {
    out << dynamic_cast<const Card &>(newCardStandard);

    out << "Limiga de extragere: " << newCardStandard.limitaExtragere;
    out << std::endl;

    out << "Comisionul pentru depășirea limitei: " << newCardStandard.comisionDepasireLimita;
    out << std::endl;

    return out;
}

int CardStandard::getLimitaExtragere() const {
    return limitaExtragere;
}

double CardStandard::getComisionDepasireLimita() const {
    return comisionDepasireLimita;
}

void CardStandard::setLimitaExtragere(int newLimitaExtragere) {
    this->limitaExtragere = newLimitaExtragere;
}

void CardStandard::setComisionDepasireLimita(double newComisionDepasireLimita) {
    this->comisionDepasireLimita = newComisionDepasireLimita;
}

bool CardStandard::extragereBani(double suma) {
    bool posibil = Card::extragereBani(suma);

    if (!posibil) {
        return false;
    } else if (suma > getLimitaExtragere()) {
        setCredit(getCredit() - getComisionDepasireLimita());
        std::cout << "Ai depășit limita de extragere de " << getLimitaExtragere()
                  << " lei. \n"
                  << "Comisionul pentru depășirea limitei este de "
                  << getComisionDepasireLimita() << " lei. \n";
        std::cout << "Mai ai " << getCredit() << " lei în cont. \n";
    }
    return true;
}


CardStandard::~CardStandard() = default;


