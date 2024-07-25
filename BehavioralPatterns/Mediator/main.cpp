#include <iostream>
#include <string>
#include <vector>

class Colleague;

class Mediator {
public:
    virtual void send(const std::string& message, Colleague* colleague) = 0;
};

class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* m) : mediator(m) {}
    virtual void receive(const std::string& message) = 0;
};

class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator* m) : Colleague(m) {}

    void send(const std::string& message) {
        mediator->send(message, this);
    }

    void receive(const std::string& message) override {
        std::cout << "Colleague1 received: " << message << std::endl;
    }
};

class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator* m) : Colleague(m) {}

    void send(const std::string& message) {
        mediator->send(message, this);
    }

    void receive(const std::string& message) override {
        std::cout << "Colleague2 received: " << message << std::endl;
    }
};

class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void send(const std::string& message, Colleague* sender) override {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->receive(message);
            }
        }
    }
};

int main() {
    ConcreteMediator* mediator = new ConcreteMediator();
    ConcreteColleague1* colleague1 = new ConcreteColleague1(mediator);
    ConcreteColleague2* colleague2 = new ConcreteColleague2(mediator);

    mediator->addColleague(colleague1);
    mediator->addColleague(colleague2);

    colleague1->send("Hello from Colleague1");
    colleague2->send("Hello from Colleague2");

    delete colleague1;
    delete colleague2;
    delete mediator;

    return 0;
}
