#include "Array.hpp"

// 5000%  faster with reference
// void printAnArray(Array& a) won't work because copy constructor is private
void printAnArray(const Array& a){
    //a.PrintingData();
}

int main(){ 

    // Initialize all of our data up front 
    Array myArray;

    myArray.SetData(0, 1234567);

    //Array myArray2 = myArray; // Copy constructor 

    //myArray.PrintingData();
    //myArray2.PrintingData();

    for(int i = 0; i < 100; i++){
        printAnArray(myArray); // Copy is made here, (passing by value)
    }

    return 0;
}
