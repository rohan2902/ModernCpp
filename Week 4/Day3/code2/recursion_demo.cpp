// add function that can accept 1,2,3,4,5 infinite parameters and return total
// variadic templates(templates that can accept variable number of arguments)
/*
e.g. make_shared function template




Use concept of recurssion and base case

my base case in addition is:adding only one value
*/


#include<memory>
#include<iostream>


template<typename T>
T add(T n1){
    return n1;
}

template <typename T,typename...Args>
auto add(T n1,Args... args){
    return n1+add(args...);
}

int main()
{
    std::cout<<add<int>(10,20,30)<<"\n";
    std::cout<<add<int>(10,20)<<"\n";
    
}

/*


template<typename... T>
auto add(T... args){
    return (args + ...);
}



*/