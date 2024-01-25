#ifndef LISCENCE_H
#define LISCENCE_H

#include "LiscenecType.h"
#include<iostream>

class Liscence
{
private:
    std::string liscenceNumber;
    int liscenceValidityYears;
    LiscenceCategory liscenceCategory;
    std::string liscenceIssuingRTO;
    std::string liscenceIssusingState;

public:
    Liscence() = delete;
    Liscence(std::string number,int years,LiscenceCategory category,std::string issuingRTO,std::string issingState);
    Liscence(const Liscence &) = delete;
    Liscence &operator=(Liscence &) = delete;
    Liscence(const Liscence &&) = delete;
    Liscence &operator=(Liscence &&) = delete;
    ~Liscence() = default;

    std::string getLiscenceNumber() const { return liscenceNumber; }

    int getLiscenceValidityYears() const { return liscenceValidityYears; }

    LiscenceCategory getLiscenceCategory() const { return liscenceCategory; }

    std::string getLiscenceIssuingRTO() const { return liscenceIssuingRTO; }

    std::string getLiscenceIssusingState() const { return liscenceIssusingState; }

    friend std::ostream &operator<<(std::ostream &os, const Liscence &rhs);
};



#endif // LISCENCE_H
