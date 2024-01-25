#include"Functionalities.h"

using namespace std::placeholders;

int main(){
    ContainerOfDriver d_data;
    ContainerOfLiscence l_data;
    CreateObjects(d_data,l_data);

    ContainerOfLiscence result;
    result = FirstTwoInstancesByBirthYear(d_data);

    for(auto& ptr : result){
        std::cout<<*ptr<<"\n";
    }
    std::cout<<"\n--------------\n";
    ContainerOfDriver result1;
    result1 = FirstTwoInstancesByLiscence(d_data);
    for(auto& ptr : result1){
        std::cout<<*ptr<<"\n";
    }
    std::cout<<"\n--------------\n";
    ContainerOfDriver result2;
    result2 = FindDriverByRTO(d_data,"Nagpur");
    for(auto& ptr : result2){
        std::cout<<*ptr<<"\n";
    }
    VectorOfStrings vec{"Maharashtra","AP","Gujrat"};
    std::cout<<"\n--------------\n";
    ContainerOfLiscence result3;
    result3 = SearchByVectorOfState(d_data,vec);
    for(auto& ptr : result3){
        std::cout<<*ptr<<"\n";
    }

    auto partial = std::bind(FindDriverByRTO,_1,"Pune");
    std::cout<<"\n--------------\n";
    ContainerOfDriver result4;
    partial(d_data);
    for(auto& ptr : result4){
        std::cout<<*ptr<<"\n";
    }

    Operation(FirstTwoInstancesByBirthYear,d_data);
    Operation(FirstTwoInstancesByLiscence,d_data);






}