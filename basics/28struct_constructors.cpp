#include <iostream>

struct Point
{
    int x; // 4 bytes
    int y; // 4 bytes
    // Total = 8 bytes (no padding needed here)

    /*
    ------------------------------------------------------------------
    CONSTRUCTORS IN C++
    ------------------------------------------------------------------
    1. Default constructor:
       - Automatically generated if you don't define *any* constructor.
       - Creates the object without requiring parameters.
       - If you define a custom constructor, you must explicitly define
         the default one if you still want it.
       Example:
           Point() {} // explicitly defined

    2. Parameterized constructor:
       - Allows passing/setting of values at object creation time.
       - Two main styles:
            a) Initialization list (recommended for efficiency)
            b) Assignment inside constructor body (less efficient)
       - Prevents having to set members manually after creation.

    3. Initialization list:
       - Syntax: Point(int a, int b) : x(a), y(b) {}
       - More efficient than assigning inside constructor body,
         because it initializes variables directly instead of
         first creating them with default values and then reassigning.
       - Directly initializes members as they are created.
       - Avoids unnecessary default-initialization + reassignment.
    ------------------------------------------------------------------
    */

    // Parameterized constructor (using initialization list)
    Point(int new_x, int new_y) : x(new_x), y(new_y) {}

    // (Commented out) Another way — assignment inside constructor body
    // Point(int new_x, int new_y)
    // {
    //     x = new_x; // first default-constructed, then reassigned
    //     y = new_y;
    // }

    // Explicitly enabling default constructor
    // If not present, "Point p;" will not compile if only the above
    // parameterized constructor exists.
    Point() = default;

    // Member function to print values
    void print_point()
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

int main()
{
    // Using parameterized constructor
    Point p(10, 1);
    p.print_point();

    std::cout << '\n';

    // Using default constructor (x & y will have indeterminate values for POD types like int)
    // In this case, since we used `= default;`, nothing sets x and y.
    Point p2;
    p2.x = 5;
    p2.y = 8;
    p2.print_point();

    std::cout << '\n';

    // Example: Creating with parameterized constructor again
    Point p3{-3, 42}; // uniform initialization (C++11 feature)
    p3.print_point();

    return 0;
}

/*
MEMORY NOTE:
----------------
struct Point
{
    int x; // 4 bytes
    int y; // 4 bytes
};
- On a 64-bit system, sizeof(Point) = 8 bytes
- No padding because both members are int (aligned to 4 bytes)

KEY TAKEAWAYS:
-----------------
- Constructors are special functions used to initialize objects.
- Default constructor allows creating objects with no parameters.
- Initialization lists are preferred for efficiency.
- If you define *any* constructor, the compiler won't generate a default one
  unless you explicitly declare it.

REFERENCE:
----------------
- https://en.cppreference.com/w/cpp/language/initializer_list.html

The same applies for Classes as well
*/
