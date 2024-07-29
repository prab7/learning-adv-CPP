#include <iostream>

namespace A {
    int i;
}

namespace B {
    int i;
    int j;
    
    namespace C {
        
        namespace D {
            
            using namespace A; // all names from A injected into global namespace

            int j; 
            int k;
            int a = 1;        // i is B::i, because A::i is hidden by B::i;
        }
        using namespace D; // names from D are injected into C
                           // names from A are injected into global namespace

        int k = 89; // OK to declare name identicle to one introduced by a using
        // int l = k;  // ambiguous: C::K or D::K
        int m = i;  // ok: B::i hides A::i
        int n = j;  // ok: D::j hides B::j
    }
}

/**
 * Uses of using keyword:
 * 1. using namespace std;
 * 2. type alias - something like typedef, prefer using over typedef
 */

// typedef void void_t;
// equivalent as below 
using void_t = void;

void foo(){
    using std::cout;
    cout << "will this work?\n";
}

int main(){

    using namespace std;
    cout << "Mike's Modern C++ Series\n";

    return 0;
}