#ifndef INTARRAY_HPP 
#define INTARRAY_HPP 

#include <string>

class IntArray {
    public:
        // The Big 3
        // (1) Constructor
        IntArray(std::string name);
        // (2) Destructor 
        ~IntArray();
        // (3) Copy Constructor policy
        IntArray(const IntArray& rhs);
        // Copy Assignment operator policy
        IntArray& operator = (const IntArray& rhs);

        // Other 2;
        // (4) Move Constructor policy
//        IntArray(IntArray&& source) = delete;
        IntArray(IntArray&& source);
        // (5) Move Assignmnet operator policy
        IntArray& operator = (IntArray&& source);
    
    private:
        std::string m_name;
        int* m_data;
};

#endif