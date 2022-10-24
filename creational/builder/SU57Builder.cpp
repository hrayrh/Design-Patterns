#include "SU57Builder.hpp"
#include <iostream>

SU57Builder::SU57Builder()
{
	fighter = new Fighter();
}

SU57Builder::~SU57Builder()
{

}

void SU57Builder::BuildEngine()
{	
	fighter->SetEngine("izdeliye 117");
	std::cout << "SU57 Engine is set\n";
}

void SU57Builder::BuildCockpit()
{	
	fighter->SetCockpit("glass");
	std::cout << "SU57 cockpit is set\n";
}

fighter* SU57Builder::GetFighter()
{
	return this->fighter;
}
