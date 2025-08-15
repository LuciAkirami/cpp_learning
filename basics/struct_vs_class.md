| Feature                  | `struct`                                                  | `class`                                                |
| ------------------------ | --------------------------------------------------------- | ------------------------------------------------------ |
| **Default Access**       | Public members                                            | Private members                                        |
| **Purpose (common use)** | Simple data grouping (PODs)                               | Encapsulation, abstraction, OOP                        |
| **Inheritance Default**  | Public                                                    | Private                                                |
| **Access Modifiers**     | Can still use `public`, `private`, `protected` explicitly | Same                                                   |
| **Memory Layout**        | Same as class if members are identical                    | Same as struct if members are identical                |
| **Example Use Case**     | `struct Point { int x, y; };` for plain storage           | `class Point { private: int x, y; ... };` with methods |
