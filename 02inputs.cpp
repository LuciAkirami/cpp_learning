// iostream is a headerfile
// #include is a preprocessor directive that links
// a header file to the source code
#include <iostream>

/**
 * argc -> stores the number of arguments passed
 * argv -> contains the list of arguments passed on the program
 */
int main(int argc, const char *argv[])
{
    printf("Number of Arguments: %d\n", argc);
    printf("First Argument, %s\n", argv[0]); // will be the name of the program
    printf("Hello, %s\n", argv[1]);
    return 0;
}

// How to Run?
// g++ 02inputs.cpp -o inp
// ./inp Ajay