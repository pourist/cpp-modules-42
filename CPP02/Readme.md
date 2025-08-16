# C++ Module 02 – Fixed-Point Numbers, Operator Overloading & Orthodox Canonical Form

This module introduces:

* **Orthodox Canonical Form** (the “big four” functions every class should implement)
* **Fixed-point numbers** (integer-based decimal representation)
* **Operator overloading** for intuitive usage of custom types
* Applying these concepts in a geometric algorithm (BSP)

---

##  Exercises Overview

### **ex00 – My First Class in Orthodox Canonical Form**

**Concepts:**

* Implement the **Orthodox Canonical Form**:

  * Default constructor
  * Copy constructor
  * Copy assignment operator
  * Destructor
* Fixed-point basics: store a number as an integer (`value`) with a fixed number of fractional bits (`fractional_bits = 8`).
* Accessor methods (`getRawBits` / `setRawBits`) to interact with the raw integer storage.

---

### **ex01 – Towards a More Useful Fixed-Point Number Class**

**New features:**

* Constructors from `int` and `float`:

  * **Int → Fixed:** `value = int << fractional_bits`
  * **Float → Fixed:** multiply by `2^fractional_bits` and round
* Conversion methods:

  * `toFloat()` – returns a floating-point representation
  * `toInt()` – returns the integer part
* Overload `operator<<` to print the `Fixed` as a float via `std::ostream`.

---

### **ex02 – Now We’re Talking**

**Enhancements:**

* Overload:

  * **Comparison operators:** `>`, `<`, `>=`, `<=`, `==`, `!=`
  * **Arithmetic operators:** `+`, `-`, `*`, `/` (preserve fixed-point precision)
  * **Increment/decrement:** pre (`++a`, `--a`) and post (`a++`, `a--`)
* Add `min` and `max` static methods (both const and non-const overloads) to return the smaller/larger of two `Fixed` objects.

---

### **ex03 – BSP (Binary Space Partitioning)**

**Application:**

* Create a `Point` class (Orthodox Canonical Form) using `Fixed` for coordinates.
* Implement `bsp(Point a, Point b, Point c, Point point)`:

  * Returns `true` if `point` lies **strictly inside** triangle `abc`.
  * Uses **area method**:

    * Calculate `Area(ABC)`, `Area(PBC)`, `Area(APC)`, `Area(ABP)`
    * Point is inside if `Area(ABC) == sum of sub-areas` and none are zero.

---

## Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

---

## Key Takeaways

* **Orthodox Canonical Form** ensures safe copying, assignment, and destruction of objects.
* **Fixed-point representation** allows precise fractional math with predictable behavior.
* **Operator overloading** makes custom classes feel like built-in types.
* Applying these abstractions to real problems (like geometric point-in-triangle checks) shows the power of C++’s OOP features.

---
