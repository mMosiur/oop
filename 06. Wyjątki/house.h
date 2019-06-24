#ifndef HOUSE_H
#define HOUSE_H

struct Room;
class House
{
    Room *rooms;
    int size;

public:
    House(Room *rooms, int size);
    Room& operator[](int i);

};

#endif // HOUSE_H
