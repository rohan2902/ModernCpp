#include<iostream>
#include<functional>

auto n1 = 10;

using FnType = std::function<int(int)>;
/*

LAMBDAS->

WHAT?

Lambdas are callable like regular function(top - level functions/global functions)
lambdas have no name i.e. they are anonymous functions 

WHY?

They help us to pass,receive,store and utilize topic in the form of an object with proper type system support.

They can be used specifying a short-term,one-time or scope based logical process to be performed on some data.

CPP lambdas have a concept of capture clause which allows them to act like closure


// square bracket is also known as capture clause


*/

//auto lfn1 = [](int number) {return number * number;};


/*
a) [n1]  = capture n1 by value
b) [=]   = capture and use all variables from surrounding function by value.

options a and b will not allow 

 [&n1] = capture n1 by lvalue reference
 [&]   = capture all variables by reference

 // lambdas treat variables as const

 if we write mutable after lambda it will act as mutable function(we can change the value of the variable)

*/


void operation (std::function <void()>f){
    f();
}

int main()
{
    int n1 = 10;
    // std::array<FnType,1>arr{lfn1};
    // int n1= 100;
    
    // std::cout<<lfn1(n1);

     /*
     lambdas to be used as "closures"
     (also known as lambda closures)
     
     
     */
    auto lf1 =[  n1  ]() {std::cout<<n1 * n1;};  // capture clause is same as passing parameter to the function  

    auto fn2 = [n1] {int data = 10; std::cout<<n1* data;};
    //operation(fn2);   // if we want to perform operation on that function then use this
    fn2();

    lf1();
}



/*
1) lambdas can also predicate  - return boolean
2) lambdas can be binary       - takes two operands and performs binary operation 
3) lambdas can be comparator  - takes two operands and compares them
4) 


*/