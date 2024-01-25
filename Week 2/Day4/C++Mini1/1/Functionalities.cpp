#include "Functionalities.h"

void CreateObjects(Container &data)
{
    // Putting data in the container
    data.emplace_back(
        std::make_shared<Order>(
            "ID1",
            100.5,
            Type::COD,
            10.5));
    data.emplace_back(
        std::make_shared<Order>(
            "ID2",
            200.5,
            Type::PAID,
            20.5));
    data.emplace_back(
        std::make_shared<Order>(
            "ID3",
            300.5,
            Type::PROMOTION,
            30.5));
    data.emplace_back(
        std::make_shared<Order>(
            "ID4",
            400.5,
            Type::PAID,
            40.5));
    data.emplace_back(
        std::make_shared<Order>(
            "ID5",
            1000.5,
            Type::COD,
            50.5));
}

std::string FindIDWithHighestDiscount(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container"); // check for empty container

    auto itr = data.begin();        // using iterator to start from first place
    std::string ans = (*itr)->id(); // setting initial values
    float currentDiscount = (*itr)->discount();

    for (const Pointer &ptr : data)
    { // for each loop
        if (ptr->discount() > currentDiscount)
        {
            currentDiscount=ptr->discount();
            ans = ptr->id();
        }
    }

    return ans;
}

Type FindTypeUsingID(const Container &data, std::string key)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container");
    for (const Pointer &ptr : data)
    {
        if (ptr->id() == key)
        {
            return ptr->type();
        }
    }
    throw std::runtime_error("No matching data found");
}

float FindAverageOfValue(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container");

    float sum = 0;
    for (const Pointer &ptr : data)
    {
        sum += ptr->value(); // storing all values in sum variable
    }
    return sum / data.size(); // returning average
}

Container FirstNInstances(const Container &data, int N)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container");
    if (N == 0)
        throw std::runtime_error("N with zero value entered");
    Container NewData;

    for (const Pointer &ptr : data)
    {
        NewData.emplace_back(ptr);
        N--;
        if (N == 0) // check if given value is completed
            break;
    }

    return NewData;
}
