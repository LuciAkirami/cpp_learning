## What is this syntax?

```cpp
auto make_int = []() -> std::unique_ptr<int>
{
    return std::make_unique<int>(999);
};
```

### 🎯 This is a **lambda function**.

**Lambda functions** are anonymous (unnamed) functions you can define inline.

### 🔍 Breakdown:

| Part                                     | Meaning                                                                                |
| ---------------------------------------- | -------------------------------------------------------------------------------------- |
| `[]`                                     | **Capture clause** – here, empty (`[]`), so it captures nothing from the outer scope.  |
| `()`                                     | **Parameter list** – empty, meaning it takes no arguments.                             |
| `-> std::unique_ptr<int>`                | **Return type** – explicitly declares the lambda will return a `std::unique_ptr<int>`. |
| `{ return std::make_unique<int>(999); }` | The function body, which returns a `unique_ptr` to the value `999`.                    |
| `auto make_int = ...;`                   | This **assigns the lambda to a variable** so you can call it like a regular function.  |

### 💡 Equivalent Normal Function

This is equivalent to writing:

```cpp
std::unique_ptr<int> make_int() {
    return std::make_unique<int>(999);
}
```

But the lambda version is more concise and inline. It’s useful when you don’t want to define a separate named function.

You can call it like this:

```cpp
std::unique_ptr<int> ptr = make_int();
```
