#include <iostream>
#include <vector>

// Iterator
template <typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};

// Concrete Iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T>& collection;
    size_t index;

public:
    ConcreteIterator(std::vector<T>& c) : collection(c), index(0) {}

    bool hasNext() override {
        return index < collection.size();
    }

    T next() override {
        return collection[index++];
    }
};

// Aggregate
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
    virtual ~Aggregate() = default;
};

// Concrete Aggregate
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> collection;

public:
    void add(const T& item) {
        collection.push_back(item);
    }

    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(collection);
    }
};

int main() {
    ConcreteAggregate<int> aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);

    Iterator<int>* iterator = aggregate.createIterator();
    while (iterator->hasNext()) {
        std::cout << "Item: " << iterator->next() << std::endl;
    }

    delete iterator;

    return 0;
}
