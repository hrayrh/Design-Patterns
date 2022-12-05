#include <iostream>

class Machine
{
  class State *current;
  public:
    Machine();
    void setCurrent(State *s)
    {
        current = s;
    }
    void on();
    void off();
};

class State
{
  public:
    virtual void on(Machine *m)
    {
        std::cout << "   already ON\n";
    }
    virtual void off(Machine *m)
    {
        std::cout << "   already OFF\n";
    }
};

void Machine::on()
{
  current->on(this);
}

void Machine::off()
{
  current->off(this);
}

class ON: public State
{
  public:
    ON()
    {
        std::cout << "   ON-ctor ";
    };
    ~ON()
    {
        std::cout << "   dtor-ON\n";
    };
    void off(Machine *m);
};

class OFF: public State
{
  public:
    OFF()
    {
        std::cout << "   OFF-ctor ";
    };
    ~OFF()
    {
        std::cout << "   dtor-OFF\n";
    };
    void on(Machine *m)
    {
        std::cout << "   going from OFF to ON";
        m->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Machine *m)
{
  std::cout << "   going from ON to OFF";
  m->setCurrent(new OFF());
  delete this;
}

Machine::Machine()
{
  current = new OFF();
  std::cout << '\n';
}

int main()
{
  Machine m;
  m.on();
}