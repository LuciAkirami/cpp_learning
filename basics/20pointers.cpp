#include <iostream>

using namespace std;

int main()
{
    // Declare an integer variable and initialize it with 10
    int a = 10;

    // Declare a pointer to an int and assign it the address of variable 'a'
    int *b = &a;

    // Display the value of 'a'
    cout << "Value of a = " << a << endl;

    // Display the memory address of 'a'
    cout << "Address of a = " << &a << endl;

    // Display the value stored in pointer 'b' (which is the address of 'a')
    cout << "\nPointer b (address it holds) = " << b << endl;

    // Dereference pointer 'b' to access the value at the address (i.e., value of 'a')
    cout << "Dereferencing pointer b = " << *b << endl;

    // Modify the value at the address 'b' points to (i.e., increment value of 'a')
    *b += 1;

    // Show that both 'a' and '*b' reflect the updated value
    cout << "\nAfter incrementing *b:" << endl;
    cout << "Value of a = " << a << endl;
    cout << "Dereferencing pointer b = " << *b << endl;

    // Show that 'a' and '*b' share the same address
    cout << "\nAddress of a = " << &a << endl;
    cout << "Pointer b = " << b << endl;

    return 0;
}

/**
|--------------------------------------------------------------------------------------|
| Concept   | Description                                                              |
| --------- | ------------------------------------------------------------------------ |
| `int *b`  | Declares a pointer to an `int`. It stores the **address** of an integer. |
| `&a`      | The **address-of** operator. Gets the memory address of variable `a`.    |
| `*b`      | The **dereference** operator. Gets the value stored at the address `b`.  |
| `*b += 1` | Modifies the value **at the address**. This changes the original `a`.    |
|--------------------------------------------------------------------------------------|
*/