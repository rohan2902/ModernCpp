#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Aman",
            "ID1",
            25000.20,
            std::make_shared<Department>("Dept1", 50),
            "Project1",
            "Pune",
            Grade::A,
            40));
    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Atharv",
            "ID2",
            35000.20,
            std::make_shared<Department>("Dept2", 60),
            "Project2",
            "Mumbai",
            Grade::B,
            50));
    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Chirag",
            "ID3",
            45000.20,
            std::make_shared<Department>("Dept3", 10),
            "Project3",
            "Banglore",
            Grade::C,
            55));
}

void DisplayBonus(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("Data Container is empty");
    std::cout << "Bonus values of all instances using CalculateBonus\n";
    for (const Pointer &ptr : data)
    {

        std::cout << ptr->CalculateBonus() << "\n";
    }
}

void FindLowestSalary(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("Data Container is empty");
    // auto itr = data.begin();
    // float currentLowest = (*data.begin())->;------------------------------not required
    Pointer Lowest = data.front();
    float currentLowest=Lowest->salary();

    for (const Pointer &ptr : data)
    {
        if (ptr->salary() < currentLowest)
        {
            currentLowest = ptr->salary();
            Lowest = ptr;
        }
    }
    std::cout << *std::dynamic_pointer_cast<FullTimeEmployee>(Lowest);// display all attributes of FullTimeEmployee
}

void FindLocation(const Container &data, Grade g)
{
    if (data.empty())
        throw std::runtime_error("Data Container is empty");

    for (const Pointer &ptr : data)
    {
        if (std::dynamic_pointer_cast<FullTimeEmployee>(ptr)->grade() == g)
        {
            std::cout << "\nEmployee with given grade has location at "
                      << "\nEmployee Name: " << ptr->name() << "\nLocation: " << std::dynamic_pointer_cast<FullTimeEmployee>(ptr)->employeeLocation();
        }
    }
}

std::string FindProjectName(const Container &data, std::string id)
{
    if (data.empty())
        throw std::runtime_error("Data Container is empty");

    for (const Pointer &ptr : data)
    {
        if (ptr->id() == id)
        {
            return std::dynamic_pointer_cast<FullTimeEmployee>(ptr)->projectName();
        }
    }
    throw std::runtime_error("No such data found");
}
