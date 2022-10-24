#ifndef DOER_HPP
#define DOER_HPP

#include "IComponent.hpp"
#include <string>
#include <iostream>

struct Doer : IComponent
{
	Doer(std::string name)
		: name("DOER_" + name)
	{
	}
	const char *getName(const char *prefix = "")
	{
		resultName = (prefix + name);
		return resultName.c_str();
	}
	void execute()
	{
		std::cout << "[" << getName() << "] Doer" << std::endl;
	}

private:
	std::string name;
	std::string resultName;
};

#endif // !DOER_HPP
