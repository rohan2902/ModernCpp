#ifndef DIESEL_H
#define DIESEL_H

#include"Vehicle.h"
#include <ostream>



class Diesel : public Vehicle
{
private:
    int _fuel_capacity;
public:

    Diesel() = default;
    Diesel(int id,std::string name,float price,VehicleType type,int fuel_capacity);



    void CalculateRegistrationCharge() override;
    Diesel(const Diesel&)=delete;

    Diesel& operator = (const Diesel&) = delete;

    Diesel(Diesel&&) = delete;

    Diesel& operator = (Diesel&&) = delete;

    ~Diesel() = default; 

    int fuelCapacity() const { return _fuel_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const Diesel &rhs);
};

#endif // DIESEL_H
