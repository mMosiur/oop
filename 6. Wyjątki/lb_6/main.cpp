#include <iostream>
#include"house.h"
#include"room.h"
#include"oversizeddoorexception.h"

int main()
{
    Room rooms[2]={{2.5,2,4,2,.8},{3,6,8,2.1,1}};
    House h1(rooms,2);
    try{
        h1[-3];
        Room r{2.5,2,4,2,8};

    }
    catch (const OversizedDoorException& err) {
        std::cerr << err.what() << '\n';
    }
    catch (const std::out_of_range& err) {
        std::cerr << err.what() << '\n';
    }



    return 0;
}
