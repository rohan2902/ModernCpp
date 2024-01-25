#include "Order.h"

Order::Order(std::string id, float value, Type type, float discount)
    : _id(id), _value(value), _type(type), _discount(discount)
{
}
std::ostream &operator<<(std::ostream &os, const Order &rhs)
{
    os << "_id: " << rhs._id
       << " \n_value: " << rhs._value
       << " \n_type: ";
    switch (rhs._type)  //putting proper values for enum values
    {
    case Type::COD:
        std::cout << "COD";
        break;
    case Type::PAID:
        std::cout << "PAID";
        break;
    case Type::PROMOTION:
        std::cout << "PROMOTION";
        break;

    default:
        break;
    }

    std::cout << " \n_discount: " << rhs._discount << '\n';
    return os;
}
