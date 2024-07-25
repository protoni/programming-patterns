#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

// Visitor
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) = 0;
    virtual ~Visitor() = default;
};

// Element
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Element() = default;
};

// Concrete Element A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }

    void operationA() {
        std::cout << "ConcreteElementA operation" << std::endl;
    }
};

// Concrete Element B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }

    void operationB() {
        std::cout << "ConcreteElementB operation" << std::endl;
    }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) override {
        element->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* element) override {
        element->operationB();
    }
};

int main() {
    std::vector<Element*> elements = {new ConcreteElementA(), new ConcreteElementB()};
    ConcreteVisitor* visitor = new ConcreteVisitor();

    for (Element* element : elements) {
        element->accept(visitor);
    }

    for (Element* element : elements) {
        delete element;
    }

    delete visitor;

    return 0;
}
