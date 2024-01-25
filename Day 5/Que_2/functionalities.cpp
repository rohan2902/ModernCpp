#include "functionalities.h"
#include <memory>

void CreateObjects(Container &data)
{

    data.emplace_back(std::make_shared<Car>(
        "1E0HYEJS",
        "NEXON",
        819000,
        CarType::HATCHBACK,
        std::make_shared<Engine>("2343EIRJ", EngineType::HYBRID, 200, 109220)));
    data.emplace_back(std::make_shared<Car>(
        "190HWEJS",
        "CIVIC",
        8899230,
        CarType::SEDAN,
        std::make_shared<Engine>("2WEREIRJ", EngineType::ICT, 70, 1090320)));
    data.emplace_back(std::make_shared<Car>(
        "1T0HYEJS",
        "JEEP",
        4319000,
        CarType::SPORTS,
        std::make_shared<Engine>("23EIRJ", EngineType::HYBRID, 100, 1009920)));

    //data.erase(data.begin()+1);        //for removing data 
}

int findEngineHorsepower(Container &data, std::string ID)
{
    if (data.empty())

    {
        throw std::runtime_error("data is empty");
    }

    for (Pointer &ptr : data)
    {
        if (ptr->carID() == ID)
        {
            return ptr->engine()->engineHorsepower();
        }
    }
    throw std::runtime_error("ID not found");
}

Container findEngineTorqueAbove80(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    Container result;
    for (Pointer &ptr : data)
    {

        while (ptr->engine()->engineTorque() > 80)
        {
            result.emplace_back(ptr);
        }
    }
    return result;
}

Container CarTypeInstance(Container &data, CarType CarType)
{
     if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    Container result;
    for (Pointer &ptr : data)
    {
        if (ptr->carType() == CarType)
        {
            result.emplace_back(ptr);
        }
    }
    return result;
}


float AverageHorsepower(Container& data)
{
     if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    float res=0;
    for(Pointer &ptr:data)
    {
        if(ptr->engine()->engType()==EngineType::ICT && ptr->carPrice()>1000000)
        {
            res+=ptr->engine()->engineHorsepower();
        }
        
    }
    if(res==0)
    {
        throw std::runtime_error("Total Horsepower is zero");
    }
    float avg = res/data.size();
    return res;
}

std::string LowestCarID(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    float min=data[0]->carPrice();
    std::string LowestCarPriceID = data[0]->carID();
    for(Pointer& ptr:data)
    {
        if(ptr->carPrice()<min)
        {
            LowestCarPriceID = ptr->carPrice();
        }
    }
    return LowestCarPriceID;
}

float CombinedPrice(Pointer p, Pointer q)
{
    
    return p->carPrice() + q ->carPrice();
    
}

