#include"Functionalities.h"
#include<thread>
#include<array>

int main()
{
    /*
                ----------------CalculateTaxPayable()
    ------------main(create object)
                ------CallParenOperator()
    */
    Container data;
    std::array<std::thread,1>arr;
    arr[0] = std::thread(CreateObjects,std::ref(data));
    arr[0].join();


    std::thread t2(CalculatePayabletax,std::ref(data));



    std::thread t3(CallParenOperator,std::ref(data));

    for(std::thread& th:arr)
    {
        if(th.joinable()){
            th.join();
        }
    }
    // CalculatePayabletax(data);
    t2.join();
    t3.join();

    // CallParenOperator(data);
}