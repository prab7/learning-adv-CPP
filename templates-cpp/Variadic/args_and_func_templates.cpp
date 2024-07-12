#include <iostream>

template <typename T>
T Sum(T arg){
    return arg;
}

template <typename T, typename... Args>
T Sum(T start, Args... args){
    return start + Sum(args...);
}

// wierd


// CAUTION!! Headache ahead
int main(){

    std::cout << Sum(1,2,3,4,5) << std::endl; 
    std::cout << Sum(1,2.2f,3.7,4,5) << std::endl; // hmm doesnt work
    std::cout << Sum<double>(1,2.2f,3.7,4,5) << std::endl;  // wierd, works
    std::cout << Sum<double>(1,1,3.7,4,5) << std::endl;  // 😭😭
    std::cout << Sum<double, double>(1,1,3.7,4,5) << std::endl;  // now works, WHY??

    // avoid all this by using 'double Sum(T arg)' func declaration

    return 0;
}

// Parameter pack ... (C++11)

/* type... pack-name */
/* typename|class... pack-name*/
/* template<parameter-list> class... pack-name*/
/* template<parameter-list> typename|class... pack-name*/

// cstdarg eqv
