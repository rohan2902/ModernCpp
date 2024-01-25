#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Order.h"
#include <list>

using Pointer = std::shared_ptr<Order>;
using Container = std::list<Pointer>;

// Functioanlities
void CreateObjects(Container &data);
std::string FindIDWithHighestDiscount(const Container &data);
Type FindTypeUsingID(const Container &data, std::string key);
float FindAverageOfValue(const Container &data);
Container FirstNInstances(const Container &data, int N);

#endif // FUNCTIONALITIES_H
