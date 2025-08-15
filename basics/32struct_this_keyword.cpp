#include <iostream>
#include <string>

// A struct in C++ can have methods just like a class.
// The only difference is that struct members are public by default.
// In C++, inside any non-static member function of a struct or class, "this" is a hidden pointer that points to the current object.
struct Point
{
    int x, y; // member variables

    // 1. Using 'this' to disambiguate between member variables and parameters
    void set(int x, int y)
    {
        // 'this' is a pointer to the current object
        // this->x means "the member variable x of the current object"
        this->x = x;
        this->y = y;
    }

    // 2. Returning *this by reference to allow method chaining
    Point &setX(int x)
    {
        this->x = x;  // set member variable x
        return *this; // return the current object as a reference
    }

    Point &setY(int y)
    {
        this->y = y;  // set member variable y
        return *this; // same object, no copy
    }

    // 3. A const method that does not modify the object
    void print() const
    {
        // 'this' is of type 'const Point*' here
        std::cout << "(" << this->x << ", " << this->y << ")\n";
    }
};

// Another example: using 'this' in a struct with strings
struct Person
{
    std::string name;

    // Returns a reference to the name so it can be modified by the caller
    std::string &getName()
    {
        return this->name; // same as just 'name', but shows use of this
    }

    // Const version: returns a const reference (read-only)
    const std::string &getName() const
    {
        return this->name;
    }

    // Set the name and return *this to allow chaining
    Person &setName(const std::string &newName)
    {
        this->name = newName;
        return *this;
    }
};

int main()
{
    // --- Example with Point ---
    Point p;
    p.set(1, 2); // uses 'this' to set members
    p.print();   // prints (1, 2)

    // Method chaining with returned *this
    p.setX(10).setY(20).print(); // prints (10, 20)

    // --- Example with Person ---
    Person person;
    person.setName("Alice").getName() = "Bob"; // modify name directly
    // person.getName() = "Nanioii"; allowed
    std::cout << person.getName() << "\n"; // prints Bob

    // Using const Person with const getName()
    const Person cp = person;
    // cp.getName() = "Alice"; not allowed
    std::cout << cp.getName() << "\n"; // read-only access
}
