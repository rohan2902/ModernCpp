#include "BusinessOwner.h"

BusinessOwner::BusinessOwner(float expenses, float revenue, std::string registeredBusinessName, BusinessType type)
:_expenses(expenses),_revenue(revenue),_registeredBusinessName(registeredBusinessName),_type(type)
{
}
std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
    os << "_expenses: " << rhs._expenses
       << " _revenue: " << rhs._revenue
       << " _registeredBusinessName: " << rhs._registeredBusinessName
       << " _type: " <<static_cast<int> (rhs._type);
    return os;
}
