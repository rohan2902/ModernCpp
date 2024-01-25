#include "DataModeller.h"


void DataModeller::operator()()
{
    if(_goodsPrices.empty())
    {
        throw std::runtime_error("Not found");
    }

    float total = 0.0f;

    for(float val:_goodsPrices){
        total+=val;
    }
    std::cout<<"Average value is " << total/_goodsPrices.size()<<"\n";

}



DataModeller::DataModeller(Vtype v,const std::vector<float>& prices)
:_instance(std::move(v)),_goodsPrices(prices)
{
}


std::ostream &operator<<(std::ostream &os, const DataModeller &rhs) {
    os << "_instance: "; //word
    std::visit(
        [&](auto && val){os<<*val;}, rhs._instance
    );
    os << " _goodsPrices: ";
    for(float val:rhs._goodsPrices){
        os<<val<<"\t";
    }
    return os;
}

/*
    Buffer
    [              ]
        word        variant visit       word            for loop
    _instance|   Harshit 0 78000.0f  | _goodsPrice | 10.21f,145.31f,204.5f



*/

