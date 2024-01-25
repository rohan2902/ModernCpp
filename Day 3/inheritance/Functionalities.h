#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<memory>
#include"Vehicle.h"
#include<vector>

//step 1: Create a alias "pointer" which is an alternative name for the std::shared ptr to vehicle
using Pointer = std::shared_ptr<Vehicle>;


// step 2: now specify alternamte name for Container which indicates which indicates a standard vector of "pointer" where pointer is explained above
using Container = std::vector<Pointer>;


void CreateObjects(Container &data);

long int AveragePrice(Container &data);

void ShowDetails(Container &data);



#endif // FUNCTIONALITIES_H
