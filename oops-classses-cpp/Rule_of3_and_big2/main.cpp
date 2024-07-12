#include "Array.hpp"

int main(){

    // Initialize all of our data up front 
    Array myArray;

    myArray.SetData(0, 1000);
    myArray.SetData(1, 77);
    myArray.SetData(2, 999);

    Array myArray2 = myArray; // Copy constructor

    Array myArray3;
    myArray3 = myArray; // Copy-Assignment Operator

    myArray.PrintingData();
    myArray2.PrintingData();

    return 0;
}
 /** 
  * law of 3 -
  * if you need to define one of them, define them all
  * 
  * law of Big Two - 
  * if you have some smart pointers, you can ditch defining the destructor
  *  or some data structures, not dynamically allocated
  */
