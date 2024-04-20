//
// Created by nicusor43 on 4/19/24.
//

#ifndef OOPPROJ2_CARD_H
#define OOPPROJ2_CARD_H

#include "string"
#include "iostream"

class Card {
    std::string nrCard;
    std::string nrDetinator;
    std::string data_expirare;
    int CVV{};
    double credit{};
    static int nrCarduri;

public:
    Card();

    Card(const std::string &nrCard, const std::string &nrDetinator,
         const std::string &data_expirare, int CVV,
         double credit);

    Card(const Card &other);

    virtual ~Card();

    Card &operator=(const Card &card2);

    friend std::istream &operator>>(std::istream &in, Card &newCard);

    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    static int getNrCarduri();

    [[nodiscard]] const std::string &getNrCard() const;

    [[nodiscard]] const std::string &getNrDetinator() const;

    [[nodiscard]] const std::string &getDataExpirare() const;

    [[nodiscard]] int getCvv() const;

    [[nodiscard]] double getCredit() const;

    void setNrCard(const std::string &newNrCard);

    void setNrDetinator(const std::string &newNrDetinator);

    void setDataExpirare(const std::string &newDataExpirare);

    void setCvv(int newCvv);

    void setCredit(double newCredit);

    virtual bool extragereBani(double suma);
};


#endif //OOPPROJ2_CARD_H
