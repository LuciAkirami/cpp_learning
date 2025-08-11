#include <iostream>
#include <memory>
#include <vector>
#include <span> // C++20 feature: non-owning view into a sequence of elements

// Function to print elements of a span
// std::span<int> is a lightweight object that refers to a contiguous block of ints.
// It does NOT own the data — just a view into it.
void print_vec(std::span<int> span)
{
    for (auto element : span)
    {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

int main()
{
    // A std::vector of ints
    std::vector<int> myvec{1, 2, 3, 4, 5};

    std::cout << "Full vector: ";
    print_vec(myvec);
    // ✅ Implicit conversion: vector<int> → span<int>

    // Create a span starting from 2nd element (index 1), length = 3
    // This will print elements at indices 1, 2, 3 → {2, 3, 4}
    std::cout << "Partial view (index 1 to 3 elements): ";
    print_vec(std::span(myvec.begin() + 1, 3));

    // Example: span from raw array
    int arr[] = {10, 20, 30, 40};
    std::cout << "Raw array via span: ";
    print_vec(arr); // arrays convert to span too

    // Example: modifying data via span
    std::span<int> subspan(myvec.begin() + 2, 2); // view of {3, 4}
    subspan[0] = 99;                              // modifies myvec directly
    std::cout << "Modified original vector via span: ";
    print_vec(myvec);

    return 0;
}

/*
==============================
WHAT IS std::span?
==============================
- Introduced in C++20
- A non-owning, lightweight view into a contiguous sequence of elements.
- Works with:
    * std::vector
    * std::array
    * Raw arrays
- Key points:
    1. Does NOT allocate or own memory — lifetime of underlying data must outlive the span.
    2. Safer than passing raw pointers + size (avoids mismatches).
    3. Can represent partial ranges (subarrays) without copying data.
    4. Allows modifying the underlying data if span is non-const.
- Syntax:
    std::span<T> name(start_pointer, count);
    std::span<T> name(container); // from vector, array, etc.
- How to Run:
    g++ 24std_span.cpp -o sp --std=c++20

More explanation in span.md
*/
