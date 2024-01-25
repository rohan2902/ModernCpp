#ifndef CAR_H
#define CAR_H
#include<memory>
#include<functional>
#include <ostream>
#include"Engine.h"

using pointer=std::shared_ptr<Engine>;
using RefType=std::reference_wrapper<pointer>;


class Car
{
private:
    /* data */
    int _id;
    std::string _model;
    float _price;
    RefType _engine;

public:
    Car(int id,std::string model, float price,RefType engine);
    ~Car()=default;

    int id() const { return _id; }

    std::string model() const { return _model; }

    float price() const { return _price; }

    RefType engine() const { return _engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    
};

#endif // CAR_H
