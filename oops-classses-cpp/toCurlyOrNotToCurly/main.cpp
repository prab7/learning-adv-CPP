#include <iostream>
#include <vector>
#include <initializer_list>

struct UDT {

    UDT(int a, int b, int c){
        std::cout << "constructor with 3 param\n";
    }

    UDT(std::initializer_list<int> data) : m_data(data){
        std::cout << "Initializer_list constructor\n";
    }  // overloads the default

    ~UDT(){} // default no overload

    void PrintData(){
        for(auto& e : m_data){
            std::cout << e << ' '; 
        }
        std::cout << std::endl;
    }

    private:
        std::initializer_list<int> m_data;

};


int main(){

    UDT u {1,2,3,4,5,6,7}; // prevents narrowing, only ints allowed
    UDT v (10, 10, 10);
    u.PrintData();

    return 0;

    // Big penis normalization


    std::vector<int> vec{1,2,3}; // initializer list
    //std::vector<int> v(1,2,3); // constructor arguments, not defined ERROR!
    std::vector<int> vec1(10,1); // constructor arguments, actual
    for(auto& idx : vec){
        std::cout << idx << '\n';
    }

    int a = 4.2;
    int b (4.2);
    //int c {4.2};  // curly prevents narrowing ERROR! 


    return 0;
}
