#include <array>    // For std::array container
#include <iostream> // For input/output using cout

using namespace std;

int main()
{
    // Declare and initialize a std::array with 5 integers
    array<int, 5> my_array{1, 2, 3, 4, 5};

    // -------------------- FORWARD ITERATION ---------------------------
    // We use iterators to walk through containers in C++ (like pointers)
    // Iterators are like smart pointers that move through containers safely.

    // my_array.begin() returns an iterator pointing to the first element
    // my_array.end() returns an iterator pointing *past the last* element (not the last itself)

    // This loop prints elements in forward order: 1 2 3 4 5
    for (auto itr = my_array.begin(); itr < my_array.end(); itr += 1)
    {
        // *itr dereferences the iterator, giving access to the value
        cout << *itr << ' ';
    }
    cout << endl;

    // -------------------- REVERSE ITERATION ---------------------------
    // rbegin() returns a reverse iterator pointing to the *last* element
    // rend() returns a reverse iterator pointing *before the first* element

    // This loop prints elements in reverse order: 5 4 3 2 1
    for (auto itr = my_array.rbegin(); itr < my_array.rend(); itr += 1)
    {
        cout << *itr << ' ';
    }
    cout << endl;

    return 0; // Program ends successfully
}
