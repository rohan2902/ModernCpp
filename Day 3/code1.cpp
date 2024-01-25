#include<iostream>

#include<list>
#include<memory>

#include<vector>



/*
    uniform initialization'
    instread of = use curly braces{} for initialization thats known as uniform initialization

    it works for data types as well as constructor and destructors and everywhere





*/


struct employee{
    int id;
    std::string name;

};






class car
{
private:
    /* data */
public:
    car() = default;

    car(int,std::string):_id(id),_name(name)
    ~car() {}
};





int main()
{



    int n1{10};

    int* ptr { &n1};

    car c1{};

    car c2{101,"Dzire"};

    int arr[3] {10,20,30};

    struct employee e;

    std::list<int> data{1,2,3};

    std::vector<int>values{1,2,3};

    std::shared_ptr<int>ptr2{ptr};




}