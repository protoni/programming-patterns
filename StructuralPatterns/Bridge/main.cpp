#include <iostream>

// Implementor
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// Concrete Implementor A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorA operation" << std::endl;
    }
};

// Concrete Implementor B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorB operation" << std::endl;
    }
};

// Abstraction
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() {
        implementor->operationImpl();
    }

    virtual ~Abstraction() {
        delete implementor;
    }
};

// Refined Abstraction
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Abstraction* abstractionA = new RefinedAbstraction(implA);
    abstractionA->operation();

    Implementor* implB = new ConcreteImplementorB();
    Abstraction* abstractionB = new RefinedAbstraction(implB);
    abstractionB->operation();

    delete abstractionA;
    delete abstractionB;

    return 0;
}
