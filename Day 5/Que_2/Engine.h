#ifndef ENGINE_H
#define ENGINE_H
#include"EngineType.h"
#include<iostream>


class Engine
{
private:
    std::string _engineNumber;
    EngineType _engType;
    int _engineHorsepower;
    int _engineTorque;    
public:
    Engine() = default;
    Engine(std::string,EngineType,int,int);
    Engine(const Engine&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (Engine&&) = delete;
    ~Engine() = default;

    std::string engineNumber() const { return _engineNumber; }

    

    int engineHorsepower() const { return _engineHorsepower; }

    int engineTorque() const { return _engineTorque; }

    EngineType engType() const { return _engType; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
