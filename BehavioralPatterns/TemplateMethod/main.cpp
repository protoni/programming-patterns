#include <iostream>

// Abstract Class
class AbstractClass {
public:
    void templateMethod() {
        primitiveOperation1();
        primitiveOperation2();
    }

    virtual ~AbstractClass() = default;

protected:
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
};

// Concrete Class A
class ConcreteClassA : public AbstractClass {
protected:
    void primitiveOperation1() override {
        std::cout << "ConcreteClassA: Primitive Operation 1" << std::endl;
    }

    void primitiveOperation2() override {
        std::cout << "ConcreteClassA: Primitive Operation 2" << std::endl;
    }
};

// Concrete Class B
class ConcreteClassB : public AbstractClass {
protected:
    void primitiveOperation1() override {
        std::cout << "ConcreteClassB: Primitive Operation 1" << std::endl;
    }

    void primitiveOperation2() override {
        std::cout << "ConcreteClassB: Primitive Operation 2" << std::endl;
    }
};

int main() {
    AbstractClass* classA = new ConcreteClassA();
    classA->templateMethod();

    AbstractClass* classB = new ConcreteClassB();
    classB->templateMethod();

    delete classA;
    delete classB;

    return 0;
}
