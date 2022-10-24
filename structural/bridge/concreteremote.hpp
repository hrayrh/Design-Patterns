#ifndef CONCRETEREMOTE_HPP
#define CONCRETEREMOTE_HPP
#include "tv.hpp"
#include "remotecontrol.hpp"

class ConcreteRemote : public RemoteControl
{
public:
    ConcreteRemote(TV *tv);
    void nextChannel();
    void previousChannel();
private:
    int currentStation;
};

#endif // CONCRETEREMOTE_HPP
