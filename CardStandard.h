//
// Created by nicusor43 on 4/19/24.
//

#ifndef OOPPROJ2_CARDSTANDARD_H
#define OOPPROJ2_CARDSTANDARD_H


#include "Card.h"

class CardStandard : public Card {
    int limitaExtragere;
    double comisionDepasireLimita;

public:
    CardStandard();

    CardStandard(int limitaExtragere, double comisionDepasireLimita,
                 const std::string &nrCard,
                 const std::string &nrDetinator,
                 const std::string &data_expirare, int CVV,
                 double credit);


    CardStandard(const CardStandard &other);

    ~CardStandard() override;

    CardStandard &operator=(const CardStandard &cardStandard2);

    friend std::istream &operator>>(std::istream &in, CardStandard &newCardStandard);

    friend std::ostream &operator<<(std::ostream &out, const CardStandard &newCardStandard);

    [[nodiscard]] int getLimitaExtragere() const;

    [[nodiscard]] double getComisionDepasireLimita() const;

    void setLimitaExtragere(int newLimitaExtragere);

    void setComisionDepasireLimita(double newComisionDepasireLimita);

    bool extragereBani(double suma) override;
};


#endif //OOPPROJ2_CARDSTANDARD_H
