#include <iostream>
#include "API.hpp"

int main(){

    API instance;
    instance.MAJOR += 7;

    std::cout << "Major : " << API::MAJOR << '\n';
    std::cout << "Major : " << API::GetMajorVerStat() << '\n';


    return 0;
}