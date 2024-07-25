#include <iostream>
#include <string>
#include <unordered_map>

// Flyweight
class Flyweight {
private:
    std::string intrinsicState;

public:
    Flyweight(const std::string& state) : intrinsicState(state) {}

    void operation(const std::string& extrinsicState) {
        std::cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << std::endl;
    }
};

// Flyweight Factory
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new Flyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() {
        for (auto pair : flyweights) {
            delete pair.second;
        }
    }
};

int main() {
    FlyweightFactory* factory = new FlyweightFactory();

    Flyweight* flyweight1 = factory->getFlyweight("State1");
    flyweight1->operation("ExtrinsicState1");

    Flyweight* flyweight2 = factory->getFlyweight("State1");
    flyweight2->operation("ExtrinsicState2");

    Flyweight* flyweight3 = factory->getFlyweight("State2");
    flyweight3->operation("ExtrinsicState3");

    delete factory;

    return 0;
}
