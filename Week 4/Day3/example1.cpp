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

  for(const std::pair<int,Pointer>&ptr:data)
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

void CheckAtLeastOne(Container& data)
{
    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }

    bool flag = std::any_of(data.begin(),data.end(),[](const std::pair<int,Pointer>&ptr){return ptr.second->salary()>80000.0f;}); // any_of returns true or false based on condition
    std::cout<<flag<<"\n";
}
/*
count the number of map pairs where salary is above 50000
*/
void CountAbove50000Employees(Container& data)
{
    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }

    int count = std::count_if(data.begin(),data.end(),[](const std::pair<int,Pointer>&ptr){return ptr.second->salary()>50000.0f;}); // count if returns the number of count whose salary is above 50000
    std::cout<<count<<"\n";
}









int main()
{
    Container data;
    CreateObjects(data);
    TotalSalary(data);
    std::cout<<FindMinSalaryEmployeeName(data);
}

/*

 1)copy - all elemts get copied from source to destination unconditionally
 2)copy if - copy elements from source to destination if the element satisfy the condition
 3)all of - return a boolean to indicate if all elements satisfy condition
 4)any_of - return a boolean to indicate if at least 1 element satisfy condition
 5)none_of - return a boolean to indicate if none of the elements satisfy condition
 6)count_if -return count of elements that satisfy the condition
 7)find_if - return the iterator to the firsst element that satisfy the condition,
          else end iterator(when no elements satisfy condition)
 8)accumulate- it produces one aggregated final output value by performing binary operations
 9)max_element - returns iterator to the maximum element in the container,Maximum can be determined by writing a custom comparator
 10)min_element - returns iterator to the minimum element in the container,Minimum can be determined by writing a custom comparator
 11)sort: write a comparator to perform ascending or descending sort of original container(in-place sorting)
 


*/



