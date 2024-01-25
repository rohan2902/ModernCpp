/*

 a container of 3 functions.
 then run a loop over the container to execute the function

        DATA
    |   |   |
    f1  f2  f3
    |   |   |
    o1  o2  o3


*/

#include<iostream>
#include<functional>
#include<vector>

                            
using FnType = std::function <void(int)>;
using FnContainer = std::vector<FnType>;
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

/*
    run a for each loop on the function container
    execute each funcion with given data



*/


void applyLogicOnData(FnContainer& functions,int data)
{
    /*
        for each function called "fn" inside container called "functions",
    
    
    */
    for(FnType & fn : functions){
        fn(data);
    }
}


int main()
{
    FnContainer functions;
    MakeLambdaFunction(functions);
    applyLogicOnData(functions,5);
}