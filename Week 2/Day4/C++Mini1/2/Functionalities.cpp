#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<Device>(
            "ID1",
            DeviceType::ACCESSORY,
            75,
            std::make_shared<DeviceDriver>("Version1", ReleaseQuarter::Q1, 100)));
    data.emplace_back(
        std::make_shared<Device>(
            "ID2",
            DeviceType::SAFETY,
            65,
            std::make_shared<DeviceDriver>("Version2", ReleaseQuarter::Q2, 10)));
    data.emplace_back(
        std::make_shared<Device>(
            "ID3",
            DeviceType::INFOTAINMENT,
            85,
            std::make_shared<DeviceDriver>("Version3", ReleaseQuarter::Q3, 90)));
    data.emplace_back(
        std::make_shared<Device>(
            "ID4",
            DeviceType::INFOTAINMENT,
            15,
            std::make_shared<DeviceDriver>("Version4", ReleaseQuarter::Q4, 120)));
    data.emplace_back(
        std::make_shared<Device>(
            "ID5",
            DeviceType::SAFETY,
            45,
            std::make_shared<DeviceDriver>("Version5", ReleaseQuarter::Q2, 50)));
}

StringContainer IDAboveDrainFactor(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container");
    StringContainer ans;
    for (const Pointer &ptr : data)
    {
        if (ptr->_battery_drain_factor() > 0.3)
        {
            ans.emplace_back(ptr->deviceId());
        }
    }
    if (ans.empty())
        throw std::runtime_error("No matching data found");
    return ans;
}

bool CheckInfotainmentInstance(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("No data exists in Container");
    bool flag = true;
    for (const Pointer &ptr : data)
    {
        if (ptr->deviceType() != DeviceType::INFOTAINMENT)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

float AverageSizeInBytes(const Container &data)
{
    if(data.empty())
        throw std::runtime_error("No data in Container");
    float sum = 0, count = 0;
    for (const Pointer &ptr : data)
    {
        if (ptr->deviceDriver()->releaseQuarter() == ReleaseQuarter::Q1 || ptr->deviceDriver()->releaseQuarter() == ReleaseQuarter::Q4)
        {
            sum += ptr->deviceDriver()->sizeInBytes();
            count++;
        }
    }
    return sum / count;
}

std::string FindVersionNumber(const Container &data, std::string key)
{
    if(data.empty())
        throw std::runtime_error("No data in Container");
    for(const Pointer&ptr:data){
        if(ptr->deviceDriver()->versionNumber()==key)
            return ptr->deviceDriver()->versionNumber();
    }

    throw std::runtime_error("No mtching data found");
}

DriverContainer FindDriverInstances(const Container &data, DeviceType type)
{
    if(data.empty())
        throw std::runtime_error("No data in Container"); 
    DriverContainer ans;
    for(const Pointer&ptr:data){
        if(ptr->deviceType()==type){
            ans.emplace_back(ptr->deviceDriver());
        }
    }
    if(ans.empty()){
        throw std::runtime_error("No matching data found"); 
    }
    return ans;
}
