#include <iostream>

class TargetCircle
{
public:
	virtual ~TargetCircle() {}
	virtual void draw() = 0;
};

class AdapteeCircle
{
private:
	double m_radius;
public:
	~AdapteeCircle(){}
	AdapteeCircle(double radius) : m_radius(radius)
	{
		std::cout << "Adaptee Circle with radius " << m_radius << " created." << std::endl;
	}

	void oldDraw()
	{
		std::cout << "Adaptee Circle has been drawn with radius "<< m_radius <<"." << std::endl;
	}

};

class CircleAdapter: public TargetCircle, private AdapteeCircle
{
public:
	CircleAdapter(double diameter) : AdapteeCircle(diameter / 2)
	{
		std::cout << "Circle Adapter created circle with diameter " << diameter << "." << std::endl;
	}
	void draw()override
	{
		std::cout << "Circle Adapter adapted method draw() from Target Circle for Adaptee Circle:" << std::endl;
		oldDraw();
	}
};



int main()
{
	TargetCircle* circle = new CircleAdapter(10);
	circle->draw();
	delete circle;
	return 0;
}
