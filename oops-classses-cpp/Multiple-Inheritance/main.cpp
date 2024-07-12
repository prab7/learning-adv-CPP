// generally a bad idea

#include <iostream>

struct noncopyable {
    noncopyable()=default;
    noncopyable(const noncopyable& rhs) = delete;
    noncopyable& operator = (const noncopyable& rhs) = delete;
};

struct Dog : public noncopyable {
    virtual void Bark(){
        std::cout << "Dog::Bark()\n";
    }
};
struct Golden : public Dog {
    virtual void Bark() override {
        std::cout << "Golden::Bark()\n";
    }
};
struct BorderColie : public Dog {
    virtual void Bark() override {
        std::cout << "BorderColie::Bark()\n";
    }
};
struct Coltriever : public Golden, BorderColie {
    void Bark() override {
        std::cout << "Coltriever::Bark()\n";
    }
};

int main(){

    Dog dog2;
    Dog dog3 = dog2;   // copy constructor by value

    Dog* dog = new Dog;
    Dog* golden = new Golden;
    Dog* borderColie = new BorderColie;;
    // Dog* coltriever = new Coltriever;
    Coltriever* coltriever = new Coltriever;

    dog->Bark();
    golden->Bark();
    borderColie->Bark();
    coltriever->Bark();

    dog = golden;   // pointer reference address


    return 0;
}

/**
 *  +-->Dog<------+
 *  |             |
 * Golden    BorderColie
 * ^               ^
 * |               |
 * +--Coltriever---+
 * 
 * virtual real advantage -> determine type on runtime
 * runtime polymorphism
 */