//call by value

#include<iostream>

int Magic(int n1)
{
    int ans = n1 * 100;
    return ans;
}

int main()
{
    int data = 20;
    //Address of data can be determined because data is lvalue.
    std::cout<<"The address of data in main "<<&data<<"\n";
    // result stores the result "value" from magic called with "data" passed by value
    int result = Magic(data);

}


// call by value means copy 