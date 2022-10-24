#ifndef TV_HPP
#define TV_HPP

class TV
{
public:
    TV();
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void turnChannel(int channel)=0;
};

#endif // TV_HPP
