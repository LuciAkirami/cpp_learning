## What `this` is

In C++, inside any **non-static** member function of a struct or class, `this` is a hidden pointer that points to the current object.

-   In a **struct**:

```cpp
struct Point {
    int x, y;

    void set(int x, int y) {
        this->x = x; // assign to the member variable
        this->y = y;
    }
};
```

When you call:

```cpp
Point p;
p.set(3, 4);
```

-   Inside `set`, `this` is a pointer to `p`.
-   `this->x` means “the `x` inside the object I’m currently in.”

---

## Returning `*this` by Reference

You can use `this` to return the **current object** from a member function — often for chaining calls.

Example:

```cpp
#include <iostream>

struct Point {
    int x, y;

    Point& setX(int x) {
        this->x = x;
        return *this; // returns a reference to the current object
    }

    Point& setY(int y) {
        this->y = y;
        return *this;
    }

    void print() {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p;
    p.setX(3).setY(4).print(); // method chaining
}
```

**Key points here:**

-   `this` is a pointer (`Point*` inside the struct).
-   `*this` dereferences that pointer to get the actual object.
-   Returning `*this` by reference (`Point&`) lets the caller keep using the same object without copying it.

---

## When to use it

-   **Disambiguation**: When local variables shadow member variables (like in the `set` example).
-   **Method chaining**: Return `*this` from setters so you can chain calls.
-   **Fluent interfaces**: Nice, readable APIs where multiple operations can be done in a single expression.
