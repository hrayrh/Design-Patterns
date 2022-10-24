#include "F35Builder.hpp"
#include <iostream>

F35Builder::F35Builder()
{
	fighter = new Fighter();
}

F35Builder::~F35Builder()
{

}

void F35Builder::BuildEngine()
{	
	fighter->SetEngine("Pratt & Whitney F135");
	std::cout << "F35 Engine is set\n";
}

void F35Builder::BuildCockpit()
{
	fighter->SetCockpit("glass");
	std::cout << "F35 cockpit is set\n";
}

fighter* F35Builder::getFighter()
{
	return this->fighter;
}
