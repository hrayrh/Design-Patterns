#include <iostream>

class Water
{

public:
    void fill() { std::cout << "Water is filled\n"; }

};

class Milk
{

public:
    void fill() { std::cout << "Milk is filled\n"; }

};

class Chocolate
{
    
public:
    void fill() { std::cout << "Chocolate is filled\n"; }
    
};

// Facade
class SmartCoffeeMaker
{

private:
    Water water;
    Milk milk;
    Chocolate chocolate;

public:
    void CappuccinoMaker()
    {
        water.fill();
        milk.fill();
        std::cout << "Cappuccino is ready!\n\n";
    }
    
    void GlasseMaker()
    {
        water.fill();
        chocolate.fill();
        std::cout << "Glasse is ready!\n\n";
    }    

};

int main()
{
    SmartCoffeeMaker machine;
    machine.CappuccinoMaker();
    machine.GlasseMaker();
    
    return 0;
}