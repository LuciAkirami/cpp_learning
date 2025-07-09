#include <iostream> // Enables input and output operations using cin and cout
#include <array>    // Includes the std::array container class from the Standard Library

using namespace std; // Allows direct use of standard library names (like cout) without prefixing them with std::

int main()
{
    // -------------------------- FOR LOOP -------------------------------
    // The 'for' loop is best used when the number of iterations is known.
    // Syntax: for(initialization; condition; update)

    // Example: Print "Iteration: 0" through "Iteration: 4"
    for (int i = 0; i < 5; i += 1)
    {
        // i starts at 0, loop continues while i < 5, and increments i by 1 each time
        cout << "Iteration: " << i << endl;
    }

    // ----------------------- C++ ARRAY AND FOR LOOP ---------------------
    // C++ provides a safer, fixed-size array class: std::array
    // It's preferred over raw C-style arrays because it includes size checking and member functions.

    // Declare and initialize a std::array with 3 integers
    array<int, 3> my_array{10, 543, 2};

    // Classic indexed for loop to iterate through the array
    for (int i = 0; i < my_array.size(); i += 1)
    {
        // .at(i) checks bounds and throws an exception if out of range (safer than operator[])
        cout << "Element at index " << i << " is: " << my_array.at(i) << endl;
    }

    // ---------------------- RANGE-BASED FOR LOOP ------------------------
    // Introduced in C++11. Ideal for iterating over containers like arrays, vectors, etc.
    // It avoids manual indexing and out-of-bounds errors.

    // Here, 'value' takes on each element in the array
    for (int value : my_array)
    {
        cout << "Array value: " << value << endl;
    }

    // -------------------------- WHILE LOOP -----------------------------
    // A 'while' loop is useful when the number of iterations is unknown beforehand.
    // It checks the condition *before* executing the loop body.

    int items = 5; // Initialize a counter

    while (items > 0)
    {
        // Will run as long as items is greater than 0
        cout << "Item: " << items << endl;
        items -= 1; // Decrement by 1 each iteration
    }

    // -------------------------- DO-WHILE LOOP ---------------------------
    // Unlike the 'while' loop, a 'do-while' loop checks the condition *after* the body executes.
    // So it always runs **at least once**, even if the condition is false initially.

    int new_items = 0; // Initialize to zero to demonstrate guaranteed execution

    do
    {
        cout << "New Item: " << new_items << endl;
        new_items -= 1; // Still decreases, but the loop stops after one run
    } while (new_items > 0);

    return 0;
}
