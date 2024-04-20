//
// Created by nicusor43 on 4/20/24.
//

#ifndef OOPPROJ2_CARDPREMIUM_H
#define OOPPROJ2_CARDPREMIUM_H


#include <string>
#include "CardStandard.h"

class CardPremium : public CardStandard {
    double cashback;

public:
    CardPremium();

    CardPremium(double cashback,
                int limitaExtragere,
                double comisionDepasireLimita,
                const std::string &nrCard,
                const std::string &nrDetinator,
                const std::string &data_expirare, int CVV,
                double credit);

    CardPremium(const CardPremium &other);

    ~CardPremium() override;

    CardPremium &operator=(const CardPremium &cardPremium2);

    friend std::istream &operator>>(std::istream &in, CardPremium &newCardPremium);

    friend std::ostream &operator<<(std::ostream &out, const CardPremium &newCardPremium);

    [[nodiscard]] double getCashback() const;

    void setCashback(double newCashback);

    bool extragereBani(double suma) override;
};


#endif //OOPPROJ2_CARDPREMIUM_H
