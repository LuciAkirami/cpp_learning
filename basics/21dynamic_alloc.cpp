#include <iostream>

using namespace std;

int main()
{
    // ---------------------- SINGLE VALUE ALLOCATION ------------------------

    // Allocate memory dynamically on the heap for a single integer
    int *int_ptr = new int;

    // int_ptr holds the address of this dynamically allocated integer
    *int_ptr = 123; // Store a value in that memory location

    cout << "Value stored at int_ptr (i.e., *int_ptr): " << *int_ptr << endl;
    cout << "Address stored in int_ptr (i.e., location of the value): " << int_ptr << endl;

    // ---------------------- DYNAMIC ARRAY ALLOCATION -----------------------

    // Allocate memory dynamically on the heap for an array of 5 integers
    int *arr_ptr = new int[5];

    // arr_ptr holds the address of the **first element** of the dynamically allocated array

    // Set values using both pointer arithmetic and array indexing
    *arr_ptr = 15;   // Same as arr_ptr[0] = 15;
    arr_ptr[2] = 30; // Sets value at index 2

    // Print values using array indexing
    cout << "\nAccessing dynamic array using arr_ptr:" << endl;
    cout << "Value at index 0 (arr_ptr[0]): " << arr_ptr[0] << endl;
    cout << "Value at index 2 (arr_ptr[2]): " << arr_ptr[2] << endl;

    // Access and modify value at index 2 using pointer arithmetic
    *(arr_ptr + 2) = 45; // Same as arr_ptr[2] = 45;

    // Print updated value
    cout << "Updated value at index 2 (arr_ptr[2]): " << arr_ptr[2] << endl;

    // ---------------------- MEMORY CLEANUP -----------------------

    // Always free dynamically allocated memory to prevent memory leaks
    delete int_ptr;   // Deallocates the single int memory block
    delete[] arr_ptr; // Deallocates the array memory block

    return 0;
}
