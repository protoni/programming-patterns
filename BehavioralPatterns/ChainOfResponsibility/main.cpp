#include <iostream>
#include <string>

// Handler
class Handler {
protected:
    Handler* successor;

public:
    Handler() : successor(nullptr) {}

    void setSuccessor(Handler* s) {
        successor = s;
    }

    virtual void handleRequest(const std::string& request) = 0;

    virtual ~Handler() = default;
};

// Concrete Handler 1
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request1") {
            std::cout << "ConcreteHandler1 handled " << request << std::endl;
        } else if (successor) {
            successor->handleRequest(request);
        }
    }
};

// Concrete Handler 2
class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Request2") {
            std::cout << "ConcreteHandler2 handled " << request << std::endl;
        } else if (successor) {
            successor->handleRequest(request);
        }
    }
};

int main() {
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();

    handler1->setSuccessor(handler2);

    handler1->handleRequest("Request1");
    handler1->handleRequest("Request2");
    handler1->handleRequest("Request3");

    delete handler1;
    delete handler2;

    return 0;
}
