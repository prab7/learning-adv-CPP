#include <iostream>

class Dogg { // Base class
    public:
        Dogg(){
        }

        void Bark(){
            std::cout << "Woof!" << std::endl;
        }

        void Walk(){
            x+= 1;
            y+= 1;
        }
        
        float x, y;

};

class Golden : public Dogg{
    public:
        void Retrieve(){
            std::cout << "retrieving a stick\n";
            m_stickerRetrieved++;
        }

        float m_stickerRetrieved;
};

class Husky : public Dogg{

};


int main(){

    Golden doggo;   
    doggo.Bark();
    doggo.Walk();

    Husky goodboi;
    goodboi.Bark();

    doggo.Retrieve();

    std::cout << sizeof(Dogg) << std::endl;
    std::cout << sizeof(Golden) << std::endl;

    return 0;
}