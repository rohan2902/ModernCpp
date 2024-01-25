#include "HybridCar.h"

HybridCar::HybridCar(int id, std::string name, float price, VehicleType type, int fuel_capacity, int battery_capacity):Vehicle(id,name,price,type)
{
    _fuel_capacity= fuel_capacity;
    _battery_capacity = battery_capacity;
}

void HybridCar::CalculateRegistrationCharge()
{
    std::cout<<"Tax on hybrid car is 13%"<<0.13f * price()<<"\n";
}

std::ostream &operator<<(std::ostream &os, const HybridCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_capacity: " << rhs._fuel_capacity
       << " _battery_capacity: " << rhs._battery_capacity;
    return os;
}
