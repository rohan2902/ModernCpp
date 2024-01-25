#include "Functionalities.h"

std::function<void(Container &)> CreateObjects = [](Container &data)
{
    data.emplace_back(
        std::make_shared<Product>(
            "1ID",
            ProductType::PERFUME,
            20.22,
            "ZARA",
            ProductOrigin::IMPORTED));

    data.emplace_back(
        std::make_shared<Product>(
            "2ID",
            ProductType::APPLIANCE,
            266.22,
            "Bajaj",
            ProductOrigin::DOMESTIC));

    data.emplace_back(
        std::make_shared<Product>(
            "3ID",
            ProductType::FOOD,
            6.22,
            "Haldirams",
            ProductOrigin::DOMESTIC));

    data.emplace_back(
        std::make_shared<Product>(
            "4ID",
            ProductType::FOOD,
            644.22,
            "Haldirams",
            ProductOrigin::DOMESTIC));
};

std::function<float(Container &)> AverageProductPrice = [](Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }

    float sum = 0;

    for (Pointer &ptr : data)
    {
        sum = sum + ptr->getProductPrice();
    }

    return sum / data.size();
};

std::function<float(Container &)> TaxOfMaxPrice = [](Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }

    auto itr = data.begin();
    float ans = (*itr)->getProductTaxAmount();

    float currentMaxPrice = (*itr)->getProductPrice();

    for (Pointer &ptr : data)
    {
        if (ptr->getProductPrice() > currentMaxPrice)
        {
            currentMaxPrice = ptr->getProductPrice();
            ans = ptr->getProductTaxAmount();
        }
    }

    return ans;
};


std::function<Container(Container &, int)> LastNProducts = [](Container &data, int N)
{
    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }

	Container result;

    int count = 0;
	
    auto end = data.end();
	for(Pointer& ptr : data){
		
        end--;
        result.emplace_back(*end);
        count++;
		if(count==N) break;
	}	

	if (result.empty())
    {
        throw std::runtime_error("Result Empty");
    }
    
    return result;
};


std::function<UniqueContainter(Container&)> UniqueProductBrands = [](Container& data){

    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }

    UniqueContainter result;

    for(Pointer& ptr : data){
        result.insert(ptr->getProductBrand());
    }

    if (result.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }


    return result;
};

std::function<std::array<int,2>(Container&)> ArrayOfInstances = [](Container& data){

    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }

    std::array<int,2> result;
    int countOfFood = 0;
    int countOfOrigins = 0;

    for(Pointer& ptr : data){
        if(ptr->getProductType()==ProductType::FOOD){
            countOfFood++;
        }
        if(ptr->getProductOrigin()==ProductOrigin::DOMESTIC){
            countOfOrigins++;
        }
    }

    result[0]=countOfFood;
    result[1]=countOfOrigins;

    return result;
};

std::function<Container(Container&,std::string )> ContainterOfBrand = [](Container& data, std::string search){
    Container result;

    if (data.empty())
    {
        throw std::runtime_error("\nERROR :: Data is empty");
    }


    for(Pointer& ptr : data){
        if(ptr->getProductBrand()==search){
            result.emplace_back(ptr);
        }
    }

    if (result.empty())
    {
        throw std::runtime_error("Result Empty");
    }

    return result;
};