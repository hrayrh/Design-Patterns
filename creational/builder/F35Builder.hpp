#pragma once
#include "builder.hpp"
#include <string>
#include "fighter.hpp"

class F35Builder : public Builder
{
public:
	F35Builder();
	~F35Builder();
	void BuildEngine();
	void BuildCockpit();
	Fighter* GetFighter();

private:
	Fighter* fighter;
};
