/**
 * () -> parenthesis
 * [] -> brackets / square brackets
 * {} -> braces / flower / curly braces
 */

// #include <iostream>

// int main()
// {
//     std::cout << "Hello Warudooo!" << std::endl;
//     return 0; // it works without return too
// }

// This is another way to print henlo world
#include <cstdio>

using namespace std;

int main()
{
    // puts - writes a string followd by newline to stdout
    // a line ending with a semicolon is called a "statement"
    puts("Hello Warudooo");
    // return 0 from main() returns an Exit code 0, implying
    // that the program excuted and exited successfulyy
    return 0;

    // return 1 from main() returns an Exit Code 1, implying
    // that the program exeecuted but exited with an error
    // try returning 1 and compiling it
    // return 1;

    // exit code 1 in reality implies, there was an error and
    // program was not exited gracefully
}
