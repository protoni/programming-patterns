#include <iostream>
#include <vector>

// Command
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Receiver
class Receiver {
public:
    void action() {
        std::cout << "Receiver action" << std::endl;
    }
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* r) : receiver(r) {}

    void execute() override {
        receiver->action();
    }
};

// Invoker
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void storeCommand(Command* command) {
        commands.push_back(command);
    }

    void executeCommands() {
        for (Command* command : commands) {
            command->execute();
        }
    }

    ~Invoker() {
        for (Command* command : commands) {
            delete command;
        }
    }
};

int main() {
    Receiver* receiver = new Receiver();
    Command* command = new ConcreteCommand(receiver);
    Invoker* invoker = new Invoker();

    invoker->storeCommand(command);
    invoker->executeCommands();

    delete receiver;
    delete invoker;

    return 0;
}
