#include <iostream> // For standard input/output (cin, cout, endl)
#include <vector>   // For using the std::vector container from the C++ Standard Library

// ------------------------------------------------------------------------------------------
// WHAT IS A VECTOR?
// ------------------------------------------------------------------------------------------
// - A vector is a dynamic array provided by the C++ Standard Template Library (STL).
// - Unlike regular arrays, vectors can grow and shrink in size automatically as needed.
// - You don’t need to manually manage memory allocation for a vector.
// - Vectors are stored in contiguous memory, just like arrays, so they are efficient.
// - The syntax: std::vector<data_type> name;
// ------------------------------------------------------------------------------------------

// This function prints all elements of a vector of integers
// It takes the vector by **value** (a copy), so the original vector is not modified
void print_vec(std::vector<int> vector)
{
    // Range-based for loop to print each element
    for (auto ele : vector)
    {
        std::cout << ele << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    // ------------------------- BASIC VECTOR CREATION -------------------------

    // Creating a vector and initializing it with values using initializer list
    std::vector<int> my_vec = {2, 4, 6};

    // Print initial vector
    print_vec(my_vec); // Output: 2 4 6

    // ------------------------ ADDING ELEMENTS ----------------------------

    // Adds a new element to the end of the vector
    my_vec.push_back(25); // Now the vector becomes {2, 4, 6, 25}
    print_vec(my_vec);    // Output: 2 4 6 25

    // ------------------------ REMOVING ELEMENTS --------------------------

    // Removes the last element from the vector
    my_vec.pop_back(); // Now the vector becomes {2, 4, 6}
    print_vec(my_vec); // Output: 2 4 6

    // -------------------- SIZE vs CAPACITY (Dynamic Behavior) ----------------------

    // Create an empty vector
    std::vector<int> my_another_vec;

    // Explain the difference between size and capacity
    std::cout << "\nSize vs Capacity\n\n";

    // Add 10 elements to the vector and display size and capacity
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Size: " << my_another_vec.size() << std::endl;
        std::cout << "Capacity: " << my_another_vec.capacity() << std::endl;
        my_another_vec.push_back(i); // Vector grows as we add elements
    }

    // -------------------------------------------------------------------------------------
    // SIZE vs CAPACITY:
    // - size():    Actual number of elements in the vector.
    // - capacity(): Total space currently allocated for the vector.
    // - Vectors grow in chunks (usually doubling capacity) to reduce the cost of reallocation.
    // - The capacity usually grows in powers of two
    // -------------------------------------------------------------------------------------

    // ------------------- USING RESERVE FOR PERFORMANCE ----------------------

    // Create another empty vector
    std::vector<int> my_other_vec;

    // Reserve memory for at least 10 elements in advance
    my_other_vec.reserve(10);

    std::cout << "\nUsing Reserve Capacity\n\n";

    // Add 10 elements again and monitor size and capacity
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Size: " << my_other_vec.size() << std::endl;
        std::cout << "Capacity: " << my_other_vec.capacity() << std::endl;
        my_other_vec.push_back(i);
    }

    // -------------------------------------------------------------------------------------
    // reserve(n):
    // - Tells the vector to pre-allocate memory for at least n elements.
    // - Improves performance by reducing the number of reallocations.
    // - Note: reserve() only affects capacity, not size.
    // -------------------------------------------------------------------------------------

    return 0; // End of program
}
