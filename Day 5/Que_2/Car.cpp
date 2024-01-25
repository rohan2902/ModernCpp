#include "Car.h"

// Car::Car(std::string carID, std::string carBrand, CarType carType,std::shared_ptr<Engine> engine, float carPrice):_carID(carID),_carBrand(carBrand),_carType(carType),_engine(engine),_carPrice(carPrice)
// {
// }

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_carID: " << rhs._carID
       << " _carBrand: " << rhs._carBrand
       << " _carType: " <<static_cast<int> (rhs._carType)
       << " _engine: " << *rhs._engine
       << " _carPrice: " << rhs._carPrice;
    return os;
}


Car::Car(std::string carID, std::string carBrand, long int carPrice, CarType carType, std::shared_ptr<Engine> engine)
: _carID(carID),_carBrand(carBrand),_carPrice(carPrice), _carType(carType),_engine(engine)
{
}
