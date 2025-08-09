#include <iostream>
#include <memory> // Required for std::shared_ptr, std::make_shared

using namespace std;

int main()
{
    // ---------------------------
    // 1. Creating a shared pointer
    // ---------------------------
    // std::shared_ptr manages an object through a pointer.
    // Multiple shared_ptr instances can own the same resource.
    // The resource is deleted automatically when the last shared_ptr owning it is destroyed.

    // Here, ptr1 points to a dynamically allocated array of 10 ints.
    shared_ptr<int[]> ptr1(new int[10]);

    // Set a value at index 5
    ptr1[5] = 10;

    // -----------------------------------------------------
    // 2. Sharing ownership between two shared_ptr variables
    // -----------------------------------------------------
    // Copying a shared_ptr increases the reference count.
    // Unlike unique_ptr, this is allowed because shared_ptr supports shared ownership.
    auto ptr2 = ptr1; // ptr1 and ptr2 now point to the same array

    // ------------------------------------------------------
    // 3. Checking the reference count (use_count)
    // ------------------------------------------------------
    // use_count() tells us how many shared_ptr instances currently own the resource
    cout << "Reference Count after sharing: " << ptr1.use_count() << '\n'; // Expect 2

    // Access the value via ptr2 (same underlying array)
    cout << "Value at Index 5 (via ptr2): " << ptr2[5] << '\n';

    // ------------------------------------------------------
    // 4. Demonstrating scope-based cleanup
    // ------------------------------------------------------
    {
        shared_ptr<int[]> ptr3 = ptr1;                                               // Add another owner
        cout << "Reference Count after creating ptr3: " << ptr1.use_count() << '\n'; // Expect 3
    }
    // ptr3 goes out of scope here, so reference count decreases
    cout << "Reference Count after ptr3 is destroyed: " << ptr1.use_count() << '\n'; // Expect 2

    // ------------------------------------------------------
    // 5. Resetting a shared_ptr
    // ------------------------------------------------------
    // reset() decreases the reference count and, if it becomes zero, deletes the managed resource
    ptr2.reset();
    cout << "Reference Count after resetting ptr2: " << ptr1.use_count() << '\n'; // Expect 1

    // ------------------------------------------------------
    // 6. Another way of making a shared_ptr
    // ------------------------------------------------------
    // make_shared is preferred for single objects, but works differently for arrays:
    // C++20 introduced std::make_shared<T[]>(n) for arrays.
    // auto ptr_array = make_shared<int[]>(10);

    // ptr_array[2] = 42;
    // cout << "Value at Index 2 in ptr_array: " << ptr_array[2] << '\n';

    // To use the code above, use g++-12 else it will not work

    // When main() ends, ptr1 and ptr_array are destroyed automatically,
    // freeing the memory they manage.
    return 0;
}

/*
 KEY POINTS ABOUT std::shared_ptr:
-----------------------------------
1. Multiple shared_ptr can own the same resource.
2. Each copy increases the reference count.
3. Resource is freed when the last owner is destroyed or reset().
4. More overhead than unique_ptr because of reference counting.
5. Useful when ownership must be shared between different parts of the code.

 Caution:
   - Avoid creating shared_ptr from a raw pointer directly more than once,
     as it can lead to multiple control blocks and double-deletion.
   - Prefer std::make_shared for safety and efficiency (except for arrays before C++20).
*/
