#include <iostream>
#include <string>

// Product
class Product {
private:
    std::string partA;
    std::string partB;
    std::string partC;

public:
    void setPartA(const std::string& part) { partA = part; }
    void setPartB(const std::string& part) { partB = part; }
    void setPartC(const std::string& part) { partC = part; }

    void show() const {
        std::cout << "Product Parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }
};

// Abstract Builder
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getResult() = 0;
};

// Concrete Builder 1
class ConcreteBuilder1 : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder1() { product = new Product(); }
    ~ConcreteBuilder1() { delete product; }

    void buildPartA() override { product->setPartA("PartA1"); }
    void buildPartB() override { product->setPartB("PartB1"); }
    void buildPartC() override { product->setPartC("PartC1"); }

    Product* getResult() override { return product; }
};

// Concrete Builder 2
class ConcreteBuilder2 : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder2() { product = new Product(); }
    ~ConcreteBuilder2() { delete product; }

    void buildPartA() override { product->setPartA("PartA2"); }
    void buildPartB() override { product->setPartB("PartB2"); }
    void buildPartC() override { product->setPartC("PartC2"); }

    Product* getResult() override { return product; }
};

// Director
class Director {
private:
    Builder* builder;

public:
    void setBuilder(Builder* b) { builder = b; }

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;

    ConcreteBuilder1 builder1;
    director.setBuilder(&builder1);
    director.construct();
    Product* product1 = builder1.getResult();
    product1->show();

    ConcreteBuilder2 builder2;
    director.setBuilder(&builder2);
    director.construct();
    Product* product2 = builder2.getResult();
    product2->show();

    return 0;
}
