#ifndef JVCTV_HPP
#define JVCTV_HPP

#include "tv.hpp"
class JVCTV : public TV
{
public:
    JVCTV():TV(){}
    void on();
    void off();
    void turnChannel(int channel = 0);
    virtual ~JVCTV(){}
};

#endif // JVCTV_HPP
