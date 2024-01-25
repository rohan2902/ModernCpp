#ifndef EMPLOYEE_H
#define EMPLOYEE_HEmployee

#include <iostream>
#include <memory>
#include "Department.h"

class Employee
{
private:
    std::string _name;
    std::string _id;
    float _salary;
    std::shared_ptr<Department> _department;

public:
    Employee(std::string name, std::string id, float salary, std::shared_ptr<Department> ptr);
    Employee(/* args */) = delete;
    ~Employee() = default;
    virtual float CalculateBonus() = 0;

    std::string name() const { return _name; }

    std::string id() const { return _id; }

    float salary() const { return _salary; }

    std::shared_ptr<Department> department() const { return _department; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
