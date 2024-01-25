#include "Functionalities.h"
int main()
{
    Container data;
    CreateObjects(data);

    try
    {
    StringContainer IDData=IDAboveDrainFactor(data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
    bool isInfotainment=CheckInfotainmentInstance(data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
    float averageByteSize=AverageSizeInBytes(data);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
    std::string FindVersion=FindVersionNumber(data,"Version1");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
    DriverContainer driverInstances=FindDriverInstances(data,DeviceType::SAFETY);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        


}