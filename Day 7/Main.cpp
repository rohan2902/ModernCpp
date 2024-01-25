#include<iostream>
#include<memory>
#include<list>
#include<vector>
#include"Employee.h"


using EmpPointer = std::shared_ptr<Employee>;
using ListContainer = std::list<EmpPointer>;
using VectorContainer = std::vector<EmpPointer>; 

void CreateObjects(ListContainer &l1,VectorContainer& v1)
{
    l1.emplace_back(
        std::make_shared<Employee>(100)
    );

    l1.emplace_back(
        std::make_shared<Employee>(101)
    );

    l1.emplace_back(
        std::make_shared<Employee>(102)
    );

    l1.emplace_back(
        std::make_shared<Employee>(200)
    );

    l1.emplace_back(
        std::make_shared<Employee>(201)
    );

    l1.emplace_back(
        std::make_shared<Employee>(202)
    );
}

int main()
{
    ListContainer l1;
    VectorContainer v1;
    CreateObjects(l1,v1);
}

/*
        Types of common logic building initial exercises
        1) Total or algebraic sum operation


        2) Find min value from a collection
            i) Create an initial min value which must be equal to the first item from the collection
            ii) for each item in the collection, do the following:
                a) fetch the item 
                b) compare item with "MIN_VALUE" so far.
                    b1) if current item is larger then min value"ignore"
                    b2) if current value is smaller ,update min_value as"current"
            iii)Finally, the min_value now holds "the global minima".

        3) Find an attribute associated with the "min" value object
            e.g. Finding the car with min mileage and returning this mileage.
            i) Create an initial min value which must be equal to the first item from the collection
            ii) also save the attribute(to be returned) of the first item 
            iii) for each loop,do the following
                 a) compare and check current value is lower than min
                    a1)if yes, update min.
                    a2)if no,ignore.
            iv) return the associated value


            FindIdMinMileage(Container& data){
                float min_mileage = data[0]->mileage();
                int min_id = data[0] ->id();
                for(Vehicle v:data)
                {
                    float current_mileage = v->mileage();
                    if(current_mileage<min_mileage)
                    {
                        min_mileage = current_mileage;
                        min_id = v->id();
                    }

                }
                return min_id;
            }
        






*/