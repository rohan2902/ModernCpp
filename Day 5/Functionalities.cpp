#include "Functionalities.h"
#include "_Customer_type.h"
#include <vector>



    void CreateObjects(Container & data) noexcept
    {
        data.emplace_back(
            std::make_shared<Customer>(
                111,
                "Rohan",
                27,
                CustomerType::REGULAR,
                std::make_shared<DebitCard>(101, "Rohan", "11/31", DebitCardType::DOMESTIC)));
    }

    float AverageAge(Container &data)
    {
        if(data.empty()){
            throw std::runtime_error("empty data");


        }

        float total = 0.0f;
        // for-each loop (range based for loop)
        /*
        for every pointer present in data ,do the following
        
        */
        for(Pointer& ptr: data)
        {
            //smart pointer used as a regular pointer
            total = total + ptr->age();
        }

        return total/data.size();  

    }

    Pointer NthCustomer(Container &data, int N)
    {
        if(data.empty()){
            throw std::runtime_error("Data is empty");
        }
        if(N>data.size()|| N<1){
            throw std::runtime_error("N is beyond available items");
        }
        auto itr = data.begin();
        while(N>1)
        {
             itr++;
             N--;
        }

        return *itr;

        return data[N-1];
    }

    int AgeOfGivenCustomerID(Container &data, int id)
    {
        if(data.empty()){
            throw std::runtime_error("Data is empty");
        }

        for(Pointer& ptr : data){
            if(ptr->id()==id){
                return ptr->age();
            }
        }

        throw std::runtime_error("ID not found");
    }

    int CVVnumberOfDebitCard(Container &data, int id)
    {
        if(data.empty()){
            throw std::runtime_error("Data is empty");
        }


        for(Pointer& ptr : data)
        {
            if(ptr->id()==id)
            {
                return ptr->card()->getCvv();
            }
        }
        throw std::runtime_error("ID not found");
    }

    std::string ExpiryDate(Container &data, int cvv)
    {
        if(data.empty()){
            throw std::runtime_error("Data is empty");
        }

        for(Pointer& ptr: data)
        {
            if(ptr->card()->getCvv()==cvv)
            {
                return ptr->card()->expiry();
            }
        }
        throw std::runtime_error("ID not found");

    }

    Container CustomerAgeAbove50(Container &data)
    {
        if(data.empty()){
            throw std::runtime_error("Data is empty");
        }
        Container result;
        for(Pointer& ptr: data)
        {
            if(ptr->age()>50)
            {
                result.emplace_back(ptr);
            }
        }

        if(result.empty()){
            throw std::runtime_error("No Customer above 50 age");
        }

        return result;

    }

    std::shared_ptr<DebitCard> DebitCardForGivenID(Container& data, int id)
    {
        if(data.empty())
        {
            throw std::runtime_error("Data is empty");
        }

        for(const Pointer &ptr : data)
        {
            if(ptr->id()==id)
            {
                return ptr->card();
            }
        }

        throw std::runtime_error("ID not found");
    }
