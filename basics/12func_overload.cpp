#include <iostream> // Enables input/output operations using cin and cout
#include <array>    // Includes the std::array container class from the Standard Library

using namespace std; // Avoids needing to prefix standard library names with 'std::'

// -------------------------- FUNCTION OVERLOADING --------------------------
// Function overloading means having multiple functions with the same name,
// but with **different parameter types or number of parameters**.

// These functions are overloaded based on the type of the std::array elements.

// Function to print an array of integers
void print_array(array<int, 3> array)
{
    // 'auto' is used here to automatically deduce the type of 'val'
    for (auto val : array)
    {
        cout << "Integer Array Element: " << val << endl;
    }
}

// Function to print an array of floats
void print_array(array<float, 3> array)
{
    for (auto val : array)
    {
        cout << "Float Array Element: " << val << endl;
    }
}

// ------------------------------- MAIN FUNCTION ----------------------------

int main()
{
    // Declare and initialize an array of 3 integers
    array<int, 3> array_1{1, 2, 3};

    // Declare and initialize an array of 3 floats
    array<float, 3> array_2{4.1f, 5.1f, 6.1f}; // Note: the 'f' suffix makes them float literals

    // Call the appropriate overloaded function based on array type
    print_array(array_1); // Calls the version that accepts array<int, 3>
    print_array(array_2); // Calls the version that accepts array<float, 3>

    return 0; // Indicates successful execution
}
