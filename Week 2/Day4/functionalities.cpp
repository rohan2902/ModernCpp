#include"Functionalities.h"


std::function<float(Container&)> AverageSalary = [] (Container& data){
    float total = 0.0f;

    for(Pointer&ptr :data)
    {
        total+=ptr->salary();
    }
    return total;
};      // lambda function ends with semicolon and it treats function as a variable.

std::function<float(Container&,int)>SalaryGivenID = [](Container& data,int id)
{
    float salary = 0.0f;
    for(auto &ptr:data)
    {
        if(ptr->id()==id){
            salary = ptr->salary();
        }
    }
    return salary;
};

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<Employee>(101,"Rohan",99999.9f));

    data.emplace_back(std::make_shared<Employee>(102,"Ritesh",25000.0f));

    data.emplace_back(std::make_shared<Employee>(103,"Rushi",20000.0f));
}