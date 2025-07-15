#include <iostream> // For standard input/output using cout
#include <array>    // For using std::array container

using namespace std;

// ------------------------ FUNCTION TEMPLATE -----------------------------
// This is a generic function template that works with any type T.
// When called, the compiler generates a version based on the argument's type.
template <typename T>
void print_my_array(T my_array)
{
    // Range-based for loop automatically deduces element type
    for (auto element : my_array)
    {
        cout << element << endl;
    }
}

// ------------------------ TEMPLATE SPECIALIZATION ------------------------
// This is a **true template specialization** for the type array<int, 3>.
// It overrides the generic template ONLY for this specific type.
//
// Important: The 'template<>' syntax tells the compiler this is a specialization.
// It’s part of the same function family as the generic template above.
template <>
void print_my_array(array<int, 3> my_array)
{
    cout << "Specialized print for array<int, 3>" << endl;

    // You can still print the elements if desired
    for (auto element : my_array)
    {
        cout << "[int] " << element << endl;
    }
}

/*
// ------------------------ WITHOUT template<> -----------------------------
// What happens if you remove 'template<>'?

// Example:
// void print_my_array(array<int, 3> my_array)
// {
//     cout << "Overloaded version for array<int, 3>" << endl;
// }

// This looks similar, but it's NOT a template specialization!
// It's a completely separate function — a regular **function overload**.

// Why does it still work?
// Because both the template and non-template functions are visible,
// and the compiler will choose the best match. It prefers exact non-template matches
// (function overloads) over templated ones during overload resolution.

// ⚠️ But this version is not linked to the generic template.
// It's not a specialization — just a different function with the same name.

// ✅ Best Practice:
// Always use 'template<>' for true specialization to stay within the template system.
// It's clearer and behaves correctly even with references or other advanced use cases.
*/

int main()
{
    // Create an integer array (matches specialized template)
    array<int, 3> array_1{1, 2, 3};

    // Create a float array (uses generic template)
    array<float, 3> array_2{4.1f, 5.2f, 6.3f};

    // This will call the specialized version for array<int, 3>
    print_my_array(array_1);

    // This will call the generic template version for array<float, 3>
    print_my_array(array_2);

    return 0;
}
