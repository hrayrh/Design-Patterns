#ifndef REMOTECONTROL_HPP
#define REMOTECONTROL_HPP

#include "tv.hpp"

class RemoteControl
{
public:
    RemoteControl(TV *tv);
    void on();
    void off();
    void setChannel(int channel);
private:
    TV *tv;
};

#endif // REMOTECONTROL_HPP
