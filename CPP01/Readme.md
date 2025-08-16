# C++ Module 01 – Memory Allocation, References, Pointers to Members, and Switch

This module builds on C++ class basics and object handling, introducing:

* **Stack vs Heap allocation**
* **References vs Pointers**
* **Pointer-to-member functions**
* **Switch statement** control flow
  Each exercise focuses on a small, isolated concept.

---

## Exercises Overview

### **ex00 – BraiiiiiiinnnzzzZ**

**Goal:**
Implement a `Zombie` class with:

* Name (`std::string`) and `announce()` method
* Destructor logging destruction
* Helper functions:

  * `Zombie* newZombie(std::string)` → creates on **heap**
  * `void randomChump(std::string)` → creates on **stack**

**Concepts:**

* Difference between stack and heap allocation
* Constructors/destructors lifecycle
* Returning heap-allocated objects via pointers

---

### **ex01 – Moar brainz!**

**Goal:**
`Zombie* zombieHorde(int N, std::string name)`:

* Allocate a **heap array** of `N` zombies
* Initialize each zombie and call `announce()` in a loop

**Concepts:**

* `new[]` / `delete[]` for dynamic arrays
* Constructor called for each array element
* Bulk initialization in loops

---

### **ex02 – HI THIS IS BRAIN**

**Goal:**

* Create a string variable, pointer, and reference to it
* Print addresses and values

**Concepts:**

* **Pointer**: holds address, can be reseated/null
* **Reference**: alias, must bind at creation, never null
* Both allow indirect access to the same object

---

### **ex03 – Unnecessary violence**

**Goal:**
`Weapon` class with getters/setters.
Two human classes:

* `HumanA` → holds weapon by **reference** (always armed)
* `HumanB` → holds weapon by **pointer** (optional)

**Concepts:**

* Choosing reference vs pointer members
* References require initialization in constructor
* Pointers can be null or changed later
* Const-correct getters

---

### **ex04 – Sed is for losers**

**Goal:**
Program to replace all occurrences of `s1` with `s2` in a file and save as `<filename>.replace`.

**Concepts:**

* File I/O with `std::ifstream` / `std::ofstream`
* String search (`find`) and replace with `substr`
* Guarding against empty search patterns
* Reading and processing line-by-line

---

### **ex05 – Harl 2.0**

**Goal:**
`Harl` class with private methods (`debug`, `info`, `warning`, `error`)
`complain(std::string)` calls the matching method without if/else chains.

**Concepts:**

* **Pointer-to-member functions** for dynamic dispatch
* Mapping strings to method pointers
* Invoking member functions through pointers

---

### **ex06 – Harl filter**

**Goal:**
Modify `Harl` to:

* Take a level as input
* Print that level’s message and all higher severity levels

**Concepts:**

* Mapping strings to integer codes
* `switch` statement with **fallthrough** behavior
* Default case for invalid inputs

---

