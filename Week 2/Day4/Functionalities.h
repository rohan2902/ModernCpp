#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Employee.h"
#include<vector>
#include<memory>
#include<functional>

using Pointer = std::shared_ptr<Employee>;
using Container = std::vector<Pointer>;


/*
identifier AverageSalary is variable name

which is declared in different file and initialised in different file it is marked as "extern"
*/

//declaration
extern std::function<float(Container&)>AverageSalary;

                        // |float AverageSalary(Container&)|


//this function returns the salary of the employee whose id is given as second parameter 
extern std::function<float(Container&,int)>SalaryGivenID;

void CreateObjects(Container &data);

#endif // FUNCTIONALITIES_H
