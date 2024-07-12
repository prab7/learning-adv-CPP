#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>

class Array {
    public:
        // Special Member function
        // (1) Constructor
        Array();
        // (2) Destructor
        ~Array();
        // (4) Copy-Assignment Operator
        Array& operator=(const Array& rhs);

        void PrintingData();
        void SetData(int idx, int value);

        Array(const Array& rhs)=delete;
    private:
        // (3) Copy Constructor
        //Array(const Array& rhs);
        std::vector<int>  data;
};

#endif








