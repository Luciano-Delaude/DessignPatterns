#include <iostream>
#include <vector>

// Forward declaration of Subject class
class Subject;

// Observer interface
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Subject *subject) = 0;
};

// Subject class
class Subject {
public:
    void attach(Observer *observer) {
        observers_.push_back(observer);
    }

    void detach(Observer *observer) {
        // Find and remove the observer from the vector
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end()) {
            observers_.erase(it);
        }
    }

    void notify() {
        for (Observer *observer : observers_) {
            observer->update(this);
        }
    }

    virtual int getState() const = 0;
    virtual void setState(int state) = 0;

private:
    std::vector<Observer*> observers_;
};

// Concrete Subject class
class ConcreteSubject : public Subject {
public:
    int getState() const override {
        return state_;
    }

    void setState(int state) override {
        state_ = state;
        notify(); // Notify observers when the state changes
    }

private:
    int state_;
};

// Concrete Observer class
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(int id) : id_(id) {}

    void update(Subject *subject) override {
        int state = subject->getState();
        std::cout << "Observer " << id_ << " has been notified. New state: " << state << std::endl;
    }

private:
    int id_;
};

int main() {
    // Create a concrete subject
    ConcreteSubject subject;

    // Create concrete observers
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    // Attach observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Set the state of the subject
    subject.setState(10);

    // Detach observer1
    subject.detach(&observer1);

    // Set the state of the subject again
    subject.setState(20);

    return 0;
}
