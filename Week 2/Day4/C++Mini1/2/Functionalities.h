#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Device.h"
#include "DeviceDriver.h"
#include<vector>
using Pointer=std::shared_ptr<Device>;
using Container=std::vector<Pointer>;

using DriverPointer=std::shared_ptr<DeviceDriver>;
using DriverContainer=std::vector<DriverPointer>;

using StringContainer=std::vector<std::string>;

void CreateObjects(Container&data);
StringContainer IDAboveDrainFactor(const Container&data);
bool CheckInfotainmentInstance(const Container&data);
float AverageSizeInBytes(const Container&data);
std::string FindVersionNumber(const Container&data,std::string key);
DriverContainer FindDriverInstances(const Container&data,DeviceType type);



#endif // FUNCTIONALITIES_H
