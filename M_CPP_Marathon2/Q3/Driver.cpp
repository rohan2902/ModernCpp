#include "Driver.h"

Driver::Driver(std::string name, DriverCategory category, int year, ReffType liscence)
:driverName(name),driverCategory(category),driverLiscence(liscence)
{
    if(year>=1947 && year<=2023){
        driverBirthYear=year;
    }
}
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << " driverName: " << rhs.driverName
       << " driverCategory: " <<static_cast<int> (rhs.driverCategory)
       << " driverBirthYear: " << rhs.driverBirthYear
       << " driverLiscence: " << *rhs.driverLiscence.get()<<"\n";
    return os;
}
