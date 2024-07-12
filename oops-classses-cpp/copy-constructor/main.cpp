#include <iostream>
#include <string>

class Vector3 {
    public: //we already have a default compiler generated constructor destructor + Copy constructor
        Vector3(){
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
        float x,y,z;
};


class Array {
    public:
        Array(){
            std::cout << "Constructor" << std::endl;

            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = i*i;
            }
        }
        ~Array(){
            std::cout << "Destructor" << std::endl;
            delete[] data;
        }

        // Copy constructor
        Array(const Array& rhs){

            std::cout << "Copy Constructor" << std::endl;

            delete[] data; // idk why this still works with out without it
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = rhs.data[i];
            }
        }
        // Copy-Assignment Operator - object already constructed, we are just making a copy later
        Array& operator=(const Array& rhs){
            std::cout << "Copy-Assignment Operator" << std::endl;

            if(&rhs == this){
                return *this;
            }
            if(data != nullptr){
                delete[] data;
                data = new int[10];
                for(int i = 0; i < 10; i++){
                    data[i] = rhs.data[i];
                }
                return *this;
            }
        }

        void PrintingData(){
            for(int i = 0; i < 10; i++){
                std::cout << data[i] << std::endl;
            }
        }

        void SetData(int idx, int value){
            data[idx] = value;
        }


    private:
        int* data;
};



int main(){

    Vector3 myVector;
    myVector.x = 1.0f;
    myVector.y = 2.0f;
    myVector.z = 3.0f;

    Vector3 myVector2; // Copy constructor
    myVector2 = myVector;  // Copy-Assignmnet operator

    std::cout << myVector2.x << ',' << myVector2.y << ',' << myVector2.z << std::endl;
    std::cout << sizeof(Vector3) << std::endl;



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
 * Default compiler generated -
 * - Constructor
 * - Destructor
 * - Copy constructor
 * 
 */


/**
 * 
 * +---------+    +----------+
 * | myArray |    | myArray2 |
 * +---------+    +----------+  myArray2.data = myArray.data
 * |int* data|    |int* data |  pointer value is the same memory address;
 * +---------+    +----------+
 * 
 * C++ gives us a free copy constructor
 * and copy-assignment operator
 * 
 * but it does a shallow copy (trivial assignment)
 * 
 *  Deep copy needed for Dynamic memory alloc
 * 
 */





 

