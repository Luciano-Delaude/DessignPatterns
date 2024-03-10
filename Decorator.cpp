#include <iostream>
#include <memory>

// Component interface
class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() = default;
};

// Concrete component
class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }

    double cost() const override {
        return 1.99;
    }
};

// Decorator abstract class
class CondimentDecorator : public Beverage {
protected:
    std::shared_ptr<Beverage> beverage;

public:
    explicit CondimentDecorator(std::shared_ptr<Beverage> beverage) : beverage(beverage) {}
    ~CondimentDecorator() override = default;
};

// Concrete decorators
class Milk : public CondimentDecorator {
public:
    explicit Milk(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return beverage->cost() + 0.20;
    }
};

class Whip : public CondimentDecorator {
public:
    explicit Whip(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const override {
        return beverage->cost() + 0.10;
    }
};

int main() {
    // Create a base beverage
    std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();
    std::cout << "Description: " << beverage->getDescription() << ", Cost: $" << beverage->cost() << std::endl;

    // Wrap it with Milk
    beverage = std::make_shared<Milk>(beverage);
    std::cout << "Description: " << beverage->getDescription() << ", Cost: $" << beverage->cost() << std::endl;

    // Add Whip
    beverage = std::make_shared<Whip>(beverage);
    std::cout << "Description: " << beverage->getDescription() << ", Cost: $" << beverage->cost() << std::endl;

    return 0;
}
