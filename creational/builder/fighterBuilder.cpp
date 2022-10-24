#include <iostream>
#include "director.hpp"
#include "F35Builder.hpp"
#include "SU57Builder.hpp"

int main()
{
	Director director;

	SU57Builder SU57builder;
	F35Builder F35builder;


	std::cout << "Building SU57" << std::endl;
	director.SetBuilder(&SU57builder); 
	director.BuildFighter();


	std::cout << "Building F35" << std::endl;
	director.SetBuilder(&F35builder);
	director.BuildFighter();
}
