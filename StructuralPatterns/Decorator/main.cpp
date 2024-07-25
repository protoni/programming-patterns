#include <iostream>

// Component
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() = default;
};

// Concrete Component
class ConcreteComponent : public Component {
public:
    void operation() override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Decorator
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* c) : component(c) {}
    
    void operation() override {
        component->operation();
    }
};

// Concrete Decorator A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    void operation() override {
        std::cout << "ConcreteDecoratorA operation" << std::endl;
        Decorator::operation();
    }
};

// Concrete Decorator B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* c) : Decorator(c) {}

    void operation() override {
        std::cout << "ConcreteDecoratorB operation" << std::endl;
        Decorator::operation();
    }
};

int main() {
    Component* component = new ConcreteComponent();
    Component* decoratorA = new ConcreteDecoratorA(component);
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);

    decoratorB->operation();

    delete decoratorB;  // This will also delete decoratorA and component

    return 0;
}
