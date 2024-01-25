#include "Employee.h"
#include "Functionalities.h"
#include "DataModeller.h"
#include <mutex>

std::mutex mt;
/*

Variant can only be used when number of types are known

*/


void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_unique<DataModeller>(
            // instance
            std::make_unique<Employee>(
                "Harshit",
                EmployeeType::REGULAR,
                700000.0f),

            std::vector<float>{1,2,3} // it is a vector of goodsprices.
        
            // vector of float
            // std::vector<float>{10.21f, 145.31f, 204.5f}
        ));

    data.emplace_back(
        std::make_unique<DataModeller>(
            // instance
            std::make_unique<BusinessOwner>(
                100000.0f,
                77777.7f,
                "XYZ corporation ",
                BusinessType::MNC
                ),

            // vector of float
            std::vector<float>{10.21f, 145.31f, 204.5f} // it is a vector of goodsprices.
        ));
}


/*
 this function will accept a container of DataModeller Pointer

 FOR EACH POINTER,perform the following

 a) capture the instance reference
 b) Use holds_alternative to verify which type of pointer is present in the _instance
 c) if pointer of type BusinessOwner
    i)use std::get to fetch BusinessOwner (this will be safe because if has been )
    ii)Use the fetched pointer in BusinessOwner to calculate tax for business

    else when pointer is of type employee

    i) use std::get to fetch EmpPointer
    ii) use the fetched pointer to fetch type of employee
    iii) if type is REGULAR tax is 10% else it should be 20% of the salary



*/


void CalculatePayabletax(Container &data)
{
    for(const DataPointer& ptr:data)
    {
        const Vtype& val = ptr->instance();
        if(std::holds_alternative<BusinessPointer>(val)  )
        {
            const BusinessPointer& p = std::get<BusinessPointer>(val);

            mt.lock();
            std::cout<<"business : "<< 0.1f* (p->revenue()-p->expenses());
            mt.unlock();
        }
        else{
            const EmpPointer& p = std::get<EmpPointer>(val);
            if(   const EmpPointer& p = std::get<EmpPointer>(val);       p->type() == EmployeeType::REGULAR) // if initializer/if initialization syntax(it is only valid for if else block)
            {
                mt.lock();
                std::cout<<"Tax is 10%"<<0.1f*p->salary()<<"\n";
                mt.unlock();
            }
            else{
                std::cout<<"Tax is 20%"<<0.2f*p->salary()<<"\n";
            }
        }
    }
}

/*

call the paren overload operator

*/
void CallParenOperator(Container &data)
{
    if(data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    else{
        for(const DataPointer& ptr :data)
        {
            std::lock_guard<std::mutex>lk(mt);
            ptr->operator()();
        }
    }
}


