#include <iostream>
#include <memory>
#include <vector>
#include <span>

/// Function to print elements of a contiguous sequence
/// ----------------------------------------------------
/// Takes a std::span<int> which is a *view* over a contiguous block of memory
/// (e.g., vector, std::array, or raw array).
/// It does NOT own the memory — it only stores:
///     1. A pointer to the first element
///     2. The number of elements
/// This means:
///  - No copying is done
///  - Works for many container types with a single function
void print_vec(std::span<int> span)
{
    std::cout << "Span size: " << span.size() << " elements\n";
    std::cout << "Span address (ptr to first element): " << span.data() << "\n";

    for (auto element : span)
    {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

int main()
{
    // Example 1: Using a std::vector<int>
    // ------------------------------------
    // std::span<int> can be constructed from a std::vector<int> because:
    //   - std::vector stores its elements contiguously in memory
    //   - span can call vector.data() and vector.size() internally
    std::vector<int> myvec{1, 2, 3, 4, 5};
    print_vec(myvec); // Works directly — no explicit conversion

    // Example 2: Using a subrange of a std::vector<int>
    // -------------------------------------------------
    // std::span can also be made from a pointer range (begin, end)
    // Here, we create a view starting from the 2nd element (index 1)
    // and containing 3 elements: {2, 3, 4}
    print_vec(std::span(myvec.begin() + 1, 3));

    // Example 3: Using a C-style array
    // ---------------------------------
    // std::span has a constructor that can deduce the size N from
    // an array type T(&arr)[N], so it knows how many elements are in it.
    int myarr[] = {10, 20, 30, 40};
    print_vec(myarr); // Automatically converts to span<int>

    // Visualizing what's happening inside:
    // -------------------------------------
    // myvec   -> [1][2][3][4][5]     (ptr = &myvec[0], size = 5)
    // myarr   -> [10][20][30][40]    (ptr = &myarr[0], size = 4)
    // span is just a { pointer, size } pair pointing to these sequences.
}
