#ifndef COMMENTER_HPP
#define COMMENTER_HPP

#include "IComponent.hpp"
#include <iostream>

struct Commenter : IComponent
{
	Commenter(std::string name)
		: name("COMMENTER_" + name)
	{
	}
	const char *getName(const char *prefix)
	{
		resultName = prefix + name;
		return resultName.c_str();
	}
	void execute()
	{
		std::cout << "[" << name << "] Commented" << std::endl;
	}

private:
	std::string resultName;
	std::string name;
};

#endif // !COMMENTER_HPP
