#include <iostream>


class Collection {
    public: 
        Collection(){
            data = new int[10];
            //fopen("notes.txt");
            try {
                throw 20;
            } catch (int e) {
                // some error message
            }
        }
        ~Collection(){
            // destructor is still called after error message (RAII)
            std::cout << "destructor is called" << std::endl;
            delete[] data;
            //fclose("notes.txt");
        }

        int& operator[](std::size_t idx){
            return data[idx];
        }
        const int& operator[](std::size_t idx) const {
            return data[idx];
        }

    private:
        int* data;
};



int main(){

    Collection myCollection;
    myCollection[0] = 7;
    myCollection[1] = 7;
    myCollection[2] = 7;

    std::cout << myCollection[0] << std::endl;

    return 0;
}