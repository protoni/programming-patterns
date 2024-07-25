#include <iostream>
#include <string>
#include <map>

// Context
class Context {
public:
    std::map<std::string, int> variables;
};

// Abstract Expression
class AbstractExpression {
public:
    virtual int interpret(Context& context) = 0;
    virtual ~AbstractExpression() = default;
};

// Number Expression
class NumberExpression : public AbstractExpression {
private:
    int number;

public:
    NumberExpression(int n) : number(n) {}

    int interpret(Context& context) override {
        return number;
    }
};

// Variable Expression
class VariableExpression : public AbstractExpression {
private:
    std::string name;

public:
    VariableExpression(const std::string& n) : name(n) {}

    int interpret(Context& context) override {
        return context.variables[name];
    }
};

// Add Expression
class AddExpression : public AbstractExpression {
private:
    AbstractExpression* leftExpression;
    AbstractExpression* rightExpression;

public:
    AddExpression(AbstractExpression* left, AbstractExpression* right) 
        : leftExpression(left), rightExpression(right) {}

    int interpret(Context& context) override {
        return leftExpression->interpret(context) + rightExpression->interpret(context);
    }

    ~AddExpression() {
        delete leftExpression;
        delete rightExpression;
    }
};

int main() {
    Context context;
    context.variables["x"] = 5;
    context.variables["y"] = 10;

    AbstractExpression* expression = new AddExpression(
        new VariableExpression("x"),
        new NumberExpression(20)
    );

    std::cout << "Result: " << expression->interpret(context) << std::endl;

    delete expression;

    return 0;
}
