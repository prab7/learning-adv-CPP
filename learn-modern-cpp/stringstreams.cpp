// stringstreams
#include <iostream>
#include <string>
#include <sstream>

int main ()
{
    std::string mystr;
    float price=0;
    int quantity=0;

    std::cout << "Enter price: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> price;
    std::cout << "Enter quantity: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> quantity;
    std::cout << "Total price: " << price*quantity << std::endl;

    int x = 5;

    switch (x) {
        case 1:
        case 2:
        case 3:
            std::cout << "x is 1, 2 or 3";
            break;
        default:
            std::cout << "x is not 1, 2 nor 3";
        }

    return 0;
}