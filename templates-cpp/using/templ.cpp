#include <iostream>
/**
 * 2. type alias - something like typedef, prefer using over typedef
 * - it's better than typedef because it's easier to use with templates
 */

// equivalent as below 
// typedef void void_t;
using void_t = void;

template<class T, size_t>
class DataStructure {
    // some data structure
};

// typedef DataStructure<int,10> DataStructureInt10;
using   DataStructureInt10 = DataStructure<int, 10>;

template<class T>
using DataStructure10 = DataStructure<T, 10>; // can't do this with typedef (cleanly)


void foo(){
    using std::cout;
    cout << "will this work?\n";
}

int main(){

    using namespace std;
    cout << "Mike's Modern C++ Series\n";

    foo();

    DataStructure10<int> gawk;
    DataStructure10<float> ghawk;

    return 0;
}