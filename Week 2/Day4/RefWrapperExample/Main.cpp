#include<iostream>
#include"Functionalities.h"
using namespace std::placeholders;
int main(){
    Carcontainer Cardata;
    Enginecontainer engdata;

    CreateObject(Cardata,engdata);
    Display(Cardata);

    auto f1=[&](Carcontainer &cardata,EngineType type){
        float total=0;
        int count=0;
        for(Carpointer &ptr:cardata){
            if(type==ptr->engine().get()->engineType()){
            total+=ptr->engine().get()->horsepower();
            count++;
            }
        }
        return  total/count;
    };

    std::cout<<"\nAverage of Tourque is "<<f1(Cardata,EngineType::Petrol)<<std::endl;

    //highdata(Cardata,f1); 

    std::cout<<"\n data is "<<highdata(Cardata,f1);

    auto f5=std::bind(std::ref(f1),_1,EngineType::diesel);
    std::cout<<"\n After using bind : "<<f5(Cardata);

    // for member function pass address of class and object
    //std::bind(&actor::dosomething,&a,_3,_2,_1);
    
}
