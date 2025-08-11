### **1. Why `print_vec` works with both**

Your function is:

```cpp
void print_vec(std::span<int> span)
```

When you call:

```cpp
print_vec(myvec);   // std::vector<int>
print_vec(arr);     // int arr[]
```

it works because `std::span<int>` has **templated constructors** that can accept _any_ contiguous sequence of `int`s — as long as it knows the size.

---

### **2. How it works under the hood**

`std::span` is basically:

```cpp
template<class T>
class span {
    T* ptr;     // pointer to first element
    size_t sz;  // number of elements
public:
    // Constructor from raw pointer + size
    span(T* p, size_t count);

    // Constructor from contiguous container (vector, array, std::array)
    template<class ContiguousContainer>
    span(ContiguousContainer& c);

    // Constructor from C-style array
    template<size_t N>
    span(T (&arr)[N]);
};
```

So when you pass a:

-   **`std::vector<int>`** → The constructor takes `.data()` and `.size()`.
-   **C-style array (`int arr[]`)** → It uses the array’s size `N` known at compile-time.

---

### **3. Why this is nice**

Before `std::span`, you had to write **multiple overloads**:

```cpp
void print_vec(const std::vector<int>& v);
void print_vec(const int* arr, size_t size);
```

Now you just write **one function**:

```cpp
void print_vec(std::span<int> span);
```

and it works for **all contiguous int sequences** — no copies, no templates, no multiple overloads.

---

### **4. Visual idea**

```
vector<int> myvec{1, 2, 3, 4, 5};
[ 1 | 2 | 3 | 4 | 5 ]
  ^
  span: ptr → size = 5

int arr[] = {10, 20, 30, 40};
[10 | 20 | 30 | 40]
  ^
  span: ptr → size = 4
```

The function just loops through whatever memory region `span` points to.
