#include "Device.h"

Device::Device(std::string device_id, DeviceType type, int level, std::shared_ptr<DeviceDriver> driver)
:_device_id(device_id),_device_type(type),_device_battery_level(level),_device_driver(driver)
{
}

float Device::_battery_drain_factor()
{
    if(_device_type==DeviceType::INFOTAINMENT||_device_type==DeviceType::ACCESSORY)
        return 0.25;
    if(_device_type==DeviceType::SAFETY){
        if(_device_battery_level>50)
            return 0.5;
        else
            return 0.4;
    }
    return 0;
        
    
}
