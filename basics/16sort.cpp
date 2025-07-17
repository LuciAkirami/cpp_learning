#include <array>     // For std::array container
#include <algorithm> // For std::sort and std::ranges::sort
#include <iostream>  // For standard input/output using cout

using namespace std;

// ------------------------- GENERIC PRINT FUNCTION ----------------------------
// Uses C++20 'auto' parameter (abbreviated function template)
// This works with any container that supports range-based for loops
void print_array(auto my_array)
{
    // Print each element separated by space
    for (auto ele : my_array)
    {
        cout << ele << ' ';
    }
    cout << endl;
}

int main()
{
    // -------------------------- STD::SORT (C++98–C++17) --------------------------

    // Declare and initialize a std::array of integers
    array<int, 5> array_1{4, 13, 6, 32, 66};

    // Print the array before sorting
    print_array(array_1);

    // std::sort is from the <algorithm> header
    // It requires two random-access iterators: a beginning and an end
    sort(array_1.begin(), array_1.end());

    // Now the array is sorted in ascending order
    print_array(array_1);

    // -------------------------- STD::RANGES::SORT (C++20) ------------------------

    // Declare another array with the same values
    array<int, 5> array_2{4, 13, 6, 32, 66};

    // Print before sorting
    print_array(array_2);

    // std::ranges::sort is cleaner and more expressive (C++20 feature)
    // It accepts the container directly instead of requiring begin/end
    std::ranges::sort(array_2);

    // Array after sorting with ranges
    print_array(array_2);

    return 0;
}

/**
 * Run it using below code
 * g++ 16sort.cpp -o your_output -std=c++20
 *
 * If you get squiggly lines on ranges keyword, modify the below
 * in the c_cpp_properties.json
 *
 * "cppStandard": "c++20",
 */