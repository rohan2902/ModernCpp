
#include"Functionalities.h"
#include"vehicle.h"


int main()
{

    const int size = 3;
    vehicle * arr[3] = {nullptr};
    CreateObjects(arr,size);

    float ans = AveragePrice(arr,size);
    std::cout<<"Average is"<<ans<<std::endl;

    /*
    return_id of vehicle with lowest price
    
    
    */

   int id=LowestPriceId(arr,size);

   std::cout<<"Lowest price is:"<<id<<std::endl;


   
}