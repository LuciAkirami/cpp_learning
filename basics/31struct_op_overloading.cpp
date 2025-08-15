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

    WHY CHAINING WORKS HERE:
    -------------------------
    p4 += p5 += p2;
      Step 1: p5 += p2 → modifies p5 and RETURNS Point& (reference to p5)
      Step 2: p4 += (reference to p5) → valid, because operator+= expects const Point&
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

/*
----------------------------------------------------------------------
NEW EXAMPLE: Struct without chaining support
----------------------------------------------------------------------
Here we have a version of operator+= that returns `void` instead of `Point&`.

WHY CHAINING FAILS HERE:
-------------------------
q1 += q2 += q3;
  Step 1: q2 += q3 → modifies q2 and RETURNS void
  Step 2: q1 += (void) → compile error, because operator+= expects const PointNoChain&
----------------------------------------------------------------------
*/
struct PointNoChain
{
    int x;
    int y;

    PointNoChain(int new_x, int new_y) : x(new_x), y(new_y) {}

    void operator+=(const PointNoChain &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        // No return — so no chaining possible
    }

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

    std::cout << "\n=== Using operator+= in PointNoChain (void return) ===\n";
    PointNoChain q1(10, 10);
    PointNoChain q2(20, 20);
    PointNoChain q3(5, 5);

    // q1 += q2 += q3; // Won't compile: q2+=q3 returns void → q1+=void invalid
    q2 += q3; // Must do in separate statements
    q1 += q2;

    q1.print_point();
    q2.print_point();
    q3.print_point();

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

ADDITIONAL:
- If operator+= returns void (like in PointNoChain), you lose the ability
  to chain expressions like p1 += p2 += p3.
  This is because the first call returns `void`, making the second call
  effectively: `p1 += void`, which is invalid.

REFERENCE:
- https://en.cppreference.com/w/cpp/language/operators.html
*/
