#include <iostream>
#include <string>

// Prototype
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void show() const = 0;
    virtual ~Prototype() = default;
};

// Concrete Prototype 1
class ConcretePrototype1 : public Prototype {
private:
    std::string name;

public:
    ConcretePrototype1(const std::string& n) : name(n) {}
    Prototype* clone() const override {
        return new ConcretePrototype1(*this);
    }
    void show() const override {
        std::cout << "ConcretePrototype1: " << name << std::endl;
    }
};

// Concrete Prototype 2
class ConcretePrototype2 : public Prototype {
private:
    std::string name;

public:
    ConcretePrototype2(const std::string& n) : name(n) {}
    Prototype* clone() const override {
        return new ConcretePrototype2(*this);
    }
    void show() const override {
        std::cout << "ConcretePrototype2: " << name << std::endl;
    }
};

int main() {
    Prototype* prototype1 = new ConcretePrototype1("Prototype 1");
    Prototype* clone1 = prototype1->clone();
    prototype1->show();
    clone1->show();

    Prototype* prototype2 = new ConcretePrototype2("Prototype 2");
    Prototype* clone2 = prototype2->clone();
    prototype2->show();
    clone2->show();

    delete prototype1;
    delete clone1;
    delete prototype2;
    delete clone2;

    return 0;
}
