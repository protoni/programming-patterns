#include <iostream>
#include <vector>

// Component
class Component {
public:
    virtual void operation() = 0;
};

// Leaf
class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;
        for (Component* child : children) {
            child->operation();
        }
    }
};

int main() {
    Composite* composite = new Composite();
    composite->add(new Leaf());
    composite->add(new Leaf());

    Composite* subComposite = new Composite();
    subComposite->add(new Leaf());
    composite->add(subComposite);

    composite->operation();

    delete composite;  // Note: In a real application, you'd need to properly delete all children

    return 0;
}
