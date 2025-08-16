
# C++ Module 06 – Casts

This module reviews **C++ type conversions** and **RTTI** (Run-Time Type Information).
Through three small exercises, it shows when to use each kind of cast safely.

---

##  Exercises Overview

### **ex00 – Scalar Conversion**

**Goal:**
Implement a `ScalarConverter` with a static `convert(std::string literal)` that:

* Detects input type (`char`, `int`, `float`, `double`, incl. pseudo-literals).
* Converts explicitly to all other types.
* Prints results with correct formatting (handle “impossible”, “non displayable”).

**Concepts:**

* **`static_cast`** for safe, compile-time conversions.
* Parsing and formatting edge cases (ASCII chars, overflow, `nan`, `inf`).

**Key Learning:**

* How to build type detection logic.
* Why explicit casts are clearer and safer than C-style casts.

---

### **ex01 – Serialization**

**Goal:**

* Create a `Serializer` with:

  * `uintptr_t serialize(Data* ptr);`
  * `Data* deserialize(uintptr_t raw);`
* Round-trip a pointer through integer form.

**Concepts:**

* **`reinterpret_cast`** to reinterpret bit patterns (pointer ↔ integer).
* Use of `uintptr_t` (standard type guaranteed to hold a pointer).

**Key Learning:**

* Difference between *converting* vs *reinterpreting*.
* Why `reinterpret_cast` is correct here but unsafe elsewhere.

---

### **ex02 – Identify Real Type**

**Goal:**

* Polymorphic base class `Base` with virtual destructor.
* Derived classes: `A`, `B`, `C`.
* Functions:

  * `Base* generate();` → randomly return new `A/B/C`.
  * `identify(Base* p);` → detect type via pointer.
  * `identify(Base& p);` → detect type via reference.

**Concepts:**

* **`dynamic_cast`**: safe runtime downcasting with RTTI.
* Pointer version returns `nullptr` on failure.
* Reference version throws `std::bad_cast`.

**Key Learning:**

* Base must be **polymorphic** (at least one virtual function).
* How `dynamic_cast` prevents unsafe downcasts.

---

## Concepts Recap

* **`static_cast`** → type-safe compile-time conversion.
* **`reinterpret_cast`** → raw bit reinterpretation (dangerous, use sparingly).
* **`const_cast`** → add/remove const/volatile (undefined if you modify const data).
* **`dynamic_cast`** → safe runtime downcast, requires virtual base.

---
