#include <iostream>

// Subject
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() = default;
};

// Real Subject
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject request" << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(nullptr) {}

    void request() override {
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }
        realSubject->request();
    }

    ~Proxy() {
        delete realSubject;
    }
};

int main() {
    Subject* proxy = new Proxy();
    proxy->request();

    delete proxy;

    return 0;
}
