#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"Driver.h"

using DriverPointer = std::shared_ptr<Driver>;
using ContainerOfLiscence = std::vector<LiscencePointer>;
using ContainerOfDriver = std::vector<DriverPointer>;
using VectorOfStrings = std::vector<std::string>;

extern std::function<void(ContainerOfDriver&,ContainerOfLiscence&)> CreateObjects;
extern std::function<ContainerOfLiscence(ContainerOfDriver&)> FirstTwoInstancesByBirthYear;
extern std::function<ContainerOfDriver(ContainerOfDriver&)> FirstTwoInstancesByLiscence;
extern std::function<ContainerOfDriver(ContainerOfDriver&,std::string )> FindDriverByRTO;
extern std::function<ContainerOfLiscence(ContainerOfDriver&,VectorOfStrings)> SearchByVectorOfState;

void Operation(std::function<void(ContainerOfDriver&)>,ContainerOfDriver&);
#endif // FUNCTIONALITIES_H
