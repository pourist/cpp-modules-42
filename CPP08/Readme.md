# C++ Module 08 – STL Containers, Iterators, and Algorithms

This module introduces the **Standard Template Library (STL)**, focusing on containers, iterators, and algorithms.
The goal is to learn how to use ready-made C++ tools effectively instead of reimplementing them.

---

## Exercises Overview

### **ex00 – Easy Find**

**Goal:**

* Implement a function template `easyfind` to search for an integer inside any STL container.

**Concepts:**

* Function templates with generic containers.
* Iterators and `std::find`.
* Exceptions when the element is not found.

**Key Learning:**

* How to build a simple generic algorithm that works with multiple container types.

---

### **ex01 – Span**

**Goal:**

* Implement a `Span` class that:

  * Stores up to `N` integers.
  * Finds the **shortest span** (min difference) and **longest span** (max difference).

**Concepts:**

* Fixed-capacity class design.
* Exception handling for overflows and insufficient elements.
* STL algorithms (`std::sort`, `std::min_element`, etc.).
* Range insertion with iterators.

**Key Learning:**

* Combining STL algorithms with custom class logic for efficient numeric computations.

---

### **ex02 – MutantStack**

**Goal:**

* Extend `std::stack` to make it **iterable**.

**Concepts:**

* Inheriting from STL containers.
* Exposing the underlying container’s iterators.
* Using typedefs for clean iterator access.

**Key Learning:**

* How to adapt STL containers to add missing functionality.

---
