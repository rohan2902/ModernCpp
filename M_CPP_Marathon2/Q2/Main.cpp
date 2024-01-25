#include "Functionalities.h"

int main()
{
    Container data;

    CreateObjects(data);

    // for(Pointer& ptr : data){
    //     std::cout<<*ptr<<"\n";
    // }

    try
    {
        std::cout << "Average of prices : " << AverageProductPrice(data) << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Tax of most expensive Product : " << TaxOfMaxPrice(data) << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Container result;
    try
    {
        result = LastNProducts(data, 2);

        for (Pointer &ptr : result)
        {
            std::cout << *ptr << "\n-------\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    UniqueContainter result1;
    try
    {
        result1 = UniqueProductBrands(data);

        for (std::string ptr : result1)
        {
            std::cout << ptr << "\n-------\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::array<int, 2> result2;

    try
    {
        result2 = ArrayOfInstances(data);
        int count = 1;
        std::string name{""};
        for (int ptr : result2)
        {
            if (count == 1)
            {
                name = "FOOD";
            }
            else
            {
                name = "DOMESTIC";
            }
            std::cout << "Count of " << name << " : " << ptr << "\n-------\n";
            count++;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Container result3;
    try
    {
        result3 = ContainterOfBrand(data,"Haldirams");

        for (Pointer& ptr : result3)
        {
            std::cout << ptr <<"\n";
            std::cout<< "Address : "<<*ptr<<"\n-------\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}