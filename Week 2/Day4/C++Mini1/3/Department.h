#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <memory>
class Department
{
private:
    std::string _id;
    int _size;

public:
    Department(/* args */) = delete;
    Department(std::string id, int size);
    ~Department() = default;

    friend std::ostream &operator<<(std::ostream &os, const Department &rhs);
};

#endif // DEPARTMENT_H
