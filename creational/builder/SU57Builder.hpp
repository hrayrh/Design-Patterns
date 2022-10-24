#pragma once
#include "builder.hpp"
#include <string>
#include "fighter.hpp"

class SU57Builder : public Builder
{
public:
	SU57Builder();
	~SU57Builder();
	void BuildEngine();
	void BuildCockpit();
	Fighter* GetFighter();

private:
	Fighter* fighter;
};
