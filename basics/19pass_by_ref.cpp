#include <iostream> // Required for input/output using cout
#include <vector>   // Required for using std::vector container

using namespace std;

// ---------------------------------------------------------------------
// Function to print all elements in a vector
// Takes the vector by value (copy), but we only read it, so it's fine.
// ---------------------------------------------------------------------
void print_vectors(vector<int> my_vec)
{
    printf("Printing elements of a Vector:\n");
    for (auto ele : my_vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------
// Adds N elements to the vector (0 to N-1)
// BUT the vector is passed **by value**, so this modifies a **copy**,
// and the original vector in main() remains unchanged.
// ---------------------------------------------------------------------
void add_vector_pass_by_value(vector<int> my_vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        my_vec.push_back(i); // This affects the local copy only
    }
}

// ---------------------------------------------------------------------
// Adds N elements to the vector (0 to N-1)
// This time the vector is passed **by reference**, so the original
// vector in main() is directly modified.
// ---------------------------------------------------------------------
void add_vector_pass_by_ref(vector<int> &my_vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        my_vec.push_back(i); // This affects the actual vector in main()
    }
}

int main()
{
    // Create an empty vector of integers
    vector<int> my_vector;

    // ------------------ CALL PASS-BY-VALUE FUNCTION ------------------
    add_vector_pass_by_value(my_vector, 10);
    // Despite trying to add elements, my_vector is unchanged
    print_vectors(my_vector); // Output: empty

    // ------------------ CALL PASS-BY-REFERENCE FUNCTION ------------------
    add_vector_pass_by_ref(my_vector, 10);
    // Now my_vector is modified because we passed it by reference
    print_vectors(my_vector); // Output: 0 1 2 3 4 5 6 7 8 9

    return 0;
}
