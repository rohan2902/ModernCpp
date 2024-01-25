#ifndef BUSSINESSOWNER_H
#define BUSSINESSOWNER_H

#include<iostream>

class BussinessOwner
{
private:
    /* data */
public:
    BussinessOwner(/* args */) {}
    ~BussinessOwner() {}

    void PayTax(){
        std::cout<<"Business has to pay advance tax and GST every month"<<"\n";
    }
};

#endif // BUSSINESSOWNER_H
