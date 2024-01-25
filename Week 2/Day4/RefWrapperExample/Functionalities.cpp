#include "Functionalities.h"
#include<iostream>


void CreateObject(Carcontainer &cardata, Enginecontainer &engdata)
{
    engdata[0]=std::make_shared<Engine>(
        200,EngineType::Petrol 
    );

    cardata[0]=std::make_shared<Car>(
        101,"Dzire",750000.0f,
        engdata[0]
    );


    engdata[1]=std::make_shared<Engine>(
        300,EngineType::diesel
    );

    cardata[1]=std::make_shared<Car>(
        102,"Dzire",750000.0f,
        engdata[1]
    );

    engdata[2]=std::make_shared<Engine>(
        300,EngineType::hybrid
    );

    cardata[2]=std::make_shared<Car>(
        102,"Dzire",750000.0f,
        engdata[2]
    );
}

void Display(Carcontainer &cardata)
{
    for(auto &ptr:cardata){
        std::cout<<*ptr<<std::endl;
    }
}

float highdata(Carcontainer data1, std::function<float(Carcontainer &, EngineType)> fn)
{
    return fn(data1,EngineType::hybrid);
}

// lambdas FUNCTIONALITIES
// function wrapper 

// referrnece wrapper
// std ref wrapper
// functional wrapper
// bind wrapper
