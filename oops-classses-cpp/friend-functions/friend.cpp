#include <iostream>

class PrivateSecurityInformation{
    friend class UserDefinedType; //securtiy risk
    private:
        int passcode;
};

class UserDefinedType {
    public:
        UserDefinedType(): m_privateMemberVariable(0) {
            m_info.passcode = 7;
        };

    private:
        int m_privateMemberVariable;
        PrivateSecurityInformation m_info;

    friend void PrintPivateMemberVariablesOfUDT(UserDefinedType u);
};

void PrintPivateMemberVariablesOfUDT(UserDefinedType u){
    std::cout << u.m_privateMemberVariable << std::endl;
}

int main(){

    UserDefinedType instance;

    return 0;
} 

/**
 * general rule : don't use them
 * 
 * - usually used in operator overloading 
 */