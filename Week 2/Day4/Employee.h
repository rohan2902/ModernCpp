#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>


/*
class name in PASCALCASE(first letter capital)
e.g. Employee
    EmployeeData
ENUM class in PASCAL case

*/

class Employee
{
private:

    /*
        a)camalcase(first letter small) : e.g. employeeOfficialName 
        or starting with underscore
    
    
    */
    int _id;
    std::string _name;
    float _salary;
public:
    Employee(int id,std::string name,float salary) : _id(id),_name(name),_salary(salary)
    {}
    /*
        member function in pascalcase

    
    */

    //void CalculateTax();

    ~Employee() {}

    int id() const { return _id; }

    float salary() const { return _salary; }

    std::string name() const { return _name; }
};

#endif // EMPLOYEE_H
// press i to enter in insert mode to type anything and press esc for enter back in vim mode