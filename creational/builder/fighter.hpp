#pragma once
#include <string>

class Fighter
{
public:
	Fighter();
	~Fighter();
	virtual void SetEngine(std::string Engine);
	virtual void SetCockpit(std::string Cockpit);

private:
	std::string Engine, Cockpit;
};

