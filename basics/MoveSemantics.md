## 1. Refresher on References

In C++ you’ve probably seen **lvalue references** before:

```cpp
int x = 10;
int& ref = x;   // ref is a reference to x
```

-   `ref` is just another name for `x`.
-   You cannot bind `int&` to a temporary (like `10`).

```cpp
int& r1 = 10;   // ❌ ERROR: cannot bind non-const lvalue ref to rvalue
```

But you _can_ bind a const reference to temporaries:

```cpp
const int& r2 = 10; // ✅ ok, r2 extends lifetime of temporary
```

---

## 2. What’s an **lvalue**?

-   **lvalue = “locator value”** → something that has a persistent memory address.
-   Examples:

    -   Variables: `x`, `y`, `arr[i]`
    -   Expressions that refer to a memory location

-   You can take its address with `&`.

```cpp
int x = 5;    // x is an lvalue
&x;           // ✅ ok, has an address
```

---

## 3. What’s an **rvalue**?

-   **rvalue = temporary value** → does not persist beyond the expression.
-   Examples:

    -   Literals: `5`, `3.14`, `"hello"`
    -   Expressions: `x + y`, `foo()` (if it returns by value)

```cpp
int x = 5;
int y = 10;

int z = x + y;   // (x+y) is an rvalue
```

You **cannot** normally take an address of an rvalue:

```cpp
&(x + y);  // ❌ invalid, rvalue has no persistent address
```

---

## 4. So… what is `&&`?

-   `&` = lvalue reference
-   `&&` = **rvalue reference** (C++11 feature)

It lets you **bind to a temporary object** (an rvalue).

```cpp
int&& r = 10;   // ✅ r is an rvalue reference bound to temporary 10
```

Why useful?
Because now C++ can **modify or steal resources from temporaries**, instead of making expensive copies.

---

## 5. Example: Why Move Semantics Matters

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};

    // Copy: makes a full copy of v1 into v2
    std::vector<int> v2 = v1;

    // Move: steals v1’s memory into v3 (cheap!)
    std::vector<int> v3 = std::move(v1);

    std::cout << "v1 size: " << v1.size() << '\n'; // 0 (moved-from)
    std::cout << "v3 size: " << v3.size() << '\n'; // 4
}
```

Here:

-   `v2 = v1` → Copy constructor (expensive, duplicates elements).
-   `v3 = std::move(v1)` → Move constructor (cheap, steals internal buffer).
    `v1` becomes empty.

---

## 6. Summary

-   **lvalue** → has a name/address (variables).
-   **rvalue** → temporary, no name/address (like `10`, `x+y`).
-   **&** → lvalue reference.
-   **&&** → rvalue reference (binds to temporaries).
-   **Move semantics** use `&&` to transfer resources instead of copying.
