#include<iostream>
#include"Employee.h"
#include"BussinessOwner.h"
#include<variant>
#include<memory>


int main()
{
    std::variant<Employee,BussinessOwner> v1;

    /*
        visit needs at least 2 parameters

        first: Lambda function that explains what to do with item inside the variant
        second(and subsequent parameters): objects of variant class.(object/s on which visit
        lambda has to be applied)
    
    
    */

    v1 = Employee();
    std::visit(
        [](auto&&val){val.PayTax();},
        v1
    );

    v1 = BussinessOwner();   
    std::visit(
        [](auto&&val){val.PayTax();},
        v1


    );

    //both will give same output but below we used shared ptr and above we used class

    
    std::shared_ptr<Employee>e1 = std::make_shared<Employee>();

    //std::shared_ptr<BussinessOwner>e2 = std::make_shared<BussinessOwner>();

    std::variant<std::shared_ptr<Employee>,std::shared_ptr<BussinessOwner>  > v2;

    v2 = e1; // storing e1 inside the variant. this should be stored in slot 1
   

    std::visit(
        [](auto&& val ){val->PayTax();},
        v2
    );
    // v2 = e2;
    // std::visit(
    //     [](auto&& val){val->PayTax();},
    //     v2
    // );

}
