#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"
#include "Grade.h"
#include <ostream>
class FullTimeEmployee : public Employee
{
private:
    std::string _project_name;
    std::string _employee_location;
    Grade _grade;
    int _bonus_percent;

public:
    FullTimeEmployee(std::string name, std::string id, float salary, std::shared_ptr<Department> ptr,
                     std::string project, std::string location, Grade grade, int bonus);
    FullTimeEmployee() = delete;
    ~FullTimeEmployee() = default;
    float CalculateBonus();

    std::string projectName() const { return _project_name; }

    std::string employeeLocation() const { return _employee_location; }

    Grade grade() const { return _grade; }

    int bonusPercent() const { return _bonus_percent; }

    friend std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs);
};

#endif // FULLTIMEEMPLOYEE_H
