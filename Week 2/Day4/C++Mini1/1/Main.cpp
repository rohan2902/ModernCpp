#include "Functionalities.h"
int main()
{
    Container data, NewData;

    CreateObjects(data);
    try
    {
        std::cout << "ID with highest Discount: " << FindIDWithHighestDiscount(data) << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Type OrderType = FindTypeUsingID(data, "ID2");
        std::cout << "Type for given ID: ";
        switch (OrderType)
        {
        case Type::COD:
            std::cout << "COD";
            break;
        case Type::PAID:
            std::cout << "PAID";
            break;
        case Type::PROMOTION:
            std::cout << "PROMOTION";
            break;

        default:
            break;
        }
        std::cout << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {

        std::cout << "Average value of all instances: " << FindAverageOfValue(data) << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {

        NewData = FirstNInstances(data, 3);
        for (const Pointer &ptr : data)
        {
            std::cout << *ptr << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}