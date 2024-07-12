#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>

class Array {
    public:
        // Special Member function
        // (1) Constructor
        Array();
        // (2) Destructor
        //~Array();
        // (3) Copy Constructor
        Array(const Array& rhs);
        // (4) Copy-Assignment Operator
        Array& operator=(const Array& rhs);

        void PrintingData();
        void SetData(int idx, int value);

    private:
        std::vector<int>  data;
};

#endif








