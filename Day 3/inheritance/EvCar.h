#ifndef EVCAR_H
#define EVCAR_H

#include"Vehicle.h"
#include <ostream>



class EvCar:public Vehicle
{
private:
    int _battery_capacity;
    int _battery_percentage;
public:

    EvCar(int id,std::string name,float price,VehicleType type, int battery_capacity, int battery_percentage);
    void CalculateRegistrationCharge() override;
    
    EvCar() = default;

    EvCar(const EvCar&) = delete;

    EvCar& operator = (const EvCar&) = delete;

    EvCar(EvCar&&)= delete;

    EvCar& operator = (EvCar&&) = delete;


    ~EvCar() = default;

    int batteryCapacity() const { return _battery_capacity; }

    int batteryPercentage() const { return _battery_percentage; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
