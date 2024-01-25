#include<iostream>
#include<memory>
#include"Employee.h"

// Employee* Magic(Employee* emp){
//     emp -> setId(100);
// }

// int main()
// {
//     Employee* e1 = new Employee(111);
//     Employee* modified_e1 = Magic(e1);
// }



using emp_pointer = std::shared_ptr<Employee>;

void Magic(emp_pointer& emp){
    emp->setId(100);
}

int main()
{
    emp_pointer e1 = std::make_shared<Employee>(101);
    Magic(e1);
}