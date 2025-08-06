## Comparing `unique_ptr` with raw pointer copying

Let's contrast this:

### 🔸 Raw Pointer Copying

```cpp
int* raw_ptr1 = new int(10);
int* raw_ptr2 = raw_ptr1; // ✅ You can copy raw pointers

*raw_ptr2 = 20;

std::cout << *raw_ptr1 << std::endl; // prints 20

// DANGER: Both pointers point to the same memory.
// Deleting one and using the other = undefined behavior!
delete raw_ptr1;
// delete raw_ptr2; ❌ Double delete! Causes crash.
```

> 🧨 **Problem**: No ownership clarity. Raw pointers allow copying, leading to double deletes, memory leaks, or dangling pointers.

---

### 🔹 `unique_ptr` Ownership Model

```cpp
auto uptr1 = std::make_unique<int>(10);
// auto uptr2 = uptr1; ❌ Not allowed! Copy constructor is deleted

auto uptr2 = std::move(uptr1); // ✅ Ownership transferred

if (!uptr1) std::cout << "uptr1 is now null" << std::endl;
```

> ✅ **Safe**: Only one pointer (`uptr2`) owns the memory. Automatic deletion when out of scope. No double delete.

---

### 🔍 Summary: Copying Comparison

| Feature             | Raw Pointer | `unique_ptr`           |
| ------------------- | ----------- | ---------------------- |
| Copyable?           | ✅ Yes      | ❌ No (only movable)   |
| Ownership?          | ❌ Unclear  | ✅ Exclusive           |
| Auto cleanup?       | ❌ No       | ✅ Yes (on scope exit) |
| Risk of double free | ✅ Yes      | ❌ No                  |
| Safer?              | ❌ No       | ✅ Absolutely          |

---
