#include <iostream>
#include <typeinfo>

template <typename T1, typename T2>
void foo(T1 input1, T2 input2){
    std::cout << typeid(input1).name() << std::endl;
    std::cout << typeid(input2).name() << std::endl;
}
template <typename T1, size_t N>  // <object-type, non-object-type>
void bar(T1 input){
    std::cout << typeid(input).name() << std::endl;
    std::cout << typeid(N).name() << std::endl;

    for(int i = 0; i < N; i++){
        std::cout << "zoink" << std::endl;
    }
}

int main(){

    foo<int, float>(5, 3.14f);
    foo<float, int>(5, 3.14f);

    bar<int, 3>(5);
    bar<int, 4>(5);
    bar<int, 5>(5); // lot's of code generated

    return 0;
}