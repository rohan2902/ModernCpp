#include"Functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);
    try{
    std::cout<<"Average Price of Given type = "<<AveragePriceOfGivenType(data,productType::APPLIANCES)<<"\n";
    }
    catch(std::runtime_error &e)
    {
        std::cout<<e.what();
    }
    try{
    std::cout<<ProductTaxAmountWithMaxPrice(data);
    }
    catch(std::runtime_error &e)
    {
        std::cout<<e.what();
    }
    try{
    std::cout<<LastNinstance(data,2);
    }
    catch(std::runtime_error &e)
    {
        std::cout<<e.what();
    }

}


