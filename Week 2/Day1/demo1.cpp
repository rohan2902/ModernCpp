#include<iostream>
#include<functional>

// void operation(void (*logic)(int),int data)      //taking function as a parameter
// {
//     logic(data); 
// }

void operation(std::function <void(int)>logic,int data) // function operation is taking function as a parameter
{
    logic(data);            // Function Wrapper
}


void square(int number){
    std::cout<<number * number<<"\n";
}


void times100(int number){
    std::cout<<number * 100;
}


void percent_10(int number){
    std::cout<<(int)(number * 0.1f);
}

int main(){
    // void(*ptr)(int) = &square;  // A function pointer (which points to a function)
    //Type of ptr is signature of function

    // jab tak signature match hota hai you can do anything with the function

    operation(square,5);
    operation([](int number){ std::cout<<number * number * number<<"\n";},7); // Lambda
    operation(percent_10,15);

}

