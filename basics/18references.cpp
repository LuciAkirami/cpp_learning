#include <iostream> // Required for input/output using cout
using namespace std;

int main()
{
    int a = 5; // Declare an integer variable 'a' and initialize it with value 5

    // ---------------------------------------------------------------------
    // WHAT IS A REFERENCE?
    // ---------------------------------------------------------------------
    // - A reference is an alias to another variable.
    // - It does NOT create a new object in memory.
    // - Any modification to the reference also modifies the original variable.
    // - Syntax: int &ref = original_variable;
    // ---------------------------------------------------------------------

    int &b = a; // 'b' is a reference to 'a'. Now 'a' and 'b' refer to the same memory.
    int c = a;  // 'c' is a copy of 'a'. It holds the same value initially, but is independent.

    // --------------------- Initial Values -----------------------
    cout << "a = " << a << endl; // Output: 5
    cout << "b = " << b << endl; // Output: 5
    cout << "c = " << c << endl; // Output: 5

    // ---------------------- Modify Reference ---------------------
    b += 1; // Increment b by 1. Since b is a reference to a, this also changes 'a'

    // After increment:
    // - a becomes 6 (since b is just another name for a)
    // - b shows 6 (same as a)
    // - c remains 5 (independent copy)
    cout << "a = " << a << endl; // Output: 6
    cout << "b = " << b << endl; // Output: 6
    cout << "c = " << c << endl; // Output: 5

    // ---------------------- Memory Addresses ----------------------

    // The addresses of a and b will be the same because b is just another name for a
    // The address of c will be different because it is a separate variable (copy)
    cout << "Address of a = " << &a << endl;
    cout << "Address of b = " << &b << endl;
    cout << "Address of c = " << &c << endl;

    // This demonstrates that references do not occupy separate space in memory

    return 0; // Program ends
}
