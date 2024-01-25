#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<memory>
#include<functional>
#include<vector>
#include"Product.h"
#include<set>

using Pointer = std::shared_ptr<Product>;
using Container = std::vector<Pointer>;
using UniqueContainter = std::set<std::string>;

//function to create objects
extern std::function<void(Container&)> CreateObjects;

//returns average of prices
extern std::function<float(Container&)> AverageProductPrice;

//returns tax of product with max price
extern std::function<float(Container&)> TaxOfMaxPrice;

//returns last specified objects on container
extern std::function<Container(Container&, int )> LastNProducts;

//returns container with unique brands
extern std::function<UniqueContainter(Container&)> UniqueProductBrands;

//Array with FOOD and DOMESTIC instances count
extern std::function<std::array<int,2>(Container&)> ArrayOfInstances;

//Container with addresses of Products instances with same brand
extern std::function<Container(Container&,std::string )> ContainterOfBrand;



#endif // FUNCTIONALITIES_H
