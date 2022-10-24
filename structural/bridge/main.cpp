#include <iostream>
#include "concreteremote.hpp"
#include "jvctv.hpp"
#include "sonytv.hpp"

int main()
{
    TV *tv = new JVCTV();
    ConcreteRemote *remoteControl = new ConcreteRemote(tv);
    remoteControl->on();
    remoteControl->nextChannel();
    remoteControl->previousChannel();
    remoteControl->off();

    delete remoteControl;
    delete tv;


    tv = new SonyTV();
    remoteControl = new ConcreteRemote(tv);
    remoteControl->on();
    remoteControl->nextChannel();
    remoteControl->previousChannel();
    remoteControl->off();

    delete remoteControl;
    delete tv;

    return 0;
}
