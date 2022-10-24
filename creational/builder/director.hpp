#pragma once
#include "builder.hpp"

class Director
{

public:
	Director();
	~Director();
	void SetBuilder(Builder* newBuilder);
	void BuildFighter();

private:
	Builder* builder;
};
