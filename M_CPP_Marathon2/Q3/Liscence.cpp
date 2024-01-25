#include "Liscence.h"

Liscence::Liscence(std::string number, int years, LiscenceCategory category, std::string issuingRTO, std::string issingState)
:liscenceNumber(number),liscenceCategory(category),liscenceIssuingRTO(issuingRTO),liscenceIssusingState(issingState)
{
    if(years>=15){
        liscenceValidityYears=years;
    }
}
std::ostream &operator<<(std::ostream &os, const Liscence &rhs) {
    os << " liscenceNumber: " << rhs.liscenceNumber
       << " liscenceValidityYears: " << rhs.liscenceValidityYears
       << " liscenceCategory: " << static_cast<int>(rhs.liscenceCategory) 
       << " liscenceIssuingRTO: " << rhs.liscenceIssuingRTO
       << " liscenceIssusingState: " << rhs.liscenceIssusingState;
    return os;
}
