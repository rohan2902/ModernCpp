/*
    I am creating a function magic
    It needs to accept one integer "data"

    Scenario 1: 
    copy and create duplicated data value to preserve original value inside data and yet 
    perform operations on the copy inside magic
    (call by value)

    scenatio 2:
    I have "temporary" integer which needs to be passed to magic.magic would perform
    operations like modifications on the integer and return the modified value.
    solutions=2A-pass integer value to data and returns modified data by value.
              2B- pass data by value and return data by value


*/
/*
this overload magic accepts one integer by rvalue reference and returns one integer by value.

*/

#include<iostream>
#include"Employee.h"

int Magic(int&& data){ // remove && to perform 2B scenario and it will act as pass by value

}
Employee Magic(Employee&& data)
{

}

int main()
{
    Magic(10);
    Magic(Employee(101));
}