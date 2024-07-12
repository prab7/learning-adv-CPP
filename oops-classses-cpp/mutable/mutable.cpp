#include <iostream>
#include <vector>
#include <mutex>

struct Point3f {

    explicit Point3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z), w(1.0f){
    }
    void ChangeW(float newW) const {
        // x = 1;
        w = newW;
    }

    float x, y, z;
    mutable float w;
};

// cppref example - concurrency
class ThreadsafeCounter {

    mutable std::mutex m;  // M&M rule
    int data = 0;

public:
    int get() const {
        std::lock_guard<std::mutex> lk(m);
        return data;
    }
    void inc(){
        std::lock_guard<std::mutex> lk(m);
        data++;
    }
};

int main(){

    Point3f p{1.0f, 2.0f, 3.0f};
    p.ChangeW(5.0f);

    std::cout << p.x << '\n' << p.y << '\n' 
              << p.z << '\n' << p.w << '\n'; 

    return 0;
}