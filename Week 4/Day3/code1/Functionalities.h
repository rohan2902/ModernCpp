#include<memory>
#include"Employee.h"
#include<unordered_map>


using Pointer = std::shared_ptr<Employee>;
using Container = std::unordered_map<int,Pointer>;

void CreateObjects(Container& data);

void EmployeeNameBelow7Character(Container& data);

void FindSalaryByID(Container& data,int id);


void FindAverageSalaryForGivenEmployees(Container& data,std::vector<int>& ids);