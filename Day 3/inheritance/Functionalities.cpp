#include"Functionalities.h"
#include"PetrolCar.h"
#include"Diesel.h"
#include"EvCar.h"
#include"HybridCar.h"


void CreateObjects(Container &data)
{
    data.emplace_back(
    std::make_shared<PetrolCar>(101,"city",1400000.0f,VehicleType::PERSONAL,99)
);

data.emplace_back(
    std::make_shared<PetrolCar>(102,"dzire",900000.0f,VehicleType::SECURITY,43)
);

data.emplace_back(
    std::make_shared<PetrolCar>(101,"baleno",950000.0f,VehicleType::TRANSPORT,44)
);
data.emplace_back(
    std::make_shared<Diesel>(700,"Safari",2000000.0f,VehicleType::SECURITY,50)
);
data.emplace_back(
    std::make_shared<EvCar>(702,"Nexon",1500000.0f,VehicleType::PERSONAL,60,80)
);
data.emplace_back(
    std::make_shared<HybridCar>(900,"Hycross",2800000.0f,VehicleType::PERSONAL,40,80)
);

}

long int AveragePrice(Container &data)
{
    float sum = 0.0f;
    for(int i=0;i<data.size();i++)
    {
        sum = sum + data[i]-> price();
       
    }
    float avg = sum/data.size();
    return avg;
}

void ShowDetails(Container &data)
{
    for(Pointer& ptr:data)
    {
        std::cout<<*ptr<<"\n";
    }
}


