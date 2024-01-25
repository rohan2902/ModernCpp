#include"Vehicle.h"



std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}

Vehicle::Vehicle(int id, std::string name, float price, VehicleType type):Vehicle(id,name,type) // constructor deligation in initialization 
{
    _price = price;

}

Vehicle::Vehicle(int id, std::string name, VehicleType type):_id(id),_name(name),_type(type)
{


}

// void Vehicle::display()
// {
//     switch (type())
//     {
//     case VehicleType::PERSONAL :
//         std::cout<<"Personal";
//         break;

//     case VehicleType::SECURITY :
//         std::cout<<"Security";
//         break;

//     case VehicleType::TRANSPORT :
//         std::cout<<"Transport";
//         break;
    
//     default:
//         break;
//     }
// }
