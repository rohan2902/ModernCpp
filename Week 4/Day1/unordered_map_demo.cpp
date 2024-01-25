


#include<unordered_map>
#include<iostream>

int main()
{
    std::unordered_map<int,std::string>umap{  // int is a key and std::string is a value
        {101,"Harshit"},
        {202,"Rohan"}
    };

    std::cout<<"Employee with ID 202: "<<umap[202]<<"\n";

}


/*
I want to design an application to process 10 recent transactions made by user by fething heir details from the databse
OPERATION:
    Each transaction amount,time and receipient has to be printed on a log file

Note : 1 tramsaction has no readability with others.i.e.all transactions are mutually exclusive

Every transaction has the following state
    [transaction time | amount | source | destination ]

Answer: Array(because it consumes less time)

Example 2:
I want to design an application where a new data value is received at a fixed interval and gets added at the back of the data values so far.I want to process only the oldest value from these values at a time and print values at the console.

I am not allowed to modify any received value and for as a value gets processed, it needs to be removed from the transaction pending set.



*/

