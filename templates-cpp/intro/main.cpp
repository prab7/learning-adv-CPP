#include <iostream>

int square(int input) {
    return input*input;
}

double square(double input) {
    return input*input;
}

float square(float input) {
    return input*input;
}
// we can avoid this copy and paste using generics! (templates)

template <typename T> // template param
T cube(T input){
    return input*input*input;
}


int main(){
    std::cout << square(5) << std::endl;
    std::cout << square(5.5) << std::endl; // well this gives 25 huh, unless we overload
    std::cout << square(6.5f) << std::endl; // compiler just keeps downcasting it, UNLESS!

    // Templates baby!!
    std::cout << cube(5) << std::endl; // checkout cppinsights.com
    std::cout << cube(5.5) << std::endl; 
    std::cout << cube(5.7f) << std::endl; 

    std::cout << cube<int>(5) << std::endl; // or just do the template argument deduction
    std::cout << cube<int>(5.5) << std::endl; 
    std::cout << cube<int>(5.7f) << std::endl; 

    return 0;
}

// Templates 
// - Avoid copy and paste
// Serves as a blueprint for the compiler to generate code for us

/*
#include <iostream>

template<typename T>
T cube(T input)
{
  return (input * input) * input;
}

/* First instantiated from: insights.cpp:10 *//*
#ifdef INSIGHTS_USE_TEMPLATE
template<>
int cube<int>(int input)
{
  return (input * input) * input;
}
#endif


/* First instantiated from: insights.cpp:11 *//*
#ifdef INSIGHTS_USE_TEMPLATE
template<>
double cube<double>(double input)
{
  return (input * input) * input;
}
#endif


/* First instantiated from: insights.cpp:12 *//*
#ifdef INSIGHTS_USE_TEMPLATE
template<>
float cube<float>(float input)
{
  return (input * input) * input;
}
#endif


int main()
{
  std::cout.operator<<(cube(6)).operator<<(std::endl);
  std::cout.operator<<(cube(6.5)).operator<<(std::endl);
  std::cout.operator<<(cube(6.6999998F)).operator<<(std::endl);
  return 0;
}
*/