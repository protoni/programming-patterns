#include <iostream>

class Target {
public:
    virtual void request() {
        std::cout << "Target request" << std::endl;
    }
};

class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee specific request" << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();
    delete adaptee;
    delete target;
    return 0;
}
