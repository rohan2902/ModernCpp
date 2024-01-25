#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<memory>
#include<array>
#include"Product.h"
#include<functional>

using Pointer = std::shared_ptr<Product>;
using Container = std::array<Pointer,4>;

void CreateObjects(Container &data);

extern std::function<float(Container &,productType)>AveragePriceOfGivenType;

extern std::function<float(Container &)>ProductTaxAmountWithMaxPrice;

extern std::function<Pointer(Container &,int)>LastNinstance;




#endif // FUNCTIONALITIES_H