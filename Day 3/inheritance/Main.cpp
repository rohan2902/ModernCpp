#include<iostream>
#include<memory>
#include"Functionalities.h"


using Pointer = std::shared_ptr<Vehicle>;
using Container = std::vector<Pointer>;

int main()
{
Container ptr;
CreateObjects(ptr);

for(Pointer &ptrs : ptr)
{
    ptrs->CalculateRegistrationCharge();
}

ptr[0]->CalculateRegistrationCharge();

std::cout<<"AVG price "<<AveragePrice(ptr)<<"\n";


std::cout<<"======================================================\n";

ShowDetails(ptr);



}





