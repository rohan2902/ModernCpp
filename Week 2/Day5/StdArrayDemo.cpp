#include<array>
#include<iostream>

int main()
{
    // int arr1[3]
    std::array<int,3>arr1;

    arr1[0] = 100;
    arr1[1] = 200;
    arr1[2] = 300;

    for(int i=0;i<3;i++)
    {
        arr1[i] = (i+1)*100;
    }

    //print array

    for(int val:arr1)
    {
        std::cout<<val<<"\n";
    }

    //size

    std::cout<<arr1.size()<<"\n";

    std::cout<<"first number : "<<arr1.front()<<"\n";

    std::cout<<"Last number : "<<arr1.back()<<"\n";

    //  int arr2d[3][2]{{70,30},
    //                 {40,50},
    //                 {60,70}
    // };

    std::array<std::array<int,2>,3>arr2d{
                std::array<int,2>{70,30},
                std::array<int,2>{40,50},
                std::array<int,2>{60,70}
   
    };

    //display

    for(auto row:arr2d)
    {
        //columns
        for(auto element:row){
            std::cout<<element<<"\n";
        }
    }

    std::cout<<arr2d[1][1]<<"\n";
}