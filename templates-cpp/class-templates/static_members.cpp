#include <iostream>

template <typename T, int N>
class Container {
    public:
        Container(){
            m_data = new T[N];
        }
        ~Container(){
            delete[] m_data;
        }

        static T m_variable;
    
    private:
        T* m_data;
};

// Static member variable telling the compiler, "Hey, we exist"
template <typename T, int N>
T Container<T,N>::m_variable; // if you comment this out, another linker error occurs

int main(){

    Container<int, 5> c1;
    Container<int, 7> c2;
    std::cout << c2.m_variable << std::endl;
    Container<int, 5>::m_variable = 8; // linker error
    std::cout << c1.m_variable << std::endl;

    return 0;
}

