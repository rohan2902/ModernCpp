#include "PetrolCar.h"



PetrolCar::PetrolCar(int id, std::string name, float price, VehicleType type, int capacity):Vehicle(id,name,price,type), _fuel_tank_capacity(capacity) // this is not constructor deligation
{
}

PetrolCar::PetrolCar(int id, std::string name, VehicleType type, int capacity):Vehicle(id,name,type),_fuel_tank_capacity(capacity)  // this is not constructor deligation 
{
}

std::ostream &operator<<(std::ostream &os, const PetrolCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity;
    return os;
}

void PetrolCar::CalculateRegistrationCharge()
{
    std::cout<<"Tax on petrol car is 13%"<<0.13f * price()<<"\n";
}
