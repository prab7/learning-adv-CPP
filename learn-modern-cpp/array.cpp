#include <iostream>
#include <numeric>
#include <iterator>
#include <array>

using namespace std;

int main(){

    int arr[100]; // garbage values

    int brr[] = {1, 3, 5};

    array<int, 100> ids;

    iota(begin(arr), end(arr), 0); // RAW array
    // arr[1000] = 9   gives a seg fault

    iota(begin(ids), end(ids), 0); // STL array

    ids.at(99) = 9; // warning instead of seg fault
    // accesses the outside element with bounds checking

    for(int i = 0; i < 100; i++){
        cout << arr[i] << endl;
    }
    for(int i = 0; i < 100; i++){
        cout << ids[i] << endl;
    }

    return 0;
}