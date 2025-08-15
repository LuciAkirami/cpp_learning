#include <iostream>

/// A `class` in C++
/// ----------------
/// - Groups data members (variables) and member functions (methods).
/// - **Private by default** — members are not accessible from outside unless marked public.
/// - Often used with **encapsulation**, where internal details are hidden and controlled through public methods.
class Point
{
    // PRIVATE MEMBERS (default in class)
    int x; // X-coordinate (accessible only inside this class)
    int y; // Y-coordinate

public:
    /// PUBLIC MEMBER FUNCTIONS (accessible from outside)
    /// Setter function to assign values to `x` and `y`.
    /// - Good practice: Use setters instead of directly assigning values.
    /// - Allows adding validation, logging, or restrictions before changing data.
    void set_x_y(int new_x, int new_y)
    {
        // Example of validation
        if (new_x < -1000 || new_x > 1000 || new_y < -1000 || new_y > 1000)
        {
            std::cout << "Error: Coordinates out of range!\n";
            return;
        }

        x = new_x;
        y = new_y;
    }

    /// Prints the coordinates to the console.
    void print_point()
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }

    /// Getter functions (example)
    int get_x() { return x; }
    int get_y() { return y; }
};

int main()
{
    Point p1;

    // p1.x = 5; // ERROR: `x` is private and cannot be accessed directly.

    // Use setter to modify values
    p1.set_x_y(5, -10);
    p1.print_point();

    // Trying to set invalid values
    p1.set_x_y(5000, 10); // Will trigger error message

    // Using getters to access private values
    std::cout << "\nAccessing via getters: x = " << p1.get_x()
              << ", y = " << p1.get_y() << '\n';

    // Creating another object
    Point p2;
    p2.set_x_y(0, 0);
    p2.print_point();

    return 0;
}
