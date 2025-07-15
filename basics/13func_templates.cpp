#include <iostream> // Provides input/output functionality via cin and cout
#include <array>    // Provides std::array container

using namespace std; // Avoids needing to write 'std::' every time

// ------------------------ FUNCTION TEMPLATE -----------------------------

// A function template allows the same function to work with different data types
// The compiler generates the appropriate version of the function during compilation

// 'T' is a template parameter that represents a type (like int, float, etc.)
// You can replace 'T' with any other name
// When print_my_array is called, the compiler infers 'T' from the argument
template <typename T>
void print_my_array(T array)
{
    // Range-based for loop to iterate over the array
    // 'auto' deduces the element type (e.g., int, float)
    for (auto element : array)
    {
        cout << element << endl;
    }
}

/*
------------------ C++20 AUTO PARAMETER SYNTAX (ABBREVIATED TEMPLATE) ------------------

In C++20, you can write the above using abbreviated function templates like this:

    void print_my_array(auto array) {
        for (auto element : array) {
            cout << element << endl;
        }
    }

This is called a *templated lambda-style* or *abbreviated function template*.
It’s cleaner and lets the compiler deduce the type automatically — no need for 'template<typename T>'.

BUT: If you try to compile this in older C++ versions (like C++17 or C++14),
you'll get a **compiler warning or error** like:

    warning: use of ‘auto’ in parameter declaration only available with ‘-std=c++20’ or ‘-fconcepts’

To fix it, compile your code like this:

    g++ file.cpp -o output -std=c++20

-------------------------------------------------------------------------------
*/

// ---------------------------- MAIN FUNCTION ------------------------------

int main()
{
    // Declare and initialize a std::array of integers
    array<int, 3> array_1{1, 2, 3};

    // Declare and initialize a std::array of floats
    array<float, 3> array_2{4.1f, 5.2f, 6.3f};

    // Call the generic print_my_array function
    // The compiler automatically generates a version for array<int, 3>
    print_my_array(array_1);

    // And here it generates one for array<float, 3>
    print_my_array(array_2);

    return 0; // Program completed successfully
}
