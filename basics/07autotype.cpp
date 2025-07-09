#include <iostream> // For input/output operations

int main()
{
    // 'auto' lets the compiler deduce the variable's type from the initializer.
    // In this case, 22.2 is a double literal, so var1 is deduced to be of type double.
    auto var1 = 22.2; // var1 is double

    // Similarly, var2 is deduced to be of type double.
    auto var2 = 67.9; // var2 is double

    // var3 is the result of adding two doubles, so it is also deduced to be double.
    auto var3 = var1 + var2; // var3 is double

    // Print the result to the standard output.
    std::cout << var3 << '\n';

    // We get an error stating - Cannot Deduce 'auto' type (initializer required)
    // auto car;
    // car = 22;

    return 0;
}

/**
 * The auto keyword tells the compiler to infer the type from the expression on the right-hand side.
 * It's particularly useful for long or complex types (e.g., iterators or lambdas).
 * auto forces us to do the variable definition and initialization at the same type
 *
 * CPP Reference for Variables: https://en.cppreference.com/w/cpp/language/types.html
 */