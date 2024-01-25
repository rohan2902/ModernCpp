#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "FullTimeEmployee.h"
#include <list>
using Pointer = std::shared_ptr<Employee>;
using Container = std::list<Pointer>;

void CreateObjects(Container &data);
void DisplayBonus(const Container &data);
void FindLowestSalary(const Container &data);
void FindLocation(const Container &data, Grade g);
std::string FindProjectName(const Container &data, std::string id);

#endif // FUNCTIONALITIES_H
