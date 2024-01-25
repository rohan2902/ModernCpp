// multi threading

// thread is a set of instructions 



#include<iostream>
#include<thread>

std::array<int,10>result;

void square(std::array<int,5>&data)
{
    int k=0;
    for(int val:data){

        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val;
    }

}


void cube(std::array<int,5>&data)
{
    int k=5;
    for(int val:data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++] = val*val*val;
    }
}

int main()
{
   
    std::array<int,5>data {1,2,3,4,5};
    std::thread t1(&square,std::ref(data));  // this are objects
    std::thread t2(&cube,std::ref(data));

    t1.join();  // main should not proceed further than this line UNTIL t1 sends a signal "that it has finished"
    t2.join();      //synchronization   // main should not proceed further than this line UNTIL t2 sends a signal "that it has finished"

    for(int val:result)
    {
        std::cout<<val<<"\t";
    }
    std::cout<<"\n";

}
