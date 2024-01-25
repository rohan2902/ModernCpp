#include "Functionalities.h"
#include "_Customer_type.h"
#include<vector>


void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<Customer>(
            111,
            "Rohan",
            27,
            CustomerType::REGULAR,
            std::make_shared<DebitCard>(101, "Rohan", "11/31", DebitCardType::DOMESTIC)
            )
    );
}