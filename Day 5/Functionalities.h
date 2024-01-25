#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<memory>
#include"Customer.h"


using Pointer = std::shared_ptr<Customer>;
using Container = std::vector<Pointer>;
/*

A function to cretae object of type customer

*/
void CreateObjects(Container &data) noexcept;

/*
    A function to find average age of all customers

*/

float AverageAge(Container& data);

/*

a function to return Nth object from the customer

*/

Pointer NthCustomer(Container& data,int N);


/*

a function to find the age of the customer whose id is provided as a parameter

*/

int AgeOfGivenCustomerID(Container& data,int id);



   /*
   
    A function to find the cvv number of debit card for customer whose ID is provided as a parameter
   
   */
int CVVnumberOfDebitCard(Container& data,int id);

  /*
  A function to return the expiry date of debit card whose cvv number matches with value given by the user
  
  */
std::string ExpiryDate(Container& data,int cvv);

 /*
 
 A function to return a container of all pointers which point to customer with age above 50 
 
 */

Container CustomerAgeAbove50(Container&data);


/*

A function to return the debitcard pointer for a customer whose ID is given as input parameter

*/
std::shared_ptr<DebitCard> DebitCardForGivenID(Container& ID,int id);


#endif // FUNCTIONALITIES_H

