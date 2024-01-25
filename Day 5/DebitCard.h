#ifndef DEBITCARD_H
#define DEBITCARD_H

#include<iostream>
#include"DebitCardType.h"


class DebitCard
{
private:
    int _cvv;
    std::string _name_on_card;
    std::string _expiry;
    DebitCardType _type;

public:
    DebitCard() = default;
    DebitCard(int cvv,std::string name_on_card,std::string expiry,DebitCardType type);
    DebitCard(const DebitCard&) = delete;
    DebitCard& operator = (const DebitCard&) = delete;
    DebitCard(DebitCard&&) = delete;
    DebitCard& operator = (DebitCard&&) = delete;
    ~DebitCard() = default;

    int getCvv() const { return _cvv; }

    std::string nameOnCard() const { return _name_on_card; }

    std::string expiry() const { return _expiry; }

    int cvv() const { return _cvv; }

    DebitCardType type() const { return _type; }

 
    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);

    
};

#endif // DEBITCARD_H
