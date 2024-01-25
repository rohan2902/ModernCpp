#ifndef FUNCTIONALITITES_H
#define FUNCTIONALITITES_H
#include<vector>
#include<memory>
#include"DataModeller.h"

using DataPointer = std::unique_ptr<DataModeller>;
using Container = std::vector<DataPointer>;

void CreateObjects(Container &data);

void CalculatePayabletax(Container &data);

void CallParenOperator(Container& data);

#endif // FUNCTIONALITITES_H
