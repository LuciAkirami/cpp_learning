/**
 * A namespace in C++ is a declarative region that organizes code
 * into logical groups and prevents name conflicts.
 * Here's a detailed explanation in points:
 *
 * ---- Key Features of Namespace: -----
 * Purpose:
 * 1. Avoids name conflicts, especially when integrating multiple
 * libraries or large projects.
 * 2. Groups related functions, variables, and classes.
 */

// ---- Syntax of Namespace ----
// namespace namespace_name {
//     // Declarations and definitions
// }

// Members are accessed using the scope resolution operator (::)
// namespace_name::member_name;

// --- Default NameSpace - std ---
// 1. The std namespace is the Standard Library namespace in C++.
// It contains standard classes, functions, and objects
// (e.g., cout, cin, string).
// 2. To use elements from std without prefixing, you can write:
// using namespace std;

// ---- Nested NameSpace ----
// namespace Outer {
//     namespace Inner {
//         int multiply(int a, int b) {
//             return a * b;
//         }
//     }
// }
// Access: Outer::Inner::multiply(2, 3);

// ---- Namespace Alias ----
// namespace LongNamespaceName = std;
// LongNamespaceName::cout << "Alias example!" << std::endl;

#include <iostream>

// Alternatively, you can use specific members using std::
// int main()
// {
//     std::cout << "Henlo Warudoo" << std::endl;
//     return 0;
// }

using namespace std;
// above brings all namespace members like cin, cout, etc to scope

namespace MathConstants
{
    float get_pi()
    {
        return 3.14;
    }
}

namespace MathFunctions
{
    int add_two(int a, int b)
    {
        return a + b;
    }
}

// here we are brining all members present in MathFunctions namespace
// which here is just a single function add_two
using namespace MathFunctions;

int main()

{
    // using members of std namespace
    cout << "Henlo Warudoo" << endl;

    // using members of MathConstants namespace
    float pi_value = MathConstants::get_pi();
    // the below gives an error as we didn't bring the namespace
    // using the "using" keyword
    // float pi_value = get_pi()

    printf("Value of PI is %.2f\n", pi_value);

    // using member of MathFunction namespace without MathFunctio
    int sum = add_two(28, 2);
    printf("Addition of 28 + 2 = %d\n", sum);

    return 0;
}