#include <iostream>

// this will actually give a ton of Ruleof5, Ruleof3 with -Weffc++

template <typename T=int, int Size=10>
class Container {
    public:
        Container(){
            m_data = new T[Size];
            std::cout << Size << std::endl;
        }
        ~Container(){
            delete[] m_data;
        }

    private:
        T* m_data;
};

int main(){

    Container<int, 5> c1;
    Container c2; // C++ 17 ▲ because of CTAD

    return 0;
}