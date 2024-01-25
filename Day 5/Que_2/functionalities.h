#include<memory>
#include<vector>
#include"Car.h"


using Pointer = std::shared_ptr<Car>;
using Container = std::vector<Pointer>;

void CreateObjects(Container& data);

int findEngineHorsepower(Container& data,std::string carId);
Container findEngineTorqueAbove80(Container& data);
Container CarTypeInstance(Container& data,CarType CarType);
std::string LowestCarID(Container& data);
float CombinedPrice(Pointer p,Pointer q);