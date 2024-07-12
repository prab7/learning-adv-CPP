#include <iostream>

struct Point2D {
    Point2D(){
    std::cout << "Point2d Constructor" << std::endl;
    }
    ~Point2D(){
    std::cout << "Point2d Destructor" << std::endl;
    }
    int x, y;
};

//class Character : public Point2D {   // Inheritance- something "is-a" relationship, but it doesnt make that much sense here
class Character {
    public:
        Character(Point2D& ref) : ref_home(ref) {
            std::cout << "Character(ref) Constructor" << std::endl;
            // ref_home = ref; ERROR kyuki uninitialized reference
        }
        Character() : ref_home(m_position){ 
            std::cout << "Character Constructor" << std::endl;
        }
        ~Character(){
            std::cout << "Character Destructor" << std::endl;
        }
    private:
        Point2D m_position;
        Point2D m_direction;
        // composition

        Point2D& ref_home;
        // aggregation
};

int main(){

    Point2D somePoint;
    Character mike(somePoint);


    return 0;
}

// Composition - something "has-a" relationship
// -> lifetime of member variables is tied to the object
// Aggregation - same a composition
// -> lifetime is not necessarily tied to the object