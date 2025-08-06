#include <iostream> // For standard input/output operations
#include <memory>   // For smart pointers like std::unique_ptr

int main()
{
    // ----------------------------- INTRO TO UNIQUE_PTR -----------------------------

    /**
     * std::unique_ptr is a smart pointer introduced in C++11.
     * It **owns a dynamically allocated object** and ensures that the object is
     * **automatically deallocated** when the unique_ptr goes out of scope.
     *
     * Unlike raw pointers (e.g., `int*`), we don’t need to manually call `delete`.
     *
     * As the name suggests, **only one unique_ptr can own a resource at a time**.
     * Copying is disabled to prevent multiple owners.
     * Moving is allowed to transfer ownership.
     */

    // ---------------------- CREATING UNIQUE_PTR FOR DYNAMIC ARRAY -------------------

    // Allocate an array of 5 integers using unique_ptr
    // Use unique_ptr<int[]> for managing arrays
    std::unique_ptr<int[]> ptr(new int[5]); // Manages a dynamically allocated int array

    // ptr points to the start of a 5-element int array on the heap
    // Setting values using array indexing
    ptr[2] = 44;
    ptr[3] = 55;

    // Accessing and printing elements
    std::cout << "Element at index 2: " << ptr[2] << std::endl;
    std::cout << "Element at index 3: " << ptr[3] << std::endl;

    // ------------------- SAFER WAY: USING std::make_unique -------------------------

    /**
     * Since C++14, we can use std::make_unique<T[]>(size) to create a unique_ptr
     * This is safer and more concise than using 'new' directly.
     *
     * Benefits of make_unique:
     * - No need to use 'new' (avoids memory leaks due to exceptions)
     * - Automatically deduces type
     * - Clean, less error-prone syntax
     */

    // Allocate an array of 10 integers using make_unique
    auto my_ptr = std::make_unique<int[]>(10); // Creates unique_ptr<int[]> managing 10 ints

    // Setting values at specific indices
    my_ptr[2] = 43;
    my_ptr[3] = 54;

    // Accessing and printing elements
    std::cout << "Element at index 2: " << my_ptr[2] << std::endl;
    std::cout << "Element at index 3: " << my_ptr[3] << std::endl;

    // ------------------- MEMORY CLEANUP HANDLED AUTOMATICALLY -----------------------

    /**
     * When `ptr` and `my_ptr` go out of scope (i.e., when main() ends),
     * the memory for the arrays is automatically deallocated.
     *
     * No need to call delete or delete[] manually!
     */

    return 0;
}
