#include <iostream>
#include <memory> // for std::unique_ptr

/*
----------------------------------------------------------------------
Case 1: Raw Pointer
----------------------------------------------------------------------
- We allocate memory manually using `new`.
- This memory is NOT automatically released when the object goes out of scope.
- We must define a destructor (`~IntArray`) to free it using `delete[]`.
- If we forget, we cause a MEMORY LEAK.

Case 2: Smart Pointer (unique_ptr)
----------------------------------------------------------------------
- `std::unique_ptr` automatically calls `delete[]` when it goes out of scope.
- We don't need to manually define a destructor.
- This is safer because it eliminates the chance of forgetting cleanup.
*/

struct IntArray
{
    int *array; // RAW POINTER → holds address of the first element

    // Constructor: allocates memory
    IntArray(int size)
    {
        std::cout << "Running IntArray Constructor\n";
        array = new int[size]; // dynamic allocation
    }

    // Destructor: manually frees allocated memory
    ~IntArray()
    {
        std::cout << "Running IntArray Destructor\n";
        delete[] array; // MUST match with new[] — avoids memory leaks
    }
};

struct IntArrayUniquePtr
{
    // unique_ptr to an array → will free memory automatically
    std::unique_ptr<int[]> array;

    // Initialization list: allocates memory
    IntArrayUniquePtr(int size) : array(new int[size])
    {
        std::cout << "Running IntArrayUniquePtr Constructor\n";
    }

    // No destructor needed — unique_ptr’s destructor does the cleanup
};

int main()
{
    std::cout << "=== Raw Pointer Example ===\n";
    {
        IntArray a(10); // Constructor runs here
        a.array[0] = 1;
        std::cout << "Value at index 0: " << a.array[0] << '\n';
        // Destructor automatically called here at scope end → memory freed
    }

    std::cout << "\n=== unique_ptr Example ===\n";
    {
        IntArrayUniquePtr u(10); // Constructor runs
        u.array[4] = 24;
        std::cout << "Value at index 4: " << u.array[4] << '\n';
        // No manual destructor — unique_ptr frees memory automatically
    }

    std::cout << "\n=== Program End ===\n";
    return 0;
}

/*
LIFETIME & DESTRUCTION:
--------------------------
- For raw pointers:
  1. Memory is allocated in constructor.
  2. Memory stays allocated until manually freed in destructor.
  3. If destructor is missing → MEMORY LEAK.

- For unique_ptr:
  1. Memory allocated when unique_ptr is created.
  2. Memory automatically freed when unique_ptr goes out of scope.
  3. This works because unique_ptr’s own destructor calls delete[].

MEMORY CONSUMPTION:
----------------------
- Both store the actual array in heap (size × sizeof(int) bytes).
- For `IntArray` → plus a raw pointer (8 bytes on 64-bit systems).
- For `IntArrayUniquePtr` → stores a small smart-pointer object (size similar to raw pointer, but with extra destructor logic in its class).

KEY TAKEAWAY:
----------------
- Always prefer smart pointers like `unique_ptr` when you own heap memory.
- They prevent leaks by automating cleanup.
- Use raw pointers only if you have a very specific reason and know exactly how you’ll manage cleanup.
- These constructors and destructors, the same apply for classes
*/
