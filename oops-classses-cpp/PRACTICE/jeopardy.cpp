// Q2 

class Rectangle {
    public:
        void set_values(int , int);
        int area(void);
    private:
        int height, width;
} rect ;

int main(){
    return 0;
}


// Q4

struct UDT {
    int x, y;
};

int main(){
    UDT u;
    u.x = 5;
    u.y = 7;

    return 0;
}


// Q7
#include <iostream>

class Array {
    public:
        Array(const Array& rhs){
            std::cout << "Copy constructor" << std::endl;
            data = new int[10];
            for(int i = 0; i < 10 ; i++){
                data[i] = rhs.data[i];
            }
        }

        Array& operator=(const Array& rhs){
            std::cout << "Copy assignment operator" << std::endl;

            if(&rhs == this){
                return *this;
            }
            delete[] data;
            data = new int[10];
            for(int i = 0; i < 10 ; i++){
                data[i] = rhs.data[i];
            }

            return *this;
        }

    private:
        int* data;
};

// Q24
class Base {
    public:
        virtual void MemberFunc(){}
};
class Derived : public Base {
    public: 
        Derived(){
            std::cout << "Derived Constructor" << std::endl;
            derivedData = new int[15];
        }
        ~Derived(){
            std::cout << "Derived Constructor" << std::endl;
            delete[] derivedData;
        }
        void MemberFunc() override {
            std::cout << "Derived::MemberFunc()\n";
        }

    private:
        int* derivedData;
};

int main(){
    Base* instance = new Derived; // ptr to anything that 'is-a' base
    instance->MemberFunc();
    delete instance;
    
    return 0;
}


// Q25

class IRenderer {
    public:
        virtual void Draw() = 0;
        virtual void Update() = 0;
};


