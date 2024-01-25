#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(std::string version, ReleaseQuarter quarter, float size)
:_version_number(version),_release_quarter(quarter),_size_in_bytes(size)
{
}