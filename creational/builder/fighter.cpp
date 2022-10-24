#include "fighter.hpp"

Fighter::Fighter()
{
}

Fighter::~Fighter()
{
}

void Fighter::SetEngine(std::string Engine)
{
	this->Engine = Engine;
}

void Fighter::SetCockpit(std::string Cockpit)
{	
	this->Cockpit = Cockpit;
}
