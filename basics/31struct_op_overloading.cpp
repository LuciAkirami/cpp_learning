#include <iostream>

/*
----------------------------------------------------------------------
OPERATOR OVERLOADING:
----------------------------------------------------------------------
We can overload operators (+, +=, -, etc.) so that they work with our
custom types like they do with built-in types.

Here:
1. `operator+`   → Creates and returns a NEW Point (does not modify the current one).
2. `operator+=`  → Modifies the CURRENT object and returns a reference to it.
*/

struct Point
{
    int x;
    int y;

    // Constructor
    Point(int new_x, int new_y) : x(new_x), y(new_y) {}

    /*
    ------------------------------------------------------------------
    operator+:
    - Takes another Point (rhs) and returns a NEW Point with summed coords.
    - Passed by const reference(`const Point&`) here, thus making it read only
    - Returns by value because we are creating a NEW Point object.
    ------------------------------------------------------------------
    */
    Point operator+(const Point &rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    /*
    ------------------------------------------------------------------
    operator+=:
    - Adds rhs.x, rhs.y to the current object (*this).
    - Returns a REFERENCE (`Point&`) to the current object so that:
        a) We can chain operations like p1 += p2 += p3;
        b) No unnecessary copy is made.
    - `*this` is the current object (type: Point), so `return *this;`
      works because `*this` is an lvalue and matches `Point&` return type.
    ------------------------------------------------------------------
    */
    Point &operator+=(const Point &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this; // 'this' is a pointer (Point*), '*this' is a reference to current object
    }

    // Prints point coordinates
    void print_point() const
    {
        std::cout << "x = " << x << '\n';
        std::cout << "y = " << y << '\n';
    }
};

int main()
{
    Point p1(10, 10);
    Point p2(20, 20);

    std::cout << "=== Using operator+ (returns NEW object) ===\n";
    Point p3 = p1 + p2; // same as p1.operator+(p2)
    p3.print_point();   // p3 = (30, 30)

    std::cout << "\n=== Using operator+= (modifies existing object) ===\n";
    p1 += p2; // p1 = (10,10) + (20,20) = (30,30)
    p1.print_point();

    std::cout << "\n=== Chaining operator+= ===\n";
    Point p4(5, 5);
    Point p5(1, 1);
    p4 += p5 += p2; // p5 first becomes (21, 21), then p4 becomes (26, 26)
    p4.print_point();
    p5.print_point();

    return 0;
}

/*
KEY TAKEAWAYS:
----------------
1. `Point&` in operator+= means "return a reference to the same object"
   so that we can modify and chain operations without copies.
2. `return *this;` works because:
   - `this` is a pointer to the current object (`Point*`)
   - `*this` dereferences it, giving a `Point&`
   - This matches the return type `Point&`.
3. `operator+` is for creating a NEW object without modifying operands.
4. `operator+=` modifies the existing object directly.

THIS
- To understand more about "this", go to 32.cpp and this_keyword.md
*/
