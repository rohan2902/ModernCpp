#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include <iostream>
#include<memory>
#include "ReleaseQuarter.h"

class DeviceDriver
{
private:
    std::string _version_number;
    ReleaseQuarter _release_quarter;
    float _size_in_bytes;

public:
    DeviceDriver(std::string version,ReleaseQuarter quarter,float size);

    ~DeviceDriver()=default;
    DeviceDriver()=delete;
    DeviceDriver(const DeviceDriver&)=delete;
    DeviceDriver(DeviceDriver&&)=delete;
    DeviceDriver operator=(const DeviceDriver&)=delete;
    DeviceDriver operator=(DeviceDriver&&)=delete;

    std::string versionNumber() const { return _version_number; }

    ReleaseQuarter releaseQuarter() const { return _release_quarter; }

    float sizeInBytes() const { return _size_in_bytes; }
};



#endif // DEVICEDRIVER_H
