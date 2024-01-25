#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>

template <typename T>

void display(T& container)
{
    for(auto & val:container){
        std::cout<<val<<"\t";
    }
    std::cout<<"\n";
}

int main()
{
    //example 1 : copy all elements unconditionally from source to destination
    std::vector<int>v1 {10,20,30};
    std::vector<int> result(v1.size());
    
    std::copy(v1.begin(),v1.end(),result.begin()); // source, destination, from where to copy  //copy the elements from v1 to result.

    // example 2: sum of all values
    // addition ke liye accumulator default hai, if we have to perform other than addition we have to use lambda
    std::cout<<"Total is : "<<std::accumulate(v1.begin(),v1.end(),0)<<"\n"; // source ka begining,source ka end,0 is starting value

    std::cout<<"Product is : "<<std::accumulate(v1.begin(),v1.end(),1,[](int total, int val){return total*val;})<<"\n";

    // this is a sample code to find average salary
    // std::function<float(Container&)>AverageSalary = [](Container &data){
    //     std::accumulate(
    //         data.begin(),
    //         data.end(),
    //         0.0,                                 
    //         [](float current_result,Pointer& p){
    //             return current_result + p->salary();
    //         }
    //     );
    //      return result/data.size();
    // };

    return 0;
}
