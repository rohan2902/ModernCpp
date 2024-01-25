#include "Diesel.h"

Diesel::Diesel(int id, std::string name, float price, VehicleType type, int fuel_capacity):Vehicle(id,name,price,type),_fuel_capacity(fuel_capacity)
{
}

void Diesel::CalculateRegistrationCharge()
{
    std::cout<<"Tax on diesel car is 13%"<<0.13f * price()<<"\n";
}

std::ostream &operator<<(std::ostream &os, const Diesel &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_capacity: " << rhs._fuel_capacity;
    return os;
}
