#include <iostream>
#include "functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);
    Container p = CarTypeInstance(data, CarType::SEDAN);

    for (Pointer &ptr : p)
    {
        std::cout << *ptr;
    }
   std::cout<<"======\n\n\n\n";

   int long ans = CombinedPrice(data[0], data[1]);
   std::cout<<"Combined Car Price======\n"<<ans<<"\n\n\n";
}