# C++ Module 09 – STL Containers in Practice

This module focuses on practicing **STL containers** by solving progressively more complex problems.
Each exercise requires a different choice of container suited to the task.

---

## Exercises Overview

### **ex00 – Bitcoin Exchange**

**Goal:**

* Read a CSV database of Bitcoin exchange rates.
* Compute conversions from an input file of `date | value` lines.

**Container Used:**

* `std::map<int, float>` (dates mapped to rates).

**Concepts:**

* Efficiently storing data keyed by date.
* Lookup of the closest earlier date when an exact match isn’t found.
* Robust input validation (invalid dates, negative/too large values, malformed lines).

**Key Learning:**

* Ordered lookups with `std::map`.
* Importance of rigorous parsing and error checking.

---

### **ex01 – Reverse Polish Notation (RPN)**

**Goal:**

* Evaluate a postfix mathematical expression passed as a single argument.

**Container Used:**

* `std::stack<float>`.

**Concepts:**

* Stack-based evaluation of expressions.
* Support for operators: `+ - * /`.
* Restricted input: single-digit numbers (< 10).
* Error handling (invalid characters, too few operands, division by zero, malformed expressions).

**Key Learning:**

* Using `std::stack` for direct expression evaluation.
* Defensive programming to handle invalid input.

---

### **ex02 – PmergeMe**

**Goal:**

* Sort a sequence of positive integers.
* Compare performance between two STL containers.

**Containers Used:**

* `std::vector<int>`
* `std::list<int>`

**Concepts:**

* Implemented merge sort for both containers.
* Displayed sequence before and after sorting.
* Measured runtime with `gettimeofday`.
* Subject mentions Ford–Johnson, but merge sort is acceptable for correct results and timing comparison.

**Key Learning:**

* Different strategies for sorting depending on container type.
* Practical comparison of performance between `vector` and `list`.
* Measuring algorithm performance with timing utilities.

---



