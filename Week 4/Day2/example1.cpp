#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <numeric>


class Employee
{
private:
    std::string _name;
    float _salary;

public:
    Employee(/* args */) = default;
    Employee(std::string name,float salary):_name(name),_salary(salary){}
    ~Employee() = default;

    float salary() const { return _salary; }
    std::string name() const { return _name; }
};
using Pointer = std::shared_ptr<Employee>;
using Container = std::unordered_map<int, Pointer>;
void CreateObjects(Container &data)
{
    data.emplace(
        101, std::make_shared<Employee>("harshit", 70000.0f)
    );

    data.emplace(
        102, std::make_shared<Employee>("Snehal", 70000.0f)
    );

    data.emplace(
        103, std::make_shared<Employee>("Ajay", 70000.0f)
    );


}

/*
    total salary for all employees
*/

    

void TotalSalary(Container& data)
{
    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }

    float total = 0.0f;

    for(auto& [k,v]:data){
        total = total + v->salary(); // you need to access salary by value not by key.
    }
    std::cout<<"total = "<<total<<"\n";
    /*
    alternative for loop
    
    */
   for(auto itr = data.begin(); itr!=data.end();++itr){
    total = total+itr->second->salary();
   }

   /*
   
   alternative for loop

   */

  for(const std::pair<int,Pointer>&ptr:data)     //he std::pair container is used to combine two values that may be of different data types into a single unit. It provides a way to store two heterogeneous objects together. Here are some key points about using std::pair
  {
    total = total + ptr.second->salary();
  }

    /*
    alternative accumulate STL algo
    
    */
   std::accumulate(
    data.begin(),
    data.end(),
    0.0f,
    [](float sum_till_current_val, const std::pair<int,Pointer>& row){ 
        return sum_till_current_val +row.second->salary();
    });

}
/*

find the name of employee with lowest salary.

*/
std::string FindMinSalaryEmployeeName(Container& data)
{
    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }
    /*
    min element will return an iterator to the min element found (it will return only position of that employee) and std::min will return actual value
    */
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<int,Pointer>& pair1,const std::pair<int,Pointer>& pair2){
            return pair1.second->salary()<pair2.second->salary();
        }
    );
    //std::cout<<"Name of min salary employee is: "<<itr->second->name();
    return itr->second->name();
}


int main()
{
    Container data;
    CreateObjects(data);
    TotalSalary(data);
    std::cout<<FindMinSalaryEmployeeName(data);
}

