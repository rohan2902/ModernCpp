#include "EvCar.h"

EvCar::EvCar(int id, std::string name, float price,VehicleType type, int battery_capacity, int battery_percentage): Vehicle(id,name,price,type)
{
    _battery_capacity = battery_capacity;
    _battery_percentage = battery_percentage;
}

void EvCar::CalculateRegistrationCharge()
{
    std::cout<<"Tax on ev car is 13%"<<0.13f * price()<<"\n";
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _battery_percentage: " << rhs._battery_percentage;
    return os;
}
