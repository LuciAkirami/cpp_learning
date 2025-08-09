#include <iostream>
#include <memory> // For std::unique_ptr

int main()
{
    // ----------------- UNIQUE_PTR OWNS A RESOURCE EXCLUSIVELY -------------------

    /**
     * A unique_ptr ensures exclusive ownership of a dynamically allocated object.
     * You CANNOT copy a unique_ptr. Only one unique_ptr can manage a resource at a time.
     */

    auto ptr1 = std::make_unique<int>(100); // ptr1 owns the integer with value 100

    std::cout << "ptr1 points to value: " << *ptr1 << std::endl;

    // ----------------- COPYING IS DISALLOWED -------------------
    // auto ptr2 = ptr1; // ❌ This will cause a compile-time error: copy constructor is deleted

    // ----------------- MOVING TRANSFERS OWNERSHIP -------------------

    /**
     * We can TRANSFER ownership using std::move.
     * After moving, ptr1 becomes empty (nullptr), and ptr2 becomes the new owner.
     * std::unique_ptr ensures a unique ownership of a dynamically allocated memory / object
     */

    std::unique_ptr<int> ptr2 = std::move(ptr1); // Transfer ownership from ptr1 to ptr2

    if (!ptr1)
    {
        std::cout << "ptr1 is now null after move." << std::endl;
    }

    std::cout << "ptr2 points to value: " << *ptr2 << std::endl;

    // ----------------- MOVING ARRAYS -------------------

    /**
     * unique_ptr also works with dynamically allocated arrays (using [] syntax).
     * Let's create and move an array pointer.
     */

    auto array_ptr1 = std::make_unique<int[]>(5);
    array_ptr1[0] = 10;
    array_ptr1[1] = 20;

    std::cout << "array_ptr1[0]: " << array_ptr1[0] << ", array_ptr1[1]: " << array_ptr1[1] << std::endl;

    // Transfer ownership to another pointer
    auto array_ptr2 = std::move(array_ptr1);

    if (!array_ptr1)
    {
        std::cout << "array_ptr1 is now null after move." << std::endl;
    }

    std::cout << "array_ptr2[0]: " << array_ptr2[0] << ", array_ptr2[1]: " << array_ptr2[1] << std::endl;

    // ----------------- FUNCTION RETURN -------------------

    /**
     * unique_ptr is often used for returning dynamically allocated resources from functions.
     * It avoids raw pointer return and clearly conveys ownership transfer.
     */

    // The below is a lambda function. To know more visit lambda.md
    auto make_int = []() -> std::unique_ptr<int>
    {
        return std::make_unique<int>(999); // Returning ownership to the caller
    };

    std::unique_ptr<int> number = make_int();
    std::cout << "Returned number: " << *number << std::endl;

    return 0;
}

/**
 * References:
 * https://en.cppreference.com/w/cpp/memory/unique_ptr.html
 * https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique.html
 *
 * To learn about difference between Raw vs Unique Ptr in Copying check raw_vs_unique.md
 *
 */