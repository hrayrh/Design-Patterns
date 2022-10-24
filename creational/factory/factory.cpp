#include <iostream>
#include <list>

class Furniture{
public:
    std::string type;
    int height;
    int length;
    int width;

    void display(){
        std::cout<< "type: "<< type<< ", height: "<<height<<", length: "<<length <<", width: "<<width <<std::endl;
    }
};

class Chair{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual std::string getType() const=0;
    virtual ~Chair(){};

};

class VictorianChair: public Chair{
public:
    int getHeight() const {return 10;}
    int getLength() const {return 24;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }

};

class ModernChair: public Chair{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 33;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Modern";
    }

};

class ArtDecoChair: public Chair{
public:
    int getHeight() const {return 11;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArtDeco";
    }

};

class Sofa{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual ~Sofa(){};
    virtual std::string getType() const = 0;
};

class VictorianSofa: public Sofa{
public:
    int getHeight() const {return 10;}
    int getLength() const {return 29;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }
};

class ModernSofa: public Sofa{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 30;}
    int getWidth() const {return 27;}
    std::string getType() const override{
        return "Modern";
    }
};

class ArtDecoSofa: public Sofa{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArtDeco";
    }

};

class CoffeeTable{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual ~CoffeeTable(){};
    virtual std::string getType() const = 0;
};

class VictorianCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 11;}
    int getLength() const {return 20;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }

};

class ModernCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 36;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Modern";
    }

};

class ArtDecoCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 40;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArteDeco";
    }

};

class Factory{
public:
    virtual Chair *CreateChair() const =0;
    virtual Sofa *CreateSofa() const =0;
    virtual CoffeeTable *CreateCoffeeTable() const =0;

};

class VictorianFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new VictorianChair();
    }
    Sofa *CreateSofa() const override{
        return new VictorianSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new VictorianCoffeeTable();
    }

};

class ModernFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new ModernChair();
    }
    Sofa *CreateSofa() const override{
        return new ModernSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new ModernCoffeeTable();
    }

};

class ArtDecoFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new ArtDecoChair();
    }
    Sofa *CreateSofa() const override{
        return new ArtDecoSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new ArtDecoCoffeeTable();
    }

};

void clientCode(const Factory &factory){

    Furniture dictionaryChair;
    const Chair *chair = factory.CreateChair();
    dictionaryChair.type = chair->getType();
    dictionaryChair.width = chair->getWidth();
    dictionaryChair.height = chair->getHeight();
    dictionaryChair.length = chair->getLength();
    dictionaryChair.display();
    delete chair;

    Furniture dictionarySofa;
    const Sofa *sofa = factory.CreateSofa();
    dictionarySofa.type = sofa->getType();
    dictionarySofa.width = sofa->getWidth();
    dictionarySofa.height = sofa->getHeight();
    dictionarySofa.length = sofa->getLength();
    dictionarySofa.display();
    delete sofa;

    Furniture dictionaryCoffeeTable;
    const CoffeeTable *coffeeTable = factory.CreateCoffeeTable();
    dictionaryCoffeeTable.type = coffeeTable->getType();
    dictionaryCoffeeTable.width = coffeeTable->getWidth();
    dictionaryCoffeeTable.height = coffeeTable->getHeight();
    dictionaryCoffeeTable.length = coffeeTable->getLength();
    dictionaryCoffeeTable.display();
    delete coffeeTable;

}


int main() {
    VictorianFabric *Vf = new VictorianFabric();
    clientCode(*Vf);
    delete Vf;

    return 0;
}
