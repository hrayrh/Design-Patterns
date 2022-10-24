#include "sonytv.hpp"
#include <iostream>

SonyTV::SonyTV()
{

}

void SonyTV::on()
{
    std::cout<<"sony tv is turned on."<<std::endl;
}
void SonyTV::off()
{
    std::cout<<"sony tv is turned off."<<std::endl;
}

void SonyTV::turnChannel(int channel)
{
    std::cout<<"sony tv is turned to channel "<<channel<<"."<<std::endl;
}
