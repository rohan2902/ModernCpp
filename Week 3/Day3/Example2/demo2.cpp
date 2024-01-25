#include<vector>
#include<iostream>
#include<optional>


void TakeInput(std::vector<int>&data,int N)
{
    int val = -1;
    while(N>0)
    {
        std::cout<<"Enter elememts"<<"\t";
        std::cin>>val;
        data.push_back(val); // for premitive data type push back is ok
        N--;
    }
}

/*
    Identify even number from data,store all them in result
    return result

    scenario 1: there is at least 1 even number in data.
                you identify the number.store in result

    scenario 2: data is empty.handle by raising exception

    scenario 3: data is not empty.however,all numbers are ODD(instead of throwing exception runtime error(result.empty()) at this point use OPTIONAL)


*/

std::optional<std::vector<int>  >ReturnEvenNumber(std::vector<int>&data){  
    if(data.empty())
    {
        throw std::runtime_error("Error as data is empty");
    }

    std::vector<int>result;

    for(int v:data){
        if(v%2==0){
            result.push_back(v);
        }
    }

    if(result.empty()){
        return std::nullopt; // nullopt is a symbol to indicate no value.(no even numbers found)
    }
    return result;
}

int main()
{
    int N = -1;
    std::cout<<"Enter size:"<<"\t";
    std::cin>>N;

    std::vector<int> v1(N); // space for N integers is now reserved on the heap
    std::vector<int> data;

    TakeInput(data,N);

    std::optional<std::vector<int> > even_number = ReturnEvenNumber(data);

    /*
     has_value returns false if optional wrapper contains nullopt
     if there is no even number present it will NOT go in for loop
    


     has_value return true if a valid value is found in optional 
    
    */
    if(even_number.has_value()){   // has_value return true/false
        /*
        we only come inside if has_value returns true 
        i.e. valid value is present
        i.e. container of even numbers is found in optional
        
        */             
        std::cout<<"Count of even numbers\t"<<even_number.value().size();
    }
    else{
        std::cout<<"Vector returned no values \n";
    }

}
