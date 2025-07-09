#include <iostream>

using namespace std;

int main()
{
    int score = 200;
    int *myp = &score;

    printf("Value of score is %d\n", score);
    printf("Value of pointer is %p\n", myp);

    // now we will create a reference to score
    int &another_score = score;

    another_score = 350; // no explicit deference required

    // as the reference another_score is a reference to
    // the variable score, changing another_score will
    // also change the score variable;
    printf("Value of score is %d\n", score);

    // this will point to same address, as we are changing
    // the value stored at the address but not that address
    printf("Value of pointer is %p\n", myp);
    printf("Value of another_score is %d\n", another_score);

    // --------- other way to change score ----------
    // To change the value of num using the pointer, you dereference
    // it (*p) to access the value stored at the memory address.

    *myp = 500; // Dereference the pointer to modify the value of 'num'

    printf("Value of score is %d\n", score);

    // this will point to same address, as we are changing
    // the value stored at the address but not that address
    printf("Value of pointer is %p\n", myp);
    printf("Value of another_score is %d\n", another_score);

    return 0;
}

// Comparison between pointers and references in C++

// 1. Syntax:
//    - Pointer: Requires dereferencing (*) to access or modify the value.
//    - Reference: Behaves like a regular variable, no dereferencing needed.

// 2. Binding:
//    - Pointer: Can point to different variables during its lifetime (reassignable).
//    - Reference: Bound to one variable at initialization, cannot be re-bound.
//    Once initialized, a reference cannot be changed to refer to another variable.

// 3. Null Safety:
//    - Pointer: Can be nullptr, so dereferencing it without checking is unsafe.
//    - Reference: Cannot be null, always refers to a valid variable.

// 4. Initialization:
//    - Pointer: Can be declared without initialization and assigned later.
//    - Reference: Must be initialized when declared, and cannot be changed.

// 5. Flexibility:
//    - Pointer: Can be used for dynamic memory, arrays, and when reassignment is needed.
//    - Reference: Ideal for fixed aliasing and pass-by-reference in functions.

// 6. Memory Usage:
//    - Pointer: Uses memory to store the address it points to (4 or 8 bytes typically).
//    - Reference: Treated like an alias, often optimized away by the compiler.

// Note
// For more information view pointer_vs_reference.md