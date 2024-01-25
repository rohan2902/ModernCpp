#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<memory>
#include"Employee.h"
#include"BussinessOwner.h"
#include<variant>


// I need alias for shared ptr to employee
using EmpPointer = std::shared_ptr<Employee>;
//I need alias for shared ptr to BusinessOwner
using BusinessPointer = std::shared_ptr<BussinessOwner>;

// I need alias for variant of above 2 pointers
using VType = std::variant<EmpPointer,BusinessPointer>;
// I finally want a container of above variant
using Container = std::vector<VType>;


void CreateObjects(Container& data)
{
    data.emplace_back(
        std::make_shared<Employee>()
    );

    data.emplace_back(
        std::make_shared<BussinessOwner>()
    );

    
}

#endif // FUNCTIONALITIES_H
