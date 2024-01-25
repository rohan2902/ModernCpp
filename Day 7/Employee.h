#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    int _id;
public:
    Employee(int id):_id(id) {}
    ~Employee() {}

    void setId(int id) { _id = id; }
};

#endif // EMPLOYEE_H
