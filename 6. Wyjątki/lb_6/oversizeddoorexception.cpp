#include "oversizeddoorexception.h"
#include<cmath>
#include<string>
#include"house.h"
struct Room;

OversizedDoorException::OversizedDoorException(float widthDiff,float heightDiff)
    :widthDiff(widthDiff), heightDiff(heightDiff){
    result="Diff in width: "+std::to_string(widthDiff)+", diff in height: "+std::to_string(heightDiff);
}




const char *OversizedDoorException::what() const noexcept{

    return result.c_str();
}


