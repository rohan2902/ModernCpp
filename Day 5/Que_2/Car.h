#ifndef CAR_H
#define CAR_H
#include"CarType.h"
#include<iostream>
#include<memory>
#include"Engine.h"

class Car
{
private:
    std::string _carID;
    std::string _carBrand;
    CarType _carType;
    std::shared_ptr<Engine> _engine;
    long int _carPrice;

public:
    Car() = default;
   // Car(std::string,std::string,CarType,std::shared_ptr<Engine>,float);
    Car(std::string carid, std::string carband, long int price, CarType ctype,std::shared_ptr<Engine> engine);
    Car(const Car&) = delete;
    Car& operator = (const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator = (Car&&) = delete;

    ~Car() = default;

    std::string carID() const { return _carID; }

    std::string carBrand() const { return _carBrand; }

    CarType carType() const { return _carType; }

    long int carPrice() const { return _carPrice; }

    std::shared_ptr<Engine> engine() const { return _engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
