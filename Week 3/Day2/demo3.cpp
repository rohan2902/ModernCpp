// Mutex

#include<iostream>
#include<thread>
#include<mutex>
/*

    100 withdraw transactions of 10 units each
    100 deposit transactions of 10 units each

*/
int amount = 1000;
std::mutex mt;
void withdraw(){
    for(int i=0;i<10;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        //critical section start
        mt.lock();
        amount -=10;
        mt.unlock();
        // critical section end
    }

}

void deposit(){
        for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        //critical section start
        mt.lock();
        amount +=10;
        mt.unlock();
        //critical section end
    }


}

int main()
{
    std::thread t1(&withdraw);

    std::thread t2(&deposit);

    t1.join();
    t2.join();

    std::cout<<"Final amount ="<<amount<<"\n";

}