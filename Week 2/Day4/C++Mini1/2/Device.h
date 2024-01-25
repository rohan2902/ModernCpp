#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include<memory>
#include "DeviceType.h"
#include "DeviceDriver.h"

class Device
{
private:
    std::string _device_id;
    DeviceType _device_type;
    int _device_battery_level;
    std::shared_ptr<DeviceDriver> _device_driver;

public:
    Device(std::string device_id,DeviceType type,int level,std::shared_ptr<DeviceDriver>driver);
    ~Device()=default;

    //Disabled functions
    Device()=delete;
    Device(const Device&)=delete;
    Device(Device&&)=delete;
    Device operator=(const Device&)=delete;
    Device operator=(Device&&)=delete;

    //member functions
    float _battery_drain_factor();

    std::string deviceId() const { return _device_id; }

    DeviceType deviceType() const { return _device_type; }

    int deviceBatteryLevel() const { return _device_battery_level; }

    std::shared_ptr<DeviceDriver> deviceDriver() const { return _device_driver; }
};



#endif // DEVICE_H
