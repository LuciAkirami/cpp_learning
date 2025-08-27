#include <iostream>
#include <memory>
#include <utility>

/*
----------------------------------------------------------------------
TOPIC: UNIQUE_PTR, MOVE SEMANTICS, LVALUES vs RVALUES
----------------------------------------------------------------------

1. std::unique_ptr:
   - A smart pointer that has *unique ownership* of the resource.
   - Cannot be copied (copy constructor deleted).
   - Can only be *moved* (ownership transferred).

2. lvalues vs rvalues:
   - lvalue: has a persistent memory address (e.g., variables like `x`, `ptr1`).
   - rvalue: temporary object or value (e.g., `10`, `x+y`, `std::move(ptr1)`).

   Example:
     int x = 10;
     int& lref = x;       // lvalue reference → valid
     int&& rref = 5;      // rvalue reference → valid
     int&& rref2 = x;     // ❌ invalid, x is lvalue

3. Move constructor:
   - Special constructor that "steals" resources from an rvalue.
   - Leaves the source object in a valid but unspecified (often null/empty) state.

   Example: unique_ptr’s move constructor transfers ownership of the pointer.
----------------------------------------------------------------------
*/

int main()
{
    auto ptr1 = std::make_unique<int[]>(10);
    std::cout << "ptr1 before moving " << ptr1.get() << '\n';

    // Transfer ownership from ptr1 to ptr2
    auto ptr2 = std::move(ptr1);

    std::cout << "ptr1 after moving " << ptr1.get() << '\n'; // nullptr
    std::cout << "ptr2 after moving " << ptr2.get() << '\n'; // valid pointer

    // NOTE: After move, ptr1 becomes nullptr (resource released).
    // Only ptr2 owns the array now.

    return 0;
}

/*
----------------------------------------------------------------------
EXAMPLE 2: Custom Class with Copy and Move
----------------------------------------------------------------------
We’ll define a struct that manages a heap array manually.
This shows why we need move semantics.
*/
struct MyArray
{
    int *data;
    size_t size;

    // Constructor
    MyArray(size_t n) : size(n), data(new int[n])
    {
        std::cout << "Constructor: allocated " << size << " ints\n";
    }

    // Copy constructor (lvalue reference)
    MyArray(const MyArray &other) : size(other.size), data(new int[other.size])
    {
        std::cout << "Copy Constructor: deep copy\n";
        std::copy(other.data, other.data + size, data);
    }

    // Move constructor (rvalue reference)
    MyArray(MyArray &&other) noexcept : size(other.size), data(other.data)
    {
        std::cout << "Move Constructor: stealing resources\n";
        other.data = nullptr; // important! leave source safe
        other.size = 0;
    }

    // Destructor
    ~MyArray()
    {
        std::cout << "Destructor: freeing memory\n";
        delete[] data;
    }

    void print_size() const
    {
        std::cout << "Size = " << size << ", data = " << data << '\n';
    }
};

int main2()
{
    std::cout << "\n=== Copy Example (lvalue) ===\n";
    MyArray arr1(5);
    MyArray arr2 = arr1; // Calls COPY constructor
    arr1.print_size();
    arr2.print_size();

    std::cout << "\n=== Move Example (rvalue) ===\n";
    MyArray arr3(10);
    MyArray arr4 = std::move(arr3); // Calls MOVE constructor
    arr3.print_size();              // now size=0, data=nullptr
    arr4.print_size();              // owns the data

    return 0;
}

/*
----------------------------------------------------------------------
KEY TAKEAWAYS:
----------------------------------------------------------------------
1. Copy Constructor (const T&):
   - Used when passing/returning by value or explicitly copying.
   - Deep copies resources.

2. Move Constructor (T&&):
   - Used when the object is temporary (rvalue).
   - Steals the resource, avoids expensive deep copy.

3. std::move():
   - Converts an lvalue into an rvalue reference.
   - Does NOT move anything itself, only enables move constructor/assignment.

4. Unique_ptr:
   - Non-copyable (ensures unique ownership).
   - Movable (ownership can be transferred).
   - After move, original becomes nullptr.

5. Lvalue vs Rvalue:
   - Lvalue → object with name/address.
   - Rvalue → temporary, no persistent address.
   - Move semantics leverage rvalue references (T&&) for efficiency.
*/
