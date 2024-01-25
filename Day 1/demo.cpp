#include<iostream>

enum class Rank{  // use enum class instead of enum. 
    FIRST,
    SECOND,
    THIRD,
};

enum class GEAR{
    FIRST,
    SECOND,
    THIRD
};
void Magic(int data)
{

}
int main()
{
    enum Rank r1 = Rank::FIRST;

    enum GEAR g1 = GEAR::FIRST;

    if(r1==g1)
    {
        std::cout<<"Oops!\n";  
    }

    Magic(r1);
}

