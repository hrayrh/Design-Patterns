#include "Composite.hpp"
#include "Doer.hpp"
#include "Commenter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	auto mainComponent = new Composite("main");
	auto secondaryComposite = new Composite("secondary");
	auto firstDoer = new Doer("1");
	auto secondDoer = new Doer("2");
	auto thirdDoer = new Doer("3");

	auto lastCommenter = new Commenter("nobody");

	mainComponent->add(firstDoer);
	mainComponent->add(secondaryComposite);
	mainComponent->add(lastCommenter);

	secondaryComposite->add(secondDoer);
	secondaryComposite->add(thirdDoer);

	std::cout << "Application structure:" << std::endl;
	std::cout << mainComponent->getName() << std::endl;

	mainComponent->execute();

	return 0;
}
