#include <iostream>

using namespace std;

int main()
{
    int my_array[4] = {1, 2, 3, 4};

    // gives the 2nd element in the array
    cout << "Second element is " << my_array[1] << "\n\n";

    cout << "Address of First Element is " << &my_array[0] << endl;

    // Output the address of the first element using array name - int*
    cout << "Address of First Element is " << my_array << endl;

    // Output the address of the entire array - int (*)[4]
    cout << "Address of First Element is " << &my_array << "\n\n";

    // Note:
    // my_array itself is a pointer that stores the address of first element
    // that is the reason my_array and &my_array[0] is same

    // Explanation:
    // - `my_array` decays into a pointer pointing to the first element of the array.
    // - `&my_array` is a pointer pointing to the entire array's memory.
    // Though their values may be the same because the array starts at the first element's address,
    // their types are different!

    // --------- Accesing Elements - Pointer Method ----------
    // my_array stores the address of first element. And elements in array
    // are contiguous. So the address of second element is addr of 1st element+ 1
    // which is myarray + 1. Now to get the element at this address, we need
    // to deref it, which we can do using (*), so it'll be *(my_array + 1)
    cout << "Value of Second element is " << *(my_array + 1) << "\n\n";

    // Address of second element is
    cout << "Address of Second element is " << my_array + 1 << "\n";

    // Confirming its the same
    cout << "Address of Second element is " << &my_array[1] << "\n\n";

    // -------- Pointer Arithmetic ----------

    // Pointer arithmetic to access the address of the 2nd element using the array pointer
    cout << "my_array + 1 (Address of 2nd element): " << my_array + 1 << "\n";

    // Pointer arithmetic to move past the entire array (pointer to memory just after the array)
    cout << "&my_array + 1 (Address after entire array): " << &my_array + 1 << "\n\n";

    // Explanation:
    // - `my_array + 1` points to the address of the second element in the array.
    // - `&my_array + 1` points to the memory right after the entire array, outside its bounds.

    // ------------ Updating Arrays - Pointer Approach ------------
    cout << "First element before updating is " << my_array[0] << "\n";

    *my_array = 99;

    cout << "First element after updating is " << my_array[0] << "\n\n";

    cout << "Third element before updating is " << my_array[2] << "\n";

    *(my_array + 2) = 56;
    // my_array[2] = 56; // this is without pointer method

    cout << "Third element after updating is " << my_array[2] << "\n\n";

    // updating array through another array
    int *array_pointer = my_array; // array_pointer points to 1st ele of my_array
    array_pointer++;               // increamenting array pointer with 1

    cout << "Second element before updating is " << my_array[1] << "\n";

    // *array_pointer points to the value stored at add of 2 element in my_array
    *array_pointer = 35; // changing value using deref

    cout << "Third element after updating is " << my_array[1] << "\n\n";
}

// Note
// For more information view array_vs_&array.md