#include "DebitCard.h"

DebitCard::DebitCard(int cvv, std::string name_on_card, std::string expiry, DebitCardType type)
{
}


std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "cvv: " << rhs._cvv
       << " _name_on_card: " << rhs._name_on_card
       << " _expiry: " << rhs._expiry;
    return os;
}
