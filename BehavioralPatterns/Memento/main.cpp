#include <iostream>
#include <string>

// Memento
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& s) : state(s) {}

    std::string getState() const {
        return state;
    }
};

// Originator
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& s) {
        state = s;
    }

    std::string getState() const {
        return state;
    }

    Memento* saveStateToMemento() {
        return new Memento(state);
    }

    void getStateFromMemento(Memento* memento) {
        state = memento->getState();
    }
};

// Caretaker
class Caretaker {
private:
    Memento* memento;

public:
    void setMemento(Memento* m) {
        memento = m;
    }

    Memento* getMemento() {
        return memento;
    }
};

int main() {
    Originator* originator = new Originator();
    Caretaker* caretaker = new Caretaker();

    originator->setState("State1");
    std::cout << "Current State: " << originator->getState() << std::endl;
    caretaker->setMemento(originator->saveStateToMemento());

    originator->setState("State2");
    std::cout << "Current State: " << originator->getState() << std::endl;

    originator->getStateFromMemento(caretaker->getMemento());
    std::cout << "Restored State: " << originator->getState() << std::endl;

    delete originator;
    delete caretaker;

    return 0;
}
