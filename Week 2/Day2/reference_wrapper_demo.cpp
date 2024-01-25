#include<iostream>
#include<vector>
#include<functional>



void Magic(std::reference_wrapper<int>n1){
    std::cout<<"Address of n1 in magic"<<&n1<<"\n";     //std::cout<<"Address of n1 in magic"<<&(n1.get())<<"\n"; // .get is used to take address of n1 data(it will print same address as main)
    std::vector<std::reference_wrapper<int> > v1{n1};  // vector of reference wrapper
    std::cout<<n1.get(); // value in n1;
    


}

int main()
{
    int n1=10;

    std::cout<<"Address of n1 in main"<<&n1<<"\n";

    Magic(n1);













    //int& ref1 = n1;
    /*
    arr is an array of size 1
    arr can store lvalue reference

    arr is an array of 1 integer lvalue reference
    
    
    */

    //int& arr[1] {ref1};
}