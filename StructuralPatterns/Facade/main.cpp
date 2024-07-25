#include <iostream>

// Subsystem classes
class Subsystem1 {
public:
    void operation1() const {
        std::cout << "Subsystem1: Operation 1" << std::endl;
    }
    void operation2() const {
        std::cout << "Subsystem1: Operation 2" << std::endl;
    }
};

class Subsystem2 {
public:
    void operation1() const {
        std::cout << "Subsystem2: Operation 1" << std::endl;
    }
    void operation2() const {
        std::cout << "Subsystem2: Operation 2" << std::endl;
    }
};

// Facade class
class Facade {
private:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;

public:
    Facade() {
        subsystem1 = new Subsystem1();
        subsystem2 = new Subsystem2();
    }
    ~Facade() {
        delete subsystem1;
        delete subsystem2;
    }

    void operation() const {
        std::cout << "Facade initializes subsystems:" << std::endl;
        subsystem1->operation1();
        subsystem2->operation1();
        std::cout << "Facade orders subsystems to perform the action:" << std::endl;
        subsystem1->operation2();
        subsystem2->operation2();
    }
};

int main() {
    Facade* facade = new Facade();
    facade->operation();
    delete facade;

    return 0;
}
