#ifndef SONYTV_HPP
#define SONYTV_HPP

#include "tv.hpp"

class SonyTV : public TV
{
public:
    SonyTV();

    void on();
    void off();
    void turnChannel(int channel = 0);
};

#endif // SONYTV_HPP
