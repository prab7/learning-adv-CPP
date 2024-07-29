#include <iostream>
#include <algorithm>
#include <vector>

// equivalent Funtor
struct print_functor {
    int lastResult{-1};
    void operator()(int n){
        lastResult = n;
        std::cout << n << ' ';
    }
};

// equivalent function
void print_function(int n){
    std::cout << n << ' ';
}

int main(){

    std::vector<int> vec{1,3,2,5,9};

    int lastResult = -1;
    // you can store the lambda because it's a function object.
    auto print_vec = [&](int n) -> void {lastResult = n; std::cout << n << " ";};

    std::for_each(
                begin(vec),
                end(vec),
                /*[&lastResult](int n){lastResult = n; std::cout << n << " ";} // lambda (unnamed function object) */
                print_vec
            );
    
    std::cout << '\n' << "lastResult value now: " << lastResult << std::endl;
    
    // the above is a little more readable than this
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << ' '; 
    } std::cout << '\n';
    // or even this.
    for(auto it = vec.begin(); it != vec.end(); it++){
        std::cout << *it << ' '; 
    } std::cout << '\n';

    // most straight forward implementation
    for(auto element: vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}



// Lambda is something that constructs a closure
// Closure -
    //  unnamed function object capable of capturing variables in scope.

/**
 * Lambda is interchangeable with "functions" and "function objects" as inputs for STL functions.
 */

/**
 * Syntax:
 * 
 * [captures] (params) specs requires {body}
 * [captures] {body}
 * [captures] specs {body}
 * [captures] <tparams> requires (params) specs requires {body}
 * [captures] <tparams> requires {body}
 * [captures] <tparams> requires specs {body}
 * 
 * *all requires are optional
 * 
 * captures capture the variables within a block scope by reference
 * 
 */