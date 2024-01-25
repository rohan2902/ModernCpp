// SMART POINTERS


#include<iostream>
#include"vehicle.h"
#include"vehicleType.h"
#include<memory>



int main()
{
    std::shared_ptr <vehicle> ptr = std::make_shared<vehicle>(101,"city",1400000.0f,vehicleType::PERSONAL);
}