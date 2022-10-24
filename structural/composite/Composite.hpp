#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "IComponent.hpp"
#include "List.hpp"
#include <string>

struct Composite : IComponent
{
	Composite(std::string name)
		: components(2),
		  name("LIST_" + name)
	{
	}

	void add(IComponent *component)
	{
		components.add(component);
	}

	const char *getName(const char *prefix = "")
	{
		resultName = prefix;
		resultName += name;
		
		auto pref = std::string(prefix) + " ";

		for (auto component : components)
		{
			resultName += std::string("\n");
			resultName += prefix;
			resultName += component->getName(pref.c_str());
		}

		return resultName.c_str();
	}

	void execute()
	{
		for (auto component : components)
			component->execute();
	}

private:
	List<IComponent *> components;
	std::string name;
	std::string resultName;
};

#endif // COMPOSITE_HPP
