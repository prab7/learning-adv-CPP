#include "API.hpp"

API::API(){}
API::~API(){}

int API::GetMajorVerStat(){ // static func
    return MAJOR;
}
int API::MAJOR = 7;