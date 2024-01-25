#include<iostream>
#include<functional>
#include<vector>
// function f1 applied on 10
// function f2 applied on 20
// function f3 applied on 30
using FnType = std::function <void(int)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>; 
/*

    accepts a blank container
    It will add 3 lambdas into the container

*/


void MakeLambdaFunction(FnContainer& functions)
{
    
    //auto f2 = [](int number) {std::cout<<number * number * number <<"\n";};

    functions.emplace_back([](int number) {std::cout<<number * number <<"\n";});

    functions.emplace_back([](int number) {std::cout<<number * number * number <<"\n";});

}


void applyLogicOnData(const FnContainer& functions,const DataContainer& data)
{
    auto itr = data.begin();
    for(const FnType& fn: functions)
    {
        int value = *itr++;
        fn(value);
    }
}


int main()
{
    FnContainer functions;
    MakeLambdaFunction(functions);
    DataContainer data{10,20,30};
    applyLogicOnData(functions, data);

}

