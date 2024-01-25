#ifndef VEHICLE_H
#define VEHICLE_H

#include"vehicleType.h"

#include<iostream>


class vehicle
{
private:
    int _id;
    std::string model_name;
    float _price;
    vehicleType _type;
public:


    vehicle(int id, std::string model , float price,vehicleType type);
    // special members
    // 1) Default Construcor (disabling default constructor)
    vehicle() = delete; 

    //2) copy constructor(deleted copy constructor)
    vehicle(const vehicle& ) = delete;

    //3) copy assignment operator

    vehicle& operator = (const vehicle&)= delete; // overloading = operator and disabling it so that we cannot copy

    //4) move semantics

    // i) move constructor
    vehicle(vehicle&&) = delete;

    //ii) move assignment

    vehicle& operator = (vehicle&&) = delete;



    // 6) Destructor (enable destructor)
    ~vehicle() = default;

    int id() const { return _id; }

    float price() const { return _price; }
};



#endif // VEHICLE_H
