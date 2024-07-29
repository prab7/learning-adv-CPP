#include <iostream>
#include <algorithm>
#include <vector>

// Lamba Syntax
// [captures] (params) specs requires {body}
// [captures] <tparams> requires (params) specs requires {body}


int global = 1;

int main(){

    std::vector<int> vec{1,3,2,5,9};
    int lastResult = -1;
    int lastResult2 = -1;

    // Captures by copy are READ-ONLY, always pass by reference to modify(write) value.
    // unless, mutable!

    // global variables are ALWAYS mutable, no need to specify mutable keyword.
    std::for_each(
                begin(vec),
                end(vec),
                [=](int n) mutable {
                    global = 10;
                    lastResult = n;
                    lastResult2 = n;
                    std::cout << n << ' ';
                } // lambda (unnamed function object)
            );

    // we passed a mutable copy, not the actual variable, hence no change.
    std::cout << "\n" "global value now: " << global     << std::endl;
    std::cout <<  "lastResult value now: " << lastResult << std::endl;
    std::cout << "lastResult2 value now: " << lastResult2<< std::endl;

    // this is essentially a 'raw function pointer' 
    // void(*print_vec)(int);
    auto print_vec = [=](int n){
                            global = 69;
                            std::cout << n << ' ';
                        };

    std::for_each(
                begin(vec),
                end(vec),
                print_vec
            );
    
    std::cout <<"\nglobal value now: " << global << std::endl;

    return 0;
}

// checkout cppinsights for this aswell. 