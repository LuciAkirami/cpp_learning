/**
 * --------- Identifiers (Variable Names) -------
 * They are case sensitive, i.e. helloWorld and helloworld are not same
 *
 * Numbers: we can use numbers while naming variables. We can use numbers only
 * in between or at the end but not at the fronts
 *
 * Underscore: "_" we can use underscore as well for naming variables
 *
 * We cannot use reserver keywords for variable names like int, friend, if, inline
 *
 * Do not go beyond 31 characters, might face compiler issues
 *
 * ------ UnderScores --------
 *  Do not Start with the below or with numbers at start for normal variables
 *
 *  _ at start means private
 *  __ means system keyword
 *
 * -------------- Primitive Data Types -------------
 *
 * bool - boolean
 * char - Character
 * int - Integer
 * float - Floating Point
 * double - Double floating point
 * void - valueless
 */

#include <iostream>
#include <string>

using namespace std;
int main()
{

    string my_name;

    // // we can use cin to get the input
    int number;
    cout << "Enter a number: \n";
    cin >> number;
    cout << "Your number is " << number << endl;

    // Clear the newline character left in the input buffer
    // `cin >> number` leaves a newline in the buffer. Without clearing it,
    // `getline` would immediately read this leftover newline as input.
    // if you want to see the issue, comment the below line and compile
    cin.ignore(1000, '\n'); // Ignore up to 1000 characters or until a newline

    // cin only takes single char for strings, so we use getline
    // getline takes two inputs, one is the method that is capable
    // of taking inputs and the other is, where to store it

    // getline allows us to take and store an entire line, whereas
    // cin can only take in and store a single char
    cout << "Enter yout name: \n";
    getline(cin, my_name);

    cout << "Nice to meet you, " << my_name << endl;
}