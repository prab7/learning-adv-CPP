#include <iostream>

class UserDefinedType {
    public: 
        UserDefinedType(){
        }
        ~UserDefinedType(){
        }
        UserDefinedType(const UserDefinedType& rhs){
        }
        // move constructor 
        // move-assignment 
        // copy-assignment operator

        void SetValue(int newValue){
            m_value = newValue;
        }

        //void ComputeValue()const{}
        //void ComputeValue(){}
        void ComputeValue(){
            m_value = 10;
        }

        int GetValue() const {
            ComputeValue();
            return m_value;
        }
    
    private:
        int m_value;
}; 

int main(){

    UserDefinedType u;
    u.SetValue(12);
    std::cout << u.GetValue() << std::endl;

    return 0;
}

// const 
// read-only ("immutable") variables
// read-only parameters
// making all of the member-variables in a member-function read-only