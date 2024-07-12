#include <iostream>


class Vector3f {
    public: 
        Vector3f(): x(1.0f), y(z), z(1.0f){ // garbage value

        }

        float x,y,z; // because of this order
};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj){
    os << obj.x << "," << obj.y << "," << obj.z;
    return os; 
}


int main(){

    Vector3f myVector;

    std::cout << myVector << std::endl; 



    return 0;
}
















