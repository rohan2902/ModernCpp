#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(std::string name, std::string id, float salary, std::shared_ptr<Department> ptr, 
std::string project, std::string location, Grade grade, int bonus)
:Employee(name,id,salary,ptr),_project_name(project),_employee_location(location),_grade(grade),_bonus_percent(bonus)
{
}

float FullTimeEmployee::CalculateBonus()
{
    switch (grade())
    {
    case Grade::A:
        return _bonus_percent*salary()/100.0;
        break;
    case Grade::B:
        return _bonus_percent*0.5*salary()/100.0;
        break;
    case Grade::C:
        return _bonus_percent*0.25*salary()/100.0;
        break;
    
    default:
        return 0.0f;

        break;
    }
}

std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _project_name: " << rhs._project_name
       << " _employee_location: " << rhs._employee_location
       << " _grade: " <<static_cast<int> (rhs._grade)
       << " _bonus_percent: " << rhs._bonus_percent;
    return os;
}
