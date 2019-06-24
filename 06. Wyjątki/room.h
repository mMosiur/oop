#ifndef ROOM_H
#define ROOM_H

struct Room{
    float room_height, room_width,room_length;
    float door_height, door_width;

    Room(){}
    Room(float rh, float rw, float rl, float dw, float dh);
private:
    float freeSpace;
public:
    bool setFurniture(float length, float width, float height);
};


#endif // ROOM_H
