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
    
    private:
        T* m_data;
};

int main(){

    Container<int, 5> c; // con;t get away without declaring <int>
    Container<float, 5> c2;
    Container<double, 5> c3;

    return 0;
}

// Class template

/* template <parameter-list> class-declaration */
/* export template <parameter-list> class-declaration */
