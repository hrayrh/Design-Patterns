#include "director.hpp"
#include "builder.hpp"

Director::Director()
{

}

Director::~Director()
{

}

void Director::SetBuilder(Builder* newBuilder)
{
	builder = newBuilder;
}


void Director::BuildFighter()
{
	builder->BuildEngine();
	builder->BuildCockpit();
}
