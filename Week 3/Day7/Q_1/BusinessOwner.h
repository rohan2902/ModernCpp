#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H
#include"BusinessType.h"

#include<iostream>


class BusinessOwner
{
private:
    float _expenses;
    float _revenue;
    std::string _registeredBusinessName;
    BusinessType _type;
public:
    BusinessOwner() = delete;
    BusinessOwner(float expenses,float revenue,std::string registeredBusinessName,BusinessType type);
    BusinessOwner(const BusinessOwner&) = delete;
    BusinessOwner(BusinessOwner&&) = delete;
    BusinessOwner &operator= (const BusinessOwner&) = delete;
    BusinessOwner &operator= (BusinessOwner&&) = delete;
    ~BusinessOwner() = default;

    float expenses() const { return _expenses; }

    float revenue() const { return _revenue; }

    std::string registeredBusinessName() const { return _registeredBusinessName; }

    BusinessType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_H
