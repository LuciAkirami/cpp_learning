#include <iostream> // Required for input/output operations using cin and cout
#include <array>    // Includes the std::array container from the Standard Library

using namespace std; // Allows use of standard library symbols without the 'std::' prefix

// ------------------------ FUNCTION DECLARATIONS -------------------------

// Function to print all elements of a std::array of size 3
// Takes the array by value (a copy is made)
void print_array(array<int, 3> array);

// Function to compute and return the sum of a std::array of size 3
// Also takes the array by value (a copy is made)
int sum_array(array<int, 3> array);

// ------------------------ FUNCTION DEFINITIONS --------------------------

// Prints each element in the passed array using a range-based for loop
void print_array(array<int, 3> array)
{
    // Loop through each element in the array
    for (int val : array)
    {
        cout << "Array Element: " << val << endl;
    }
}

// Calculates and returns the sum of all elements in the array
int sum_array(array<int, 3> array)
{
    int sum = 0; // Initialize sum variable

    for (int val : array)
    {
        sum += val; // Accumulate sum
    }

    return sum; // Return the total
}

// ----------------------------- MAIN FUNCTION ----------------------------

int main()
{
    // Declare and initialize two arrays with 3 integers each
    array<int, 3> array_1{1, 2, 3}; // Sum: 6
    array<int, 3> array_2{4, 5, 6}; // Sum: 15

    // Call function to print contents of array_1
    print_array(array_1);

    // Call function to print contents of array_2
    print_array(array_2);

    // Call function to calculate and print sum of array_1
    cout << "Sum of array_1: " << sum_array(array_1) << endl;

    return 0; // Program ends successfully
}
