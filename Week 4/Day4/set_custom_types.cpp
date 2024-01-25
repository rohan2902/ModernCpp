#include<set>
#include<iostream>
//#include<ostream>

template<typename T>
void Display(std::set<T>& data)
{
    for(const T& val:data)
    {
        std::cout<<val<<"\n";
    }
}




struct Employee{
    int _id;
    float _salary;

    friend std::ostream& operator<<(std::ostream& os,const Employee& obj){
        os<<"Employee: [ "<<"_id: "<<obj._id<<" salary: "<<obj._salary<<" ]";
        return os;
    }

    Employee(int id,float salary):_id(id),_salary(salary){}

    bool operator<(const Employee& rhs)const{
        return (_salary <rhs._salary);//||(rhs._salary>_salary) || (_salary!=rhs._salary);
    }

};

int main()
{
    Employee e1(101,89000.0f), e2(202,78000.0f),e3(100,80000.0f);
    std::set<Employee> s1{e1,e2,e3};
    Display<Employee>(s1);
}


/*


1)comparator with how many conditions?
Ans: Comparator must be designed for strict weak ordering which requires equivalence check.

2) I have smart pointers and I want to store them in set?
Ans: Write a comparison function for smart_pointer<T> as a global function (can use in many cases)
 

*/


