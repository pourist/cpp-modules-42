# C++ Module 07 – Templates

This module introduces **function and class templates** to write **generic, reusable code** in C++.
It focuses on template syntax, const-correctness, and safety in generic contexts.

---

## Exercises Overview

### **ex00 – Start with a few functions**

**Goal:**

* Implement three function templates:

  * `swap(T&, T&)`
  * `min(T const&, T const&)`
  * `max(T const&, T const&)`

**Concepts:**

* Writing **function templates**.
* References to avoid copies.
* Const-correctness for comparison functions.

**Key Learning:**

* Generic functions work with any type that supports the needed operators.
* Templates are instantiated at compile time.

---

### **ex01 – Iter**

**Goal:**

* Implement `iter(T* array, size_t length, void (*f)(T&))` (or const overload).
* Apply a function to each element of an array.

**Concepts:**

* Passing function pointers (and deducing template arguments).
* Supporting both const and non-const arrays.
* Iterating over generic arrays.

**Key Learning:**

* Higher-order functions in C++ via templates.
* Importance of const safety in generic code.

---

### **ex02 – Array**

**Goal:**

* Implement a class template `Array<T>` with:

  * Default constructor (empty).
  * Constructor taking size (allocates elements).
  * Copy constructor, assignment operator, destructor (**Rule of Three**).
  * `operator[]` with bounds checking (throw `std::out_of_range`).
  * `size()` method.

**Concepts:**

* **Class templates** with dynamic allocation.
* Deep copy for template containers.
* Exception safety (bounds checking).
* Mimicking behavior of `std::vector`/`std::array` in a minimal form.

**Key Learning:**

* Implementing a safe, generic container.
* Managing memory in a templated class.
* How templates and exceptions work together.

---