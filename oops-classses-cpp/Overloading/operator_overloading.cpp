#include <iostream>


class Vector3f {
    public: 
        Vector3f(){
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    
        Vector3f operator + (const Vector3f& rhs) const {
            Vector3f result;
            result.x = x + rhs.x;
            result.y = y + rhs.y;
            result.z = z + rhs.z;
            return result;
        }

        // ++ prefix 
        Vector3f operator ++ (){
            x += 1;
            y += 1;
            z += 1;
            return *this;
        }

        // part of class
        bool operator == (const Vector3f& rhs)   { // it doesnt work when i write const instead, wierd.
            std::cout << "part of class" << std::endl;
            if(std::abs(x - rhs.x) < 0.00001 &&   
               std::abs(x - rhs.x) < 0.00001 &&
               std::abs(x - rhs.x) < 0.00001  ) { // because floats 
                return true;
            } 
            return false;
        }


        float x,y,z;
};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj){
    os << obj.x << "," << obj.y << "," << obj.z;
    return os; 
}

// free function (preferred when overloading)
bool operator == (const Vector3f& lhs, const Vector3f& rhs) {
    std::cout << "free function" << std::endl;
    if(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z){
        return true;
    } 
    return false;
}



int main(){

    Vector3f myVector;
    myVector.x = 1.f;
    myVector.y = 2.f;
    myVector.z = 3.f;

    Vector3f myVector2;
    myVector2.x = 3.f;
    myVector2.y = 2.f;
    myVector2.z = 1.f;

    ++myVector;
    ++myVector;
    ++myVector;
    ++myVector;

    myVector = myVector + myVector2;

    std::cout << myVector << std::endl; 
    std::cout << (myVector == myVector2) << std::endl; 

    // caution: floats can't be compared easily

    return 0;
}
















