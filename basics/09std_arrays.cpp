#include <iostream> // For input and output operations
#include <array>    // For using std::array container

using namespace std;

int main()
{
    // Declare and initialize a std::array with 5 integers
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Alternative way to initialize a std::array with 3 elements
    // array<int, 3> arr2{1, 2, 3};

    // Access elements of the array using different member functions and operators

    // Access the third element (index 2) using the .at() method (bounds-checked)
    cout << arr.at(2) << endl;

    // Access the first element (index 0) using the subscript operator []
    cout << arr[0] << endl;

    // Access the first element using the .front() method
    cout << arr.front() << endl;

    // Access the last element using the .back() method
    cout << arr.back() << endl;

    // Output the total number of elements in the array
    cout << arr.size() << endl;

    // Fill all elements in the array with the value 10
    arr.fill(10);

    // Output the modified values at index 1 and 2 after filling
    cout << arr[1] << endl; // Should print 10
    cout << arr[2] << endl; // Should also print 10

    return 0; // Indicate successful program termination
}
