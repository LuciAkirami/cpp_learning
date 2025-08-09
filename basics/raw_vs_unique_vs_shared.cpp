#include <iostream>
#include <memory> // for unique_ptr and shared_ptr

using namespace std;

int main()
{
    cout << "\n===== RAW POINTER =====\n";
    // Raw pointer: just stores an address, no ownership
    int *raw = new int(10); // allocate memory manually
    cout << "Raw pointer value: " << *raw << endl;
    cout << "Raw pointer address: " << raw << endl;

    // You MUST delete manually to prevent memory leak
    delete raw; // If you forget, memory leaks!
    // If two raw pointers delete the same address, program crashes (double delete)

    cout << "\n===== UNIQUE_PTR (Exclusive Ownership) =====\n";
    // unique_ptr: owns the resource exclusively
    unique_ptr<int> uptr = make_unique<int>(20);
    cout << "unique_ptr value: " << *uptr << endl;
    cout << "unique_ptr address: " << uptr.get() << endl;

    // Copying is NOT allowed — uncommenting below will cause compile error
    // unique_ptr<int> uptr2 = uptr; // Copy not allowed

    // Moving transfers ownership
    unique_ptr<int> uptr2 = move(uptr); // Ownership moved from uptr to uptr2
    cout << "After move, uptr is " << (uptr ? "not null" : "null") << endl;
    cout << "uptr2 value: " << *uptr2 << endl;

    cout << "\n===== SHARED_PTR (Shared Ownership) =====\n";
    // shared_ptr: multiple shared_ptrs can own the same resource
    shared_ptr<int> sptr1 = make_shared<int>(30);
    shared_ptr<int> sptr2 = sptr1; // Copy allowed, reference count increases
    cout << "sptr1 value: " << *sptr1 << endl;
    cout << "sptr2 value: " << *sptr2 << endl;
    cout << "Reference count: " << sptr1.use_count() << endl;

    // When last shared_ptr is destroyed, memory is freed automatically
    sptr2.reset(); // decrease ref count
    cout << "After resetting sptr2, ref count: " << sptr1.use_count() << endl;

    cout << "\n===== SUMMARY TABLE =====\n";
    cout << "Raw Pointer   : No ownership rules, must delete manually, unsafe\n";
    cout << "unique_ptr    : Exclusive ownership, no copying, moving allowed, auto-delete\n";
    cout << "shared_ptr    : Shared ownership, copying allowed, ref counting, auto-delete\n";

    return 0;
}
