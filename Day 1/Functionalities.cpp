#include "Functionalities.h"

void CreateObjects(vehicle **arr, const int size)
{
    int id=0;
    std::string name = "";
    float price = 0.0f;
    vehicleType type = vehicleType::PERSONAL;
    int choice = -1;


    for(int i=0;i<size;i++)
    {
        std::cin>>id;
        std::cin>>name;
        std::cin>>price;

        std::cin>>choice;

        if(choice==0)
        {
            type = vehicleType::PERSONAL;
        }

        else if(choice ==1)
        {
            type = vehicleType::SECURITY;
        }

        else if(choice ==2)
        {
            type = vehicleType::TRANSPORT;
        }

        else{
            type = vehicleType::PERSONAL;
        }

        arr[i] = new vehicle(id,name,price,type);
    }



    //arr[0]=new vehicle(101,"Maruti Dzire",850000.0f,vehicleType::PERSONAL);
}

float AveragePrice( vehicle **arr, const int size)
{
    float total =0.0f;

    for(int i=0;i<size;i++)
    {
        total+=arr[i]->price();
    }

    return total/size;

    
}

int LowestPriceId(vehicle **arr, const int size)
{

    int ans = arr[0] -> id();
    float min_price = arr[0]->price();

    for(int i=0;i<size;i++)
    {
        float current_price = arr[i]->price();

        if(current_price<min_price)
        {
            min_price = current_price;
            ans = arr[i]->id();
        }

    }
    return ans;
}
