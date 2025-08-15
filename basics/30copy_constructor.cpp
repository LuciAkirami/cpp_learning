#include <iostream>

/*
----------------------------------------------------------------------
📌 COPY CONSTRUCTOR:
----------------------------------------------------------------------
- A special constructor used to create a new object from an existing one.
- Syntax: `ClassName(const ClassName& other)`
- The `const` ensures the source object is read-only (good practice).
- If you don’t define one, the compiler generates a default copy constructor,
  which performs a shallow copy (member-wise copy).

When do we define our own copy constructor?
-------------------------------------------
- When we have dynamically allocated memory or other resources to copy.
- When we want to customize copy behavior.
*/

struct Point
{
    int x;
    int y;

    // Normal constructor
    Point(int new_x, int new_y) : x(new_x), y(new_y) {}

    // User-defined Copy Constructor
    Point(const Point &p)
    {
        std::cout << "Copy Constructor Called\n";
        x = p.x;
        y = p.y;
    }

    // If you want to DISABLE copying, uncomment below:
    // Point(const Point &p) = delete;

    // Prints point coordinates
    void print_point() const
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

/*
----------------------------------------------------------------------
Example: Struct where copying is NOT allowed
----------------------------------------------------------------------
- We can delete the copy constructor (and copy assignment operator).
- This is useful when:
    1. An object owns a resource that must not be duplicated (like file handles, sockets, or memory with unique ownership).
    2. Example: `std::unique_ptr` has its copy constructor deleted to ensure only ONE owner at a time.
*/

struct NonCopyable
{
    int data;

    NonCopyable(int value) : data(value) {}

    // Delete copy constructor
    NonCopyable(const NonCopyable &) = delete;

    // Delete copy assignment
    // NonCopyable &operator=(const NonCopyable &) = delete;

    void print() const
    {
        std::cout << "Data = " << data << '\n';
    }
};

int main()
{
    std::cout << "=== Copy Constructor Example ===\n";
    Point p1(10, 1);
    p1.print_point();

    std::cout << '\n';

    // Calls our copy constructor
    Point p2 = p1;
    p2.print_point();

    std::cout << "\n=== Non-Copyable Example ===\n";
    NonCopyable nc1(42);
    nc1.print();

    // The following line will cause a compile-time ERROR because copying is deleted
    // NonCopyable nc2 = nc1;

    return 0;
}

/*
KEY TAKEAWAYS:
----------------
1. Copy constructors allow controlled copying of objects.
2. Use `const` in copy constructors to avoid modifying the source object.
3. Deleting copy constructors prevents accidental duplication of resources.
4. `std::unique_ptr` deletes its copy constructor — because unique ownership must not be shared.
5. If your object manages a non-shareable resource → delete copy constructor.

REFERENCES:
----------------
- https://en.cppreference.com/w/cpp/language/copy_constructor.html
*/
