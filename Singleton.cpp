#include <iostream>

class Singleton {
public:
    // Static method to get the singleton instance
    static Singleton& getInstance() {
        // Static local variable to hold the single instance
        static Singleton instance;
        return instance;
    }

    // Example method of the singleton
    void showMessage() {
        std::cout << "Hello, I am a singleton instance!" << std::endl;
    }

private:
    // Private constructor to prevent instantiation
    Singleton() {}
    
    // Private destructor to prevent deletion through pointers
    ~Singleton() {}
    
    // Private copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};

int main() {
    // Get the singleton instance
    Singleton& singleton = Singleton::getInstance();
    
    // Use the singleton
    singleton.showMessage();
    
    return 0;
}
