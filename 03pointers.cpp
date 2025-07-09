#include <iostream>

using namespace std;

/**
 * ------ Pointer --------
 *
 * A pointer is a variable that stores memory addr of another variable
 *
 *
 * -------- Types and Compatability ----------
 *
 * &num is the address of the integer num, and its type is int* (pointer to an int).
 *
 * p is declared as an int*, which means it is specifically designed to store
 * addresses of int variables.
 *
 * The assignment p = &num; is valid because the types match: both are int*.
 */
int main()
{
    // declare and initialize a variable
    int num = 55;

    // declare the pointer
    int *p; // this also implies that p stores variables of type int *

    // initialize the pointer
    // &num is the memory address of the variable num, which is of type int*
    // we then store the address of "num" into pointer "p"
    // so the pointer "p" stores the address of variable "num"
    p = &num;

    // this works, but gives a warning stating that "&num" is "int *"
    // but %d expects a type "int"
    // printf("Address of Num: %d\n", &num);

    // so for the warning to go way, we use %p, which is for pointers / int *
    // %p will display memory in hexadecimal format
    printf("Address of Num: %p\n", &num);

    // same reason, as p is int * hence %d gives warning
    // printf("Value of Pointer: %d\n", p);

    // so for the warning to go way, we use %p, which is for pointers
    printf("Value of Pointer: %p\n", p);

    // to access the value of "num" through "p", we use
    // *p which points to the value at address that is stored in pointer "p"
    // *p is also called "pointer dereference"

    int value;
    value = *p; // pointer deref/dereference

    printf("Value at the address stored in Pointer: %d\n", value);

    // changing the value through pointer deref
    *p = 66;
    // by doing the above, we are basically changing the value
    // at an address that is stored in p

    // we know that p stores the address of num. So changing the value
    // at that address through p will automatically change the value that
    // num points to
    printf("Value of Num after performing *p=66 is : %d\n", num);

    return 0;
}