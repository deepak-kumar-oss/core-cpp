/*
Encapsulation: Encapsulation is the bundling of data and methods that operate on that data within a single unit, 
such as a class. It allows for data hiding and abstraction, 
which helps to protect the internal state of an object and provides a clear interface for interacting with it.

example of encapsulation:
class BankAccount {
private:
    double balance; // Encapsulated data
public:
    BankAccount(double initialBalance) : balance(initialBalance) {} // Constructor to initialize balance
    void deposit(double amount) { // Method to modify balance
        balance += amount;
    }
    void withdraw(double amount) { // Method to modify balance
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds\n";
        }
    }
    double getBalance() const { // Method to access balance
        return balance;
    }
};

advantages of encapsulation:
1. Data Hiding: Encapsulation allows you to hide the internal state of an object from the outside world,
    which helps to prevent unauthorized access and modification of the data.
2. Abstraction: Encapsulation provides a clear interface for interacting with an object,
    which allows you to focus on what the object does rather than how it does it.
3. Modularity: Encapsulation promotes modularity by allowing you to group related data and methods together,
    which makes it easier to manage and maintain code.
4. Reusability: Encapsulation allows you to create reusable code by defining classes that can be instantiated multiple times with different data.
5. Flexibility: Encapsulation allows you to change the internal implementation of a class without affecting
6. Security: Encapsulation can help to improve security by preventing unauthorized access to sensitive data and methods.

*/

/*
inheritance: Inheritance is a fundamental object-oriented programming concept that allows a 
new class (called a derived class or child class) to inherit properties and behaviors (data members and member functions) 
from an existing class (called a base class or parent class).

example of inheritance:
class Animal {
public:
    void eat() {
        std::cout << "Eating...\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Woof!\n";
    }
};

advantages of inheritance:
1. Code Reusability: Inheritance allows you to reuse existing code from a base class
2. Extensibility: Inheritance allows you to extend the functionality of a base class 
    by adding new data members and member functions in the derived class.
3. Polymorphism: Inheritance enables polymorphism, which allows you to use a base class pointer or reference 
    to refer to objects of derived classes, enabling dynamic method binding.
4. Modularity: Inheritance promotes modularity by allowing you to organize related classes into a class hierarchy, 
    making it easier to manage and maintain code.
5. Abstraction: Inheritance allows you to create abstract classes that define a common interface for derived classes,
    which can help to improve code organization and readability.
6. Overriding: Inheritance allows derived classes to override base class methods, 
    providing a way to customize behavior while still maintaining a common interface.

*/

/*
polymorphism: Polymorphism is a fundamental concept in object-oriented programming that allows objects of
different classes to be treated as objects of a common base class. It enables a single interface to represent different types of objects,
allowing for flexibility and extensibility in code design.

example of polymorphism:
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape...\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle...\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square...\n";
    }
};

void drawShape(Shape* shape) {
    shape->draw(); // Polymorphic call
}

advantages of polymorphism:
1. Flexibility: Polymorphism allows you to write code that can work with objects of different types through a common interface, 
    making it easier to extend and maintain code.

2. Code Reusability: Polymorphism promotes code reusability by allowing you to write functions and methods 
    that can operate on objects of different classes,
    reducing the need for duplicate code.

3. Extensibility: Polymorphism allows you to add new classes that implement a common interface without modifying existing code,
    making it easier to extend functionality.

4. Dynamic Binding: Polymorphism enables dynamic method binding, 
    which allows the correct method to be called at runtime based on the actual type of the object,
    rather than the type of the pointer or reference.

5. Abstraction: Polymorphism allows you to create abstract classes and interfaces 
    that define a common interface for derived classes,
    which can help to improve code organization and readability.
    
6. Improved Maintainability: Polymorphism can improve maintainability by allowing you to change the
implementation of a class without affecting the code that uses it, as long as the interface remains consistent.

*/