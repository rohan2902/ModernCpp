#include<set>
#include<memory>
#include<iostream>

//using Pointer = std::shared_ptr<Employee>;
//using pointer_container = std::set<Pointer>;

template<typename T>
void Display(T& Container)
{
    for(auto& val : Container){
        std::cout<<val<<"\n";
    }
}

// template <>
// void Display(pointer_container& data){
//     for(const Pointer& ptr:data)
//     {
//         std::cout<<*ptr<<"\n";
//     }
// }

int main()
{
    std::set<int>s1{10,20,30,40,50,10};
    Display<std::set<int>>(s1);
}


/*
final marathon containers to study:-

vector
array
list
unordered map
ordered set
queue
priority queue



*/