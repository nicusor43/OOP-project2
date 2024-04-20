//
// Created by nicusor43 on 4/19/24.
//

#include "Card.h"


// Static variable
int Card::nrCarduri = 0;

Card::Card() {
    nrCard = "";
    nrDetinator = "";
    data_expirare = "";
    CVV = 000;
    credit = 0;
    nrCarduri++;
}

Card::Card(const std::string &nrCard, const std::string &nrDetinator,
           const std::string &data_expirare, int CVV,
           double credit) {
    this->nrCard = nrCard;
    this->nrDetinator = nrDetinator;
    this->data_expirare = data_expirare;
    this->CVV = CVV;
    this->credit = credit;
    nrCarduri++;
}

Card::Card(const Card &other) {
    this->nrCard = other.nrCard;
    this->nrDetinator = other.nrDetinator;
    this->data_expirare = other.data_expirare;
    this->CVV = other.CVV;
    this->credit = other.credit;
}

Card &Card::operator=(const Card &card2) {
    if (this == &card2) {
        return *this;
    }

    this->nrCard = card2.nrCard;
    this->nrDetinator = card2.nrDetinator;
    this->data_expirare = card2.data_expirare;
    this->CVV = card2.CVV;
    this->credit = card2.credit;

    return *this;
}

Card::~Card() = default;


std::istream &operator>>(std::istream &in, Card &newCard) {
    std::cout << "Citesti un card. \n Va trebui să scrii următoarele atribute: "
              << "\n Numărul cardului \n Numărul deținătorului \n Data de expirare"
              << "\n CVV-ul \n Creditul\n";

    std::cout << "1. Scrie numărul cardului: \n";
    std::getline(in >> std::ws, newCard.nrCard);


    std::cout << "\n2. Scrie numărul deținătorului: \n";
    std::getline(in >> std::ws, newCard.nrDetinator);

    std::cout << "\n3. Scrie data de expirare: \n";
    std::getline(in >> std::ws, newCard.data_expirare);

    std::cout << "\n4. Scrie CVV-ul: \n";
    in >> newCard.CVV;

    std::cout << "\n5. Scrie Creditul: \n";
    in >> newCard.credit;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Card &card) {
    out << "Numărul cardului: " << card.nrCard;
    out << std::endl;

    out << "Numărul deținătorului: " << card.nrDetinator;
    out << std::endl;

    out << "Data de expirare: " << card.data_expirare;
    out << std::endl;

    out << "CVV-ul: " << card.CVV;
    out << std::endl;

    out << "Creditul: " << card.credit;
    out << std::endl;

    return out;
}

int Card::getNrCarduri() {
    return nrCarduri;
}

const std::string &Card::getNrCard() const {
    return nrCard;
}

const std::string &Card::getNrDetinator() const {
    return nrDetinator;
}

const std::string &Card::getDataExpirare() const {
    return data_expirare;
}

int Card::getCvv() const {
    return CVV;
}

double Card::getCredit() const {
    return credit;
}

void Card::setNrCard(const std::string &newNrCard) {
    this->nrCard = newNrCard;
}

void Card::setNrDetinator(const std::string &newNrDetinator) {
    this->nrDetinator = newNrDetinator;
}

void Card::setDataExpirare(const std::string &newDataExpirare) {
    this->data_expirare = newDataExpirare;
}

void Card::setCvv(int newCvv) {
    this->CVV = newCvv;
}

void Card::setCredit(double newCredit) {
    this->credit = newCredit;
}

bool Card::extragereBani(double suma) {
    if (suma > credit) {
        std::cout << "Nu ai suficienți bani în cont. \n";
        return false;
    } else {
        credit -= suma;
        std::cout << "Ai extras " << suma << " lei. \n";
        return true;
    }
}






