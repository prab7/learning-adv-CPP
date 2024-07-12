#include <iostream>
#include <utility>

int main(){
    std::string myString = "copy construct here";
    std::string newValue;

    std::cout << "myString:  " <<  myString << std::endl;
    std::cout << "newValue:  " <<  newValue << std::endl;

    newValue = std::move(myString); // stealing the value from the resource, literally re-assigning
    // explicitly whats being done here:
    newValue = static_cast<std::string&&>(myString);

    std::cout << "myString:  " <<  myString << std::endl;
    std::cout << "newValue:  " <<  newValue << std::endl;

    return 0;
}