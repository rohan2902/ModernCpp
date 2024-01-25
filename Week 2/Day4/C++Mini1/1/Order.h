#ifndef ORDER_H
#define ORDER_H

#include "Type.h"
#include <iostream>
#include <memory>

class Order
{
private:
    std::string _id;
    float _value;
    Type _type;
    float _discount;

public:
    Order(std::string id, float value, Type type, float discount);

    Order() = delete;
    ~Order() = default;
    Order(const Order &) = delete;
    Order(Order &&) = delete;
    Order operator=(const Order &) = delete;
    Order operator=(Order &&) = delete;

    std::string id() const { return _id; }

    float value() const { return _value; }

    Type type() const { return _type; }

    float discount() const { return _discount; }

    friend std::ostream &operator<<(std::ostream &os, const Order &rhs);
};

#endif // ORDER_H
