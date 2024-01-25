#ifndef DATAMODELLER_H
#define DATAMODELLER_H
#include<variant>
#include<vector>
#include<memory>
#include <ostream>

#include"Employee.h"
#include"BusinessOwner.h"

/*
    data can be read by many persons but
    data can be write by only one person 


*/

using BusinessPointer = std::unique_ptr<BusinessOwner>; // unique_ptr cannot copy 
using EmpPointer = std::unique_ptr<Employee>;           // unique_ptr gives you unique access
using Vtype = std::variant<BusinessPointer,EmpPointer>;
class DataModeller
{
private:
    Vtype _instance;
    std::vector<float> _goodsPrices;
public:
    DataModeller() = delete;
    void operator()();
    DataModeller(Vtype v, const std::vector<float>& prices);
    DataModeller(const DataModeller&) = delete;
    DataModeller(DataModeller&&) = delete;
    DataModeller &operator= (const DataModeller&) = delete;
    DataModeller &operator= (DataModeller&&) = delete;
    ~DataModeller() = default;

    const Vtype& instance() const { return _instance; }  // we are giving reference and we cannot modify the data

    std::vector<float> goodsPrices() const { return _goodsPrices; }

    friend std::ostream &operator<<(std::ostream &os, const DataModeller &rhs);

};


#endif // DATAMODELLER_H
