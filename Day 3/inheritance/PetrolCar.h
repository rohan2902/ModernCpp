#ifndef PETROLCAR_H
#define PETROLCAR_H

#include"Vehicle.h"
#include <ostream>

class PetrolCar:public Vehicle
{
private:
    int _fuel_tank_capacity;
public:

    void CalculateRegistrationCharge() override;
    PetrolCar(int id,std::string name,float price,VehicleType type, int capacity);


    PetrolCar(int id,std::string name,VehicleType type,int capacity);

    PetrolCar() = default;
    PetrolCar(const PetrolCar&) = delete;

    PetrolCar& operator = (const PetrolCar&) = delete;

    PetrolCar(PetrolCar&&) = delete;

    PetrolCar& operator= (PetrolCar&&) = delete;


  



    ~PetrolCar() = default;

    int fuelTankCapacity() const { return _fuel_tank_capacity; }



    friend std::ostream &operator<<(std::ostream &os, const PetrolCar &rhs);
};

#endif // PETROLCAR_H
