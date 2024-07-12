#include <iostream>

struct API{
    API(){
    }
    ~API(){
    }

    // Member variable that belonds to each instance
    int m_local;
    static int MAJOR;
    static int MINOR;

    static int GetMajorVerStat(){
        // std::cout << this << std::endl;
        return MAJOR;  // try with m_local
    }
    int GetMajorVerNorm(){
        return MAJOR;
    }

    // when it's static, you're not allowed to work with things specific to instances of classes;

};

int API::MAJOR = 7;

int main(){

    API instance;
    instance.MAJOR += 7; // linker error (if line 13 not there)

    std::cout << "Major              : " << API::MAJOR << '\n';
    std::cout << "Major (static func): " << instance.GetMajorVerStat() << '\n';
    std::cout << "Major (static func): " << API::GetMajorVerStat() << '\n';
    //std::cout << "Major (Norm func): " << API::GetMajorVerNorm() << '\n'; // non-static member function must to relative to a spefific object
    std::cout << "Major (Norm func)  : " << instance.GetMajorVerNorm() << '\n';


    return 0;
}