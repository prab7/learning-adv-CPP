#include <iostream>
#include <array>
#include <vector>


void PrintVector(const std::vector<int>& vec){
    // std::cout << "sizeof(arr)  : " << sizeof(arr) << std::endl;
    for(decltype(vec.size()) i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }
}

int main(){
    //int arr[] = {1,3,5,7};
    std::vector<int> myVec = {1,3,5,7,9};
    PrintVector(myVec);

    return 0;
}


