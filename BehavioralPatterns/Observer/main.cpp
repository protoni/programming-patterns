#include <iostream>
#include <list>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::list<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.remove(observer);
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

class ConcreteObserver : public Observer {
private:
    std::string name;
    Subject* subject;

public:
    ConcreteObserver(std::string name, Subject* subject) : name(name), subject(subject) {}

    void update() override {
        std::cout << "Observer " << name << " updated" << std::endl;
    }
};

int main() {
    Subject* subject = new Subject();

    Observer* observer1 = new ConcreteObserver("Observer 1", subject);
    Observer* observer2 = new ConcreteObserver("Observer 2", subject);

    subject->attach(observer1);
    subject->attach(observer2);

    subject->notify();

    subject->detach(observer1);

    subject->notify();

    delete observer1;
    delete observer2;
    delete subject;

    return 0;
}
