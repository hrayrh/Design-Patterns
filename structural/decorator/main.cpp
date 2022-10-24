#include <iostream>
class Component {
	public:
		Component(){}
		virtual ~Component() {}
		virtual std::string method() const = 0;
};

class ConcreteComponent : public Component {
	public:
		ConcreteComponent () {
		}
		virtual ~ConcreteComponent() {}
		std::string method() const override {
			return "concrete component";
		}
};

class Decorator : public Component {
	private:
		Component *component_;
	public:
		Decorator(Component *component) : component_(component) {}
		std::string method() const override {
			return component_->method();
		}
};

class ConcreteDecoratorA : public Decorator {
	public:
		ConcreteDecoratorA(Component *component) : Decorator(component) {}
		std::string method() const override{
			return "Decorator A (" + Decorator::method() + ")";
		}
};

class ConcreteDecoratorB : public Decorator {
	public:
		ConcreteDecoratorB( Component *component) : Decorator(component) {}
		std::string method() const override{
			return "Decorator B (" + Decorator::method() + ")";
		}
};

int main(int argc, char *argv[])
{
	ConcreteComponent *concreteComponent = new ConcreteComponent();

	ConcreteDecoratorA *decoratorA = new ConcreteDecoratorA(concreteComponent);

	ConcreteDecoratorB *decoratorB = new ConcreteDecoratorB(decoratorA);

	ConcreteDecoratorB *decoratorC = new ConcreteDecoratorB(concreteComponent);

	Component *component = decoratorB;

	std::cout << component->method() << std::endl;
	std::cout << decoratorA->method() << std::endl;
	std::cout << concreteComponent->method() << std::endl;
	std::cout << decoratorB->method() << std::endl;
	std::cout << decoratorC->method() << std::endl;

	delete decoratorA;
	delete decoratorB;
	delete decoratorC;
	delete concreteComponent;
}
