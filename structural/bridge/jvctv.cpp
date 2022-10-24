#include "jvctv.hpp"
#include <iostream>

void JVCTV::on()
{
    std::cout<<"jvc tv is turn on."<<std::endl;
}
void JVCTV::off()
{
    std::cout<<"jvc tv is turn off."<<std::endl;
}

void JVCTV::turnChannel(int channel)
{
    std::cout<<"jvc tv is turn to channel "<<channel<<"."<<std::endl;
}
