#include <iostream>

// Strategy
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() = default;
};

// Concrete Strategy A
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// Concrete Strategy B
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// Context
class Context {
private:
    Strategy* strategy;

public:
    void setStrategy(Strategy* s) {
        strategy = s;
    }

    void executeStrategy() {
        strategy->execute();
    }

    ~Context() {
        delete strategy;
    }
};

int main() {
    Context* context = new Context();

    context->setStrategy(new ConcreteStrategyA());
    context->executeStrategy();

    context->setStrategy(new ConcreteStrategyB());
    context->executeStrategy();

    delete context;

    return 0;
}
