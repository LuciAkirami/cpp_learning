#include <iostream> // Includes the input/output stream library

using namespace std; // Allows usage of standard library names without the 'std::' prefix

int main()
{
    // Declare two integer variables and initialize them to 0
    int a = 0;
    int b = 0;

    // Take input from the user and store it in variable 'a'
    cin >> a;

    // Take another input and store it in variable 'b'
    cin >> b;

    // Compare the values of 'a' and 'b'
    if (a > b)
    {
        // This block executes if 'a' is greater than 'b'
        cout << "a is greater than b\n";
    }
    else if (a == b)
    {
        // This block executes if 'a' is equal to 'b'
        cout << "a is equal to b\n";
    }
    else
    {
        // This block executes if 'a' is less than 'b'
        cout << "a is smaller than b\n";
    }

    return 0; // Indicate that the program ended successfully
}
