#include <iostream>

class IBank
{
public:
	virtual void requestMoney() = 0;
	virtual ~IBank() {}
};
 
class ActualBank : public IBank
{
public:
	void requestMoney() { 
		std::cout << "Money is Requested from actual bank!\n"; 
	}
};
 
class RealBank : public IBank
{
private:
	IBank* bank;
public:
	RealBank() : bank (new ActualBank()) 
	{}
	~RealBank() { 
		delete bank; 
	}
	// Forward calls to the RealSubject:
	void requestMoney() { 
		bank->requestMoney(); 
	}
};
 
int main() {
	RealBank b;
	b.requestMoney();
}