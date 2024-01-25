#include "Functionalities.h"
int main()
{
    Container data;
    CreateObjects(data);
    try
    {
    DisplayBonus(data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"\n\n";
    
    try
    {
    FindLowestSalary(data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"\n\n";

    try
    {
    FindLocation(data,Grade::B);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"\n\n";

    try
    {
    std::cout<<"\nProject Name: "<<FindProjectName(data,"ID3");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

}