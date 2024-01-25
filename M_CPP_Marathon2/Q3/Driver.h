#ifndef DRIVER_H
#define DRIVER_H

#include "DriverType.h"
#include "Liscence.h"
#include <memory>
#include <functional>
#include <ostream>

using LiscencePointer = std::shared_ptr<Liscence>;
using ReffType = std::reference_wrapper<LiscencePointer>;

class Driver
{
private:
    std::string driverName;
    DriverCategory driverCategory;
    int driverBirthYear;
    ReffType driverLiscence;

public:
    Driver() = delete;
    Driver(std::string name,DriverCategory category,int year,ReffType liscence);
    Driver(const Driver &) = delete;
    Driver &operator=(Driver &) = delete;
    Driver(const Driver &&) = delete;
    Driver &operator=(Driver &&) = delete;
    ~Driver() = default;

    std::string getDriverName() const { return driverName; }

    DriverCategory getDriverCategory() const { return driverCategory; }

    int getDriverBirthYear() const { return driverBirthYear; }

    ReffType getDriverLiscence() const { return driverLiscence; }

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};



#endif // DRIVER_H
