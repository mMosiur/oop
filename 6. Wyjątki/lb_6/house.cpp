#include "house.h"
#include<cstring>
#include<stdexcept>
#include"room.h"


House::House(Room *rooms,int size):size(size)
{
    this->rooms=new Room[size];
    memcpy(this->rooms,rooms,this->size*sizeof(Room));
}

Room &House::operator[](int i)
{
    if(i<0 || i>=size)
        throw std::out_of_range(std::to_string(i)+" is out of range");
    return rooms[i];
}
