#include <iostream>

class Product {
public:
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;

    void anOperation() {
        Product* product = factoryMethod();
        product->use();
        delete product;
    }
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    creatorA->anOperation();
    delete creatorA;

    Creator* creatorB = new ConcreteCreatorB();
    creatorB->anOperation();
    delete creatorB;

    return 0;
}
