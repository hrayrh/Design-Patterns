#include<iostream>
 
class AtmHandler
{
 
AtmHandler* m_suc;
public:
    AtmHandler(AtmHandler* s = nullptr): m_suc(s){}
    ~AtmHandler(){} 
    virtual void HandleRequest(int amt);
};
void AtmHandler::HandleRequest(int amt)
{ 
    if(m_suc)
    m_suc->HandleRequest(amt);
}
 
//50 Dollar Handler
class Dollar50Handler: public AtmHandler
{
 
public:
    Dollar50Handler(AtmHandler* s = nullptr): AtmHandler(s){}
    ~Dollar50Handler(){}
    void HandleRequest(int amt);
};
void Dollar50Handler::HandleRequest(int amt)
{
    if(amt%50 == 0)
    {
        std::cout << "Number of 50 Dollar: " << amt/50 << "\n";
        std::cout << "Request is completed so no need to forward it\n\n";
    }
    else
    {
        int numberOf50Dollar= amt/50;
        std::cout << "Number of 50 Dollar: " << numberOf50Dollar << "\n";
        amt = amt-numberOf50Dollar*50;
        AtmHandler::HandleRequest(amt);
    }
}
 
class Dollar20Handler: public AtmHandler
{
 
public:
    Dollar20Handler(AtmHandler* s = nullptr): AtmHandler(s){}
    ~Dollar20Handler(){}
    void HandleRequest(int amt);
};
void Dollar20Handler::HandleRequest(int amt)
{
    if(amt%20 == 0)
    {
        std::cout << "Number of 20 Dollar: " << amt/20 << "\n";
        std::cout << "Request is completed so no need to forward it\n\n";
    }
    else
    {
        int numberOf20Dollar= amt/20;
        std::cout << "Number of 20 Dollar: " << numberOf20Dollar << "\n";
        amt = amt-numberOf20Dollar*20;
        AtmHandler::HandleRequest(amt);
    }
}
 
class Dollar10Handler: public AtmHandler
{
 
public:
    Dollar10Handler(AtmHandler* s = nullptr): AtmHandler(s){}
    ~Dollar10Handler(){}
    void HandleRequest(int amt);
};

void Dollar10Handler::HandleRequest(int amt)
{
    if(amt%10 == 0)
    {
        std::cout << "Number of 10 Dollar:" << amt/10 << "\n";
        std::cout << "Request is completed so no need to forward it\n\n";
    }
    else
    {
        std::cout << "Cannot withdraw this!\n";
    }
}
 
int main()
{
    //Chain of Responsibility
    
    Dollar10Handler* p10 = new Dollar10Handler;
    Dollar20Handler* p20 = new Dollar20Handler(p10);
    Dollar50Handler* p50 = new Dollar50Handler(p20);
    
    AtmHandler* atm = new AtmHandler(p50);
    
    std::cout << "Request of withdrawing 230 Dollars\n";
    atm->HandleRequest(230);
 
    std::cout << "Request of withdrawing 245 Dollars\n";
    atm->HandleRequest(245);
 
    return 0;
}