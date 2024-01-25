#include "Engine.h"

Engine::Engine(std::string engineNumber, EngineType engType, int engineHorsepower, int engineTorque):_engineNumber(engineNumber),_engType(engType),_engineHorsepower(engineHorsepower),_engineTorque(engineTorque)
{
}


std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engineNumber: " << rhs._engineNumber
       << " _type: " <<static_cast<int> (rhs._engType)
       << " _engineHorsepower: " << rhs._engineHorsepower
       << " _engineTorque: " << rhs._engineTorque;
    return os;
}
