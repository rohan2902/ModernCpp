#include<iostream>

class MyClass{
    private:
    int _id;
    public:
    MyClass() = default;
    MyClass(int id):_id(id){}
    MyClass(MyClass&&) = default;
    MyClass(const MyClass&) {std::cout<<"copy constructor called\n";} //dont write anything in copy constructor this is the bottom line of copy elision,dont make empty curly braces also
    MyClass &operator=(MyClass&&) = default;
    MyClass &operator=(const MyClass&) = default;
    ~MyClass() = default;
    
};


//step 4 : Signature is matched and copy is invoked
MyClass Magic(MyClass& obj){
    //temp object is instantiated by "copy constructor"
    MyClass temp(obj);
    // step 6:address of temp is printed
    std::cout<<"Address of temp is "<<&temp<<"\n";
    //step 7: temp is returned by value 
    return temp;

}


int main()
{
    //step 1: obj gets instantiated
    MyClass obj(100);
    //step 2: address is printed (obj is in stack of main function)
    std::cout<<"Address of obj is "<<&obj<<"\n";

    // step 3:call magic function. Whatever is returned from magic will be saved in return_obj variable
    /*
    return_obj is a variable which is "assigned" 
    
    */
    MyClass return_obj = Magic(obj);
    //final step
    std::cout<<"Address of return_obj is "<<&return_obj<<"\n";
    
    //std::cout<<&return_obj<<"\n";
}