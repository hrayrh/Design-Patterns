#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

struct IComponent
{
	virtual ~IComponent() {}

	virtual const char *getName(const char* prefix) = 0;

	virtual void execute() = 0;
};

#endif // ICOMPONENT_HPP
