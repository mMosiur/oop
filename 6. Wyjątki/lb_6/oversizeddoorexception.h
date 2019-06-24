#ifndef OVERSIZEDDOOREXCEPTION_H
#define OVERSIZEDDOOREXCEPTION_H
#include<stdexcept>
#include<string>

class OversizedDoorException: public std::exception
{
    float widthDiff, heightDiff;
    std::string result;
public:
    OversizedDoorException(float widthDiff,float heightDiff);
    const char *what() const noexcept;
};

#endif // OVERSIZEDDOOREXCEPTION_H
