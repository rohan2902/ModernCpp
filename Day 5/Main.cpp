#include"Functionalities.h"

int main()
{
    Container data;
    CreateObjects(data);

    std::cout<< *NthCustomer(data,1);

    //std::cout<< ExpiryDate(data,101);
    // try{

    // Container ans = CustomerAgeAbove50(data);
    // for(Pointer& ptr :ans)
    // {
    //     std::cout<<*ptr<<"\n";
    // }
    // }
    // catch(std::runtime_error& ex)
    // {
    //     std::cout<<ex.what()<<"\n";
    // }
    
}