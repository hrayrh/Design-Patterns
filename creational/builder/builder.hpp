#pragma once
#include <string>
#include "fighter.hpp"
class Builder
{	

public:
	Builder();
	~Builder();
	virtual void BuildEngine();
	virtual void BuildCockpit();
	virtual Fighter* GetFighter();
	void BuildFighter();
};

