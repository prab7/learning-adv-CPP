#include <iostream>

class Base {
    public:
        Base(){
            std::cout << "Base Constructor" << std::endl;
        }
        ~Base(){
            std::cout << "Base Destructor" << std::endl;
        }
    
    public: 
        int m_base_public_member_var;
    protected:
        int m_base_protected_member_var;
    private:
        int m_base_private_member_var;
};

class Derived : protected Base {
    public:
        Derived(){
            std::cout << "Derived Constructor" << std::endl;

            m_base_public_member_var = 123;
            m_base_protected_member_var = 234;
// ERROR    m_base_private_member_var = 345;
        }
        ~Derived(){
            std::cout << "Derived Destructor" << std::endl;
        }
};

int main(){

    Derived d;

// ERROR    d.m_base_public_member_var = 123;      // because protected inheritence
// ERROR    d.m_base_protected_member_var = 234;
// ERROR    d.m_base_private_member_var = 234;

    return 0;
} 
 
/**
 * +--------------+--------------+---------------------+
 * | When the     | When the     | The resulting       | 
 * | component is | class is     | access inside the   |
 * | declared as  | inherited as | subclass is         |
 * +--------------+--------------+---------------------+
 * |   public     |              |      public         |
 * | protected    |    public    |     protected       |
 * |  private     |              |       none          |
 * +--------------+--------------+---------------------+
 * |   public     |              |     protected       |
 * | protected    |  protected   |     protected       |
 * |  private     |              |       none          |
 * +--------------+--------------+---------------------+
 * |   public     |              |      private        |
 * | protected    |   private    |      private        |
 * |  private     |              |       none          |
 * +--------------+--------------+---------------------+
 * 
 * leak as less info as less as possible
 * 
 */


