#include<iostream>
/*
pass by value: accepts both lvalue and rvalue value is assigned.
lvalue is copied.n1 is also modifyable in the scope of f1

*/

int f1(int n1)
{
    std::cout<<"Addess of n1 in f1 function"<<&n1<<"\n";
    std::cout<<"value of n1 before modification"<<n1<<"\n";
    n1=100;
    std::cout<<"Value of n1 after modification"<<n1<<"\n";
}


/*

pass by non-const reference.Accept only lvalue

*/
int f2(int& n1){
    std::cout<<"Address of n1 in f1 function: "<<&n1<<'\n';
    std::cout<<"Value of n1 before modification: "<<n1<<'\n';
    n1=100;
    std::cout<<"Value of n1 after modification: "<<n1<<'\n';
}




/*
if we use && symbol with template parameter i does not mean r value reference it mean forwarded reference


*/