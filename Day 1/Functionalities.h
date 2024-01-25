#include"vehicle.h"

// dont return address of local variable.


/*
accept a pointer to an array of pointers.

Initialize objects on heap, store their addresses in the array.


*/
void CreateObjects (vehicle **arr,const int size);



/*

 loop over instances.

 calculate total price and divide it by number of instances



*/

float AveragePrice( vehicle** arr,const int size);

int LowestPriceId( vehicle** arr,const int size);
