#include "Employee.h"

Employee::Employee(std::string name, std::string id, float salary, std::shared_ptr<Department> ptr)
    : _name(name), _id(id), _salary(salary), _department(ptr)
{
}
std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_name: " << rhs._name
       << " _id: " << rhs._id
       << " _salary: " << rhs._salary
       << " _department: " << *rhs._department;
    return os;
}
