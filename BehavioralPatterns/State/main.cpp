#include <iostream>

class State; // Forward declaration of State

// Context
class Context {
private:
    State* state;

public:
    Context(State* s);
    void setState(State* s);
    void request();
    ~Context();
};

// State
class State {
public:
    virtual void handle(Context* context) = 0;
    virtual ~State() = default;
};

// Concrete State A
class ConcreteStateA : public State {
public:
    void handle(Context* context) override;
};

// Concrete State B
class ConcreteStateB : public State {
public:
    void handle(Context* context) override {
        std::cout << "State B handling" << std::endl;
        context->setState(new ConcreteStateA());
        delete this;
    }
};

// Definitions after State class is fully defined
Context::Context(State* s) : state(s) {}

void Context::setState(State* s) {
    state = s;
}

void Context::request() {
    state->handle(this);
}

Context::~Context() {
    delete state;
}

void ConcreteStateA::handle(Context* context) {
    std::cout << "State A handling" << std::endl;
    context->setState(new ConcreteStateB());
    delete this;
}

int main() {
    Context* context = new Context(new ConcreteStateA());
    context->request();
    context->request();

    delete context;

    return 0;
}
