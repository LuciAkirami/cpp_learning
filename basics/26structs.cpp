#include <iostream>

/// A `struct` in C++
/// -----------------
/// - Groups related variables (called *members*) into one type.
/// - Unlike classes, struct members are **public by default**.
/// - Each instance (object) has its own copy of the member variables.
///
/// Memory usage:
/// For this struct, `x` and `y` are both `int` (4 bytes each on most systems).
/// So:
///     Total size ≈ 8 bytes
///     (may be slightly more due to padding for alignment)
struct Point
{
    int x; // X-coordinate
    int y; // Y-coordinate

    /// Member function to print the point’s coordinates
    /// - Has access to the object’s own members (`x` and `y`)
    /// - Every object of `Point` can call this function
    void print_point()
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

int main()
{
    // Creating first point object
    Point p1;
    p1.x = 2;         // Assign to x of p1
    p1.y = 5;         // Assign to y of p1
    p1.print_point(); // Calls member function on p1

    // Creating second point object
    Point p2;
    p2.x = -2;        // Assign to x of p2
    p2.y = 10;        // Assign to y of p2
    p2.print_point(); // Calls member function on p2

    // Memory check:
    std::cout << "\nSize of Point struct: " << sizeof(Point) << " bytes\n";

    return 0;
}
