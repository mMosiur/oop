#include "room.h"
#include<algorithm>
#include"oversizeddoorexception.h"

Room::Room(float rh, float rw, float rl, float dw, float dh)
    :room_height(rh), room_length(rl), room_width(rw), door_height(dh), door_width(dw)
{
    if(rh<=0 || rw<=0 || rl <=0 || dh<=0|| dw<=0)
        throw std::range_error("Dimensions must be positive!");
    if(dh>rh || dw>rw)
        throw OversizedDoorException(rw-dw,rh-dh);
    freeSpace=rw*rl;

}

