#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data[0] = std::make_shared<Product>(
        "101",
        2000.0f,
        "Samsung",
        2000*0.5,
        productType::APPLIANCES,
        productOrigin::IMPORTED
    );

    data[1] = std::make_shared<Product>(
        "102",
        200.0f,
        "Dominos",
        200*0.5,
        productType::FOOD,
        productOrigin::IMPORTED
    );

    data[2] = std::make_shared<Product>(
        "103",
        20000.0f,
        "Fogg",
        20000*0.5,
        productType::PERFUME,
        productOrigin::DOMESTIC
    );

    data[3] = std::make_shared<Product>(
        "101",
        15000.0f,
        "Sony",
        15000*0.5,
        productType::APPLIANCES,
        productOrigin::IMPORTED
    );

}

std::function<float(Container &,productType)>AveragePriceOfGivenType = [](Container &data, productType ptype)
{
    if(data.empty())
    {
        throw std::runtime_error("data is empty");
    }
    float total = 0.0f;
    int count =0;
    for(Pointer& ptr:data)
    {
        if(ptr->pType()==ptype)
        {
            total+=ptr->productPrice();
            count++;
        }
        

    }
    return total/count;
};

//std::function<float(Container&,int)>SalaryGivenID = [](Container& data,int id)
std::function<float(Container &)>ProductTaxAmountWithMaxPrice = [](Container &data)
{
    if(data.empty())
    {
        throw std::runtime_error("data is empty");
    }
    float maxPrice = data[0]->productPrice();
    float maxTaxAmount = data[0]->productTaxAmount();
    for(Pointer& ptr:data)
    {
        if(maxPrice>ptr->productPrice())
        {
            maxTaxAmount = ptr->productTaxAmount();
        }
    }
    return maxTaxAmount; 
};

std::function<Pointer(Container &,int)>LastNinstance = [](Container& data,int N)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    if (N > data.size() || N < 1)
    {
        throw std::runtime_error("N is beyond available items");
    }
    auto itr = data.end();
    while (N > 1)
    {
        itr--;
        N++;
    }

    return data[N + 1];


};


