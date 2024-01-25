#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>

//question in notes


class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;


public:
    Employee() = default;
    Employee(int id,std::string name,float salary);
    Employee(const Employee&) = delete;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = delete; 
    ~Employee() = default;

    int id() const { return _id; }

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
