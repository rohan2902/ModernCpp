#include"Functionalities.h"
#include<algorithm>


void CreateObjects(Container &data)
{
    data.emplace(101,
    std::make_shared<Employee>(200,"Rohan",99999.9f)
    );

    data.emplace(102,
    std::make_shared<Employee>(201,"Shubham",9999.9f)
    );

    data.emplace(103,
    std::make_shared<Employee>(202,"Hetvi",999.9f)
    );

    data.emplace(104,
    std::make_shared<Employee>(203,"Bhagyashri",99.9f)
    );
}

void EmployeeNameBelow7Character(Container &data)
{
    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }

    int count = std::count_if(data.begin(),data.end(),[](const std::pair<int,Pointer>&ptr){return ptr.second->name().size()<7;});
    std::cout<<count;

}


void FindSalaryByID(Container& data,int id)
{

    if(data.empty())
    {
        throw std::runtime_error("Empty!");
    }

  // auto itr= std::find_if(data.begin(),data.end(),[&](const std::pair<int,Pointer>& ptr){return ptr.first==id;});

    auto itr = data.find(id);
    if(itr==data.end())
    {
        std::cout<<"ID not found";
    }
    else{
        std::cout<<itr->second->salary();
    }
}

void FindAverageSalaryForGivenEmployees(Container& data,std::vector<int>& ids)
{
    float total = 0.0f;
    int count = 0;
    //option 1:
    for(int id:ids){
        
        // this is not feasible solution 
        auto itr = std::find_if(data.begin(),data.end(),[&](const std::pair<int,Pointer>& ptr){return id==ptr.first;});

        if(itr!=data.end()){
            count++;
            total = total+itr->second->salary();
        }
    }
    std::cout<<"total salary for given ids: "<<total/count<<"\n";

    

}

//option 2: 
void FindAverageSalaryForGivenEmployeesImproved(Container& data,std::vector<int>& ids)
{
    float total = 0.0f;
    int count = 0;
   
    for(int id:ids){
        
        auto itr = data.find(id);

        if(itr!=data.end()){
            count++;
            total = total+itr->second->salary();
        }
    }
    std::cout<<"total salary for given ids: "<<total/count<<"\n";

    
    
}

